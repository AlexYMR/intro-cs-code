def main():
    contacts = {"Alice":["alice.allister@fandm.edu","aallister@gmail.com"],"Bob":["robert.robertson@fandm.edu","bobbob@mail.yahoo.com","bsquared97@hotmail.com"],"Carol":["carol.carleton@fandm.edu"]}
    print("Part A: " + str(contacts) + "\n")

    contacts["Carol"].append("ccarleto@initech.net")
    print("Part B: " + str(contacts) + "\n")

    contacts["Bob"].pop()
    print("Part C: " + str(contacts) + "\n")

    del contacts["Bob"]
    print("Part D: " + str(contacts) + "\n")

    contacts["Miles"] = ["miles.dyson@gmail.com","mdyson@cyberdyne.com"]
    print("Part E: " + str(contacts) + "\n")

    print("Part F: " + str(len(contacts)) + "\n")

    print("Part G: " + str(len(contacts["Alice"])) + "\n")

    print("Part H: " + str(contacts["Carol"][1].split("@")[1].split(".")[0]))

main()
