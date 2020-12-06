#include<string>
#include<iostream>

using namespace std;

void rlIntRemoveLeadingZeros(unsigned* x, unsigned& xSize){
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
		}
	}
}

unsigned* rlIntMake(const string& numStr, unsigned& numDigits){
	//should take a string of a number and convert it to a really long int array
	//dynamically allocates unsigned int array of appropriate size, & fills w/ digits of number
	//remember to keep track of the size of arrays (numDigits)
	//before returning, numDigits should represent the #digits in the really long int array
	//you may assume the string only contains digits
	numDigits = numStr.size();
	unsigned* array = new unsigned[numDigits];
	unsigned i = 0;
	while(i < numDigits){
		array[i] = numStr[i] - '0';
		i++;
	}
	numDigits = i;
	rlIntRemoveLeadingZeros(array,numDigits);
	return array;
}

string rlIntToString(const unsigned* x, unsigned xSize){
	//takes an RL int and generates a string of the number
	string numString = "";
	for(unsigned i = 0; i < xSize; i++){
		numString = numString + to_string(*(x+i));//just to remind me that *(x+i) = x[i]
	}
	return numString;
}

bool rlIntEqual(const unsigned* x, unsigned xSize, const unsigned* y, unsigned ySize){
	//take two RLs and return true if equal, false otherwise
	//should take O(min(xSize,ySize)) time -> O(n) time
	if(xSize > 0 and ySize > 0 and xSize == ySize and x[0] == y[0]){
		const unsigned* minArray = (min(xSize,ySize) == xSize) ? x : y;
		const unsigned* maxArray = (min(xSize,ySize) == xSize) ? y : x;
		unsigned minSize = (min(xSize,ySize) == xSize) ? xSize : ySize;
		for(unsigned i = 0; i < minSize; i++){
			if(minArray[i] != maxArray[i]){
				return false;
			}
		}
		return true;
	}
	return false;
}

bool rlIntGreater(const unsigned* x, unsigned xSize, const unsigned* y, unsigned ySize){
	//returns true if x > y, false otherwise
	//should also take O(min(xSize,ySize)) time -> O(n) time
	if(xSize > ySize){
		return true;
	} else if(xSize == ySize){
		int i = xSize-1;
		while(i >= 0){
			if(x[i] < y[i]){
				return false;
			}
			i--;
		}
		if(x[i] == y[i]){
			return false;
		} else{
			return true;
		}
	} else{
		return false; //if xSize < ySize
	}
}
