#include <stdio.h>
#include <string.h>


void count_char(char arr[200]);

int main()
{
	char str[200];
	printf("Enter:");
 	scanf(" %[^\n]",str); 
	printf("Encoding: ");
	count_char(str);
	return 0;
}
void count_char(char arr[200])
{
	int counter=0,i=0;
	char k=arr[0];
	int size=strlen(arr);
	while(i< size+1)
	{
		if (k==arr[i])
		{
			counter++;
		}else{
			printf("%c%d",k,counter );
			k=arr[i];
			counter=1;
		}
		i++;
	}

}