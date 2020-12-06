import sys
#from party.py import*

class Party:
    def __init__(self, location, DT, theme, peopleList):
       self.__location = location
       self.__dateTime = DT
       self.__theme = theme
       self.__invitees = peopleList
       self.__inviteeResponses = {}
       for i in peopleList:
           self.__inviteeResponses[i] = None
        
    def getPartyTime(self):
        return self.__dateTime

    def getPartyLocation(self):
        return self.__location
    
    def getPartyTheme(self):
        return self.__theme

    def getInvitedGuests(self):
        return self.__invitees

    def recordResponse(self,name,response):
        if name in self.__inviteeResponses:
            self.__inviteeResponses[name] = response
        print(self.__inviteeResponses)
        
    def whoIsComing(self):
        coming = []
        for i,v in self.__inviteeResponses.items():
            if v:
                coming.append(i)
        return coming

    def whoIsNotComing(self):
        notComing = []
        for i,v in self.__inviteeResponses.items():
            if v == False:
                notComing.append(i)
        return notComing

    def hasNotResponded(self):
        notResp = []
        for i,v in self.__inviteeResponses.items():
            if v == None:
                notResp.append(i)
        return notResp
    
    def isComing(self,person):
        coming = whoIsComing(self)
        notComing = whoIsNotComing(self)
        notResp = hasNotResponded(self)
        if person in coming:
            return True
        else:
            return False

def main():
    party = Party("My ass","Oct.24, 2014 8:00 PM","Nothing",["George", "Linda","Lisa"])
    Party.recordResponse(party,"George",True)
    Party.recordResponse(party,"Lisa",False)
    print(Party.whoIsNotComing(party))
    print(Party.whoIsComing(party))
    print(Party.hasNotResponded(party))
    
main()
