#ifndef CMATRIX_H
#define CMATRIX_H

#include <iostream>
using namespace std;

class CMatrix {

public:

	CMatrix(int m, int n);			 //����һ��m*n��ȫ�����
	CMatrix(int n);					 //����һ��n*n��ȫ�����
	CMatrix(const CMatrix &);		 //�������캯�������                  
									 //���ṩ�޲������캯��CMatrix()
	~CMatrix();

	static bool printWhenCreateAndDelete;	//�����Ƿ��ӡ����������

	int getRowNum() const;					//���ؾ��������
	int getColNum() const;					//���ؾ��������
	bool getTransState() const;				//���ؾ����ת��״̬

	CMatrix trans() const;					//������ת��
	double norm() const;					//������F����
	double get(int i, int j) const;			//���ؾ����i��j��Ԫ��
	void set(int i, int j, double val);		//���þ����i��j��Ԫ��Ϊval
	void diagUnitize();						//������Խ���Ԫ��ȫ������Ϊ1
	void clear();							//����������Ԫ������Ϊ��

	CMatrix operator +(const CMatrix &mat);	 //�����������
	CMatrix operator -(const CMatrix &mat);	 //�����������
	CMatrix operator *(const CMatrix &mat);	 //�����������
	CMatrix operator *(const double f);		 //������Գ���
	CMatrix operator /(const double f);		 //������Գ���
	CMatrix operator ^(const double f);		 //����Ԫ�طֱ�����
	void operator =(const CMatrix &mat);	 //��һ�����󸳸���һ��

private:

	double *start;		//ָ�������Ԫ�ص�ָ��
	int rowNum;			//��������
	int colNum;			//��������

	bool isTransposed;	//��¼�����Ƿ�ת��
	void rowColSwap();	//ת��ʱ���ڽ���row_num��col_num��ֵ
};

//�ڿ���̨�Թ淶�ĸ�ʽ��ӡ����
ostream & operator <<(ostream &, const CMatrix &);

#endif