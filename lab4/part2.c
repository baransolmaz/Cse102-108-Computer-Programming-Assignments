#include <stdio.h>
int check_prime(int a);
int check_semi_prime(int a);
void generete_primes(int n1,int n2,int *nump,int *numsemp)
{
	*nump=0;
	*numsemp=0;
	for (int i=n1; i <=n2 ; ++i)
	{
		int k=check_prime(i);

		if (k == 1)
		{
			*nump+=1;
			printf("%d is prime\n",i );
		}else
		{
			int h =check_semi_prime(i);
			if (h==1)
			{
				*numsemp+=1;
				printf("%d is semi-prime\n",i );
			}
			
		}
	}

		
}


int main(int argc, char const *argv[])
{
	int n,m,nump,numsemp;
	printf("enter two number:\n");
	scanf("%d %d",&n,&m);

	generete_primes(n,m,&nump,&numsemp);
	
	printf("primes:%d\n",nump);
	printf("semi-primes:%d\n",numsemp);

	return 0;
}
int check_prime(int a)
{
	for (int i = 2; i < a; ++i)
	{
		if (a%i==0)
		{
		return 0;	
		}
	}
	return 1;
}
int check_semi_prime(int a)
{
		if (a%2==0)
		{
			a/=2;
		}else
			a/=3;
	
	for (int i = 2; i < a; ++i)
	{
		if (a%i==0)
		{
		return 0;	
		}
	}
	return 1;
}