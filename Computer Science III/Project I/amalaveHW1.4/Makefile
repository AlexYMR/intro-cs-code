OPTS = -Wall

all: numberTheory.o encrypt decrypt

numberTheory.o: numberTheory.h numberTheory.cpp numberTheory.tpp
	g++ ${OPTS} -c numberTheory.cpp

encrypt: numberTheory.o encrypt.cpp ReallyLongInt.o
	g++ ${OPTS} -o encrypt numberTheory.o encrypt.cpp ReallyLongInt.o

decrypt: numberTheory.o decrypt.cpp ReallyLongInt.o
	g++ ${OPTS} -o decrypt numberTheory.o decrypt.cpp ReallyLongInt.o

numberTheory_TEST: numberTheory_TEST.cpp numberTheory.tpp numberTheory.h ReallyLongInt.o
	g++ ${OPTS} -o numberTheoryTest numberTheory_TEST.cpp ReallyLongInt.o

numberTheory_COV: numberTheory_TEST.cpp numberTheory.cpp numberTheory.h
	g++ ${OPTS} --coverage -o numberTheoryCov numberTheory_TEST.cpp numberTheory.cpp

reallyLongInt.o: reallyLongInt.cpp reallyLongInt.h
	g++ ${OPTS} -c reallyLongInt.cpp

reallyLongInt_TEST: reallyLongInt_TEST.cpp reallyLongInt.o
	g++ ${OPTS} -o reallyLongIntTest reallyLongInt_TEST.cpp reallyLongInt.o

reallyLongInt_COV: reallyLongInt_TEST.cpp reallyLongInt.cpp reallyLongInt.h
	g++ ${OPTS} --coverage -o reallyLongIntCov reallyLongInt_TEST.cpp reallyLongInt.cpp

ReallyLongInt.o: ReallyLongInt.cpp ReallyLongInt.hpp
	g++ ${OPTS} -c ReallyLongInt.cpp

ReallyLongInt_TEST: ReallyLongInt_TEST.cpp ReallyLongInt.o
	g++ ${OPTS} -o ReallyLongIntTest ReallyLongInt_TEST.cpp ReallyLongInt.o

tests: numberTheory_TEST reallyLongInt_TEST ReallyLongInt_TEST

clean:
	rm -f *.o encrypt decrypt decrypted.txt encrypted.txt numberTheory.h.gch numberTheory_Test reallyLongInt_Test

cleancov: #Cleans up the files generated when we measure coverage
	rm -r -f *.gcda *.gcno *.gcov *.info *.coverage numberTheory_Cov reallyLongInt_Cov