def main():
    s = input("Input something to acronymize: ")
    acr = s.split( )
    acronym = ""
    for word in acr:
        acronym = acronym + word[:1]
    print(acronym.upper())

main()
