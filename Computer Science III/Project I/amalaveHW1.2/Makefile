OPTS = -Wall

all: numberTheory.o encrypt decrypt

numberTheory.o: numberTheory.h numberTheory.cpp
	g++ ${OPTS} -c numberTheory.cpp

encrypt: numberTheory.o encrypt.cpp
	g++ ${OPTS} -o encrypt numberTheory.o encrypt.cpp

decrypt: numberTheory.o decrypt.cpp
	g++ ${OPTS} -o decrypt numberTheory.o decrypt.cpp

numberTheory_TEST: numberTheory_TEST.cpp numberTheory.o
	g++ ${OPTS} -o numberTheory_Test numberTheory_TEST.cpp numberTheory.o

numberTheory_COV: numberTheory_TEST.cpp numberTheory.cpp numberTheory.h
	g++ ${OPTS} --coverage -o numberTheory_Cov numberTheory_TEST.cpp numberTheory.cpp

reallyLongInt.o: reallyLongInt.cpp reallyLongInt.h
	g++ ${OPTS} -c reallyLongInt.cpp

reallyLongInt_TEST: reallyLongInt_TEST.cpp reallyLongInt.o
	g++ ${OPTS} -o reallyLongInt_Test reallyLongInt_TEST.cpp reallyLongInt.o

reallyLongInt_COV: reallyLongInt_TEST.cpp reallyLongInt.cpp reallyLongInt.h
	g++ ${OPTS} --coverage -o reallyLongInt_Cov reallyLongInt_TEST.cpp reallyLongInt.cpp

tests: numberTheory_TEST reallyLongInt_TEST

clean:
	rm -f *.o encrypt decrypt decrypted.txt encrypted.txt numberTheory.h.gch numberTheory_Test reallyLongInt_Test

cleancov: #Cleans up the files generated when we measure coverage
	rm -r -f *.gcda *.gcno *.gcov *.info *.coverage numberTheory_Cov reallyLongInt_Cov