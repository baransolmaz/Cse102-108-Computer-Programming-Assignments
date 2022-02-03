#include <stdio.h>

int sum(int n,int flag)//Prints and calculates the sum of numbers
{
	int sums=0;
	if (flag==0)//for evens
	{
		for (int i = 2; i <n-1  ; i +=2)
		{
			printf("%d + ", i );
			
			sums += i;
		}
		printf("%d = %d\n",n-(n%2),sums+n-(n%2) );
	}else//for odds
	{
		for (int i = 1; i <n-1 ; i+=2)
		{
			printf("%d + ", i );
			
			sums+= i;
		}
		printf("%d = %d\n",n-1-(n%2),sums+n-1-(n%2) );
	}
}
int mult(int n,int flag)//Prints and calculates the multiplication of numbers
{
	double mults=1;
	if (flag==0)//for evens
	{
		for (int i = 2; i <n-1 ; i +=2)
		{
			printf("%d * ", i );
			
			mults *=i;
		}
		printf("%d = %.1lf\n",n-(n%2),mults*(n-(n%2)) );
	}else//for odds
	{
		for (int i = 1; i <n-1 ; i +=2)
		{
			printf("%d * ", i );
			
			mults *=i;
		}
		printf("%d = %.1lf\n",n-1-(n%2),mults*(n-1-(n%2)) );
	}
}

int main()//MAIN//
{
	int n,choice,flag;
	printf("Enter a positive integer:\n");
	scanf("%d",&n);
	
	printf("Please enter '0' for sum,'1' for multiplication\n");
	scanf("%d",&choice);
	printf("Please enter '0'to work on even numbers,'1' to work on odd numbers\n");
	scanf("%d",&flag);
	if (flag== 0 || flag==1)//kind of boolean
	{
		switch(choice)
		{
			case 0:	sum(n,flag);
						break;
			case 1:	mult(n,flag);
						break;
			default : printf("Unsupported operation.\n");

		}
	}else
		printf("Invalid value for odd/even selection.\n");

	
	return 0;
}
