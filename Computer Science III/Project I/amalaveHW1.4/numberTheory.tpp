template<class X>
X extendedEuclid(const X& a,const X& b, X* x, X* y){
	if(b == 0){
		*x = 1;
		*y = 0;
		return a;
	} else{
		X d = extendedEuclid(b,a%b,x,y);
		X xprime = *y;
		X yprime = *x - *y * (a/b);
		*x = xprime;
		*y = yprime;
		return d;
	}
}

template<class X>
X modPower(const X& base,const X& exponent,const X& modulus){
	if (exponent == 1){
		return base;
	} else if (exponent == 0){
		return 1;
	} else {
		if (exponent%2 == 0){
			X n = modPower(base,exponent/2,modulus);
			return ((n%modulus)*(n%modulus))%modulus;
		} else {
			X n = modPower(base,exponent/2,modulus);
			return ((base%modulus)*(n%modulus)*(n%modulus))%modulus;
		}
	}
}

template<class X>
bool isPrime(const X& num){
	if (num == 1 or num == 0){
		return false;
	} else{
		for (int i = 2;i < num/2;i++){
			if (num % i == 0){
				return false;
			}
		}
		return true;
	}
}