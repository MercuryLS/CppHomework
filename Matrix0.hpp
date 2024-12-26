#pragma once
#ifndef _MATRIX_H
#define _MATRIX_H
class Matrix0 {
public:
	Matrix0(int size);  //���캯��
	~Matrix0();//��������
	void setMatrix0(const double* values);//���󸳳�ֵ
	void printMatrix0();//��ʾ����
	int getSize()const { return size;}//�õ������С
	double& element(int i, int j) { return elements[i * size + j]; }
	double element(int i, int j)const { return elements[i * size + j]; }
private:
	int size;//����Ĵ�С
	double* elements; // �����������׵�ַ
};
#endif