#include "Expression.hpp"
#include <cmath>
bool Expression::compute()
{
	int theInt = 0;	 //�ݴ�����
	int state = OUT; //��ʼ״̬Ϊ��������
	char c;
	bool dot = false;
	double count = 1.0;
	int negative = 1;
	for (int i = 0; i < theStr.length(); i++)
	{
		c = theStr[i];
		if (isdigit(c) || c == '.')
		{
			if (isdigit(c))
			{
				theInt *= 10;
				theInt += c - '0';
				state = IN; //״̬Ϊ��������
				if (dot == true)
				{
					count *= 10.0;
				}
			}
			if (c == '.')
			{
				dot = true;
				continue;
			}
		}
		else
		{
			dot = false;
			double ans = theInt / count;
			count = 1.0;
			if (state == IN)
			{
				val.push(ans);
				theInt = 0;
				negative = 1;
			}
			double x, y;
			if (c != ' ')
			{
				if (char_in_string(c, "+-*/^"))
				{
					x = val.top();
					val.pop();
					y = val.top();
					val.pop();
					if (c == '+')
					{
						val.push(y + x);
					}
					else if (c == '-' && !(isdigit(theStr[i + 1]))) //���Ŷ����Ǹ���
					{
						val.push(y - x);
					}
					else if (c == '*')
					{
						val.push(y * x);
					}
					else if (c == '/')
					{
						if (x == 0)
						{
							cout << "��������Ϊ�㣡" << endl;
							return false;
						}
						else
							val.push(y / x);
					}
					else if (c == '^')
					{
						if (y < 0)
						{
							if (x - round(x) < 1e-8 && x - round(x) > -1e-8)
							{
								val.push(pow(y, round(x)));
							}
							else
							{
								cout << "�׳˳���������" << endl;
								return false;
							}
						}
						else
							val.push(pow(y, x));
					}
				}
				else if (isRectangle(c) || c == '!')
				{
					x = val.top();
					if (isRectangle(c))
					{
						double temp = ComputeRectangle(c, x);
						if (temp == NAN)
						{
							cout << "�����Ǻ�������������" << endl;
							return false;
						}
						else
							val.push(ComputeRectangle(c, x));
					}
					else if (c == '!')
					{
						if ((x - round(x) < 1e-8 && x - round(x) > -1e-8) && x >= 0)
							val.push(cal_factorial(round(x)));
						else
						{
							cout << "�׳˵���ӦΪ��������" << endl;
							return false;
						}
					}
					else
					{
						cout << "δ֪�Ĵ���!" << endl;
					}
				}
			}
			state = OUT;
		}
	}
	return true;
}

double ComputeRectangle(char c, double x)
{ //�������Ǻ���
	switch (c)
	{
	case SIN_OPT:
		return sin(x);
	case COS_OPT:
		return cos(x);
	case TAN_OPT:
		return tan(x);
	case ARCSIN_OPT:
		return asin(x);
	case ARCCOS_OPT:
		return acos(x);
	case ARCTAN_OPT:
		return atan(x);
	}
}