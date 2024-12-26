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
		cout << "矩阵的行数和列数不能为0" << endl;
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
			cout << "请输入第" << i + 1 << "行元素的" << endl;
			for (int j = 0; j < cols; j++)
			{
				cout << "第" << j + 1 << "列元素:";
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
	cout << "您的加法计算结果如下：" << endl;
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
	cout << "您的减法计算结果如下:" << endl;
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
	cout << "您的乘法计算结果如下:" << endl;
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
	cout << "所求得的转置矩阵式是：" << endl;
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
	int iter = 0;  //记录行变换的次数（交换）  
	double det1 = 1, yin;
	for (ii = 0; ii < rows; ii++)
	{
		if (*(A + ii * rows + ii) == 0)

			for (jj = ii; jj < rows; jj++)
			{
				if (*(A + jj * rows + ii) != 0)
				{
					EX((*A + ii * rows), *(A + jj * rows), rows);//交换两行    
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
	for (ii = 0; ii < rows; ii++)  //求对角线的积即行列式的值  
		det1 = det1 * (*(A + ii * rows + ii));
	//行变换偶数次符号不变  
	if (iter % 2 == 1)
		det1 = -det1;
	double* a = new double[rows * cols];
	if (flag2 == 1)
	{
		if (det1 != 0)
		{
			cout << "矩阵的行列式的值为：" << det1 << endl;
		}
		else
		{
			cout << "矩阵的行列式为：" << abs(det1) << endl;
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
	cout << "所求得的逆矩阵为：" << endl;
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
	cout << "方阵除法的结果为：" << endl;
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
	int iter = 0;  //记录行变换的次数（交换）  
	double det1 = 1, yin;
	for (ii = 0; ii < rows; ii++)
	{
		if (*(A + ii * rows + ii) == 0)

			for (jj = ii; jj < rows; jj++)
			{
				if (*(A + jj * rows + ii) != 0)
				{
					EX((*A + ii * rows), *(A + jj * rows), rows);//交换两行    
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
	cout << "该方阵的秩为：" << n << endl;;
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
			cout.width(7);//设置字段宽度
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
//交换数组指定的两行，即进行行变换（具体为行交换）    
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
	//LUP分解
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

		//交换P[i]和P[row]
		int tmp = P[i];
		P[i] = P[RR];
		P[RR] = tmp;

		double tmp2 = 0.0;
		for (int j = 0; j < N; j++)
		{
			//交换A[i][j]和 A[row][j]
			tmp2 = A[i * N + j];
			A[i * N + j] = A[RR * N + j];
			A[RR * N + j] = tmp2;
		}

		//以下同LU分解
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

	//构造L和U
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

	//正向替换
	for (int i = 0; i < N; i++)
	{
		y[i] = b[P[i]];
		for (int j = 0; j < i; j++)
		{
			y[i] = y[i] - L[i * N + j] * y[j];
		}
	}
	//反向替换
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
/*****************矩阵原地转置BEGIN********************/

/* 后继 */
int getNext(int i, int m, int n)
{
	return (i % n) * m + i / n;
}

/* 前驱 */
int getPre(int i, int m, int n)
{
	return (i % m) * n + i / m;
}
/* 处理以下标i为起点的环 */
void movedata(double* mtx, int i, int m, int n)
{
	double temp = mtx[i]; // 暂存
	int cur = i;    // 当前下标
	int pre = getPre(cur, m, n);
	while (pre != i)
	{
		mtx[cur] = mtx[pre];
		cur = pre;
		pre = getPre(cur, m, n);
	}
	mtx[cur] = temp;
}
/* 转置，即循环处理所有环 */
void transpose(double* mtx, int m, int n)
{
	for (int i = 0; i < m * n; ++i)
	{
		int next = getNext(i, m, n);
		while (next > i) // 若存在后继小于i说明重复,就不进行下去了（只有不重复时进入while循环）
			next = getNext(next, m, n);
		if (next == i)  // 处理当前环
			movedata(mtx, i, m, n);
	}
}
/*****************矩阵原地转置END********************/
//LUP求逆(将每列b求出的各列x进行组装)
double* LUP_solve_inverse(double* A, int N)
{
	//创建矩阵A的副本，注意不能直接用A计算，因为LUP分解算法已将其改变
	double* A_mirror = new double[N * N]();
	double* inv_A = new double[N * N]();//最终的逆矩阵（还需要转置）
	double* inv_A_each = new double[N]();//矩阵逆的各列
	//double *B    =new double[N*N]();
	double* b = new double[N]();//b阵为B阵的列矩阵分量

	for (int i = 0; i < N; i++)
	{
		double* L = new double[N * N]();
		double* U = new double[N * N]();
		int* P = new int[N]();

		//构造单位阵的每一列
		for (int i = 0; i < N; i++)
		{
			b[i] = 0;
		}
		b[i] = 1;

		//每次都需要重新将A复制一份
		for (int i = 0; i < N * N; i++)
		{
			A_mirror[i] = A[i];
		}

		LUP_Descomposition(A_mirror, L, U, P, N);

		inv_A_each = LUP_Solve(L, U, P, b, N);
		memcpy(inv_A + i * N, inv_A_each, N * sizeof(double));//将各列拼接起来
	}
	transpose(inv_A, N, N);//由于现在根据每列b算出的x按行存储，因此需转置

	return inv_A;
}