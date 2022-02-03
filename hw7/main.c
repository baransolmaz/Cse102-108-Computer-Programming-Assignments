#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void read_all_file(char all_text[2001][200]);
void cut_lines(char all_text[2001][200],char names_of_games[2000][100],char genres[12][20],char platforms[10][20],float arr[2000][7];);
int get_index(char arr[12][20], char* var,int k);
void list_genres(char genres[12][20]);
void list_platforms(char platforms[10][20]);
void games_through_years(char names_of_games[2000][100],float arr[2000][7]);
void all_information_of_single(char names_of_games[2000][100],char genres[12][20],char platforms[10][20],float arr[2000][7];);
void average_scores(float arr[2000][7]);
void geograpical_information_of_single(char names_of_games[2000][100],float arr[2000][7]);
void frequence_of_genres(char genres[12][20],float arr[2000][7]);
void frequence_of_platforms(char platforms[10][20],float arr[2000][7]);

void main()
{
	char all_text[2001][200],names_of_games[2000][100],genres[12][20],platforms[10][20];
	float arr[2000][7];//Contains all datas of games as a float number 
	int choice;

	read_all_file(all_text);
	cut_lines(all_text,names_of_games,genres,platforms,arr);
	do
	{
		printf("\n\n\n0:List of Genres\n");
		printf("1:List of Platforms\n");
		printf("2:List of The Games Through The Years\n");
		printf("3:All Information of a Single Game\n");
		printf("4:Average of The User Scores\n");
		printf("5:Geograpical Information of a Single Game\n");
		printf("6:Frequence of Genres\n");
		printf("7:Frequence of Platforms\n");
		printf("8:Exit\n");
		printf("\nPlease select an operation:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:		list_genres(genres);
						break;
			case 1:		list_platforms(platforms);
						break;
			case 2:		games_through_years(names_of_games,arr);
						break;
			case 3:		all_information_of_single(names_of_games,genres,platforms,arr); 
						break;
			case 4:		average_scores(arr);
						break;
			case 5:		geograpical_information_of_single(names_of_games,arr);
						break;
			case 6:		frequence_of_genres(genres,arr);
						break;
			case 7:		frequence_of_platforms(platforms,arr);
						break;
			case 8:		break;
			default:    printf("Try Again...\n");
		}		
	} while (choice!=8);
	printf("Program is closing...\n");	
}
void read_all_file(char all_text[2001][200])
{
	FILE *fp = fopen("Video_Games.txt","a+");
	for (int i = 0; i <2001; ++i)
	{
		fgets(all_text[i],200,fp);
	}
}
int get_index(char arr[15][20], char* var , int k)
{
	for (int i = k ; i>=0 ; --i)
	{
		if (strcmp(var,arr[i])==0)
			return i;
	}
	return -1;
}
void cut_lines(char all_text[2001][200],char names_of_games[2000][100],char genres[12][20],char platforms[10][20],float arr[2000][7])
{
	char *name,*genre,*platform,*data;
	int g,p,h=0,l=0;

	const char s[1]={' '};
	for (int i = 1; i < 2001; ++i)
	{
		name=strtok(all_text[i], s);
		strcpy(names_of_games[i-1],name);

		genre=strtok(NULL, s);
		g=get_index(genres,genre,h);
		if (g==-1)
		{
			strcpy(genres[h],genre);
			arr[i-1][0]=h;
			h+=1;
		}else
			arr[i-1][0]=g;

		platform=strtok(NULL,s);
		p=get_index(platforms,platform,l);
		if (p==-1)
		{
			strcpy(platforms[l],platform);
			arr[i-1][1]=l;
			l+=1;
		}else
			arr[i-1][1]=p;

		for (int t = 2; t < 7; ++t)
		{
			data=strtok(NULL,s);
			arr[i-1][t]=strtod(data,NULL);
		}	
	}
}
void list_genres(char genres[12][20])
{ 
	printf("\n\n\n");
	for (int i = 0; i < 12; ++i)
	{
		printf("%s\n",genres[i]);
	}
}
void list_platforms(char platforms[10][20])
{
	printf("\n\n\n");
	for (int i = 0; i < 10; ++i)
	{
		printf("%s\n",platforms[i]);
	}
}
void all_information_of_single(char names_of_games[2000][100],char genres[12][20],char platforms[10][20],float arr[2000][7])
{
	char s[100];
	int k=0;
	printf("\n\n\nPlease enter the name of the game:\n");
	scanf("%s",s);
	for (int i = 0; i < 2000; ++i)
	{
	 	if (strcmp(s,names_of_games[i])==0)
	 	{
	 		k=1;
	 		printf("\nName:\t%s\n",names_of_games[i] );
	 		printf("Genre:\t%s\n",genres[(int)arr[i][0]] );
	 		printf("Platform:\t%s\n",platforms[(int)arr[i][1]] );
	 		printf("Year:\t%d\n",(int)arr[i][2] );
	 		printf("Sales in NA:\t%.3lf\n",arr[i][3] );
	 		printf("Sales in EU:\t%.3lf\n",arr[i][4] );
	 		printf("Total Sales:\t");
	 		if (arr[i][5]==0)
	 		{
	 			printf("NOT AVAILABLE\n");
	 		}else
	 			printf("%.3lf\n", arr[i][5]);
	 		printf("User Score:\t%.3lf\n",arr[i][6]);
	 		break;
	 	}
	}
	if (k==0)
	{
		printf("Try AGAIN\n");
		all_information_of_single(names_of_games,genres,platforms,arr); 
	}
}
void games_through_years(char names_of_games[2000][100],float arr[2000][7])
{
	int year,time,k=0;
	printf("\n\n\nEnter a year:\n");
	scanf("%d",&year);
	printf("Until(0) or Since(1) %d :\n",year);
	scanf("%d",&time);

	switch(time)
		{
			case 0: for (int i = 0; i < 2000; ++i)
					{
						if (arr[i][2]<year)
						{
							printf("%s\n",names_of_games[i] );
							k=1;
						}
					}
					break;

			case 1: for (int i = 0; i < 2000; ++i)
					{
						if (arr[i][2]>year)
						{
							printf("%s\n",names_of_games[i] );
							k=1;
						}
					}
					break;
		}
	if (k==0)
	{
		printf("Try AGAIN\n");
		games_through_years(names_of_games,arr);
	}
}
void average_scores(float arr[2000][7])
{
	double scores=0;
	for (int i = 0; i < 2000; ++i)
	{
		scores+=arr[i][6];
	}
	printf("Average of User Scores :%.5lf\n",scores/2000 );
}
void geograpical_information_of_single(char names_of_games[2000][100],float arr[2000][7])
{
	char s[100];
	int k=0;
	printf("\n\nPlease enter the name of the game:\n");
	scanf("%s",s);
	for (int i = 0; i < 2000; ++i)
	{
		if (strcmp(s,names_of_games[i])==0)
		{
			k=1;
			if (arr[i][3]<arr[i][4])
			{
				printf("This game was more popular in Europe.\n");
			}else if (arr[i][3]>arr[i][4])
			{
				printf("This game was more popular in North America.\n");
			}else
				printf("This game had same popularity in North America and Europe.\n");
			break;
		}
	}
	if (k==0)
	{
		printf("Try AGAIN\n");
		geograpical_information_of_single(names_of_games,arr);
	}
}
void frequence_of_genres(char genres[12][20],float arr[2000][7])
{
	int count=0;
	for (int i = 0; i < 12; ++i)
	{
		for (int j = 0; j < 2000; ++j)
		{
			if (arr[j][0]==i)
				count+=1;
		}
		printf("%s \t %d\n",genres[i],count );
		count=0;
	}
}
void frequence_of_platforms(char platforms[10][20],float arr[2000][7])
{
	int count=0;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 2000; ++j)
		{
			if (arr[j][1]==i)
				count+=1;
		}
		printf("%s \t %d\n",platforms[i],count );
		count=0;
	}
}
