#include <stdio.h>
#include <stdlib.h>

int main()
{
	int random=5+rand()%5;
	int *dyn=(int*)malloc(sizeof(int)*random);
	int *pop=(int*)malloc(sizeof(int));
	int *stack=(int*)malloc(sizeof(int)*random);
	int i=0,j=0;
	printf("Generated\tOperation\tStack\tSize\n");
	while(i<random)
	{
		int number =rand()%20;
		number=number*number;
		dyn[i]=number;
		printf("%d\t",dyn[i]);
		int k=i;
		if (dyn[i]>dyn[i-1])
		{
			printf("Pop \t");
			for (j = 0; j < i-1; ++j)
			{
				pop[j]=dyn[j];
				pop=(int*)realloc(pop,sizeof(int)*(i+1));
			}
			printf("\n");
			for (int f = 0; f < j; ++f)
			{
				printf("\tPushed %d\t",pop[f] );
				stack[f]=pop[f];
				for (int i = 0; i < f; ++i)
				{
					printf("%d,",stack[i] );
				}
				printf("\n");
			}
		}else{
				printf("\tPushed %d\t",dyn[i] );
				stack[j]=dyn[i];
				for (int i = 0; i < j; ++i)
				{
					printf("%d,",stack[i] );
				}
				printf("\n");
		}
		i++;

	}
	return 0;
}
