#pragma once
#ifndef _LINEAR_EQU_H
#define _LINEAR_EQU_H
#include <iostream>
#include "Matrix0.hpp"
using namespace std;

class LinearEqu :public Matrix0 {
public:
	LinearEqu(int size);   //构造函数
	~LinearEqu();    //析构函数
	void setLinearEqu(const double* a, const double* b);   //方程赋值
	bool solve();   //全选主元高斯消去法求解方程
	void printLinearEqu()const;  //显示方程
	void printSolution()const;   //显示方程的解
private:
	double* sums;    //方程右端项
	double* solution;   //方程的解
};

#endif