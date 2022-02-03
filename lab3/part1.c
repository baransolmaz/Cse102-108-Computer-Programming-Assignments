#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a1,a2;
	printf("Enter first number:\n");
	scanf("%d",&a1);
	printf("Enter second number:\n");
	scanf("%d",&a2);
	for (int i = 1; i <= a2; ++i)
	{
		printf("%d * %d = %d\n",a1,i,a1*i );
	}
	return 0;
}