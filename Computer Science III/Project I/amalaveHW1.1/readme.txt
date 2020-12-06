Alex Malavé
--

CPS 222 Project 1

===================
// FILES
--

simplemodpower.cpp
recursivemodpower.cpp
modpower.cpp
numberTheory.hpp/cpp
encrypt.cpp
decrypt.cpp
numberTheory_TEST.cpp
catch.hpp
Makefile
Cover sheet

====================

simplemodpower.cpp:
	Compilation: g++ -o simplemodpower simplemodpower.cpp
	Usage: ./simplemodpower
	Description: Multiplies a given base by itself exponent times through an iterative approach (slow). The result is the exponentation mod a given modulus.
	Known issues: Test cases e-h are incorrect due to overflow

recursivemodpower.cpp:
	Compilation: g++ -o recursivemodpower recursivemodpower.cpp
	Usage: ./recursivemodpower
	Description: Utilizes a recursive approach to understanding exponentation in order to make the process faster (than the iterative approach of simplemodpower.cpp). The result is the exponentation mod a given modulus.
	Known issues: Test cases e-h are incorrect due to overflow

modpower.cpp:
	Compilation: g++ -o modpower modpower.cpp
	Usage: ./modpower
	Description: Utilizes a modified version of the approach of recursivemodpower.cpp, but uses smaller numbers in calculations, leading to more accurate answers and eliminating some overflow.
	Known issues: Test case h is still incorrect due to overflow
	
numberTheory.hpp/cpp:
	Compilation: g++ -o numberTheory numberTheory.cpp
	Usage: ./numberTheory
	Description: A local file that contains the code for the function modPower, which is the same as the function within modpower.cpp. Essentially modularizes the code for use through a preprocessor.
	Known issues: Liable to some overflow issues

encrypt.cpp:
	Compilation: 
		g++ -c numberTheory.cpp
		g++ -o encrypt numberTheory.o encrypt.cpp
	Usage: ./encrypt <public_key_file> <input_file> <output_file>
	Description: Reads an input file and encrypts it using the modPower function within numberTheory.o and the given public key file. The encrypted message is then outputted into an output file.
	Known issues: None
	
decrypt.cpp:
	Compilation:
		g++ -c numberTheory.cpp
		g++ -o decrypt numberTheory.o decrypt.cpp
	Usage: ./decrypt <private_key_file> <input_file> <output_file>
	Description: Reads an input file and decrypts it using the modPower function within numberTheory.o and the given private key file. The decrypted message is then outputted into an output file.
	Known issues: None
	
numberTheory_TEST.cpp:
	Compilation:
		g++ -c numberTheory.cpp
		g++ -o numberTheory_Test numberTheory_TEST.cpp numberTheory.o
	Usage: ./numberTheory_Test
	Description: Tests multiple use cases of the modPower function.
	Known issues: Error caused by overflow issue on case 9

Use 'make all' in order to compile the entire project as it is now. It will run the compilations of decrypt and encrypt, creating executables, which can be used as described above.

====================
// KNOWN ISSUES
--

- Very long numbers causes inaccuracy issues due to overflow

- Cannot handle typo/missing file exceptions when file parameters are given

====================

FINAL FILES (Ignore this for now; reference for final submission):
ReallyLongInt.cpp/hpp
numberTheory.tpp/hpp
keygen.cpp
encrypt.cpp
decrypt.cpp
numberTheory_TEST.cpp
ReallyLongInt_TEST.cpp
catch.hpp
Makefile
readme.txt
CoverSheet.pdf