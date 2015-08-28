#ifndef CMATRIX_H
#define CMATRIX_H

#include <iostream>
using namespace std;

class CMatrix {

public:

	CMatrix(int m, int n);			 //构建一个m*n的全零矩阵
	CMatrix(int n);				 //构建一个n*n的全零矩阵
	CMatrix(const CMatrix &);		 //拷贝构造函数，深拷贝                  
						 //不提供无参数构造函数CMatrix()
	~CMatrix();

	static bool printWhenCreateAndDelete;		//控制是否打印构造与析构

	int getRowNum() const;				//返回矩阵的行数
	int getColNum() const;				//返回矩阵的列数
	bool getTransState() const;			//返回矩阵的转置状态

	CMatrix trans() const;				//将矩阵转置
	double norm() const;				//求解矩阵F范数
	double get(int i, int j) const;			//返回矩阵第i行j列元素
	void set(int i, int j, double val);		//设置矩阵第i行j列元素为val
	void diagUnitize();				//将方阵对角线元素全部设置为1
	void clear();					//将矩阵所有元素设置为零

	CMatrix operator +(const CMatrix &mat);	 	//两个矩阵相加
	CMatrix operator -(const CMatrix &mat);	 	//两个矩阵相减
	CMatrix operator *(const CMatrix &mat);	 	//两个矩阵相乘
	CMatrix operator *(const double f);	 	//矩阵乘以常数
	CMatrix operator /(const double f);	 	//矩阵除以常数
	CMatrix operator ^(const double f);	 	//矩阵元素分别求幂
	void operator =(const CMatrix &mat);	 	//将一个矩阵赋给另一个

private:

	double *start;		//指向矩阵首元素的指针
	int rowNum;		//矩阵行数
	int colNum;		//矩阵列数

	bool isTransposed;	//记录矩阵是否转置
	void rowColSwap();	//转置时用于交换row_num与col_num的值
};

//在控制台以规范的格式打印矩阵
ostream & operator <<(ostream &, const CMatrix &);

#endif
