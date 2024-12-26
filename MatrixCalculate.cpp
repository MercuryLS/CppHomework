//#include "stdafx.h"
#include "iostream"
#include "cmath"
#include "ctime"
#include "Matrix.hpp"
#include <string.h>
using namespace std;
Matrix::Matrix(int R, int C, double* n)
{
	rows = R;
	cols = C;
	num = new double[rows * cols];
	double* a = num;
	for (int i = 0; i < rows * cols; i++)
	{
		*a++ = *n++;
	}
}
Matrix::Matrix()
{
	rows = 1;
	cols = 1;
	num = new double(1);
}
Matrix::Matrix(Matrix& theOther)
{
	rows = theOther.rows;
	cols = theOther.cols;
	num = new double[rows * cols];
	for (int i = 0; i < rows * cols; i++)
		*(num + i) = *(theOther.num + i);
}
void Matrix::setM(int r, int c)
{
	rows = r;
	cols = c;
	if (r == 0 || c == 0)
	{
		cout << "�������������������Ϊ0" << endl;
		return;
	}
	else
	{
		delete[]num;
		num = NULL;
		num = new double[rows * cols];
		double* p = num;
		for (int i = 0; i < rows; i++)
		{
			cout << "�������" << i + 1 << "��Ԫ�ص�" << endl;
			for (int j = 0; j < cols; j++)
			{
				cout << "��" << j + 1 << "��Ԫ��:";
				cin >> *(p + i * cols + j);
			}
		}
	}
}
Matrix Matrix::Add(const Matrix& theOther)
{


	double* n = new double[rows * cols];
	for (int i = 0; i < rows * cols; i++)
	{
		*(n + i) = *(num + i) + *(theOther.num + i);
	}
	Matrix temp(rows, cols, n);
	cout << "���ļӷ����������£�" << endl;
	temp.show();
	if (rows * cols > 1)
	{
		delete[]n;
	}
	else
	{
		delete n;
	}
	return temp;


}
Matrix Matrix::Minus(const Matrix& theOther)
{

	double* n = new double[rows * cols];
	for (int i = 0; i < rows * cols; i++)
	{
		*(n + i) = *(num + i) - *(theOther.num + i);
	}
	Matrix temp(rows, cols, n);
	cout << "���ļ�������������:" << endl;
	temp.show();
	if (rows * cols == 1)
	{
		delete n;
	}
	else
	{
		delete[]n;
	}
	return temp;


}
Matrix Matrix::Multiple(const Matrix& theOther)
{

	double* n = new double[rows * theOther.cols];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < theOther.cols; j++)
		{
			*(n + i * theOther.cols + j) = 0;
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			for (int t = 0; t < theOther.cols; t++)
			{
				*(n + i * theOther.cols + t) += *(num + i * cols + j) * *(theOther.num + j * theOther.cols + t);
			}
		}
	}
	Matrix temp(rows, theOther.cols, n);
	cout << "���ĳ˷�����������:" << endl;
	temp.show();
	if (rows * theOther.cols == 1)
	{
		delete n;
	}
	else
	{
		delete[] n;
	}
	return temp;

}
Matrix Matrix::T()
{
	double* n = new double[rows * cols];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			*(n + j * rows + i) = *(num + i * cols + j);
		}

	}
	Matrix temp(cols, rows, n);
	cout << "����õ�ת�þ���ʽ�ǣ�" << endl;
	temp.show();
	if (rows * cols == 1)
	{
		delete n;
	}
	else
	{
		delete[] n;
	}
	return temp;

}

Matrix Matrix::Determinant()
{
	double* A = new double[rows * cols];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			*(A + i * rows + j) = *(num + i * rows + j);
		}

	}
	void EX(double aa, double bb, int n);
	int ii, jj, k, u;
	int iter = 0;  //��¼�б任�Ĵ�����������  
	double det1 = 1, yin;
	for (ii = 0; ii < rows; ii++)
	{
		if (*(A + ii * rows + ii) == 0)

			for (jj = ii; jj < rows; jj++)
			{
				if (*(A + jj * rows + ii) != 0)
				{
					EX((*A + ii * rows), *(A + jj * rows), rows);//��������    
					iter++;
				}
			}

		for (k = ii + 1; k < rows; k++)
		{
			yin = -1 * (*(A + k * rows + ii)) / (*(A + ii * rows + ii));

			for (u = 0; u < rows; u++)
			{
				*(A + k * rows + u) = *(A + k * rows + u) + *(A + ii * rows + u) * yin;
			}
		}
	}
	for (ii = 0; ii < rows; ii++)  //��Խ��ߵĻ�������ʽ��ֵ  
		det1 = det1 * (*(A + ii * rows + ii));
	//�б任ż���η��Ų���  
	if (iter % 2 == 1)
		det1 = -det1;
	double* a = new double[rows * cols];
	if (flag2 == 1)
	{
		if (det1 != 0)
		{
			cout << "���������ʽ��ֵΪ��" << det1 << endl;
		}
		else
		{
			cout << "���������ʽΪ��" << abs(det1) << endl;
		}
	}
	D = det1;
	Matrix temp(rows, cols, A);
	if (rows * cols == 1)
	{
		delete A;
	}
	else
	{
		delete[] A;
	}
	return temp;


}

Matrix Matrix::Inverse()
{
	double* A = new double[rows * cols];
	int N = rows;
	double* LUP_solve_inverse(double* AA, int N);
	srand((unsigned)time(0));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			A[i * rows + j] = num[i * rows + j];
		}
	}
	A = LUP_solve_inverse(A, N);
	Matrix T(rows, cols, A);
	cout << "����õ������Ϊ��" << endl;
	T.show();
	if (rows * cols == 1)
	{
		delete A;
	}
	else
	{
		delete[] A;
	}
	return T;
}
Matrix Matrix::Devide(const Matrix& theOther)
{
	Matrix Temp(rows, cols, num);
	Temp.Inverse();
	double* n = new double[rows * cols];
	for (int i = 0; i < rows; i++)
	{

	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < theOther.cols; j++)
		{
			*(n + i * theOther.cols + j) = 0;
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			for (int t = 0; t < theOther.cols; t++)
			{
				*(n + i * theOther.cols + t) += *(num + i * cols + j) * *(theOther.num + j * theOther.cols + t);
			}
		}
	}
	Matrix temp(rows, cols, n);
	cout << "��������Ľ��Ϊ��" << endl;
	temp.show();
	if (rows * cols > 1)
	{
		delete[]n;
	}
	else
	{
		delete n;
	}
	return temp;
}
Matrix Matrix::Rank()
{
	double* A = new double[rows * cols];
	int n = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			*(A + i * rows + j) = *(num + i * rows + j);
		}

	}
	void EX(double aa, double bb, int n);
	int ii, jj, k, u;
	int iter = 0;  //��¼�б任�Ĵ�����������  
	double det1 = 1, yin;
	for (ii = 0; ii < rows; ii++)
	{
		if (*(A + ii * rows + ii) == 0)

			for (jj = ii; jj < rows; jj++)
			{
				if (*(A + jj * rows + ii) != 0)
				{
					EX((*A + ii * rows), *(A + jj * rows), rows);//��������    
					iter++;
				}
			}

		for (k = ii + 1; k < rows; k++)
		{
			yin = -1 * (*(A + k * rows + ii)) / (*(A + ii * rows + ii));

			for (u = 0; u < rows; u++)
			{
				*(A + k * rows + u) = *(A + k * rows + u) + *(A + ii * rows + u) * yin;
			}
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (*(A + i * rows + j) != 0)
			{
				n++;
				break;
			}
		}
	}
	cout << "�÷������Ϊ��" << n << endl;;
	Matrix temp(rows, cols, A);
	if (rows * cols == 1)
	{
		delete A;
	}
	else
	{
		delete[] A;
	}
	return temp;

}
void Matrix::show()
{
	if (rows * cols != 0)
	{
		for (int i = 0; i < rows * cols; i++)
		{
			cout.width(7);//�����ֶο��
			cout << *(num + i);
			if ((i + 1) % cols == 0)
			{
				cout << endl;
			}
		}
	}
}

Matrix::~Matrix()
{
	if (rows * cols == 1)
	{
		delete num;
	}
	else
	{
		delete[] num;
	}
}
//��������ָ�������У��������б任������Ϊ�н�����    
void EX(double aa, double bb, int n)
{
	int i;
	double temp1;
	for (i = 0; i < n; i++)
	{
		temp1 = aa;
		aa = bb;
		bb = temp1;
	}
}
void LUP_Descomposition(double* A, double* L, double* U, int* P, int N)
{
	//LUP�ֽ�
	int RR = 0;
	for (int i = 0; i < N; i++)
	{
		P[i] = i;
	}
	for (int i = 0; i < N - 1; i++)
	{
		double p = 0.0;
		for (int j = i; j < N; j++)
		{
			if (abs(A[j * N + i]) > p)
			{
				p = abs(A[j * N + i]);
				RR = j;
			}
		}

		//����P[i]��P[row]
		int tmp = P[i];
		P[i] = P[RR];
		P[RR] = tmp;

		double tmp2 = 0.0;
		for (int j = 0; j < N; j++)
		{
			//����A[i][j]�� A[row][j]
			tmp2 = A[i * N + j];
			A[i * N + j] = A[RR * N + j];
			A[RR * N + j] = tmp2;
		}

		//����ͬLU�ֽ�
		double u = A[i * N + i], l = 0.0;
		for (int j = i + 1; j < N; j++)
		{
			l = A[j * N + i] / u;
			A[j * N + i] = l;
			for (int k = i + 1; k < N; k++)
			{
				A[j * N + k] = A[j * N + k] - A[i * N + k] * l;
			}
		}

	}

	//����L��U
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i != j)
			{
				L[i * N + j] = A[i * N + j];
			}
			else
			{
				L[i * N + j] = 1;
			}
		}
		for (int k = i; k < N; k++)
		{
			U[i * N + k] = A[i * N + k];
		}
	}
}
double* LUP_Solve(double* L, double* U, int* P, double* b, int N)
{

	double* x = new double[N]();
	double* y = new double[N]();

	//�����滻
	for (int i = 0; i < N; i++)
	{
		y[i] = b[P[i]];
		for (int j = 0; j < i; j++)
		{
			y[i] = y[i] - L[i * N + j] * y[j];
		}
	}
	//�����滻
	for (int i = N - 1; i >= 0; i--)
	{
		x[i] = y[i];
		for (int j = N - 1; j > i; j--)
		{
			x[i] = x[i] - U[i * N + j] * x[j];
		}
		x[i] /= U[i * N + i];
	}
	return x;
}
/*****************����ԭ��ת��BEGIN********************/

/* ��� */
int getNext(int i, int m, int n)
{
	return (i % n) * m + i / n;
}

/* ǰ�� */
int getPre(int i, int m, int n)
{
	return (i % m) * n + i / m;
}
/* �������±�iΪ���Ļ� */
void movedata(double* mtx, int i, int m, int n)
{
	double temp = mtx[i]; // �ݴ�
	int cur = i;    // ��ǰ�±�
	int pre = getPre(cur, m, n);
	while (pre != i)
	{
		mtx[cur] = mtx[pre];
		cur = pre;
		pre = getPre(cur, m, n);
	}
	mtx[cur] = temp;
}
/* ת�ã���ѭ���������л� */
void transpose(double* mtx, int m, int n)
{
	for (int i = 0; i < m * n; ++i)
	{
		int next = getNext(i, m, n);
		while (next > i) // �����ں��С��i˵���ظ�,�Ͳ�������ȥ�ˣ�ֻ�в��ظ�ʱ����whileѭ����
			next = getNext(next, m, n);
		if (next == i)  // ����ǰ��
			movedata(mtx, i, m, n);
	}
}
/*****************����ԭ��ת��END********************/
//LUP����(��ÿ��b����ĸ���x������װ)
double* LUP_solve_inverse(double* A, int N)
{
	//��������A�ĸ�����ע�ⲻ��ֱ����A���㣬��ΪLUP�ֽ��㷨�ѽ���ı�
	double* A_mirror = new double[N * N]();
	double* inv_A = new double[N * N]();//���յ�����󣨻���Ҫת�ã�
	double* inv_A_each = new double[N]();//������ĸ���
	//double *B    =new double[N*N]();
	double* b = new double[N]();//b��ΪB����о������

	for (int i = 0; i < N; i++)
	{
		double* L = new double[N * N]();
		double* U = new double[N * N]();
		int* P = new int[N]();

		//���쵥λ���ÿһ��
		for (int i = 0; i < N; i++)
		{
			b[i] = 0;
		}
		b[i] = 1;

		//ÿ�ζ���Ҫ���½�A����һ��
		for (int i = 0; i < N * N; i++)
		{
			A_mirror[i] = A[i];
		}

		LUP_Descomposition(A_mirror, L, U, P, N);

		inv_A_each = LUP_Solve(L, U, P, b, N);
		memcpy(inv_A + i * N, inv_A_each, N * sizeof(double));//������ƴ������
	}
	transpose(inv_A, N, N);//�������ڸ���ÿ��b�����x���д洢�������ת��

	return inv_A;
}