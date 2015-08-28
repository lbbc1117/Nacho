#ifndef CTEST_H
#define CTEST_H

#include <iostream>
#include "CMatrix.h"

using namespace std;

class CTest {	

public:

	CTest(int m, int n);

	CMatrix mat;

	void addition(CMatrix &rightMat);
	void subtraction(CMatrix &rightMat);
	void multiplication(CMatrix &rightMat);
	void multiplication(double multiplier);
	void division(double divisor);
	void exponentiation(double exponent);
	void assignment(CMatrix &rightMat);

	void trans();
	void norm();
	void get(int i, int j);
	void set(int i, int j, double val);
	void diagUnitize();
	void clear();

};


#endif