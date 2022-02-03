#include <stdio.h>
#include <string.h>
#include <stdlib.h>// for rand() and abs() function
#include <time.h>// for srand() function
#define Total_hosp 4

struct card {
	char *face;
	char *suit;
};
struct Hospital
{
	char *name;
	char citiesServed[3];
};

void menu();

void part1();
int numPathsHome(int street, int avenue);

void part2();
int canOfferCovidCoverage(char _cities[6], char _locations[4][3], int _numHospitals, struct Hospital results[4]);
int check_loc(char _cities[6],struct Hospital results[4]);

void part3();
void main()
{
	menu();
	srand(time(0));	//for randomly shuffling
}

void menu()
{
	int part,exit=0;
	printf("  WELCOME TO HOMEWORK-9 , Please Choose One Of The Parts To Continue\n");
	printf("----------------------------------------------------------------------\n");
		do{
			printf("1) Stay Home Problem \n");
			printf("2) COVID-19 Health Coverage\n");
			printf("3) Shuffled Deck\n");
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
	int avenue,street;
	printf("Your home at (1,1) point.\n");
	printf("Enter the street number: ");
	scanf("%d",&street);
	printf("Street:%d\n",street);
	printf("Enter the avenue number: ");
	scanf("%d",&avenue);
	printf("Avenue:%d\n",avenue);
	printf("Number of Paths to (1,1) point: %d\n\n\n",numPathsHome(street,avenue));
}
int numPathsHome(int street, int avenue)
{//this function takes two inputs from main so there is limited way to make this function recursive so this is the basic way
	int num1,num2;
	if (avenue==1 || street ==1)//if one of them equals to 1 ,that means You are in the same street or avenue so there is only one path returns 1.
	{
		return 1;
	}else{
		num1=numPathsHome(street,avenue-1);/*firstly, decreases until your avenue comes to first avenue. 
		When it came ,you have only one path to home so returns 1 to outter function */
		num2=numPathsHome(street-1,avenue);/*then decrease the street by 1 and sends to function then does this both of street and avenue are 1 */
		return num1+num2;//sends the sum of both paths

		//This function tries all points to (1,1) then sums them all 
	}
}
void part2()
{
	char _cities[6]={'A','B','C','D','E','F'};
	char _locations[4][3]={{'A','B','C'},{'A','C','D'},{'B','F'},{'C','E','F'}};
	int _numHospitals,a; 
	struct Hospital results[4];
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 3; ++j)
			results[i].citiesServed[j]='\0';
	printf("Enter the maximum number of hospitals that can be contructed: ");
	scanf("%d",&_numHospitals);
	if (_numHospitals>4)
	{
		printf("You Do Not Have Enough Money To Contructe Too Many Hospital. \n");
	}else{
		a=canOfferCovidCoverage(_cities, _locations,_numHospitals,results);
		if(a==1)
		{
			printf("Yes, can offer Health care to all..\n");
			for (int i = 0; i < _numHospitals; ++i)
			{
				printf("Hospital -%d\n",i+1 );
				printf("Hospital locations: ");
				for (int j = 0; j < 3; ++j)
					printf("%c",results[i].citiesServed[j]  );
				printf("\n");
			}
		}else{
			printf("No,some cities are not covered..\n");
		}
	}
	printf("\n\n");
}
int canOfferCovidCoverage(char _cities[6], char _locations[4][3], int _numHospitals, struct Hospital results[4])
{ 
	int a,i=0,counter=0,r=0,l=0;
	if (_numHospitals ==0)
	{
		 return check_loc(_cities,results);
	}else{
		while(results[r].citiesServed[0]!='\0' && r<Total_hosp-1)
		{
				r++;
		}
		do{	
			results[r].citiesServed[0]='\0';
			strcpy(results[r].citiesServed, _locations[l]);
			a=canOfferCovidCoverage(_cities, _locations+1,_numHospitals-1,results);
			l++;
			if(a==1)
				return a;
		}while(l<4);
			return 0;
	}	
}
int check_loc(char _cities[6],struct Hospital results[4])
{
	int a,i=0,counter=0,r=0,l=0;
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 3; ++k)
				if (_cities[i]==results[j].citiesServed[k])
				{
					counter++;
					j=4;
					k=3;
				}
	}
	if (counter==6)
	{
		return 1; 
	}else
		return 0;
}
void part3()
{
	char *b=NULL;
	char suit[4][10]={ {"Hearts"},{"Diamonds"}, {"Clubs"},{"Spades"}};
	char face[13][10]={ "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	int k,x=0;
	struct card deck[52];
	for (int i = 0; i < 52; ++i)
		deck[i].suit = '\0';
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 13; ++j)
		{
			while(x==0)
			{
				k=rand()%52;//randomly puts in array to make the deck shuffled
				if (deck[k].suit  == b)
				{
					deck[k].face = face[j];
					deck[k].suit = suit[i];
					x=1;
				}
			}
			x=0;
		}
	}
	for (int i = 0; i < 26; i++)
		printf("%8s of %s\t%8s of %s\n",deck[i].face,deck[i].suit,deck[i+26].face,deck[i+26].suit );
	printf("\n\n");
}