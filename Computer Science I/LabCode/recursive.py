def returnSum(n):
    if n == 1:
        return n
    else:
        return n + returnSum(n-1)

def reverseString(s):
    if len(s) == 0:
        return s
    else:
        return reverseString(s[1:]) + s[0]

def exponent(base,n):
    if n == 0:
        return 1
    elif n%2 == 0:
        print(str(base) + "*" + str(n) + "=" + str(base*n))
        return exponent(base*base,n/2)
    else:
        print(str(base) + "*" + str(n) + "=" + str(base*n))
        return base*exponent(base*base,(n-1)/2)

def main():
    print(returnSum(2))
    print(reverseString("Hello world"))
    print(exponent(2,100))

main()
