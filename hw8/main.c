#include <stdio.h>
#include <string.h>
#include <math.h>

void menu();

void part1();
void generate_hofstadters_sequence (int *arr, int n);
int find_max (int arr[], int index, int max_value);
int sum_array (int arr[]);
double std_array (int arr[], double *mean, int n, int index);

void part2();
void install_pipes (int visited[8][8], int x, int y, int orientation,int counter);
int check_loc(int visited[8][8],int x,int y);
void orientation1(int* x,int*y);
void orientation2(int* x,int*y);
void orientation3(int* x,int*y);
void orientation4(int* x,int*y);
void orientation5(int* x,int*y);
void orientation6(int* x,int*y);
void orientation7(int* x,int*y);
void orientation8(int* x,int*y);
int winning(int visited[8][8]);

void part3();
char* remove_duplicates (char* str);

void main()
{
	menu();	
}
void menu()
{
	int part,exit=0;
	printf("  WELCOME TO HOMEWORK-8 , Please Choose One Of The Parts To Continue\n");
	printf("----------------------------------------------------------------------\n\n");
	do
	{
		printf("\n");
		printf("1) Execute Part-1\n");
		printf("2) Execute Part-2\n");
		printf("3) Execute Part-3\n");
		printf("4) Exit\n");
		printf("Which Part Will You Execute:\n");
		scanf("%d",&part);
		switch(part)
			{
				case 1:part1();
						break;
				case 2:part2();
						break;
				case 3:part3();
						break;
				case 4:exit=1;
						break;
				default : printf("TRY AGAIN...\n");
			}
	}while(exit==0);
}
void part1()
{
	int exit=0,choice,arr[500],index,sum,max=0,n=1;
	double std,mean=0;
	memset(arr,0,500);
	do
	{
		printf("\n\n Please Make Your Choice\n");
		printf("-------------------------\n");
		printf("1-Fill The Array\n");
		printf("2-Find The Biggest Number in The Array\n");
		printf("3-Calculate The Sum\n");
		printf("4-Calculate Standart Deviation\n");
		printf("5-EXIT\n");
		printf("Enter Your Choice:\n");
		scanf("%d",&choice);
		switch(choice)
			{
				case 1:	printf("Enter an Index:\n");
						scanf("%d",&index);
						generate_hofstadters_sequence (arr,index);
						printf("Array has been filled.\n\n");
						break;
				case 2:	max=find_max (arr,index,max);
						printf("Maximum Variable in The Filled Array: %d\n\n",max);
						break;
				case 3:	sum=sum_array(arr+1);
						printf("Sum of The Filled Array: %d\n\n",sum);
						break;
				case 4:	std=std_array (arr,&mean,1,index);
						printf("\nMean Value: %lf \nStandart Deviation: %lf\n\n",mean,sqrt(std/(index-1)));
						break;
				case 5:	exit=1;
						break;
				default : printf("TRY AGAIN...\n\n");
			}
	}while(exit==0);
}
void generate_hofstadters_sequence (int *arr, int n)
{
	if (n==1)
	{
		arr[n]=1;
	}else{
		generate_hofstadters_sequence(arr,n-1);
		arr[n]=arr[n-arr[n-1]]+arr[n-arr[n-2]];//Formula of Hofstadters Q-Sequence
	}
}
int find_max (int arr[], int index, int max_value)
{
	if (index==0)
	{
		return max_value;
	}else if (arr[index]>max_value)
	{
		max_value=arr[index];
	}
	max_value=find_max(arr,index-1,max_value);
	return max_value;
}
int sum_array (int arr[])
{
	int sum;
	if (*arr==0)
	{
		return 0;
	}else{
		sum=*arr+sum_array(arr+1);
		return sum;
	}
}
double std_array (int arr[], double *mean,int n,int index)
{
	double k=0;
	*mean+=arr[n];
	if (index==1)
	{
		*mean/=n;
		return (*mean-arr[index])*(*mean-arr[index]);
	}else
		k=std_array(arr,&*mean,n+1,index-1)+(*mean-arr[index])*(*mean-arr[index]);
	return k;
}
void part2()
{
	int visited[8][8];
	int x=0,y=0,orientation=0,counter=0;
	memset(visited,0,sizeof(visited[0][0])*8*8);
	install_pipes(visited,x,y,orientation,counter+1);
}
void install_pipes (int visited[8][8], int x, int y, int orientation,int counter)
{
	int s=0;
	visited[x][y]=1;
	if(counter==10)
	{
		visited[x][y] = 0;
		return;
	}else
	{
		for(int i=1;i<=8 && s ==0 ;++i)
		{
			int firstx=x,firsty=y;
			switch(i)
				{
					case 1: orientation1(&firstx,&firsty);
								break;
					case 2: orientation2(&firstx,&firsty);
								break;
					case 3: orientation3(&firstx,&firsty);
								break;
					case 4: orientation4(&firstx,&firsty);
								break;
					case 5: orientation5(&firstx,&firsty);
								break;
					case 6:	orientation6(&firstx,&firsty);
								break;
					case 7: orientation7(&firstx,&firsty);
								break;
					case 8: orientation1(&firstx,&firsty);
								break;
				}
			if(check_loc(visited,firstx,firsty)==0 )
			{
				install_pipes(visited,firstx,firsty,i,counter);
			}
			if (winning(visited)==1){
				printf("O%d\n",i);
				counter+=1;
				s=1;
				visited[x][y] = 0;
				return;
			}
		}
		visited[x][y] = 0; 
	}
}
int check_loc(int visited[8][8],int x,int y)
{
	if (visited[x][y]==0 && x>=0 && x<=7 && y>=0 && y<=7)
	{
		return 0;
	}else
		return 1;
}
void orientation1(int* x,int*y)
{
	*x+=2;
	*y+=1;
}
void orientation2(int* x,int*y)
{
	*x+=1;
	*y-=2;
}
void orientation3(int* x,int*y)
{
	*x+=2;
	*y-=1;
}
void orientation4(int* x,int*y)
{
	*x-=1;
	*y+=2;
}
void orientation5(int* x,int*y)
{
	*x+=1;
	*y+=2;
}
void orientation6(int* x,int*y)
{
	*x+=2;
	*y-=1;
}
void orientation7(int* x,int*y)
{
	*x-=1;
	*y-=2;
}
void orientation8(int* x,int*y)
{
	*x-=2;
	*y+=1;
}
int winning(int visited[8][8])
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (visited[i][j]==0)
			{
				return 0;
			}
		}
	}
	return 1;
}
void part3()
{
	char str[200];
	printf("Enter String(max 200 char):\n");
 	scanf(" %[^\n]",str); 
	printf("The String Without Duplicated Characters:\n\n%s\n",remove_duplicates(str));
}
char *remove_duplicates (char *str)
{
	int i=0;
	if (*str=='\n')
	{
		return str;
	}else if (*str==*(str+1))//sıradaki karakterle aynıysa,
    {
       	while(str[i]!='\n')//'\n' karakterine kadar 
		{
			str[i]=str[i+1];//bir önceki karaktere taşı
			i+=1;
		}
    	remove_duplicates(str);
    }else
    	remove_duplicates(str+1);
    return str;
}