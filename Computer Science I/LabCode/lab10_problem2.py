def arffDict(inputFile):

    attributes = []

    line = inputFile.readline()
    line = line.replace('\n', '')

    # Read until we get to @data, processing @attribute along the way



    

    # Now read until end of file, creating the list of dictionaries along the way
    EOF = ""
    data = []
    while line != EOF:
 

        # Store values in dictionary with attribute name as key
        
        

    

def main():
    
 
    inputFile = open(sys.argv[1])
    data = arffDict(inputFile)
    inputFile.close()

    

    print("*** The data is dictionary format ***\n")
    print(data)
    print()

main()
