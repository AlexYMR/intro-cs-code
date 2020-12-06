import sys

def powerTower(a,k):
    result = a
    print(result)
    for i in range(1,k):
       result = a**result
       print(result)

def main():
   # a = int(sys.argv[1])
   # k = int(sys.argv[2])
    # powerTower(a,k)
    powerTower(2,4)
    powerTower(3,3)
    

main()
