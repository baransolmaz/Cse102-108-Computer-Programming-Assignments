#include <stdio.h>
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

int main(int argc, char const *argv[])
{
	char c;
	int a,N;
	printf("a. Is it prime or not\n");
	printf("b. Nth prime number:\n");
	scanf("%c",&c);

	switch(c)
		{
			case 'a':	printf("Enter a positive integer:\n");
						scanf("%d",&a);
						if (a>0)
						{
							int s =check_prime(a);
							if (s==1)
							{
								printf("%d is prime number.\n",a );
							}else
								printf("%d is not prime number.\n",a );

						}else
							printf("it is not positive\n");
						
						break;

			case 'b':	printf("Enter a positive integer for N:\n");
						scanf("%d",&N);
						int counter =1;
						
						
							for (int i=2; i < 997 && counter<=N; ++i)
							{
								int k =check_prime(i);	
								if (k==1)
								{
									printf("%d. prime number:%d \n",counter,i );
									counter++;

								}
							}
						break;
		}
	return 0;
}