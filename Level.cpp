#include "Expression.hpp"

int level(char theOpt)
{
	int l;
	if (theOpt=='(')
	{
		l=0;
	}
	if (theOpt=='+'||theOpt=='-')
	{
		l=1;
	}
	if (theOpt=='*'||theOpt=='/')
	{
		l=2;
	}
	if (theOpt=='^')
	{
		l=3;
	}
	if (isRectangle(theOpt))
	{
		l=4;
	}
	if (theOpt=='!')
	{
		l=5;
	}
	if (theOpt==')')
	{
		l=6;
	}
	return l;
}