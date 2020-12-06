#include<string>

#ifndef RLINT_H
#define RLINT_H

unsigned* rlIntMake(const std::string& numStr, unsigned& numDigits);

std::string rlIntToString(const unsigned* x, unsigned xSize);

void rlIntRemoveLeadingZeros(unsigned* x, unsigned& xSize);

bool rlIntEqual(const unsigned* x, unsigned xSize, const unsigned* y, unsigned ySize);

bool rlIntGreater(const unsigned* x, unsigned xSize, const unsigned* y, unsigned ySize);

#endif

