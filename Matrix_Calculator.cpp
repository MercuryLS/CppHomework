// ����.cpp: �������̨Ӧ�ó������ڵ㡣
#include "main.hpp"
#include "Matrix.hpp"
#include "LinearEqu.hpp"    //LinearEqu.hppͷ�ļ�
#include <iostream>
using namespace std;
int matrix_Cal()
{
	cout << endl;
	cout << "���������" << endl;
	cout << endl;
	int L = 1;
	Matrix M1, M2;
	while (L)
	{
		cout << "�������ʲô�������㣿���������Ӧ����ĸ,����ѡ���˳���" << endl;
		cout << "A.���   B.���   C.���   D.ת��    E.����������ʽ  " << endl;
		cout << "F.�����������    G.�������    H.��������   K.�����Է�����   Q.�����ϼ�Ŀ¼ " << endl;
		int r, c;
		char C;
		cin >> C;
		if (C >= 97)
		{
			C = C - 32;
		}
		switch (C)
		{
		case 'A':
		{
			//cout << "��������мӷ����㣬��ô" << endl;
			cout << "�������������ļ������������" << endl;
			cin >> r;
			cout << "�������������ļ������������" << endl;
			cin >> c;
			//cout << "���ݾ���ӷ��ķ������ǿ�֪�����������һ���������������������Ҳ����Ϊ" << r << "��" << c << endl;
			cout << "�������ĵ�һ�����������Ԫ��,��ô";
			M1.setM(r, c);
			cout << "�������ĵڶ������������Ԫ��,��ô";
			M2.setM(r, c);
			M1.Add(M2);
			break;
		}
		case 'B':
		{
			//cout << "��������м������㣬��ô" << endl;
			cout << "�������������ļ������������" << endl;
			cin >> r;
			cout << "�������������ļ������������" << endl;
			cin >> c;
			//cout << "���ݾ���ӷ��ķ������ǿ�֪�����������һ���������������������Ҳ����Ϊ" << r << "��" << c << endl;
			cout << "�������ĵ�һ�����������Ԫ��,��ô";
			M1.setM(r, c);
			cout << "���������ĵڶ������������Ԫ�أ���ô" << endl;
			M2.setM(r, c);
			M1.Minus(M2);
			break;
		}
		case 'C':
		{
			//cout << "��������г˷����㣬��ô" << endl;
			cout << "�������������ĳ������������" << endl;
			cin >> r;
			cout << "�������������ĳ������������" << endl;
			cin >> c;
			//cout << "���ݾ���˷��ķ������ǿ�֪�����������һ�������������������������Ϊ" << c << "��" << r << endl;
			cout << "���������ĵ�һ�����������Ԫ��" << endl;
			M1.setM(r, c);
			cout << "���������ĵڶ������������Ԫ��" << endl;
			M2.setM(c, r);
			M1.Multiple(M2);
			break;
		}
		case 'D':
		{
			cout << "���������ת�����㣬��ô��������������" << endl;
			cin >> r;
			cout << "��������������" << endl;
			cin >> c;
			M1.setM(r, c);
			M1.T();
			break;
		}
		case 'E':
		{
			cout << "����������������ʽ����ô��������������������" << endl;
			cin >> r;
			M1.setM(r, r);
			M1.Determinant();
			break;
		}
		case 'F':
		{
			M1.flag2 = 0;
			cout << "�������������棬��ô��������������������" << endl;
			cin >> r;
			M1.setM(r, r);
			M1.Determinant();
			if (M1.D != 0)
			{
				M1.Inverse();
			}
			else
			{
				cout << "ֻ�з�����(����ʽ��Ϊ0������ſ������棡" << endl;
			}
			M1.flag2 = 1;
			break;
		}
		case 'G':
		{
			int M = 1;
			M1.flag2 = 0;
			cout << "������������������������" << endl;
			cin >> r;
			cout << "��Ӧ�ģ����ı��������������������ҲӦ��Ϊ" << r << endl;
			while (M)
			{
				cout << "���������ĳ��������Ԫ��" << endl;
				M1.setM(r, r);
				M1.Determinant();
				if (M1.D != 0)
				{
					M = 0;
				}
				else
				{
					cout << "ֻ�з�����(����ʽ��Ϊ0������ſ�����Ϊ������" << endl;
				}

			}
			cout << "���������ı����������Ԫ��" << endl;
			M2.setM(r, r);
			cout << "������ĳ��������";
			M1.Devide(M2);
			M1.flag2 = 1;
			break;
		}
		case 'H':
		{
			cout << "������������ȣ���ô��������������������" << endl;
			cin >> r;
			M1.setM(r, r);
			M1.Rank();
			break;
		}
		case 'K':
		{
			int N0, i;
			cout << "����������㼸Ԫ�����飿������:" << endl;
			cin >> N0;
			double* a = new double[N0 * N0];
			double* b = new double[N0];
			cout << "�����뷽����δ֪Ԫǰ���е�ϵ��" << endl;
			for (i = 0; i < N0 * N0; i++)
			{
				cin >> a[i];
			}
			cout << "��������������̵��Ҷ���" << endl;
			for (i = 0; i < N0; i++)
			{
				cin >> b[i];
			}
			/*double a[] = {
				0.2368,0.2471,0.2568,1.2671,
				0.1968,0.2071,1.2168,0.2271,
				0.1581,1.1675,0.1768,0.1871,
				1.1161,0.1254,0.1397,0.1490
			};
			double b[] = { 1.8471,1.7471,1.6471,1.5471 };*/
			LinearEqu equ(N0);
			equ.setLinearEqu(a, b);
			equ.printLinearEqu();
			if (equ.solve())
				equ.printSolution();
			else
				cout << "Fail" << endl;
			delete[] a;
			delete[] b;
			break;
		}
		case 'Q':
		{
			system("cls");
			L = 0;
			break;
		}
		default:
		{
			cout << "��������Ч����ĸ��" << endl;
			break;
		}
		}
	}

	return 0;
}