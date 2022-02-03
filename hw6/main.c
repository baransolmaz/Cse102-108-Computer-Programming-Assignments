#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROWS 20
#define COLUMS 20

void print_hidden(char hidden[10][15]);//Prints The Hidden Words
void read_words(char words[100][15]);//Reads All Words From File
void print_screen();//Prints on Terminal
char rand_char();//Generates Random Character
void selection_hidden(char words[100][15],char hidden[10][15]);// Selects Randomly Hidden Words
void put_random(char tablo2[20][20]);//Puts Random Characters on The Empty Locations
void check_word(char hidden[10][15],char ans[15],int length);//Compares Inputted Word and Hidden Word,Then Makes Upper
int check_empty(int y,int x,int length,char tablo2[20][20],int yon);//Before Hiding,Checks The Locations to 

void hid_words(char hidden[10][15],char tablo2[20][20]);//Hides The Words -- Contains 4 Functions
	void hid_downup(int length,char hidden[15],char tablo2[20][20]);
	void hid_rightleft(int length,char hidden[15],char tablo2[20][20]);
	void hid_cross_sag(int length,char hidden[15],char tablo2[20][20]);
	void hid_cross_left(int length,char hidden[15],char tablo2[20][20]);
int check_winning(char hidden[10][15]);//Checks The Winning Situations

void checking(char ans[15],char tablo2[20][20],int y,int x,int length,char hidden[10][15]);//Checks All Directions--Contains 8 Functions
	void sag_alt_check(char ans[15],char tablo2[20][20],int y,int x,int length,char hidden[10][15]);
	void sag_ust_check(char ans[15],char tablo2[20][20],int y,int x,int length,char hidden[10][15]);
	void sol_alt_check(char ans[15],char tablo2[20][20],int y,int x,int length,char hidden[10][15]);
	void sol_ust_check(char ans[15],char tablo2[20][20],int y,int x,int length,char hidden[10][15]);
	void sag_yatay_check(char ans[15],char tablo2[20][20],int y,int x,int length,char hidden[10][15]);
	void sol_yatay_check(char ans[15],char tablo2[20][20],int y,int x,int length,char hidden[10][15]);
	void ust_dikey_check(char ans[15],char tablo2[20][20],int y,int x,int length,char hidden[10][15]);
	void alt_dikey_check(char ans[15],char tablo2[20][20],int y,int x,int length,char hidden[10][15]);

void main()
{
	int length,r,k=0,x,w;
	char y,words[100][15],hidden[10][15],tablo2[20][20],s[15];
	char exit[4]={"exit"};
	srand(time(0));
	memset(tablo2, 0, sizeof(tablo2[0][0]) * 20 * 20);
	read_words(words);
	selection_hidden(words,hidden);
	hid_words(hidden,tablo2);
	printf("1.) PLAY WITH RANDOM CHARACTER.\n2.) PLAY WITHOUT RANDOM CHARACTER.\nENTER:");
	scanf("%d",&r);
	if(r==1)
		{
			put_random(tablo2);
		}
	do
	{
		print_hidden(hidden);
		print_screen(tablo2);
		printf("Position of First Letter:");
		scanf(" %c%d",&y,&x);
		printf("WORD(enter -exit- for exit):");
		scanf("%s",s);
		if (strncmp(s,exit,4)==0)
		{
			w=2;
		}else
		{
			length=strlen(s);
			checking(s,tablo2,y-'a',x,length,hidden);
			w =check_winning(hidden);
		}
	}while(w==0);
	if (w==1)
	{
		printf("YOU WON . CONGRATULATIONS...\n");
	}else
		printf("GAME IS CLOSING...\n");
}
char rand_char()
{
 	char randomletter = 'a' + (rand() % 26);
	 return randomletter;
}
void print_screen(char tablo2[20][20])
{
	printf("  ");
	for (int i = 0; i < 10; ++i)
	{
		printf(" %d",i);
	}
	for (int i = 10; i < ROWS; ++i)
	{
		printf("%d",i);
	}
	printf("\n ");
	for (int i = 0; i < 42; ++i)
	{
		printf("_");
	}
	printf("\n");
	for (int i = 0; i < COLUMS; ++i)
	{
		printf("%c|",i+'a');
		for (int j = 0; j < ROWS; ++j)
		{
			if ('A' > tablo2[i][j] || 'z'< tablo2[i][j])
			{
				tablo2[i][j]=' ';
			}
			printf(" %c",tablo2[i][j]);
		}
		printf(" |\n");
	}
	printf(" |");
	for (int i = 0; i <41; ++i)
	{
		printf("_");
	}
	printf("|\n");
}
void read_words(char words[100][15])
{
	FILE *fp = fopen("words.txt","a+");
	for (int i = 0; i <100; ++i)
	{
		fgets(words[i],15,fp);
	}
}
void print_hidden(char hidden[10][15])
{
	printf("Hidden words:\n");
	for (int i = 0; i < 10; ++i)
	{
		printf("%s",hidden[i] );
	}
}
void selection_hidden(char words[100][15],char hidden[10][15])
{
	int length;
	for (int i = 0; i < 10; ++i)
	{	
		int r=rand()%100;
		strcpy(hidden[i],words[r]);
	}
}
void hid_words(char hidden[10][15],char tablo2[20][20])
{
	int i=0,r=0,length,k;
	for (int i = 0; i < 10; ++i)
	{
		length=strlen(hidden[i]);
		k=rand()%4;
		if(k==0)
		{
			hid_downup(length-2,hidden[i],tablo2);
		}else if(k==1)
		{
			hid_rightleft(length-2,hidden[i],tablo2);
		}else if (k==2)
		{
			hid_cross_sag(length-2,hidden[i],tablo2);
		}else
			hid_cross_left(length-2,hidden[i],tablo2);
	}
}
void hid_downup(int length,char hidden[15],char tablo2[20][20])
{
	int x,y,z=0,k;
	do
	{
		x=rand()%20;
		y=rand()%20;
		k=check_empty(y,x,length,tablo2,1);
	}while(k==1);
	if (length>=y)
	{
		for (int i = y; i <y+length; ++i)
		{	
			tablo2[i][x]=hidden[z];
			z+=1;
		}
	}else
		for (int i = y; i>y-length; --i)
		{
			tablo2[i][x]=hidden[z];
			z+=1;
		}
}
void hid_rightleft(int length,char hidden[15],char tablo2[20][20])
{
	int x,y,z=0,k;
	do
	{
		x=rand()%20;
		y=rand()%20;
		k=check_empty(y,x,length,tablo2,2);
	}while(k==1);
	if (length>=x)
	{
		for (int i = x; i <x+length; ++i)
		{
			tablo2[y][i]=hidden[z];
			z+=1;
		}
	}else
		for (int i = x; i>x-length; --i)
		{
			tablo2[y][i]=hidden[z];
			z+=1;
		}
}
void hid_cross_left(int length,char hidden[15],char tablo2[20][20])
{
	int x,y,z=0,k;
	do
	{
		x=rand()%20;
		y=rand()%20;
		k=check_empty(y,x,length,tablo2,3);
	}while(k==1);
	if (x+length<=20 && y+length<=20)//sag alt
	{
		for (int i = x; i <x+length; ++i)
		{
			tablo2[y][i]=hidden[z];
			z+=1;
			y+=1;
		}
	}else if (x-length>=0 && y-length>=0)//sol ust
	{
		for (int i = x; i > x-length; --i)
			{
				tablo2[y][i]=hidden[z];
				z+=1;
				y-=1;
			}
	}else
		hid_cross_sag(length,hidden,tablo2);	
}
void hid_cross_sag(int length,char hidden[15],char tablo2[20][20])
{
	int x,y,z=0,k;
	do
	{
		x=rand()%20;
		y=rand()%20;
		k=check_empty(y,x,length,tablo2,4);
	}while(k==1);
	if ((x-length>=0 && y+length<=20))//sol alt
	{
		for (int i = x; i >x-length; --i)
			{	
				tablo2[y][i]=hidden[z];
				z+=1;
				y+=1;
			}
	}else if((x+length<=20 && y-length>=0))//sag ust
	{
		for (int i = x; i < x+length; ++i)//sag ust
			{
				tablo2[y][i]=hidden[z];
				z+=1;
				y-=1;
			}
	}else
		hid_cross_left(length,hidden,tablo2);
}
int check_empty(int y,int x,int length,char tablo2[20][20],int yon)
{
	switch(yon)
	{
		case 1:	if (length>=y)
				{
					for (int i = y; i <y+length; ++i)
					{	
						if(tablo2[i][x]>='a' &&  tablo2[i][x]<='z')
							return 1;
					}
				}else
				{
					for (int i = y; i>y-length; --i)
					{
						if(tablo2[i][x]>='a' &&  tablo2[i][x]<='z')
							return 1;
					}
				}
				return 0;

		case 2: if (length>=x)
				{
					for (int i = x; i <x+length; ++i)
					{
						if(tablo2[y][i]>='a' &&  tablo2[y][i]<='z')
							return 1;
					}
				}else
				{
					for (int i = x; i>x-length; --i)
					{
						if(tablo2[y][i]>='a' &&  tablo2[y][i]<='z')
							return 1;
					}
				}
				return 0;

		case 3:	if (x+length<=20 && y+length<=20)//sag alt
				{
					for (int i = x; i <x+length && y<=20 && x<=20; ++i)
					{
						if(tablo2[y][i]>='a' &&  tablo2[y][i]<='z')
							return 1;	
						y+=1;
					}
					return 0;
				}else if (x-length>=0 && y-length>=0)//sol ust
				{
					for (int i = x; i > x-length && y>=0 && x>=0; --i)
					{
						if(tablo2[y][i]>='a' &&  tablo2[y][i]<='z')
							return 1;	
						y-=1;
					}
					return 0;
				}else
					return 0;

		case 4:	if (x-length>=0 && y+length<=20)//sol alt
				{
					for (int i = x; i >x-length && y<=20 && x>=0; --i)
						{	
							if(tablo2[y][i]>='a' &&  tablo2[y][i]<='z')
								return 1;	
							y+=1;
						}
						return 0;
				}else if(x+length<=20 && y-length>=0)//sag ust
				{
					for (int i = x; i < x+length && y >=0 && x <=20; ++i)//sag ust
						{
							if(tablo2[y][i]>='a' &&  tablo2[y][i]<='z')
								return 1;	
							y-=1;
						}
						return 0;
				}else
					return 0;
	}
}
void put_random(char tablo2[20][20])
{
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if (tablo2[i][j] == '\0')
				tablo2[i][j]=rand_char() ;
		}
	}
}
void check_word(char hidden[10][15],char ans[15],int length)
{
	for (int i = 0; i < 10; ++i)
	{
		if (strncmp(ans,hidden[i],length)==0)
		{
			int c = 0;
			while (c!=length) 
			{
			   hidden[i][c] = hidden[i][c] - 32; //makes lowercase to uppercase
				    c++;  
		  	}
		}
	}
}
void checking(char ans[15],char tablo2[20][20],int y,int x,int length,char hidden[10][15])
{	
	sag_ust_check(ans,tablo2,y,x,length,hidden);
	sol_ust_check(ans,tablo2,y,x,length,hidden);
	sol_alt_check(ans,tablo2,y,x,length,hidden);
	sag_yatay_check(ans,tablo2,y,x,length,hidden);
	sol_yatay_check(ans,tablo2,y,x,length,hidden);
	ust_dikey_check(ans,tablo2,y,x,length,hidden);
	alt_dikey_check(ans,tablo2,y,x,length,hidden);
	sag_alt_check(ans,tablo2,y,x,length,hidden);
}
void sag_alt_check(char ans[15],char tablo2[20][20],int y,int x,int length,char hidden[10][15])
{
	int i;
	char arr[length];
	for (i = 0; i <length && x+i<=20 && y+i<=20; ++i)
	{
		arr[i]=tablo2[y+i][x+i];
	}
	if (i == length)
	 	if (strncmp(ans,arr,length)==0){
			check_word(hidden,ans,length);
			for (int i = 0; i < length; ++i)
					tablo2[y+i][x+i]-=32;								
	 	}
}
void sag_ust_check(char ans[15],char tablo2[20][20],int y,int x,int length,char hidden[10][15])
{
	int i;
	char arr[length];
	for (i = 0; i <length && x+i<=20 && y-i>=0 ; ++i)
	{
		arr[i]=tablo2[y-i][x+i];
	}
	if (i == length)
	 	if (strncmp(ans,arr,length)==0){
			check_word(hidden,ans,length);	
			for (int i = 0; i < length; ++i)
					tablo2[y-i][x+i]-=32;	
	 	}
}
void sol_alt_check(char ans[15],char tablo2[20][20],int y,int x,int length,char hidden[10][15])
{
	int i;
	char arr[length];
	for (i = 0; i <length && x-i>=0 && y+i<=20; ++i)
	{
		arr[i]=tablo2[y+i][x-i];
	}
	if (i == length)
		if (strncmp(ans,arr,length)==0){
			check_word(hidden,ans,length);	
			for (int i = 0; i < length; ++i)
					tablo2[y+i][x-i]-=32;	
		}
}
void sol_ust_check(char ans[15],char tablo2[20][20],int y,int x,int length,char hidden[10][15])
{
	int i;
	char arr[length];
	for (i = 0; i <length && x-i>=0 && y-i>=0; ++i)
	{
		arr[i]=tablo2[y-i][x-i];
	}
	if (i == length)
	 	if (strncmp(ans,arr,length)==0){
			check_word(hidden,ans,length);
			for (int i = 0; i < length; ++i)
					tablo2[y-i][x-i]-=32;		
	 	}
}
void sag_yatay_check(char ans[15],char tablo2[20][20],int y,int x,int length,char hidden[10][15])
{
	int i;
	char arr[length];
	for (i = 0; i < length && x+i<=20; ++i)
	{
		arr[i]=tablo2[y][x+i];
	}
	if (i == length)
	 	if (strncmp(ans,arr,length)==0){
			check_word(hidden,ans,length);
			for (int i = 0; i < length; ++i)
					tablo2[y][x+i]-=32;	
	 	}
}
void sol_yatay_check(char ans[15],char tablo2[20][20],int y,int x,int length,char hidden[10][15])
{
	int i;
	char arr[length];
	for (i = 0; i <length && x-i>=0; ++i)
	{
		arr[i]=tablo2[y][x-i];
	}
	if (i == length)
	 	if (strncmp(ans,arr,length)==0){
			check_word(hidden,ans,length);
			for (int i = 0; i < length; ++i)
				tablo2[y][x-i]-=32;		
	 	}
}
void ust_dikey_check(char ans[15],char tablo2[20][20],int y,int x,int length,char hidden[10][15])
{
	int i;
	char arr[length];
	for (i = 0; i <length && y-i>=0; ++i)
	{
		arr[i]=tablo2[y-i][x];
	}
	if (i == length)
	 	if (strncmp(ans,arr,length)==0){
			check_word(hidden,ans,length);
			 for (int i = 0; i < length; ++i)
					tablo2[y-i][x]-=32;		
	 	}
}
void alt_dikey_check(char ans[15],char tablo2[20][20],int y,int x,int length,char hidden[10][15])
{
	int i;
	char arr[length];
	for (i = 0; i <length && y+i<=20; ++i)
	{
		arr[i]=tablo2[y+i][x];
	}
	if (i == length)
	 	if (strncmp(ans,arr,length)==0){
			check_word(hidden,ans,length);	
			for (int i = 0; i < length; ++i)
					tablo2[y+1][x]-=32;	
	 	}
}
int check_winning(char hidden[10][15])
{
	int length;
	for (int i = 0; i < 10; ++i)
	{
		length=strlen(hidden[i]);
		for (int j = 0; j < length-2; ++j)
		{
			if (hidden[i][j] >'Z')
				return 0;
		}
	}
	return 1;
}
