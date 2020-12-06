#-------------------
# // startree.py
# // Part of HW3
# // Problem 2
#-------------------

import sys

def main():
    """
    This function draws a star tree based on an integer provided by a user,
    which is used as the number of rows for the tree.
    Input: Integer (n)
    Output: Asterisk tree with n rows, each two larger asterisks larger than
    the last
    """
    n = int(sys.argv[1])
    s = ""
    acc = 0
    spaces = n-1
    for i in range(1,n+1):
        """
        Concatenates an empty string with a decreasing number of spaces
        in order to make the string look nice on the output,
        and uses the multiplication operator to repeat the asterisk strings
        """
        s = s+" "*spaces+"*"*(acc+i)+"\n" #-- "\n" is there for neatness
        spaces = spaces - 1
        acc = acc + 1
    print(s)

main()
