#include <stdio.h>
#include <math.h>
int fact(int number)
{
	int fac=1;
	for (int i = 1; i <=number; ++i)
	{
		fac=fac*i;
	}
	return fac;
}
int com(int m,int n)
{
	int fact_m,fact_n,fact_m_n;
	fact_m=fact(m);
	fact_n=fact(n);
	fact_m_n=fact(m-n);
	return (fact_m / fact_n)/fact_m_n;
}
int per(int m,int n)
{
	int fact_m,fact_m_n;
	fact_m=fact(m);
	fact_m_n=fact(m-n);
	return fact_m /fact_m_n;	
}

int main(int argc, char const *argv[])
{
	int a1,a2;
	printf("Enter first number:\n");
	scanf("%d",&a1);
	printf("Enter second number:\n");
	scanf("%d",&a2);
	if (a1>a2)
	{
		printf("C(%d,%d)=%d\n",a1,a2,com(a1,a2));
		printf("P(%d,%d)=%d\n",a1,a2,per(a1,a2));
	}else
	printf("This can not possible.\n");
	
	return 0;
}