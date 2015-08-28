
#include "CTest.h"

int main()
{
	int rowNum = 3;
	int colNum = 3;	

	CMatrix::printWhenCreateAndDelete = false;

	CTest test = CTest(rowNum, colNum);

	// the mat would be :
	// 1,1,1
	// 2,2,2
	// 3,3,3
	for (int i = 1; i <= rowNum; i++){
		for (int j = 1; j <= colNum; j++){
			test.mat.set(i, j, i);
		}
	}

	CMatrix rightMat = CMatrix(rowNum, colNum);

	// the rightMat would be :
	// 1,1,1
	// 1,1,1
	// 1,1,1
	for (int i = 1; i <= rowNum; i++){
		for (int j = 1; j <= colNum; j++){
			rightMat.set(i, j, 1);
		}
	}

	test.addition(rightMat);
	test.subtraction(rightMat);
	test.multiplication(rightMat);
	test.multiplication(1.5);
	test.division(2.0);
	test.exponentiation(2.0);

	test.trans();
	test.norm();
	test.get(2,3);
	test.set(2, 3, 99.99);
	test.diagUnitize();
	test.assignment(rightMat);
	test.clear();

}