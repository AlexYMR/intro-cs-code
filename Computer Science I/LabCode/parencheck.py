def parenCheck(s):
    mustClose = 0
    paraCount = 0
    for i in range(len(s)):
        if ord(s[i:i+1]) == 40:
            mustClose = 1
            paraCount = paraCount + 1
        if ord(s[i:i+1]) == 41:
            paraCount = paraCount - 1
            if not paraCount:
                mustClose = 0
    return mustClose

def main():
    s = input("Enter a string: ")
    if parenCheck(s):
        print("False")
    else:
        print("True")

main()
            
