class Sentence:
    def __init__(self,aString):
        if aString[0] != aString[0].upper():
            print("First letter was not capitalized.")
            aString = aString[0].upper() + aString[1:]
        
        if aString[-1] != "." and aString[-1] != "?" and aString[-1] != "!":
            print("Sentence did not end with valid punctuation.")
            aString = aString + "."

        self.__punctuation = aString[-1]
        self.__sentence = aString[:-1]

    def getSentence(self):
        return self.__sentence + self.__punctuation

    def getWords(self):
        return self.__sentence.split()

    def getNumWords(self):
        return len(self.__sentence.split())
    
    def getNumCharacters(self):
        acc = 0
        for i in self.__sentence:
            if i != " ":
                acc = acc + 1
        return acc
    
    def getReverse(self):
        newList = []
        for i in range(len(self.__sentence.split())):
            newList.append(self.__sentence.split()[len(self.__sentence.split())-i-1])
        txt = ""
        for i in newList:
            txt = txt + i + " "
        txt = txt[:-1]
        return self.__punctuation + txt

    def sentenceType(self):
        if self.__punctuation == "!":
            return "Exclamatory"
        elif self.__punctuation == "?":
            return "Interrogative"
        elif self.__punctuation == ".":
            return "Declarative"

    def __str__(self):
        return self.__sentence

    def __getitem__(self, index):
        lst = self.__sentence.split()
        return lst[index]

    def __add__(self, otherSentence):
        newSentence = self.__sentence + " " + Sentence.getSentence(otherSentence).lower()
        return Sentence(newSentence)

    def __contains__(self,word):
        lst = self.__sentence.split()
        for i in lst:
            if word.lower() == i.lower():
                return True
        return False

def main():
    """
    sentence = Sentence("Hello.")
    sentence2 = Sentence("bye.")
    sentence3 = Sentence("Aloha")

    print(Sentence.getSentence(sentence))
    print(Sentence.getSentence(sentence2))
    print(Sentence.getSentence(sentence3))
    print(Sentence.getReverse(Sentence("Hi there!")))

    print(Sentence.sentenceType(Sentence("Hello?")))
    print(Sentence.sentenceType(Sentence("Hello.")))
    print(Sentence.sentenceType(Sentence("Hello!")))
    """
    s1 = Sentence("the quick brown fox")
    print(s1)
    print(s1[1])
    print("the" in s1)
    print("aardvark" in s1)
    print("the quick" in s1)
    print("row" in s1)
    s2 = Sentence("jumped over the lazy dog")
    s3 = s1+ s2
    print(s3)
    print(isinstance(s3,Sentence))
    
main()
