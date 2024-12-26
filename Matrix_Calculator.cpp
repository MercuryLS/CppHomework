// 矩阵.cpp: 定义控制台应用程序的入口点。
#include "main.hpp"
#include "Matrix.hpp"
#include "LinearEqu.hpp"    //LinearEqu.hpp头文件
#include <iostream>
using namespace std;
int matrix_Cal()
{
	cout << endl;
	cout << "矩阵计算器" << endl;
	cout << endl;
	int L = 1;
	Matrix M1, M2;
	while (L)
	{
		cout << "您想进行什么样的运算？请输入相对应的字母,或者选择退出：" << endl;
		cout << "A.相加   B.相减   C.相乘   D.转置    E.方阵求行列式  " << endl;
		cout << "F.方阵求逆矩阵    G.方阵除法    H.方阵求秩   K.解线性方程组   Q.返回上级目录 " << endl;
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
			//cout << "您打算进行加法运算，那么" << endl;
			cout << "请输入您想计算的加数矩阵的行数" << endl;
			cin >> r;
			cout << "请输入您想计算的加数矩阵的列数" << endl;
			cin >> c;
			//cout << "根据矩阵加法的法则，我们可知您将输入的另一个加数矩阵的行数和列数也必须为" << r << "与" << c << endl;
			cout << "输入您的第一个加数矩阵的元素,那么";
			M1.setM(r, c);
			cout << "输入您的第二个加数矩阵的元素,那么";
			M2.setM(r, c);
			M1.Add(M2);
			break;
		}
		case 'B':
		{
			//cout << "您打算进行减法运算，那么" << endl;
			cout << "请输入您想计算的减数矩阵的行数" << endl;
			cin >> r;
			cout << "请输入您想计算的减数矩阵的列数" << endl;
			cin >> c;
			//cout << "根据矩阵加法的法则，我们可知您将输入的另一个减数矩阵的行数和列数也必须为" << r << "与" << c << endl;
			cout << "输入您的第一个减数矩阵的元素,那么";
			M1.setM(r, c);
			cout << "请输入您的第二个减数矩阵的元素，那么" << endl;
			M2.setM(r, c);
			M1.Minus(M2);
			break;
		}
		case 'C':
		{
			//cout << "您打算进行乘法运算，那么" << endl;
			cout << "请输入您想计算的乘数矩阵的行数" << endl;
			cin >> r;
			cout << "请输入您想计算的乘数矩阵的列数" << endl;
			cin >> c;
			//cout << "根据矩阵乘法的法则，我们可知您将输入的另一个乘数矩阵的行数和列数必须为" << c << "与" << r << endl;
			cout << "请输入您的第一个乘数矩阵的元素" << endl;
			M1.setM(r, c);
			cout << "请输入您的第二个乘数矩阵的元素" << endl;
			M2.setM(c, r);
			M1.Multiple(M2);
			break;
		}
		case 'D':
		{
			cout << "您打算进行转置运算，那么请输入矩阵的行数" << endl;
			cin >> r;
			cout << "请输入矩阵的列数" << endl;
			cin >> c;
			M1.setM(r, c);
			M1.T();
			break;
		}
		case 'E':
		{
			cout << "您打算求矩阵的行列式，那么请输入矩阵的行数暨列数" << endl;
			cin >> r;
			M1.setM(r, r);
			M1.Determinant();
			break;
		}
		case 'F':
		{
			M1.flag2 = 0;
			cout << "您打算求矩阵的逆，那么请输入矩阵的行数暨列数" << endl;
			cin >> r;
			M1.setM(r, r);
			M1.Determinant();
			if (M1.D != 0)
			{
				M1.Inverse();
			}
			else
			{
				cout << "只有非奇异(行列式不为0）矩阵才可以求逆！" << endl;
			}
			M1.flag2 = 1;
			break;
		}
		case 'G':
		{
			int M = 1;
			M1.flag2 = 0;
			cout << "请输入除数矩阵的行数暨列数" << endl;
			cin >> r;
			cout << "对应的，您的被除数矩阵的行数暨列数也应该为" << r << endl;
			while (M)
			{
				cout << "请输入您的除数矩阵的元素" << endl;
				M1.setM(r, r);
				M1.Determinant();
				if (M1.D != 0)
				{
					M = 0;
				}
				else
				{
					cout << "只有非奇异(行列式不为0）矩阵才可以作为除数！" << endl;
				}

			}
			cout << "请输入您的被除数矩阵的元素" << endl;
			M2.setM(r, r);
			cout << "您输入的除数矩阵的";
			M1.Devide(M2);
			M1.flag2 = 1;
			break;
		}
		case 'H':
		{
			cout << "您打算求方阵的秩，那么请输入矩阵的行数暨列数" << endl;
			cin >> r;
			M1.setM(r, r);
			M1.Rank();
			break;
		}
		case 'K':
		{
			int N0, i;
			cout << "请问您想计算几元方程组？请输入:" << endl;
			cin >> N0;
			double* a = new double[N0 * N0];
			double* b = new double[N0];
			cout << "请输入方程组未知元前所有的系数" << endl;
			for (i = 0; i < N0 * N0; i++)
			{
				cin >> a[i];
			}
			cout << "请依次输入各方程的右端项" << endl;
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
			cout << "请输入有效的字母！" << endl;
			break;
		}
		}
	}

	return 0;
}