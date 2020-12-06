def lebniz(terms):
    acc = 0
    for i in range(1, terms + 1):
        acc = acc + 4*(-1)**(i+1)/(2*i - 1)
    return acc

def fastLebniz(terms):
    acc = 0
    sign = -1
    for i in range(1, terms + 1):
        denominator = 2*i - 1
        sign = sign*(-1)
        currentTerm = 4/denominator*sign
        acc = acc + currentTerm
    return acc

def wallis(terms):
    acc = 1
    for i in range(1, terms + 1):
        num = 2*i
        leftDen = num - 1
        rightDen = num + 1
        currentTerm = (num/leftDen)*(num/rightDen)
        acc = acc * currentTerm
    return acc*2
