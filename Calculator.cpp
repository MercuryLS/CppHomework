#define _CRT_SECURE_NO_WARNINGS 1
#include <iomanip>
#include <cstdlib>
#include "main.hpp"
#include "Expression.hpp"
using namespace std;

extern int LargeNumberFactorial[1000];

int Calculator()
{
	system("cls");
	cout<<"\n������"<<endl;
	int menu = 1;
	while (menu == 1)
	{
		string s;
		cout << "\n��������ʽ:" << endl;
		cin >> s;
		Expression exp(s);
		if (exp.Format() == false)
		{
			cout << "�������(�޷�ʶ��ķ���)" << endl;
		}
		else if (exp.FormatCheck() == false)
		{
			cout << "�������(��ʽ����)" << endl;
		}
		else
		{
			exp.negative_change();
			exp.change();
			if (exp.compute() == true)
				exp.showAns();
		}
		do
		{
			cout << "\n1.��������" << endl;
			cout << "2.�����ϼ��˵�" << endl;
			fflush(stdin);
			cin >> menu;
		} while (menu != 1 && menu != 2);
	}
	system("cls");
	return 0;
}