#include "Expression.hpp"

//求阶乘所用数组
int LargeNumberFactorial[1000]={0};

//利用数组求阶乘
//选用数组一方面避免了定义过多的变量，一方面还避免使用了嵌套
int cal_factorial(int theInt)
{
	LargeNumberFactorial[0]=1;
	LargeNumberFactorial[1]=1;
	int digit=1;
	for (int i=1;i<=theInt;i++)
	{
		for (int j=1;j<=digit;j++)
		{
			LargeNumberFactorial[j]*=i;
		}
		for (int j=1;j<=digit;j++)
		{
			if (LargeNumberFactorial[j]>10)
			{
				for (int k=1;k<=digit;k++)
				{
					if (LargeNumberFactorial[digit]>9)
					{
						digit++;
					}
					LargeNumberFactorial[k + 1]+=LargeNumberFactorial[k]/10;
					LargeNumberFactorial[k]%=10;
				}
			}
		}
	}
	int ans=0;
	for(int i=digit;i>0;i--){
		ans*=10;
		ans+=LargeNumberFactorial[i];
	}
	for(int i=0;i<=digit;i++){
		LargeNumberFactorial[i]=0;
	}
	return ans;
}