#------------------------
# // fraction.py
# // Part of HW9
# // Problem 1
#------------------------

class Fraction:
    def __init__(self,num,denom):
        """
        Constructs a Fraction object based on two given numbers (num and denom), which are the numerator and denominator of the fraction, respectively.
        The fraction is then simplified to ensure the cleanest calculations.
        """
        self.__num = num
        self.__denom = denom
        Fraction.__simplify(self)
    
    def getNum(self):
        """
        Returns the numerator of the Fraction.
        """
        return self.__num
    
    def getDen(self):
        """
        Returns the denominator of the Fraction.
        """
        return self.__denom

    def setNum(self,num):
        """
        Sets the numerator of the Fraction to num, and simplifies.
        """
        self.__num = num
        Fraction.__simplify(self)

    def setDen(self,denom):
        """
        Sets the denominator of the Fraction to denom, and simplifies.
        """
        self.__denom = denom
        Fraction.__simplify(self)

    def getReciprocal(self):
        """
        Returns the reciprocal of the Fraction.
        """
        return Fraction(self.__denom,self.__num)

    def __simplify(self):
        """
        Simplifies a Fraction to its base form: e.g., 20/100 becomes 1/5, 4/6 becomes 2/3, etc.
        """
        #--If the denominator is 0, makes the Fraction 0/0 (indeterminate form)
        if self.__denom == 0 and self.__num != 0:
            Fraction.setNum(self,0)
            Fraction.setDen(self,0)
        #--If the numerator is 0, makes the denominator 1
        elif self.__denom != 0 and self.__num == 0:
            Fraction.setDen(self,1)
        else:
            #20/100 -> 1/5
            num = abs(self.__num)
            denom = abs(self.__denom)
            #--Compares the numerator and denominator and assigns the smallest value to smallestNum
            smallestNum = (num > denom and denom or denom > num and num or num == denom and num)
            n = smallestNum
            divisor = 1
            while n != 0:
                #--If num and denominator are evenly divisible by the current n value, breaks the loop
                if num % n == 0 and denom % n == 0:
                    divisor = n
                    break
                n = n -1
            #--If the denominator is negative, makes the numerator negative (looks better in output)
            if self.__denom < 0 and self.__num > 0:
                Fraction.setDen(self,0 - self.__denom)
                Fraction.setNum(self, 0 - self.__num)
            #--If both numerator and denominator are negative, "cancels" them out and makes the fraction positive
            elif self.__denom < 0 and self.__num < 0:
                Fraction.setDen(self,0 - self.__denom)
                Fraction.setNum(self,0 - self.__num)
            #--Sets the adjusted (simplified) values for the Fraction
            self.__num = int(Fraction.getNum(self)/divisor)
            self.__denom = int(Fraction.getDen(self)/divisor)

    def __str__(self):
        """
        Makes it possible to convert a Fraction into a string.
        """
        sNum = str(Fraction.getNum(self))
        sDenom = str(Fraction.getDen(self))
        return sNum + "/" + sDenom

    def __float__(self):
        """
        Makes it possible to convert a Fraction into a float.
        """
        return Fraction.getNum(self) / Fraction.getDen(self)

    def __int__(self):
        """
        Makes it possible to convert a Fraction into an integer.
        """
        return Fraction.getNum(self) // Fraction.getDen(self)

    def __add__(self,otherFraction):
        """
        Makes it possible to add two Fractions by finding a common denominator and adding numbers individually.
        """
        #1/12 + 1/5 = 1*5/12*5 + 1*12/5*12
        otherNum = Fraction.getNum(otherFraction)
        otherDenom = Fraction.getDen(otherFraction)
        num = Fraction.getNum(self)
        denom = Fraction.getDen(self)
        if (num == 0 and denom == 0) or (otherNum == 0 and otherDenom == 0):
            return Fraction(0,0)
        newNum1 = num * otherDenom
        newNum2 = otherNum * denom
        newDenom = denom * otherDenom
        return Fraction((newNum1+newNum2),newDenom)

    def __sub__(self,otherFraction):
        """
        Makes it possible to subtract two Fractions by finding a common denominator and subtracting numbers individually.
        """
        otherNum = Fraction.getNum(otherFraction)
        otherDenom = Fraction.getDen(otherFraction)
        num = Fraction.getNum(self)
        denom = Fraction.getDen(self)
        if (num == 0 and denom == 0) or (otherNum == 0 and otherDenom == 0):
            return Fraction(0,0)
        newNum1 = num * otherDenom
        newNum2 = otherNum * denom
        newDenom = denom * otherDenom
        return Fraction((newNum1-newNum2),newDenom)

    def __mul__(self,otherFraction):
        """
        Makes it possible to multiply two Fractions together by multiplying across.
        """
        otherNum = Fraction.getNum(otherFraction)
        otherDenom = Fraction.getDen(otherFraction)
        num = Fraction.getNum(self)
        denom = Fraction.getDen(self)
        return Fraction((num*otherNum),(denom*otherDenom))

    def __truediv__(self,otherFraction):
        """
        Makes it possible to divide two Fractions by multiplying the left Fraction by the reciprocal of the right Fraction.
        """
        recip = Fraction.getReciprocal(otherFraction)
        return self*recip

    def __eq__(self,otherFraction):
        """
        Returns whether a Fraction equals another Fraction by comparing their float values.
        """
        if float(self) == float(otherFraction):
            return True
        else:
            return False

    def __ne__(self,otherFraction):
        """
        Returns whether a Fraction is not equal to another Fraction by comparing their float values.
        """
        if float(self) != float(otherFraction):
            return True
        else:
            return False

    def __lt__(self,otherFraction):
        """
        Returns whether a Fraction is less than another Fraction by comparing their float values.
        """
        if float(self) < float(otherFraction):
            return True
        else:
            return False

    def __le__(self,otherFraction):
        """
        Returns whether a Fraction is less than or equal to another Fraction by comparing their float values.
        """
        if float(self) <= float(otherFraction):
            return True
        else:
            return False

    def __gt__(self,otherFraction):
        """
        Returns whether a Fraction is greater than another Fraction by comparing their float values.
        """
        if float(self) > float(otherFraction):
            return True
        else:
            return False

    def __ge__(self,otherFraction):
        """
        Returns whether a Fraction greater than or equal to another Fraction by comparing their float values.
        """
        if float(self) >= float(otherFraction):
            return True
        else:
            return False
