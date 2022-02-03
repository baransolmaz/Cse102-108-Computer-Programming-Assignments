#include <stdio.h>

int find_length(int number);//Find the length of number
int is_binary(int number);//Checks the number that if it is binary or not

int andop(int a,int b)//Does "&" operation
{
		int k;
		if (a%10 == b%10 && a%10==1)
		{
				a=a/10;
				b=b/10;
				if (a ==0)
				{
					return 1;
				}
				k=andop(a,b);
				k= (k*10)+1;
			
		}else 
		{
			a/=10;
			b/=10;
			if (a ==0)
			{
				return 1;
			}
			k=andop(a,b);
			k*=10;
		}

		return k;

}
int main()//MAIN
{
	int exit=1;
	int result;
	int n1,n2,l1,l2,b1,b2;
	do
	{
		printf("First integer:");
		scanf("%d",&n1);
		printf("Second integer:");
		scanf("%d",&n2);

		l1=find_length(n1);
		b1=is_binary(n1);
		l2=find_length(n2);
		b2=is_binary(n2);

		if (l1 != l2)
		{
			printf("Integers should have the same length , please enter 2 new integer.\n");
			
		}else if (b1 == 0 || b2== 0 )
		{
			printf("Integers should be binary,please enter 2 new integer.\n");
			
		}else 
			exit=0;
		

	} while (exit == 1  );
	
	result = andop(n1,n2);
	printf("%d AND %d = %d\n",n1,n2,result );
	
}
int find_length(int number)//Finds the length of number
{
	int length=0 ;
	do
	{
		number/=10;
		length++;
	} while (number != 0);

	return length ;
}
int is_binary(int number)//Checks the number that if it is binary or not
{
	int f;
	if (number%10 <2 )
	{
		if (number == 0)
		{
			return 1;
		}
		f=is_binary(number/10);
		return f;

	}else 
		return 0;
}
