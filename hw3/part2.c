#include <stdio.h>
#include <math.h>
int isprime (int a) /*Checks the number that is prime or not ; if not, returns the number that 
divides this number*/
{
	for (int i = 2; i < a && i <= sqrt((double)a); ++i)
	{
		if (a%i==0)
		{
			return i;	
		}
	}

	return 1;
}

int main()//MAIN//
{
	int a,flag;
	printf("Enter a positive integer:\n");
	scanf("%d",&a);
	
	for (int i = 2; i < a; ++i)
	{
		flag = isprime(i);
		if (flag== 1 )
		{
			printf("%d is a prime.\n",i );
		}else
			printf("%d is not a prime.It is divisible by %d.\n",i,flag);

	}

	
	return 0;
}