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
	cout<<"\n计算器"<<endl;
	int menu = 1;
	while (menu == 1)
	{
		string s;
		cout << "\n请输入表达式:" << endl;
		cin >> s;
		Expression exp(s);
		if (exp.Format() == false)
		{
			cout << "输入错误(无法识别的符号)" << endl;
		}
		else if (exp.FormatCheck() == false)
		{
			cout << "输入错误(格式错误)" << endl;
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
			cout << "\n1.继续计算" << endl;
			cout << "2.返回上级菜单" << endl;
			fflush(stdin);
			cin >> menu;
		} while (menu != 1 && menu != 2);
	}
	system("cls");
	return 0;
}