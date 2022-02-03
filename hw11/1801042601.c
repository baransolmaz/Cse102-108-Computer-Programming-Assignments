#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct liste
{
	int value;
	struct liste *next;
};
struct different
{ 
	int n1,n2;
};

void part1();

int* read_array(char *filename,int* dyn,int* counter);//Read as a Dynamic Array
void read_linkedlist(char *filename,struct liste* linked);//Read as a Linked List

float* stats_array(int counter,int* dyn,float* arr) ;//Calculates Stats of Dynamic Array
float* stats_linkedlist(struct liste linked,int counter,float* arr);//Calculates Stats of Linked List

void part2();
struct different* find_diff(int* dyn,struct liste linked,int counter,int* count_diff);//Finds the Different Values in Linked List and Dynamic Array

int main()
{
	printf("Part 1 :\n\n\n");
	part1();
	printf("\n\n\nPart 2 :\n\n\n");
	part2();
	return 0;
}
void part1()
{
	char file_name[]={"list.txt"};
	int counter;
	float *arr_stat=(float*)malloc(sizeof(float));
	float *link_stat=(float*)malloc(sizeof(float));
	struct liste *linked =(struct liste*)malloc(sizeof(struct liste));
	int *dyn=(int*)malloc(sizeof(int));
	double total_time_read=0,total_time_stats=0;
	clock_t start,mid,end;

	dyn=read_array(file_name,dyn,&counter);
	arr_stat=stats_array(counter,dyn,arr_stat);
	printf("Stats of Dynamic Array:\nUsed Bytes: %d\n\n",4*counter);
	printf("Min:%.1f  Max:%.1f  Mean: %.3f  Std: %.3f \n\n",arr_stat[0],arr_stat[1],arr_stat[2],arr_stat[3]);
	for (int i = 0; i < 5; ++i)
	{
		start = clock();
			dyn=read_array(file_name,dyn,&counter);
		mid = clock();
			arr_stat=stats_array(counter,dyn,arr_stat);
		end = clock();
		total_time_read+=(mid-start)/5;
		total_time_stats+=(end-mid)/5;
	}
	printf("Average Time of read_array(...) Function: %f \n\n",total_time_read/CLOCKS_PER_SEC);
	printf("Average Time of stats_array(...) Function: %f \n\n",total_time_stats/CLOCKS_PER_SEC);
	total_time_read=0;
	total_time_stats=0;
	read_linkedlist(file_name,linked);
	link_stat=stats_linkedlist(*linked,counter,link_stat);
	printf("Stats of Linked List:\nUsed Bytes: %d\n\n",counter*(4+4));
	printf("Min:%.1f  Max:%.1f  Mean: %.3f  Std: %.3f \n\n",link_stat[0],link_stat[1],link_stat[2],link_stat[3]);
	for (int i = 0; i < 5; ++i)
	{
		start = clock();
			read_linkedlist(file_name,linked);
		mid = clock();
			link_stat=stats_linkedlist(*linked,counter,link_stat);
		end = clock();
		total_time_read+=(mid-start)/5;
		total_time_stats+=(end-mid)/5;
	}
	printf("Average Time of read_linkedlist(...) Function: %f \n",total_time_read/CLOCKS_PER_SEC);
	printf("Average Time of stats_linkedlist(...) Function: %f \n\n",total_time_stats/CLOCKS_PER_SEC);
}
int* read_array(char *filename,int* dyn,int* counter)
{
	FILE *in=fopen(filename,"r");
	int number,count=0;
	while(fscanf(in,"%d,",&number)==1)
	{
		dyn = (int *)realloc(dyn,sizeof(int)*(count+1)); 
		dyn[count] = number;  
		count++;
	}
	dyn[count]=0;
	*counter=count;
	fclose(in);
	return dyn;
}
void read_linkedlist(char *filename,struct liste* linked)
{
	FILE *in=fopen(filename,"r");
	int number;
	struct liste *temp=linked;
	while(fscanf(in,"%d,",&number)==1)
	{
		temp->value=number;
		temp->next=(struct liste*)malloc(sizeof(struct liste));
		temp=temp->next;
	}
	temp->next=NULL;
	temp=linked;
	fclose(in);
}
float* stats_array(int counter,int* dyn,float* arr) 
{
	double std=0;
	arr = (float *)realloc(arr,sizeof(float)*4);
	arr[0]=dyn[0];//Min
	arr[1]=dyn[0];//Max
	arr[2]=0;//mean
	for (int i = 0; i < counter; ++i)
	{
	 	if (dyn[i]>arr[1]){arr[1]=dyn[i];}else if(dyn[i]<arr[0]) arr[0]=dyn[i];
		arr[2]+=dyn[i];//Sum
	}
	arr[2]/=counter;//Mean
	for (int i = 0; i < counter; ++i)
		std+=(arr[2]-(dyn[i]))*(arr[2]-(dyn[i]));
	arr[3]=sqrt(std/counter);//Std deviation
	return arr;
}
float* stats_linkedlist(struct liste linked,int counter,float* arr)
{
	double std=0;
	struct liste *temp=&linked;
	arr = (float *)realloc(arr,sizeof(float)*4);
	arr[0]=temp->value;//Min
	arr[1]=temp->value;//Max
	arr[2]=0;
	for (int i = 0; i < counter; ++i)
	{
		if (temp->value>arr[1]){arr[1]=temp->value;}else if (temp->value<arr[0]) arr[0]=temp->value;
		arr[2]+=temp->value;//Sum
		temp=temp->next;
	}
	arr[2]/=counter;//mean
	temp=&linked;
	for (int i = 0; i < counter; ++i)
	{
		std+=((arr[2]-(temp->value))*(arr[2]-(temp->value)));
		temp=temp->next;
	}
	arr[3]=sqrt(std/counter);//Std deviation
	return arr;
}
void part2()
{
	int counter=0,number,a=0,*dyn,*temp_dyn=NULL,count_diff=0;
	struct liste *linked =(struct liste*)malloc(sizeof(struct liste));
	struct liste *temp=linked;
	struct different *diff=(struct different*)malloc(sizeof(struct different));;
	printf("Dynamic Array:\n");
	printf("Press x for exit.\n");
	do
	{	
		printf("Enter a number: ");
		a=scanf("%d",&number);	     
		if (a==1){
			counter++;
			dyn = (int *)calloc(counter,sizeof(int)); 
			for (int i = 0; i < counter-1; ++i) dyn[i]=temp_dyn[i];
			dyn[counter-1] = number;  
			temp_dyn=dyn;
		} 
	}while(a==1);
	getchar();
	printf("Linked List:\n");
	while(a!=counter)
	{
		printf("Enter:");
		scanf("%d",&number);
		temp->value=number;
		temp->next=(struct liste*)malloc(sizeof(struct liste));
		temp=temp->next;
		a++;
	}
	temp->next=NULL;
	temp=linked;
	diff=find_diff(dyn,*linked,counter,&count_diff);
	for (int i = 0; i < count_diff; ++i)
		printf("Dynamic:%d   Linked List:%d\n",diff[i].n1,diff[i].n2 );
}
struct different* find_diff(int* dyn,struct liste linked,int counter,int* count_diff)
{
	struct different *diff=(struct different*)malloc(sizeof(struct different));;
	struct different *temp_diff=NULL;
	struct liste *temp=&linked;
	int count=0;
	for (int i = 0; i < counter; ++i)
	{
		if (dyn[i]!=temp->value)
		{
			count++;
			diff = (struct different*)calloc(counter,sizeof(struct different)); 
			for (int i = 0; i < count-1; ++i) diff[i]=temp_diff[i];
			diff[count-1].n1 = dyn[i];  
			diff[count-1].n2 = temp->value;  
			temp_diff=diff;
		}
		temp=temp->next;	
	}
	*count_diff=count;
	return diff;
}