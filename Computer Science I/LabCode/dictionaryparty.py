def main():
    potLuck = {
        "Alice":"Shrimp Cocktail",
        "Bob":"Salad",
        "Carol":"Cake",
        "Dave":"Lasagna",
        }
    print("Part A: " + str(potLuck))
    
    potLuck["Eve"] = "Garlic bread"
    print("Part B: " + str(potLuck))
    
    print("Part C: " + "Alice" in potLuck)

    del potLuck["Bob"]
    print("Part D: " + str(potLuck))
    
    print("Part E: " + str("Carol" in potLuck and potLuck["Carol"] or "Nothing!"))

    print("Part F: " + str("Frank" in potLuck and potLuck["Frank"] or "Nothing!"))
    
    guestList = []
    for i,v in potLuck.items():
        guestList.append(i)
    print("Part G: " + str(guestList))

    foodList = []
    for i,v in potLuck.items():
        foodList.append(v)
    print("Part H: " + str(foodList))

main()
