#include <iostream>
#include "main.hpp"
using namespace std;
int main()
{
	while (1)
	{
		cout << "��ѡ��ģʽ��(��������0,1��2)" << endl;
		cout << "0.�˳�" << endl;
		cout << "1.���������" << endl;
		cout << "2.���������" << endl;
		int mode = -1;
		cin >> mode;
		while (mode != 0 && mode != 1 && mode != 2)
		{
			cout << "����������������룡";
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