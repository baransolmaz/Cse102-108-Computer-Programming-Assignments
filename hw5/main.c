#include <stdio.h>

void menu();
void read_news(char buffer[500],char file_path[10],int is_Only_Title);
void append_file(char* file_path, char c);
void read_magic_numbers(char buffer_magic[10], char buffer_news[500]);
double g_func(double f(int x), int a);
double f_func(int x);
//EXTRAS//
void yes_no(char* cont);//Checks The User if The User Wants to Continue or Stop
void option_a(int news);//Contains All The Functions that Needed in Optioan A
void choose_news(int* news);//Selection of Wanted News
void choose_magic(char buffer[500]);//Selection of Decrypted News
int check_readed(int* news,int k);//Checks The Wanted News that Readed or Not 

int main()//MAIN//
{
	menu();
	return 0;
}
void menu()
{
	int news;
	char choice,cont,buffer[500];
	
	printf("\n\n*************** DAILY PRESS ***************\n\n");
	printf("Today's news are listed for you: \n\n");
	printf("Title of 1. news :");	
		read_news(buffer,"news/1.txt",1);
	printf("Title of 2. news :");
		read_news(buffer,"news/2.txt",1);
	printf("Title of 3. news :");
		read_news(buffer,"news/3.txt",1);
	printf("Title of 4. news :");
		read_news(buffer,"news/4.txt",1);
	do
	{
		printf("\nWhat do you want to do? \n\n");

		printf("a.Read a new\n");
		printf("b.List the readed news\n");
		printf("c.Get decrypted information from news\n");
		scanf("\n%c",&choice);

		switch(choice)
		{
			case 'a':	option_a(news);//read_news ++ append_file
						break;

			case 'b':	append_file("readed_news_id.txt",'b');
						break;

			case 'c':	choose_magic(buffer);
						break;
			
			default :printf("\nWrong input. Try again.\n");
		}

		yes_no(&cont);

	}while(cont != 'n');
	printf("Good Bye!\n");
}
void read_news(char buffer[500],char file_path[10],int is_Only_Title)
{
	FILE *file;
	file=fopen(file_path,"r+");
	char ch,k;
	int i=0;
	buffer[0]='\0';
	if (is_Only_Title==1)//Reads Just Title
	{
		while(buffer[i] !='\n')
	    {
	    	fscanf(file,"%c",&buffer[i]);
	    	printf("%c",buffer[i]);
	    }	
	}else//Reads All The Text
	{	
		while(!feof(file))
	    {
	    	fscanf(file,"%c",&buffer[i]);
	       	i++;
	    }
    	buffer[i-1]='\0';
		printf("%s",buffer);
    }
	fclose(file);	
}
void option_a(int news)
{
	char buffer[500];
	choose_news(&news);
	switch(news)
	{
		case 1:	append_file("1.txt",'a');
				read_news(buffer,"news/1.txt",0);
				break;

		case 2:	append_file("2.txt",'a');
				read_news(buffer,"news/2.txt",0);
				break;

		case 3:	append_file("3.txt",'a');
				read_news(buffer,"news/3.txt",0);
				break;

		case 4:	append_file("4.txt",'a');
				read_news(buffer,"news/4.txt",0);
				break;
	}
}
void choose_news(int* news)
{
	int ch;
	do
	{
		printf("Which news do you want to read:");
		scanf("%d",&*news);
		int s =check_readed(&*news,1);
		if (s==2)
			*news=5;
	}while(*news >4);
	printf("\n");
}
int check_readed(int* news,int k)
{
	int ch=0,i;
	FILE *file=fopen("readed_news_id.txt","a+");

	while( !feof(file) )
	{
		fscanf(file,"%d",&ch);
		if(ch == *news )
		{
			if (k==1)
			{
				printf("\nThis new is readed. Do you want to read again?Yes(1)/No(0)\n");
				scanf("%d",&i);
				if (i==0)
				{
					return 2;
				}
				k=2;
			}else
				return 1;

		}
	}
	return 0;
}
void append_file(char* file_path, char c)
{
	int ch,s;
	FILE *file=fopen("readed_news_id.txt","a+");
	int rez= *file_path-'0';
	s=check_readed(&rez,0);
	switch(c)
	{
		case 'a':	if(s==0)
						fprintf(file,"%d\n",rez);
					break;

		case 'b':	printf("\nReaded news are listed below:\n");
					while( !feof(file) )
					{
						if(fscanf(file,"%d",&ch)==1)
						{
							printf("%d",ch);
							printf(". new is readed.\n");
						}
					}
					break;
	}
	fclose(file);
}
double f_func(int x)
{
	double a1,a2;
	a1=x*x*x;
	a2=x*x;
		return a1-a2+2;
}
double g_func(double f(int x), int a)
{
	return f(a)*f(a);
}
void read_magic_numbers(char buffer_magic[10], char buffer_news[500])
{
	char ch;
	int j=0;
	double f=0.0;
	for (int i = 0; i < 500; ++i)
	{
		int x=buffer_news[i];
		if (x=='#' && x!='\0')
		{
			buffer_magic[j]=buffer_news[i+1];
			j+=1;
		}
	}
	for (int a = 0; a < j; ++a)
	{
		f+=g_func(f_func,buffer_magic[a]-'0');
	}
	buffer_magic[0]='\0';
	printf("%.3lf\n",f);
}
void yes_no(char* cont)
{
	printf("\n\nDo you want to continue?Yes(y)/No(n)\n");
	scanf("\n%c",&*cont);
}
void choose_magic(char buffer[500])
{
	int decrypt;
	char buffer_magic[10];
	do
	{
		printf("Which news would you like to decrypt?:");
		scanf("%d",&decrypt);
		switch(decrypt)
		{
			case 1:	read_news(buffer,"news/1.txt",0);
					printf("\n\nThe number of tests performed:");
					read_magic_numbers(buffer_magic,buffer);
					break;

			case 2:	read_news(buffer,"news/2.txt",0);
					printf("\n\nThe number of sick people:");
					read_magic_numbers(buffer_magic,buffer);
					break;

			case 3:	read_news(buffer,"news/3.txt",0);
					printf("\n\nThe number of deaths:");
					read_magic_numbers(buffer_magic,buffer);
					break;

			case 4:	read_news(buffer,"news/4.txt",0);
					printf("\n\nThe expected number of sick people:");
					read_magic_numbers(buffer_magic,buffer);
					break;

			default: printf("Wrong input.Try again.\n");
		}
	}while(decrypt >4);
}