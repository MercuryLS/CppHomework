#include "Expression.hpp"
#include <ctype.h>
using namespace std;
//判断输入的操作符是否合法
char opt_set[11] = {"+-*/^()=.!"};

//用于去除空格并检查是否有非法字符
bool Expression::Format()
{
	string res;
	int len = theStr.length();
	for (int i = 0, j = 0; i < len; i++)
	{
		if (theStr[i] == ' ') //去空格
		{
			len--;
			continue;
		}
		else if (isalpha(theStr[i]))
		{
			theStr[j] = tolower(theStr[i]); //统一成小写
			j++;
		}
		else j++;
	}
	for (int i = 0; i < theStr.length();)
	{
		bool opt_legal = false; //运算符是否合法
		for (int j = 0; j < 10; j++)
		{
			if (theStr[i] == opt_set[j])
			{
				opt_legal = true;
			}
		}
		if (opt_legal || isdigit(theStr[i]))
		{
			res += theStr[i];
			i++;
		}
		else if (isalpha(theStr[i]))
		{
			char check = checkRectangle(i);
			if (check)
			{
				res += check;
				len = theStr.length(); //更新字符串长度
				continue;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	theStr = res;
	return true;
}