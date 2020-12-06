#include "ReallyLongInt.hpp"
#include<string>
#include<iostream>
#include<cmath>
#include<climits>

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
	unsigned i = 0,k = 0;
	if(numStr[0] == '-'){ //checks if number is negative
		i = 1;
		isNeg = true;
	} else{
		isNeg = false;
	} 
	unsigned size = isNeg ? numStr.size()-1:numStr.size();
	unsigned* array = new unsigned[size];

	while(i < numStr.size()){
		array[k] = numStr[i] - '0';
		k++;
		i++;
	}
	removeLeadingZeros(array,size);
	if(isNeg and array[0] == 0){
		//numDigits = 1;
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
		unsigned i = 0;
		unsigned j = 1;
		if (num < 0){
			isNeg = true;
			array = new unsigned[numDigits];
			num = abs(num);
		} else{
			isNeg = false;
			array = new unsigned[numDigits];
		}
		//
		while(i < numDigits){
			unsigned divisor = 1;//pow(10,numDigits-j);
			for(unsigned c = 0; c < numDigits-j; c++){
				divisor *= 10;
			}
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

void ReallyLongInt::flipSign(){
	if(digits[0] == 0){
		isNeg = false;
	} else{
		isNeg = !isNeg;
	}
}

void ReallyLongInt::swap(ReallyLongInt other){
	const unsigned* array = digits;
	unsigned ND = numDigits;
	bool neg = isNeg;
	//
	digits = other.digits;
	numDigits = other.numDigits;
	isNeg = other.isNeg;
	//
	other.digits = array;
	other.numDigits = ND;
	other.isNeg = neg;
}

ReallyLongInt ReallyLongInt::absAdd(const ReallyLongInt& other) const{
	//should take O(max(numdigs, ynumdigs)) time
	const unsigned* minArray;
	const unsigned* maxArray;
	unsigned maxSize;
	unsigned minSize;
	if(this->absGreater(other)){
		minArray = other.digits;
		maxArray = digits;
		maxSize = numDigits;
		minSize = other.numDigits;
	} else {
		minArray = digits;
		maxArray = other.digits;
		maxSize = other.numDigits;
		minSize = numDigits;
	}

	unsigned* sum = new unsigned[maxSize];
	int i = maxSize - 1,j = minSize - 1,k = maxSize - 1;
	int carryOver = 0,s = 0;

	while(j >= 0){
		s = maxArray[i] + minArray[j] + carryOver;
		sum[k] = (s % 10);
		carryOver = s / 10;
		k--;
		i--;
		j--;
	}

	while(i >= 0){
		s = maxArray[i] + carryOver;
		sum[k] = (s % 10);
		carryOver = s / 10;
		i--;
		k--;
	}

	if(carryOver){
		maxSize += 1;
		unsigned* newSum = new unsigned[maxSize];
		newSum[0] = carryOver;
		for(unsigned c = 1;c < maxSize;c++){
			newSum[c] = sum[c-1];
		}
		delete[] sum;
		sum = newSum;
	}

	ReallyLongInt longIntAns(sum,maxSize,false);

	return longIntAns;
}

ReallyLongInt ReallyLongInt::absSub(const ReallyLongInt& other) const{ //unfinished; untestable
	//returns abs(*this)-abs(other)
	const unsigned* minArrayOriginal;
	const unsigned* maxArrayOriginal;
	unsigned maxSize;
	unsigned minSize;
	if(this->absGreater(other)){
		minArrayOriginal = other.digits;
		maxArrayOriginal = digits;
		maxSize = numDigits;
		minSize = other.numDigits;
	} else {
		minArrayOriginal = digits;
		maxArrayOriginal = other.digits;
		maxSize = other.numDigits;
		minSize = numDigits;
	}

	unsigned* minArray = new unsigned[minSize];
	unsigned* maxArray = new unsigned[maxSize];

	//copying arrays so that they can be edited
	for(unsigned c = 0; c < minSize; c++){
		minArray[c] = minArrayOriginal[c];
	}

	for(unsigned c = 0; c < maxSize; c++){
		maxArray[c] = maxArrayOriginal[c];
	}

	unsigned* difference = new unsigned[maxSize];
	int i = maxSize-1,j = minSize-1,k = maxSize-1,currentIndex = 1;
	int borrowOver = 0,d = 0;
	ReallyLongInt multiplier(10); // EDITED

	while(j >= 0){
		if(minArray[j] > maxArray[i]){
			for(int v = i-1; v >= 0; v--){
				if(maxArray[v]*multiplier > minArray[j]){
					maxArray[v] -= 1;
					borrowOver = 10;
					if(maxArray[v+1] == 0){
						for(unsigned n = v+1; n < maxSize; n++){
							maxArray[n] += borrowOver;
							if(n != maxSize-currentIndex){
								maxArray[n] -= 1;
							}
						}
					} else{
						maxArray[v+1] += borrowOver;
					}
					multiplier *= 10;
					break;
				}
				multiplier *= 10;
			}
		}
		d = maxArray[i] - minArray[j];
		difference[k] = d;
		borrowOver = 0;
		k--;
		i--;
		j--;
		currentIndex += 1;
	}

	while(i >= 0){
		d = maxArray[i];
		difference[k] = d;
		i--;
		k--;
	}

	bool neg;
	if(this->greater(other) or this->equal(other)){
		neg = false;
	} else{
		neg = true;
	}
	
	ReallyLongInt longIntAns(difference,maxSize,neg);
	delete[] minArray;
	delete[] maxArray;
	return longIntAns;
}

ReallyLongInt ReallyLongInt::absMult(const ReallyLongInt& other) const{
	const unsigned* minArray;
	const unsigned* maxArray;
	unsigned maxSize;
	unsigned minSize;
	if(this->absGreater(other)){
		minArray = other.digits;
		maxArray = digits;
		maxSize = numDigits;
		minSize = other.numDigits;
	} else {
		minArray = digits;
		maxArray = other.digits;
		maxSize = other.numDigits;
		minSize = numDigits;
	}

	ReallyLongInt sumProduct;
	int i = maxSize-1,j = minSize-1;
	int iZeros = 0,jZeros = 0;

	while(j >= 0){
		while(i >= 0){
			int smallSum = (minArray[j]*maxArray[i]);
			string productPart = to_string(smallSum);
			for(int z = 0; z < (iZeros+jZeros);z++){
				productPart = productPart + "0";
			}
			ReallyLongInt s(productPart);
			sumProduct += s;//*imultiplier*jmultiplier;
			iZeros += 1;
			i--;
		}
		jZeros += 1;
		i = maxSize-1;
		iZeros = 0;
		j--;
	}

	return ReallyLongInt(sumProduct);
}

void ReallyLongInt::absDiv(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const{
	string q = "";
	remainder = 0;
	for(unsigned i = 0; i < this->numDigits;i++){
		remainder *= 10;
		remainder += this->digits[i];
		unsigned d = 0;
		while(remainder.absGreater(other) or remainder.equal(other)){
			remainder = remainder.absSub(other);
			d += 1;
		}
		q = q + to_string(d);
	}
	ReallyLongInt strQuotient(q);
	quotient = strQuotient;
}

bool ReallyLongInt::absGreater(const ReallyLongInt& other) const{
	if(numDigits > other.numDigits){
		return true;
	} else if(numDigits == other.numDigits){
		unsigned i = 0;
		while(i < numDigits){
			if(digits[i] > other.digits[i]){
				return true;
			} else if (digits[i] < other.digits[i]){
				break;
			}
			i++;
		}
		return false;
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
	unsigned i = 0;
	while(i < numDigits){
		numString = numString + to_string(digits[i]);
		i++;
	}
	return numString;
}

long long ReallyLongInt::toLongLong() const{
	//x = ReallyLongInt, then x%(LLONG_MAX+1) => long long conversion
	ReallyLongInt max(LLONG_MAX);
	max += 1;
	ReallyLongInt x = *this;
	x %= max;
	string stringMax = x.toString();
	long long m = stoll(stringMax);
	return m;
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
	if(!isNeg and !other.isNeg){
		return absAdd(other);
	} else if(isNeg and !other.isNeg){
		ReallyLongInt x = *this;
		x.flipSign();
		return other.absSub(x);
	} else if(!isNeg and other.isNeg){
		ReallyLongInt x = other;
		x.flipSign();
		return absSub(x);
	} else{ //both negative
		ReallyLongInt sum = absAdd(other);
		sum.flipSign();
		return sum;
	}
}

ReallyLongInt ReallyLongInt::sub(const ReallyLongInt& other) const{
	if(!isNeg and !other.isNeg){
		return absSub(other);
	} else if(isNeg and !other.isNeg){
		ReallyLongInt dif = absAdd(other);
		dif.flipSign();
		return dif;
	} else if(!isNeg and other.isNeg){
		return absAdd(other);
	} else{ //both negative
		ReallyLongInt x = other;
		ReallyLongInt y = *this;
		x.flipSign();
		y.flipSign();
		return x.absSub(y);
	}
}

ReallyLongInt ReallyLongInt::mult(const ReallyLongInt& other) const{
	if((isNeg and !other.isNeg) or (!isNeg and other.isNeg)){
		ReallyLongInt x = absMult(other);
		x.flipSign();
		return x;
	} else{
		return absMult(other);
	}
}

void ReallyLongInt::div(const ReallyLongInt& denominator, ReallyLongInt& quotient, ReallyLongInt& remainder) const{
	if(isNeg and !denominator.isNeg){
		absDiv(denominator,quotient,remainder);
		quotient.flipSign();
		remainder.flipSign();
	} else if(!isNeg and denominator.isNeg){
		absDiv(denominator,quotient,remainder);
		quotient.flipSign();
	} else if(isNeg and denominator.isNeg){
		absDiv(denominator,quotient,remainder);
		remainder.flipSign();
	} else{
		absDiv(denominator,quotient,remainder);
	}
}

ReallyLongInt& ReallyLongInt::operator=(const ReallyLongInt& other){
	swap(other);
	return *this;
}

ReallyLongInt& ReallyLongInt::operator+=(const ReallyLongInt& other){
	ReallyLongInt x = this->add(other);
	*this = x;
	return *this;
}

ReallyLongInt& ReallyLongInt::operator-=(const ReallyLongInt& other){
	ReallyLongInt x = this->sub(other);
	*this = x;
	return *this;
}

ReallyLongInt& ReallyLongInt::operator*=(const ReallyLongInt& other){
	ReallyLongInt x = this->mult(other);
	*this = x;
	return *this;
}

ReallyLongInt& ReallyLongInt::operator/=(const ReallyLongInt& other){
	ReallyLongInt q;
	ReallyLongInt r;
	this->div(other,q,r);
	*this = q;
	return *this;
}

ReallyLongInt& ReallyLongInt::operator%=(const ReallyLongInt& other){
	ReallyLongInt q;
	ReallyLongInt r;
	this->div(other,q,r);
	*this = r;
	return *this;
}

ReallyLongInt ReallyLongInt::operator-() const{
	const ReallyLongInt& s = *this;
	ReallyLongInt x(s);
	x.flipSign();
	return x;
}

ReallyLongInt& ReallyLongInt::operator++(){
	ReallyLongInt y(1);
	ReallyLongInt x = this->add(y);
	*this = x;
	return *this;
}

ReallyLongInt& ReallyLongInt::operator--(){
	ReallyLongInt y(1);
	ReallyLongInt x = this->sub(y);
	*this = x;
	return *this;
}

ReallyLongInt ReallyLongInt::operator++(int dummy){
	ReallyLongInt y(1);
	ReallyLongInt z = *this;
	ReallyLongInt x = this->add(y);
	*this = x;
	return z;
}

ReallyLongInt ReallyLongInt::operator--(int dummy){
	ReallyLongInt y(1);
	ReallyLongInt z = *this;
	ReallyLongInt x = this->sub(y);
	*this = x;
	return z;
}

// =============

// OUTSIDE FUNCTIONS

ostream& operator<<(ostream& out, const ReallyLongInt& x){
	//add string of RLI to out and return out
	out << x.toString();
	return out;
}

bool operator==(const ReallyLongInt& x, const ReallyLongInt& y){
	return x.equal(y);
}

bool operator!=(const ReallyLongInt& x, const ReallyLongInt& y){
	return !(x.equal(y));
}

bool operator>(const ReallyLongInt& x, const ReallyLongInt& y){
	return x.greater(y);
}

bool operator<(const ReallyLongInt& x, const ReallyLongInt& y){
	return y.greater(x);
}

bool operator>=(const ReallyLongInt& x, const ReallyLongInt& y){
	return (x.greater(y) or x.equal(y));
}

bool operator<=(const ReallyLongInt& x, const ReallyLongInt& y){
	return (y.greater(x) or y.equal(x));
}

ReallyLongInt operator+(const ReallyLongInt& x, const ReallyLongInt& y){
	return x.add(y);
}

ReallyLongInt operator-(const ReallyLongInt& x, const ReallyLongInt& y){
	return x.sub(y);
}

ReallyLongInt operator*(const ReallyLongInt& x, const ReallyLongInt& y){
	return x.mult(y);
}

ReallyLongInt operator/(const ReallyLongInt& x, const ReallyLongInt& y){
	ReallyLongInt q;
	ReallyLongInt r;
	x.div(y,q,r);
	return q;
}

ReallyLongInt operator%(const ReallyLongInt& x, const ReallyLongInt& y){
	ReallyLongInt q;
	ReallyLongInt r;
	x.div(y,q,r);
	return r;
}

// =============