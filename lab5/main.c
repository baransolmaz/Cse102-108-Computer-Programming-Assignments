#include <stdio.h>
#include <math.h>


int bintodec (int binary);
int countdigits (int number);
int powerfunction(int base, int power); 
int bin2dec(long long num)
{
   if(num==0) return 0;
   return num%10+2*bin2dec(num/10);
}
int main()
{
	int bin;
	do{
		printf("Enter:\n");
		scanf("%d",&bin);
		if (bin>0)
		{
			printf("%d\n",bintodec(bin));
		}
	}while(bin>0);
	return 0;
}
int bintodec(int binary)
{
	int k;
	if (countdigits(binary)==1)
	{
		return binary;
	}
	k=binary/powerfunction(10,countdigits(binary)-1);
	k=k*powerfunction(2,countdigits(binary)-1);
	return k+bintodec(binary%powerfunction(10,countdigits(binary)-1));
}
int powerfunction(int base, int power)
{
	if (power==0)
	{
		return 1;
	}
	return base *powerfunction(base,power-1);

}
int countdigits (int number)
{
	if (number < 1)
	{
		return 0;
	}
	return 1 +countdigits(number/10);
}
