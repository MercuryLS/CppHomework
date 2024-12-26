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
	Matrix Add(const Matrix& theOther);//加
	Matrix Minus(const Matrix& theOther);//减
	Matrix Multiple(const Matrix& theOther);//乘
	Matrix Determinant();//求行列式
	Matrix Inverse();//求逆
	Matrix Devide(const Matrix& theOther);//除法
	Matrix T();//转置
	Matrix Rank();//求秩
	~Matrix();
	void show();
};