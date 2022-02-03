#include <stdio.h>
int is_percect(int number)
{ 
	int sum=0;

	for (int i = 1; i <=number/2; ++i)
	{
		if (number%i==0)
		{
			sum=sum+i;
		}
	}
	if (sum==number)
	{
		return 1;
	}else
		return 0;
}
int main()
{
	int number;
	printf("Enter a number:\n");
	scanf("%d",&number);
	int f =is_percect(number);
	
	if (f==1)
	{
		printf("%d is perfect number.\n",number );
	}else
		printf("%d is not a perfect number.\n",number );
	return 0;
}
