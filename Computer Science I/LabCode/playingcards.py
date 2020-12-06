import random

class Card:
    def __init__(self,value,suit):
        if int(value) and value >= 1 and value <= 13:
            self.__value = value
        if suit == "D" or suit == "H" or suit == "C" or suit == "S":
            self.__suit = suit
        
    def getValue(self):
        return self.__value
    
    def setValue(self,val):
        if int(val) and val >= 1 and val <= 13:
            self.__value = val

    def getSuit(self):
        return self.__suit

    def setSuit(self,suit):
        if suit == "D" or suit == "H" or suit == "C" or suit == "S":
            self.__suit = suit

    def __eq__(self,otherCard):
        if self.__value == Card.getValue(otherCard):
            return True
        else:
            return False

    def __lt__(self,otherCard):
        if self.__value < Card.getValue(otherCard):
            return True
        else:
            return False

    def __le__(self,otherCard):
        if self.__value <= Card.getValue(otherCard):
            return True
        else:
            return False

    def __gt__(self,otherCard):
        if self.__value > Card.getValue(otherCard):
            return True
        else:
            return False

    def __ge__(self,otherCard):
        if self.__value >= Card.getValue(otherCard):
            return True
        else:
            return False

    def __ne__(self,otherCard):
        if self.__value != Card.getValue(otherCard):
            return True
        else:
            return False

    def __str__(self):
        return str(self.__value) + self.__suit

class Deck:
    def __init__(self):
        self.__cards = []
        suit = "S"
        for i in range(1,13):
            self.__cards.append(Card(i,suit))
        suit = "D"
        for i in range(1,13):
            self.__cards.append(Card(i,suit))
        suit = "H"
        for i in range(1,13):
            self.__cards.append(Card(i,suit))
        suit = "C"
        for i in range(1,13):
            self.__cards.append(Card(i,suit))

    def printDeck(self):
        for i in range(1,len(self.__cards)):
            print(self.__cards[-i])
            
    def shuffle(self):
        random.shuffle(self.__cards)
    
    def cut(self):
        randIdx = random.randint(0,len(self.__cards))
        firstHalf = self.__cards[:randIdx]
        secondHalf = self.__cards[randIdx:]
        self.__cards = secondHalf + firstHalf

    def takeTop(self):
        return self.__cards.pop()

    def __len__(self):
        return len(self.__cards)
