#pragma once
#ifndef _LINEAR_EQU_H
#define _LINEAR_EQU_H
#include <iostream>
#include "Matrix0.hpp"
using namespace std;

class LinearEqu :public Matrix0 {
public:
	LinearEqu(int size);   //���캯��
	~LinearEqu();    //��������
	void setLinearEqu(const double* a, const double* b);   //���̸�ֵ
	bool solve();   //ȫѡ��Ԫ��˹��ȥ����ⷽ��
	void printLinearEqu()const;  //��ʾ����
	void printSolution()const;   //��ʾ���̵Ľ�
private:
	double* sums;    //�����Ҷ���
	double* solution;   //���̵Ľ�
};

#endif