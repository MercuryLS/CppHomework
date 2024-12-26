#include"Matrix0.hpp"
#include<iostream>
using namespace std;

void Matrix0::setMatrix0(const double* values) {
	//设置矩阵
	for (int i = 0; i < size * size; i++)
		elements[i] = values[i];   //矩阵成员赋初值
}

Matrix0::Matrix0(int size/*=2*/) :size(size) {   //矩阵Matrix0类的构造函数
	elements = new double[size * size];
}

Matrix0::~Matrix0() {    //矩阵Matrix0类的析构函数
	delete[] elements;   //内存释放
}

void Matrix0::printMatrix0() {
	cout << "The Matrix is:" << endl;
	for (int i = 0; i < size; i++) {
		for(int j=0;j<size;j++)
		cout << element(i, j) << " ";
		cout << endl;
	}
}