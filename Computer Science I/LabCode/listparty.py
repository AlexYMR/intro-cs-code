def main():
    items = ["Chips","Salsa","Strawberry Ice-cream","Orange Juice","Fruit Punch"]
    print("Part A: ", items)
    
    items.append("Bottle of Soda")
    print("Part B: ", items)
    
    print("Part C: ", len(items))
    
    items.insert(3,"Vanilla Ice-cream")
    print("Part D: ", items)
    
    fp = items.pop(len(items)-1)
    print("Part E: ", items)

    items.remove("Orange Juice")
    print("Part F: ", items)

    items.extend(["Burgers","Buns","Condiments"])
    print("Part G: ", items)

main()
