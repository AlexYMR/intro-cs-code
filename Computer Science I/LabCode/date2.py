class Date:

    def __init__(self, *args):

        if len(args) == 1:
            splt = args[0].split("/")
            month = int(splt[0])
            day = int(splt[1])
            year = int(splt[2])
        elif len(args) == 3:
            month = args[0]
            day = args[1]
            year = args[2]

        if not isinstance(month, int):
            raise TypeError('Month was not an integer')
        if not isinstance(day, int):
            raise TypeError('Day was not an integer')
        if not isinstance(year, int):
            raise TypeError('Year was not an integer')
        
        self.__monthsOfYear = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
        self.__daysOfMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    
        # Make sure we have a valid month
        if month not in self.__monthsOfYear:
            self.__month = 1 # Default to January if invalid
        else:
            self.__month = month

        if year >= 0:
            self.__year = year
        else:
            self.__year = 1900

        # Make sure that the day is okay for the given month
        idx = self.__monthsOfYear.index(self.__month)
        if self.__month == 2 and self.isLeapYear() and day == 29:
            self.__day = day
        elif day < 1 or day > self.__daysOfMonth[idx]:
            self.__day = 1 # Default to 1 if invalid
        else:
            self.__day = day
        
    def getMonth(self):
        return self.__month

    def getDay(self):
        return self.__day
    
    def getYear(self):
        return self.__year

    def isLeapYear(self):
        if self.getYear() % 400 == 0:
            return True
        elif self.getYear() % 100 != 0 and self.getYear() % 4 == 0:
            return True
        else:
            return False
            
    def endOfMonth(self):
        if self.getMonth() == 2 and self.isLeapYear():
            return self.getDay() == 29 # Comparison not assignment operation
        else:
            idx = self.__monthsOfYear.index(self.getMonth())
            return self.getDay() == self.__daysOfMonth[idx] # Comparison not assignment operation

    def printDate(self):
        print(str(self.getMonth()) + '/' + str(self.getDay()) + '/' + str(self.getYear()))

    def dayOfWeek(self):
        days = ["Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"]
        startDay = 0
        century = int(str(Date.getYear(self))[:2])
        lastTwoOfCentury = int(str(Date.getYear(self))[:-2])
        if Date.isLeapYear(self):
            startDay = 6
        cycle = [6,4,2,0]
        cycleIdx = 2
        centuryStartDays = {}
        for i in range(8):
            start = 18
            cycleIdx = (cycleIdx) % (len(cycle))
            centuryStartDays[str(start + i)] = cycle[cycleIdx]
            cycleIdx = cycleIdx + 1
        centuryStartDay = centuryStartDays[str(century)]
        secondTerm = lastTwoOfCentury // 4
        sumSoFar = int(centuryStartDay) + secondTerm + lastTwoOfCentury
        daysInMonths = [31,28,31,30,31,30,31,31,30,31,30,31]
        MonthDays = []
        if not Date.isLeapYear(self):
            for i in range(daysInMonth):
                MonthDays.append(daysInMonth(Date.getMonth(self)))
        
def main():
    #d1 = Date(12,4,1998)
    #d2 = Date("5/29/1982")
    Date.dayOfWeek(Date("11/11/1111"))

main()
