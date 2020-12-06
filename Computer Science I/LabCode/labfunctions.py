import sys

def calcGamma(n):
    gamma = 1.5 * 3**2 + n # a
    return gamma

def calcOmega(n):
    omega = n**2 + (4.8 / 6.2) * 3 # b
    return omega

def calcUpsilon(n):
    upsilon = 8 * n // 3 % 2 + 1.678 # c
    return upsilon

def main():

    number = int(sys.argv[1])
    
    omega = calcOmega(number)
    gamma = calcGamma(number)
    upsilon = calcUpsilon(number)

    print(omega)
    print(gamma)
    print(upsilon)

main()
