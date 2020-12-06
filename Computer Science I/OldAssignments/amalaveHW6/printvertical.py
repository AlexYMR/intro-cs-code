#-----------------------------
# // printvertical.py
# // Part of HW6
# // Problem 1
#-----------------------------

def main():
    """
    Takes  a sentence as an input variable, and prints the sentences in a vertical fashion by organizing the letters in the sentence into lists..
    Input: Sentence (string)
    Output: A series of prints that rearrange the sentence in a vertical fashion
    """
    sent = input("Enter a sentence: ")
    #--Creates a list out of the sentence given
    wordSplit = sent.split()
    tab = []
    largestWord = ""
    #--Checks for the largest word in the list wordSplit
    for word in wordSplit:
        if len(largestWord) < len(word):
            largestWord = word
    for word in wordSplit:
        #--Uses largestWord's length in order to get spaces into the list objects
        for i in range(len(largestWord)):
            #--If the length of the list is 0 (it's empty), or if the index doesn't exist yet, but should, then...
            if (len(tab) < (i+1) or len(tab) == 0):
                if len(word) < (i+1):
                    tab.insert(i," ")
                else:
                    tab.insert(i,word[i])
            else:
                #--Checks if the index doesn't exist and the word is smaller than the largest word (thus putting a space in the place of an alphabetical character)
                if len(word) < (i+1) and len(word) < len(largestWord):
                    tab[i] = tab[i] + " " + " "
                else:
                    tab[i] = tab[i] + " " + word[i]
    for idx in tab:
        #--Prints each line in the list
        print(idx)

main()
    
        
