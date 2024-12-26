#include "Expression.hpp"
//中缀转后缀
bool Expression::change()
{
	int state = OUT;
	char c;
	string to="";//暂存后缀表达式
	for (int i = 0; i < theStr.length(); i++)
	{
		c = theStr[i];
		if (isdigit(c))
		{
			to = to + c;
			state = IN;
		}
		else
		{
			if (state == IN && c == '.')
			{
				to = to + '.';
				continue;
			}
			if (state == IN && c != '.')
			{
				to += ' ';
			}
			if (c == '(')
			{
				opt.push(c);
			}
			else if (c == ')')
			{
				while (!opt.empty() && opt.top() != '(')
				{
					to += opt.top();
					to += ' ';
					opt.pop();
				}
				opt.pop();
			}
			else
			{
				while (true)
				{
					if (opt.empty() || opt.top() == '(')
					{
						opt.push(c);
					}
					else if (level(c) > level(opt.top()))
					{
						opt.push(c);
					}
					else
					{
						to += opt.top();
						to += ' ';
						opt.pop();
						continue;
					}
					break;
				}
			}
			state = OUT;
		}
	}
	while (!opt.empty())
	{
		to += opt.top();
		to += ' ';
		opt.pop();
	}
	theStr=to;
	return true;
}