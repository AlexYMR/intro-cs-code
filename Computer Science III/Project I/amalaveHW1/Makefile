OPTS = -Wall

all: ReallyLongInt.o encrypt decrypt keygen

numberTheory.o: numberTheory.hpp numberTheory.cpp numberTheory.tpp
	g++ ${OPTS} -c numberTheory.cpp

encrypt: numberTheory.tpp numberTheory.hpp encrypt.cpp ReallyLongInt.o
	g++ ${OPTS} -o encrypt encrypt.cpp ReallyLongInt.o

decrypt: numberTheory.tpp numberTheory.hpp decrypt.cpp ReallyLongInt.o
	g++ ${OPTS} -o decrypt decrypt.cpp ReallyLongInt.o

keygen: keygen.cpp ReallyLongInt.o
	g++ ${OPTS} -o keygen keygen.cpp ReallyLongInt.o

numberTheory_TEST: numberTheory_TEST.cpp numberTheory.tpp numberTheory.hpp ReallyLongInt.o
	g++ ${OPTS} -o numberTheoryTest numberTheory_TEST.cpp ReallyLongInt.o

numberTheory_DEBUG: numberTheory_TEST.cpp numberTheory.tpp numberTheory.hpp ReallyLongInt.o
	g++ ${OPTS} -g -o numberTheoryDebug numberTheory_TEST.cpp ReallyLongInt.o

numberTheory_COV: numberTheory_TEST.cpp numberTheory.tpp numberTheory.hpp ReallyLongInt.o
	g++ ${OPTS} --coverage -o numberTheoryCov numberTheory_TEST.cpp ReallyLongInt.o

reallyLongInt.o: reallyLongInt.cpp reallyLongInt.hpp
	g++ ${OPTS} -c reallyLongInt.cpp

reallyLongInt_TEST: reallyLongInt_TEST.cpp reallyLongInt.o
	g++ ${OPTS} -o reallyLongIntTest reallyLongInt_TEST.cpp reallyLongInt.o

reallyLongInt_COV: reallyLongInt_TEST.cpp reallyLongInt.cpp reallyLongInt.hpp
	g++ ${OPTS} --coverage -o reallyLongIntCov reallyLongInt_TEST.cpp reallyLongInt.cpp

ReallyLongInt.o: ReallyLongInt.cpp ReallyLongInt.hpp
	g++ ${OPTS} -g -c ReallyLongInt.cpp

ReallyLongInt_TEST: ReallyLongInt_TEST.cpp ReallyLongInt.o
	g++ ${OPTS} -o ReallyLongIntTest ReallyLongInt_TEST.cpp ReallyLongInt.o

ReallyLongInt_DEBUG: ReallyLongInt_TEST.cpp ReallyLongInt.o
	g++ ${OPTS} -g -o ReallyLongIntDebug ReallyLongInt_TEST.cpp ReallyLongInt.o

ReallyLongInt_COV: ReallyLongInt_TEST.cpp ReallyLongInt.o
	g++ ${OPTS} --coverage -o ReallyLongIntCov ReallyLongInt_TEST.cpp ReallyLongInt.o

tests: numberTheory_TEST reallyLongInt_TEST ReallyLongInt_TEST

clean:
	rm -f *.o encrypt decrypt decrypted.txt encrypted.txt numberTheory.hpp.gch numberTheory_Test reallyLongInt_Test

cleancov: #Cleans up the files generated when we measure coverage
	rm -r -f *.gcda *.gcno *.gcov *.info *.coverage numberTheoryCov reallyLongIntCov ReallyLongIntCov