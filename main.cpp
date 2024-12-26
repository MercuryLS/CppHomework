#include <iostream>
#include "main.hpp"
using namespace std;
int main()
{
	while (1)
	{
		cout << "请选择模式：(输入数字0,1或2)" << endl;
		cout << "0.退出" << endl;
		cout << "1.常规计算器" << endl;
		cout << "2.矩阵计算器" << endl;
		int mode = -1;
		cin >> mode;
		while (mode != 0 && mode != 1 && mode != 2)
		{
			cout << "输入错误，请重新输入！";
			cin >> mode;
		}
		if (mode == 0)
		{
			return 0;
		}
		else if (mode == 1)
		{
			Calculator();
		}
		else if (mode == 2)
		{
			matrix_Cal();
		}
	}
}