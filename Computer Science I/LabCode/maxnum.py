import sys

def main():
    maxNum = int(sys.argv[1])
    acc = 0
    for i in range(1,maxNum+1,2):
        acc = acc + i
    print(acc)

main()
