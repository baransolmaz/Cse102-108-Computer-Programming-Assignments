#include <stdio.h>


#define dolar_tl 6.14//Dolar ---> TL
#define euro_tl 6.69//Euro ---> TL
#define euro_dolar 6.69/6.14//Euro ---> Dolar

int main()
{
	float amount;
	int currency,wanted;

	printf("*****Welcome to ABC Exchange Office*****\n");

	printf("Enter your amount:\n");
	scanf("%f",&amount);

	printf("Please select your currency\n");
	printf("1.Turkish Lira\n");
	printf("2.Euro\n");
	printf("3.Dolar\n");
	scanf("%d",&currency);

	if (1<=currency && currency<=3)//Checks the chosen currency that optional or not
	{
		
		switch(currency)
		{
			case 1:printf("You have %.3f Turkish Liras\n",amount);
					break;		
			case 2:printf("You have %.3f Euros\n",amount);
					break;
			case 3:printf("You have %.3f Dolars\n",amount);
					break;	
		}

		printf("Choose which currency you want to convert?\n");
		scanf("%d",&wanted);

		if (1<=wanted && wanted<=3)//Checks the wanted currency that optional or not
		{
			if (currency==1)//if the chosen currency is TL, converts depends on the wanted
			{
				switch(wanted)
				{
				case 1:printf("You have %f Turkish Liras\n",amount);
						break;		
				case 2:printf("You have %f Euros\n",amount/euro_tl);
						break;
				case 3:printf("You have %f Dolars\n",amount/dolar_tl);
						break;	
				}

			}else if (currency==2)//if the chosen currency is Euro, converts depends on the wanted
			{
				switch(wanted)
				{
				case 1:printf("You have %f Turkish Liras\n",amount*euro_tl);
						break;		
				case 2:printf("You have %f Euros\n",amount);
						break;
				case 3:printf("You have %f Dolars\n",amount*euro_dolar);
						break;	
				}

			}else if (currency==3)//if the chosen currency is Dolar, converts depends on the wanted
			{
				switch(wanted)
				{
				case 1:printf("You have %f Turkish Liras\n",amount*dolar_tl);
						break;		
				case 2:printf("You have %f Euros\n",amount/euro_dolar);
						break;
				case 3:printf("You have %f Dolars\n",amount);
						break;	
				}
			}

		}else
			printf("Your selection is invalid.\n");//if the WANTED currency is not optional, prints this

	}else
		printf("Your selection is invalid.\n");//if the currency is not optional, prints this
	
	
	return 0;
}
