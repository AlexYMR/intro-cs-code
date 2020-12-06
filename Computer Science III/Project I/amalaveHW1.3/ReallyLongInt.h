#include<string>

#ifndef REALLYLONGINT_H
#define REALLYLONGINT_H

class ReallyLongInt{
private:
	bool isNeg;
	const unsigned* digits; //can't use this to change values in array it points to
	unsigned numDigits;

	void removeLeadingZeros(unsigned* x, unsigned& xSize) const;
	bool absGreater(const ReallyLongInt& other) const;
	ReallyLongInt absAdd(const ReallyLongInt& other) const;
	ReallyLongInt absSub(const ReallyLongInt& other) const;

	ReallyLongInt(unsigned* digitsArr, unsigned arrSize, bool isNeg);
public:
	ReallyLongInt();
	ReallyLongInt(const std::string& numStr);
	ReallyLongInt(long long num);
	ReallyLongInt(const ReallyLongInt& other);
	~ReallyLongInt();
	std::string toString() const;
	bool equal(const ReallyLongInt& other) const;
	bool greater(const ReallyLongInt& other) const;
	ReallyLongInt add(const ReallyLongInt& other) const;
	ReallyLongInt sub(const ReallyLongInt& other) const;
};

#endif