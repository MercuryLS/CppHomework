#pragma once
//#include"stdafx.h"
#include"iostream"
using namespace std;
class Matrix
{
public:
	int rows, cols, flag2 = 1;
	double D;
	double* num;
	Matrix(int R, int C, double* n);
	Matrix();
	Matrix(Matrix& theOther);
	void setM(int r, int c);
	Matrix Add(const Matrix& theOther);//��
	Matrix Minus(const Matrix& theOther);//��
	Matrix Multiple(const Matrix& theOther);//��
	Matrix Determinant();//������ʽ
	Matrix Inverse();//����
	Matrix Devide(const Matrix& theOther);//����
	Matrix T();//ת��
	Matrix Rank();//����
	~Matrix();
	void show();
};