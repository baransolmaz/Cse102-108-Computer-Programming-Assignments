#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int number_length(int number)//Finds The Number of Digits
{
	int a = log10((double)number)+1;
	return a;
}
int find_digit(int number, int index)//Finds The Wanted Digit
{ 
	if (index==0)
	{
		return number%10;
	}
	double d =pow(10,(double)index);
	number=number/d;
	return number%10;
	
}
int main()//MAIN
{
	int num,nth,nth1,digit;

	printf("Enter a number(MAX 6 DIGITS):\n");//Actually, This program can calculate 10 digits but you want just 6 digits.
	scanf("%d",&num);
	int l=number_length(num);
	if (l>6)
	{
		printf("This number has more than 6 digits.\n");
	}else
	{

		
		printf("Your number has %d digits.\n",l);
		printf("When your number is written 100 times next to each other,which digits of this number would you like to see?\n");
		scanf("%d",&nth);
		nth1=l-(nth%l);
		if (nth1 == l)
		{
			nth1=0;
		}
		digit = find_digit(num,nth1);
		printf("%d.th digit of the big number sequance: %d\n",nth,digit);
	}
	return 0;
}
