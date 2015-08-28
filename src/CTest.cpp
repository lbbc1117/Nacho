
#include <iostream>
#include <math.h>
#include "CTest.h"

CTest::CTest(int m, int n) : mat(CMatrix(m,n)){}


void CTest::addition(CMatrix &rightMat)
{
	cout << "---------------------- addtion test ----------------------\n\n";
	cout << mat;
	cout << "    +\n";
	cout << rightMat;
	cout << "    =\n";
	cout << (mat + rightMat) << endl;
}

void CTest::subtraction(CMatrix &rightMat)
{
	cout << "---------------------- subtraction test ----------------------\n\n";
	cout << mat;
	cout << "    -\n";
	cout << rightMat;
	cout << "    =\n";
	cout << (mat - rightMat) << endl;
}

void CTest::multiplication(CMatrix &rightMat)
{
	cout << "---------------------- multiplication test ----------------------\n\n";
	cout << mat;
	cout << "    *\n";
	cout << rightMat;
	cout << "    =\n";
	cout << (mat * rightMat) << endl;
}

void CTest::multiplication(double d)
{
	cout << "---------------------- multiplication test ----------------------\n\n";
	cout << mat;
	cout << "    *\n";
	cout << d << endl;
	cout << "    =\n";
	cout << (mat * d) << endl;
}

void CTest::division(double d)
{
	cout << "---------------------- division test ----------------------\n\n";
	cout << mat;
	cout << "    /\n";
	cout << d << endl;
	cout << "    =\n";
	cout << (mat / d) << endl;
}

void CTest::exponentiation(double d)
{
	cout << "---------------------- exponentiation test ----------------------\n\n";
	cout << mat;
	cout << "    ^\n";
	cout << d << endl;
	cout << "    =\n";
	cout << (mat ^ d) << endl;
}

void CTest::assignment(CMatrix &rightMat)
{
	cout << "---------------------- assignment test ----------------------\n\n";
	cout << "left:\n";
	cout << mat;
	cout << "right:\n";
	cout << rightMat;

	mat = rightMat;

	cout << "left after assignment:\n";
	cout << mat << endl;
}

void CTest::trans()
{
	cout << "---------------------- trans test ----------------------\n\n";
	cout << "before trans:\n";
	cout << mat << endl;
	cout << "after trans:\n";
	cout << mat.trans() << endl;
}

void CTest::norm()
{
	cout << "---------------------- norm test ----------------------\n\n";
	cout << "matrix:\n";
	cout << mat;
	cout << "F-norm:\n";
	cout << mat.norm() << endl << endl;
}

void CTest::get(int i, int j)
{
	cout << "---------------------- get test ----------------------\n\n";
	cout << "matrix:\n";
	cout << mat;
	cout << "[" << i <<","<< j << "]:\n";
	cout << mat.get(i,j) << endl << endl;
}

void CTest::set(int i, int j, double val)
{
	cout << "---------------------- set test ----------------------\n\n";
	cout << "before set:\n";
	cout << mat;
	cout << "set [" << i << "," << j << "] to " << val << ":\n";
	mat.set(i, j, val);
	cout << mat << endl;
}

void CTest::diagUnitize()
{
	cout << "---------------------- diagUnitize test ----------------------\n\n";
	cout << "before diagUnitize:\n";
	cout << mat;
	cout << "after diagUnitize:\n";
	mat.diagUnitize();
	cout << mat << endl;
}

void CTest::clear()
{
	cout << "---------------------- clear test ----------------------\n\n";
	cout << "before clear:\n";
	cout << mat;
	cout << "after clear:\n";
	mat.clear();
	cout << mat << endl;
}