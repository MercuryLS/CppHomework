#include"Matrix0.hpp"
#include<iostream>
using namespace std;

void Matrix0::setMatrix0(const double* values) {
	//���þ���
	for (int i = 0; i < size * size; i++)
		elements[i] = values[i];   //�����Ա����ֵ
}

Matrix0::Matrix0(int size/*=2*/) :size(size) {   //����Matrix0��Ĺ��캯��
	elements = new double[size * size];
}

Matrix0::~Matrix0() {    //����Matrix0�����������
	delete[] elements;   //�ڴ��ͷ�
}

void Matrix0::printMatrix0() {
	cout << "The Matrix is:" << endl;
	for (int i = 0; i < size; i++) {
		for(int j=0;j<size;j++)
		cout << element(i, j) << " ";
		cout << endl;
	}
}