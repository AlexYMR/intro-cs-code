'''
Author: Prof. Weaver
Description:  Defines a basic class to handle dates given in 
              the American standard format of month/day/year.
              Also demonstrates some simple error handling.
'''
     
class Date:
    ''' Creates new date objects based on month/day/year format '''
    def __init__(self, month, day, year):
        ''' Class constructor, requires a month (int), a day(int), 
            and a year(int).
            Checks to make sure all three parameters are valid.
            Invalid month defaults to 1
            Invalid day defaults to 1
            Invalid year defaults to 1900 '''

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
        ''' Returns the month '''
        return self.__month

    def getDay(self):
        ''' Returns the day '''
        return self.__day
    
    def getYear(self):
        ''' Returns the year '''
        return self.__year

    def isLeapYear(self):
        ''' Returns True if year is a leap year, False otherwise '''
        if self.getYear() % 400 == 0:
            return True
        elif self.getYear() % 100 != 0 and self.getYear() % 4 == 0:
            return True
        else:
            return False
            
    def endOfMonth(self):
        ''' Returns boolean True if date is last day of month,
            False otherwise '''

        if self.getMonth() == 2 and self.isLeapYear():
            return self.getDay() == 29 # Comparison not assignment operation
        else:
            idx = self.__monthsOfYear.index(self.getMonth())
            return self.getDay() == self.__daysOfMonth[idx] # Comparison not assignment operation

    def printDate(self):
        ''' Prints date in month/day/year format'''
        print(str(self.getMonth()) + '/' + str(self.getDay()) + '/' + str(self.getYear()))

