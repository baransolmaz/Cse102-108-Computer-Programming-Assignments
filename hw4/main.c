#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void decrypt_and_print (char *file_path);//part1
char decrypt_numbers (int number);//part1
void deep_decrypt_and_print (char *file_path);//part2
void track_machine ();//part3
void refresh_position (int *X, int *Y, double *D, double *R);//part3
void encrypt_messages (char *file_path);//part4
int encrypt_characters(char character);//part4
void menu();//part5

int main()//MAIN//
{
	menu();
	return 0;
}
void decrypt_and_print (char *file_path)//part1
{
	FILE *file=fopen(file_path,"r+");
	char ch,k;
	printf("\nCopy that,Sir!\n\n");
	while( !feof(file) )
 	{
		fscanf(file,"%c",&ch);
		k=decrypt_numbers(ch-'0');
		printf("%c",k);
 	}

	fclose(file);	
}
char decrypt_numbers (int number)//part1
{
	switch(number)
	{
		case 0:return ' ';

		case 1:return '-';
				
		case 2:return '_';
				
		case 3:return '|';

		case 4:return '/';
				
		case 5:return '\\';
			
		case 6:return 'o';

		default: return '\n';
	}

}
void deep_decrypt_and_print (char *file_path)//part2
{
	FILE *file=fopen(file_path,"r+");
	char ch,k,c1,c2;
	int h=0;	
	printf("\nCopy that,Sir!\n");
	printf("\nThis message had complex format.\n");
	printf("\nBut We translated.\n\n");

	fscanf(file,"%c",&c1);
	fscanf(file,"%c",&c2);
	while( !feof(file))
 	{
		fscanf(file,"%c",&ch);
		h=(c1-'0')+(c2-'0')+(ch-'0');
		if (ch !='\n')
		{
			k=decrypt_numbers(h%7);
			h=0;
			printf("%c",k);
 			c1=c2;
 			c2=ch;	
		}else
		{
			ch='0';
			fscanf(file,"%c",&c1);
			fscanf(file,"%c",&c2);
			
			printf("\n");
 		}
		
 	}
 	printf("\n");

 	fclose(file);
}
void track_machine ()//part3
{
	int n=1,m=1;//intial position of Enemy (1,1)
	char choice ;
	double disp=0.0,dist=7.071;
	printf("\nTracking Machine has opened.\n\n");
	while(choice != 'E')
	{

		for (int i = 1; i < 12; ++i)
		{
			for (int j = 1; j < 12; ++j)
			{
				if (i== 6 && j==6)
				{
					printf("O\t");
				}else if(i== n && j == m)
				{
					printf("E\t");
				}else
					printf(".\t");
			}
			printf("\n");
		}
		printf("\n");
			
		printf("\nEnemies's X position: %d, Y position : %d ,",n,m);
		printf("Displacement: %.3lf, Distance to our camp: %.3lf \n\n",disp,dist);
		
		printf("Comment waiting...:");
		scanf("\n%c",&choice);
		if (choice =='R')
		{
			refresh_position(&n,&m,&dist,&disp);
			printf("\nThe Position of Enemy is changing.STAY ALERT!!!\n\n");
		}else if (choice !='E')
		{
			printf("\nWrong input. Nothing changed. Try again.\n\n");
		}else
			printf("\nThe  Tracking Machine has closed...\n\n");
		
	}
}
void refresh_position (int *X, int *Y, double *D, double *R)//part3
{
	int tempn,tempm;
	double dx,dy;

	tempn=*X;
	tempm=*Y;

	*X=(rand()%11)+1;
	*Y=(rand()%11)+1;

	dx=tempn-*X;
	dy=tempm-*Y;
	*R=sqrt((dx*dx)+(dy*dy));

	dx=*X-6;
	dy=*Y-6;
	*D=sqrt((dx*dx)+(dy*dy));
}

void encrypt_messages (char *file_path)//part4
{
	FILE *file1=fopen(file_path,"r+");
	FILE *file2;
	file2=fopen("encrypted_p4.img","a+");
	int c1=0,c2=0,toplam=0;
	char k,ch;
	printf("\nWe will send this message to our base.\n\n");

	while( !feof(file1))
 	{
		
		fscanf(file1,"%c",&ch);
		if (ch=='\n')
		{
			fprintf(file2,"\n");
			c1=0;
			c2=0;
			k=0;
		}else
		{
			k=encrypt_characters(ch);
			toplam=c1+c2+k;
			fprintf(file2,"%d",toplam%7);
		}
		c1=c2;
		c2=k;
		toplam=0;
 	
 	}
 	printf("\nEncryption is done...\n\n");
	fclose(file1);
	fclose(file2);	
}
int encrypt_characters(char character)//part4
{
	switch(character)
	{
		case ' ':return 0;
				 
		case '-':return 1;
				 
		case '_':return 2;
				 
		case '|':return 3;
				 
		case '/':return 4;
				 
		case '\\':return 5;
				 
		case 'o':return 6;
				 
	}
}
void menu()//part5
{
	int choice;
	printf("\n\n*************** 1 MESSAGE FROM COMPUTER ENGINEERS ************\n");
	printf("Captain,\n\tWe found the messages of The Enemy. What should We do?\n");
	printf("**************************************************************\n\n");
	do
	{
		printf("1-)Decrypt and print encrypted_p1.img\n");
		printf("2-)Decrypt and print encrypted_p2.img \n");
		printf("3-)Switch on the tracking machine \n");
		printf("4-)Encrypt the message \n");
		printf("5-)Switch off \n\n");

		printf("Please make your choice:\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:decrypt_and_print("encrypted_p1.img");
					break;
			case 2:deep_decrypt_and_print("encrypted_p2.img");
					break;
			case 3:track_machine();
					break;
			case 4:encrypt_messages("decrypted_p4.img");
					break;
			default :printf("\nThe machine is closing...\n");
		}

	}while(choice < 5);

}