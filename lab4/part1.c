#include <stdio.h>

int main(int argc, char const *argv[])
{
	int c;
	int a=1;
	char ch;
	int n,m;
	double toplam=0.0;
	FILE *fp;
	fp =fopen("integers.txt","r+");
	printf("enter two number:\n");
	scanf("%d%d",&n,&m);
	
	
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				fscanf(fp,"%d",&c);
				printf("%d ",c);
				toplam+=c;
			}
			while(a != 0)	
			{
				fscanf(fp,"%c",&ch);
				if (ch == '\n')
				{
					a=0;
				}
			}
			a=1;
		}
		printf("ort:%lf\n",toplam/(double)(n*m) );
	

	fclose(fp);

	return 0;
}