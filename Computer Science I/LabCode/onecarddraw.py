from playingcards import *

def main():
    deck = Deck()
    Deck.shuffle(deck)
    Deck.cut(deck)
    Cpts = 0
    Upts = 0
    while len(deck) != 0:
        print("Length: " + str(len(deck)))
        input("\nPress Enter to pick a card.")
        card = Deck.takeTop(deck)
        card2 = Deck.takeTop(deck)
        print(str(card) + " " + str(card2))
        if card > card2:
            Upts = Upts + 1
        elif card2 > card:
            Cpts = Cpts + 1
        print("\nCurrent CPU score: " + str(Cpts) + " | Current user score: " + str(Upts))
    if Cpts > Upts:
        print("The computer won!")
    elif Upts > Cpts:
        print("You win!")
    else:
        print("No one won!")

main()
