
#include <iostream>
#include <math.h>
#include "CMatrix.h"


bool CMatrix::printWhenCreateAndDelete = false;


// 创建一个 m * n 的全零矩阵
// To construct a new m * n zero matrix

CMatrix::CMatrix(int m, int n):

	rowNum ( m>0 ? m : 0 ), 
	colNum ( n>0 ? n : 0 ),
	start ( new double[m*n] ),
	isTransposed ( false )

{
	if (m <= 0 || n <= 0)
	{
		cerr << "ERROR CMatrix(const int, const int) : nonpositive arguments !";
	}

	if(CMatrix::printWhenCreateAndDelete)
	{
		cout << "++++++++++++++++++++ Constructor Called ++++++++++++++++++++" << endl;
	}	

	int total = m*n;
		
	for (int i = 0; i < total; ++i)
	{
		start[i] = 0.0;
	}		
}


// 创建一个 n * n 的全零矩阵
// To construct a new n * n zero matrix

CMatrix::CMatrix(int n):

	rowNum ( n>0 ? n : 0 ), 
	colNum ( n>0 ? n : 0 ),
	start ( new double[n*n] ),
	isTransposed ( false )

{
	if (n <= 0)
	{
		cerr << "ERROR CMatrix(const int) : nonpositive argument !";
	}

	if (CMatrix::printWhenCreateAndDelete)
	{
		cout << "++++++++++++++++++++ Constructor Called ++++++++++++++++++++" << endl;
	}
		
	int total = n*n;

	for (int i = 0; i < total; ++i)
	{
		start[i] = 0.0;
	}		
}


// 拷贝构造函数
// Constructor for copy

CMatrix::CMatrix(const CMatrix & mat):

	rowNum ( mat.rowNum ), 
	colNum ( mat.colNum ),
	start ( new double[mat.rowNum * mat.colNum] ),
	isTransposed ( mat.isTransposed )

{
	if (CMatrix::printWhenCreateAndDelete)
	{
		cout << "++++++++++++++++++++ Constructor Called ++++++++++++++++++++" << endl;
	}

	int total = rowNum*colNum;

	for (int i = 0; i < total; ++i)
	{
		start[i] = mat.start[i];
	}		
}


// 析构函数
// Destructor

CMatrix::~CMatrix()
{
	if (CMatrix::printWhenCreateAndDelete)
	{
		cout << "-------------------- Destructor Called --------------------" << endl;
	}
	
	delete[] start;
}


// 获得矩阵行数
// Get the row number of the matrix

int CMatrix::getRowNum() const
{
	return rowNum;
}


// 获得矩阵列数
// Get the column number of the matirx

int CMatrix::getColNum() const
{
	return colNum;
}


// 返回矩阵转置的状态
// Get the transpose state

bool CMatrix::getTransState() const
{
	return isTransposed;
}


// 计算矩阵的F范数
// Calculate the F-norm of the matrix

double CMatrix::norm() const
{
	double result = 0.0;

	for (int i = 1; i <= rowNum; ++i)
	{
		for (int j = 1; j <= colNum; ++j)
		{
			result = result + pow(abs(get(i, j)), 2);
		}			
	}	

	return sqrt(result);
}


// 将矩阵转置
// To transpose the matrix

CMatrix CMatrix::trans() const
{
	CMatrix result = *this;

	result.rowColSwap();
	result.isTransposed = !isTransposed;

	return result;
}


// 返回矩阵第i行j列元素
// Get the [i,j] element

double CMatrix::get(int i, int j) const
{
	if (i>rowNum || j>colNum || i <= 0 || j <= 0)
	{
		cerr << "ERROR get() : wrong matrix index !" << endl;
		return 0.0;
	}

	if (isTransposed)
	{
		return start[(j - 1)*rowNum + i - 1];
	}
		
	return start[(i - 1)*colNum + j - 1];
}


// 设置矩阵第i行j列元素为val
// Set the [i,j] element to val

void CMatrix::set(int i, int j, double val)
{
	if (i>rowNum || j>colNum || i <= 0 || j <= 0)
	{
		cerr << "ERROR set() : wrong matrix index !" << endl;
		return;
	}

	if (isTransposed)
	{
		start[(j - 1)*rowNum + i - 1] = val;
	}		
	else
	{
		start[(i - 1)*colNum + j - 1] = val;
	}		
}


// 将方阵对角线元素全部设置为1
// Set all diagonal elements to 1 in a square matrix

void CMatrix::diagUnitize()
{
	if (rowNum == colNum && rowNum > 0)
	{
		for (int i = 1; i <= rowNum; ++i)
		{
			set(i, i, 1);
		}			
	}
	else
	{
		cerr << "ERROR unitize() : wrong dimension !";
	}		
}


// 将矩阵所有元素设置为零
// Set all elements to 0

void CMatrix::clear()
{
	for (int i = 1; i <= rowNum; ++i)
	{
		for (int j = 1; j <= colNum; ++j)
		{
			set(i, j, 0.0);
		}			
	}		
}


// 两个矩阵相加 ：必须具有相同维度
// Addition between two matrics ：same demension must

CMatrix CMatrix::operator +(const CMatrix &mat2)
{
	//相加的两个矩阵的行数与列数均须相等
	if (rowNum != mat2.rowNum ||
		colNum != mat2.colNum)
	{
		cerr << "ERROR : matrix wrong dimesion when added !";
		return *this;
	}

	CMatrix result = *this;

	for (int i = 1; i <= rowNum; ++i)
	{
		for (int j = 1; j <= colNum; ++j)
		{
			result.set(i, j, get(i, j) + mat2.get(i, j));
		}
	}

	return result;
}


// 两个矩阵相减 ：必须具有相同维度
// Subtraction between two matrics ：same demension must

CMatrix CMatrix::operator -(const CMatrix &mat2)
{
	//相减的两个矩阵的行数与列数均须相等
	if (rowNum != mat2.rowNum ||
		colNum != mat2.colNum)
	{
		cerr << "ERROR : matrix wrong dimesion when subtracted !";
		return *this;
	}

	CMatrix result = *this;

	for (int i = 1; i <= rowNum; ++i)
	{
		for (int j = 1; j <= colNum; ++j)
		{
			result.set(i, j, get(i, j) - mat2.get(i, j));
		}			
	}

	return result;
}


// 两个矩阵相乘
// Multiplication between two matrics

CMatrix CMatrix::operator *(const CMatrix &mat2)
{
	//第一个矩阵的列数必须等于第二个矩阵的行数
	if (colNum != mat2.rowNum)
	{
		cerr << "ERROR : matrix wrong dimesion when multiplied !" << endl;
		return *this;
	}

	//乘积矩阵与第一个矩阵行数相同，与第二个矩阵列数相同
	CMatrix result(rowNum, mat2.colNum);
	int result_rn = result.rowNum;
	int result_cn = result.colNum;
	double tempVal = 0.0;

	for (int i = 1; i <= result_rn; ++i)
	{
		for (int j = 1; j <= result_cn; ++j)
		{
			for (int k = 1; k <= colNum; ++k)
			{
				tempVal = tempVal + get(i, k) * mat2.get(k, j);
			}				
			result.set(i, j, tempVal);
			tempVal = 0.0;
		}
	}

	//返回时调用拷贝构造函数进行深拷贝，而默认拷贝是浅拷贝，会发生内存重复释放
	return result;
}


// 矩阵与常数相乘
// Multiplication between a matrix and a number

CMatrix CMatrix::operator *(const double f)
{
	CMatrix result = *this;

	for (int i = 1; i <= rowNum; ++i)
	{
		for (int j = 1; j <= colNum; ++j)
		{
			result.set(i, j, get(i, j)*f);
		}			
	}

	return result;
}


// 矩阵除以常数
// Matrix divided by a none-zero number

CMatrix CMatrix::operator /(const double f)
{
	if (f == 0.0)
	{
		cerr << "ERROR : matrix divided by zero !\n";
		return *this;
	}

	CMatrix result = *this;

	for (int i = 1; i <= rowNum; ++i)
	{
		for (int j = 1; j <= colNum; ++j)
		{
			result.set(i, j, get(i, j) / f);
		}			
	}

	return result;
}


// 矩阵元素分别求幂
// Exponentiate all elements

CMatrix CMatrix::operator ^(const double f)
{
	CMatrix result = *this;

	for (int i = 1; i <= rowNum; ++i)
	{
		for (int j = 1; j <= colNum; ++j)
		{
			if (get(i, j) < 0)
			{
				cerr << "ERROR : root is negtive when powered !!!\n";
			}				
			result.set(i, j, pow(get(i, j), f));
		}
	}

	return result;
}


// 将一个矩阵赋给另一个 : 检查维度，若不相同则改变左矩阵维度
// Copy a matrix to another ：if demensions are different, the left matrix's demension will be changed

void CMatrix::operator =(const CMatrix &mat2)
{
	if (rowNum != mat2.rowNum ||
		colNum != mat2.colNum)
	{
		cout << "WARNING : different demensions，force assignment will change the demension of the left matrix，continue？\n" << "(Y)es  or  (N)o" << endl;

		char userChoice = 'N';

		cin >> userChoice;

		if (userChoice == 'Y' || userChoice == 'y')
		{
			rowNum = mat2.rowNum;
			colNum = mat2.colNum;
			isTransposed = mat2.isTransposed;

			delete[] start;
			start = new double[rowNum * colNum];
			

			for (int i = 1; i <= rowNum; ++i)
			{
				for (int j = 1; j <= colNum; ++j)
				{
					set(i, j, mat2.get(i, j));
				}
			}
			return;
		}
		else if (userChoice == 'N' || userChoice == 'n')
		{
			cerr << "NOTICE : force assignment failed !!!" << endl;
		}
		else
		{
			cerr << "ERROR : wrong input of force assignment option !!!" << endl;
		}

		
	}
	else
	{
		rowNum = mat2.rowNum;
		colNum = mat2.colNum;
		isTransposed = mat2.isTransposed;

		for (int i = 1; i <= rowNum; ++i)
		{
			for (int j = 1; j <= colNum; ++j)
			{
				set(i, j, mat2.get(i, j));
			}				
		}
		return;
	}
}


// 转置时用于交换rowNum与colNum的值
// Swap rowNum and colNum when transposing

void CMatrix::rowColSwap()
{
	int temp = rowNum;
	rowNum = colNum;
	colNum = temp;
}


// 在控制台以规范的格式打印矩阵
// Print matrix in console

ostream &operator <<(ostream &os, const CMatrix &mat)
{
	int row_n = mat.getRowNum();
	int col_n = mat.getColNum();

	for (int i = 1; i <= row_n; ++i)
	{
		for (int j = 1; j <= col_n; ++j)
		{
			os << fixed << mat.get(i, j) << '\t';
		}
			
		if (i < row_n)
		{
			os << '\n';
		}			
	}

	os << '\n';

	return os;
}

