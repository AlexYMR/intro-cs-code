import sys

price = float(sys.argv[1])
percentage = float(sys.argv[2])

tips = price*percentage

print("You need to pay: ", tips, " dollars as gratuity.")
