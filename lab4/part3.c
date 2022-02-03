#include <stdio.h>
int check_prime(int a);
int check_co_prime(int a);
int main()
{
	int n,k,nump,temp,numcopr,j=1;
	printf("enter a number:\n");
	scanf("%d",&n);
	printf("STEP -- VALUE -- NO PRIMES -- NO CO PRIMES\n");
	do
	{
		nump=0;
		temp=n;
		if (n%2==0)
		{
			for (int i = 2; i <=n; ++i)
			{
				k=check_prime(i);
				if (k==1)
				{
					nump+=1;
				}
			}
			numcopr= check_co_prime(n);
			n/=2;
			
		}else
		{
			for (int i = 2; i <=n; ++i)
			{
				k=check_prime(i);
				if (k==1)
				{
					nump+=1;
				}
			}
			numcopr= check_co_prime(n);
			n=(3*n)+1;
		}

		printf(" %d \t %d\t\t%d\t%d \n",j,temp,nump,numcopr);
		j+=1;
	}while(n != 1);
	printf(" %d \t 1\t\t0\t0 \n",j);
	return 0;
}
int check_prime(int a)
{
	for (int i = 2; i < a; ++i)
	{
		if (a%i==0  )
		{
		return 0;	
		}
	}
	return 1;
}
int check_co_prime(int a)
{
	int numcopr=0;
	for (int i = 2; i < a; ++i)
	{
		for (int j = 2; j <=i; ++j)
		{
			if (a%j==0 && i%j==0)
			{
				numcopr=numcopr;
			}else
				numcopr+=1;
		}
		
	}
	return numcopr;
}