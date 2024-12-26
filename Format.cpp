#include "Expression.hpp"
#include <ctype.h>
using namespace std;
//�ж�����Ĳ������Ƿ�Ϸ�
char opt_set[11] = {"+-*/^()=.!"};

//����ȥ���ո񲢼���Ƿ��зǷ��ַ�
bool Expression::Format()
{
	string res;
	int len = theStr.length();
	for (int i = 0, j = 0; i < len; i++)
	{
		if (theStr[i] == ' ') //ȥ�ո�
		{
			len--;
			continue;
		}
		else if (isalpha(theStr[i]))
		{
			theStr[j] = tolower(theStr[i]); //ͳһ��Сд
			j++;
		}
		else j++;
	}
	for (int i = 0; i < theStr.length();)
	{
		bool opt_legal = false; //������Ƿ�Ϸ�
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
				len = theStr.length(); //�����ַ�������
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