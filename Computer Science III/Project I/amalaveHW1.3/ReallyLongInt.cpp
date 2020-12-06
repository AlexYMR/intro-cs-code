#include "ReallyLongInt.h"
#include<string>
#include<iostream>
#include<cmath>

using namespace std;

// =============

// CONSTRUCTORS

ReallyLongInt::ReallyLongInt(){
	isNeg = false;
	unsigned* array = new unsigned[1];
	array[0] = 0;
	digits = array;
	numDigits = 1;
}

ReallyLongInt::ReallyLongInt(const string& numStr){
	unsigned size = numStr.size();
	unsigned* array = new unsigned[size];
	unsigned i = 0;
	if(numStr[0] == '-'){ //checks if number is negative
		array[0] = '-';
		i = 1;
		isNeg = true;
	}
	while(i < size){
		array[i] = numStr[i] - '0';
		i++;
	}
	removeLeadingZeros(array,size);
	if(array[0] == '-' and array[1] == 0){
		array[0] = 0;
		numDigits = 1;
		isNeg = false;
	}
	digits = array;
	numDigits = size;
}

ReallyLongInt::ReallyLongInt(long long num){
	if(num == 0){
		isNeg = false;
		unsigned* array = new unsigned[1];
		array[0] = 0;
		digits = array;
		numDigits = 1;
	} else{
		numDigits = log10(abs(num))+1;
		unsigned* array;
		unsigned i;
		unsigned j = 1;
		if (num < 0){
			isNeg = true;
			array = new unsigned[numDigits+1]; // to accomodate for the -
			numDigits += 1;
			array[0] = '-';
			num = abs(num);
			i = 1;
			j = 2;
		} else{
			isNeg = false;
			array = new unsigned[numDigits];
			i = 0;
		}
		//
		while(i < numDigits){
			unsigned divisor = pow(10,numDigits-j);
			array[i] = num / divisor;
			num = num % divisor;
			i++;
			j++;
		}
		digits = array;
		//
	}
}

ReallyLongInt::ReallyLongInt(const ReallyLongInt& other){
	isNeg = other.isNeg;
	numDigits = other.numDigits;
	unsigned* array = new unsigned[numDigits];
	for(unsigned i = 0; i < numDigits; i++){
		array[i] = other.digits[i];
	}
	digits = array;
}

// =============

// PRIVATE

ReallyLongInt ReallyLongInt::absAdd(const ReallyLongInt& other) const{ //Unfinished; untestable
	//should take O(max(numdigs, ynumdigs)) time
	const unsigned* minSizeReallyLongInt = (min(numDigits,other.numDigits) == numDigits) ? *this : other;
	const unsigned* maxSizeReallyLongInt = (min(numDigits,other.numDigits) == numDigits) ? other : *this;
	unsigned* array = new unsigned[];
	int xIdx = maxSizeReallyLongInt.numDigits - 1;
	int yIdx = minSizeReallyLongInt.numDigits - 1;
	unsigned i = 0;
	unsigned carryOver = 0;
	unsigned singleResult = 0;
	while(i < maxSizeReallyLongInt.numDigits){
		unsigned divisor = pow(10,maxSizeReallyLongInt.numDigits-xIdx);
		if(yIdx >= 0){
			unsigned sum = carryOver + digits[xIdx] + other.digits[yIdx];
			carryOver = sum / divisor;
			singleResult = sum % divisor;
		} else {
			unsigned sum = carryOver + digits[xIdx];
			singleResult = sum % divisor;
			carryOver = 0;
		}

		xIdx--;
		yIdx--;
		i++;
	}
}

ReallyLongInt absSub(const ReallyLongInt& other) const{ //unfinished; untestable
	return 0;
}

bool ReallyLongInt::absGreater(const ReallyLongInt& other) const{
	if(numDigits > other.numDigits){
		return true;
	} else if(numDigits == other.numDigits){
		int i = numDigits-1;
		while(i >= 0){
			if(digits[i] < other.digits[i]){
				return false;
			}
			i--;
		}
		if(digits[i] == other.digits[i]){
			return false;
		} else{
			return true;
		}
	} else{
		return false;
	}
}

ReallyLongInt::ReallyLongInt(unsigned* digitsArr, unsigned arrSize, bool neg){
	removeLeadingZeros(digitsArr,arrSize);
	digits = digitsArr;
	numDigits = arrSize;
	if(digits[0] == 0){
		isNeg = false;
	} else{
		isNeg = neg;
	}
}

void ReallyLongInt::removeLeadingZeros(unsigned* x, unsigned& xSize) const{
	if(xSize > 1){
		if(x[0] == 0){ //making sure there ARE leading zeros
			unsigned lastZeroIdx;
			bool overwriting = false;
			for(unsigned i = 0; i < xSize; i++){
				if(x[i] != 0){
					lastZeroIdx = i - 1;
					overwriting = true;
					break;
				}
			}
			if(!overwriting){ //size = 1 if array is all 0s
				xSize = 1;
			} else{
				for(unsigned i = 0; i < xSize-(lastZeroIdx+1); i++){ //overwrites 
					x[i] = x[lastZeroIdx+1+i];
				}
				xSize = xSize-(lastZeroIdx+1);
			}
		} else if(x[0] == '-' and xSize >= 2 and x[1] == 0){ // if it's negative...
			unsigned lastZeroIdx;
			bool overwriting = false;
			for(unsigned i = 1; i < xSize; i++){
				if(x[i] != 0){
					lastZeroIdx = i - 1;
					overwriting = true;
					break;
				}
			}
			if(!overwriting){ //size = 1 if array is all 0s
				xSize = 1;
			} else{
				for(unsigned i = 1; i < xSize-lastZeroIdx; i++){ //overwrites 
					x[i] = x[lastZeroIdx+i];
				}
				xSize = xSize-lastZeroIdx;
			}
		}
	}
}

// =============

// PUBLIC

ReallyLongInt::~ReallyLongInt(){
	delete[] digits;
}

string ReallyLongInt::toString() const{
	string numString = isNeg ? "-":"";
	unsigned i = isNeg ? 1:0;
	while(i < numDigits){
		numString = numString + to_string(digits[i]);
		i++;
	}
	return numString;
}

bool ReallyLongInt::equal(const ReallyLongInt& other) const{
	if(numDigits > 0 and other.numDigits > 0 and numDigits == other.numDigits and digits[0] == other.digits[0]){
		const unsigned* minArray = (min(numDigits,other.numDigits) == numDigits) ? digits : other.digits;
		const unsigned* maxArray = (min(numDigits,other.numDigits) == numDigits) ? other.digits : digits;
		unsigned minSize = (min(numDigits,other.numDigits) == numDigits) ? numDigits : other.numDigits;
		for(unsigned i = 0; i < minSize; i++){
			if(minArray[i] != maxArray[i]){
				return false;
			}
		}
		return true;
	}
	return false;
}

bool ReallyLongInt::greater(const ReallyLongInt& other) const{
	if(absGreater(other)){
		if(!isNeg){
			return true;
		} else{
			return false;
		}
	} else{
		if(other.isNeg){
			return true;
		} else{
			return false;
		}
	}
}

ReallyLongInt ReallyLongInt::add(const ReallyLongInt& other) const{
	return absAdd(other);
}

ReallyLongInt ReallyLongInt::sub(const ReallyLongInt& other) const{
	return absSub(other);
}

// =============