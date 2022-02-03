#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define sizeof_array 15

typedef struct tree
{
	int freq;
	char harf;
	char arr[sizeof_array];//huffman codes
	int top;
	struct tree* left_zero;
	struct tree* right_one;
}Tree;

void read_file(char* buffer,int freq[50],char characters[50],int* counter);//Reads 'reference.txt' file
void get_freq(char characters[50], char var,int* k,int freq[50]);//Counts the characters
void sort_freq(char characters[],int freq[],int size);//Sorts characters by their frequency
Tree* fill_nodes_array(Tree* node_array,char* characters,int* freq,int counter);//Creats the array of nodes with characters and their frequencies

Tree* connect_nodes(Tree* node_array,Tree* left,Tree* right,int counter_v2);//Connects the nodes
void sort_nodes(Tree* node_array,int counter);//Sorts the nodes array

void print_codes(Tree *root,char arr[], int top);//Finds the codes and put in an array then sends that to print_array funtion
void print_array(char arr[], int n) ;//Prints the Huffman codes array

void encode(Tree* root);//Encodes 'message.txt' file
void binary_search(FILE* in,char k,Tree* root);//Finds the characters in tree then prints the huffman code of it in 'encoded.dat' file
void decode(Tree* root);//Decodes 'encoded.dat' file
void search_tree(FILE* in,Tree* root,char arr[],int top);//Searchs by read code in tree then prints the character in 'decoded.txt' file also calculates the file size difference
void main()
{
	char characters[50],arr[sizeof_array],*buffer=(char*)malloc(sizeof(char));
	int freq[50],counter=0,counter_v2,top=0;

	read_file(buffer,freq,characters,&counter);
	sort_freq(characters,freq,counter);
	Tree *node_array=(Tree*)malloc(sizeof(Tree)*(2*counter-1));
	node_array=fill_nodes_array(node_array,characters,freq,counter);
	counter_v2=2*counter-1;//Maximum number of all connections of nodes
	for(int i=0; i< counter_v2-1;i+=2)
	{
		sort_nodes(node_array,counter_v2);
		node_array=connect_nodes(node_array,&node_array[i],&node_array[i+1],counter+(i/2));
	}
	Tree *root=&node_array[counter_v2-1];
	print_codes(root,arr,top);
	encode(root);
	decode(root);
}
void read_file(char* buffer,int freq[50],char characters[50],int* counter)
{
	FILE *in=fopen("reference.txt","r");
	int i=0;
	while(!feof(in))
	{
    	buffer = (char *)realloc(buffer,sizeof(char)*(i+1)); 
		fscanf(in,"%c",&buffer[i]);
    	get_freq(characters,buffer[i],&(*counter),freq); 
    	i++;
	}
	fclose(in);
}
void sort_freq(char characters[],int freq[],int size)
{
	int temp_freq,counter=0;
	char temp_char;
	while(counter!=size-1)
		if (freq[counter]>freq[counter+1])
		{
			temp_freq=freq[counter+1];
			temp_char=characters[counter+1];
			freq[counter+1]=freq[counter];
			characters[counter+1]=characters[counter];
			freq[counter]=temp_freq;
			characters[counter]=temp_char;
			counter=0;
		}else
			counter++;
}
void get_freq(char characters[50], char var,int* k,int freq[50])
{
	for (int i = *k ; i>=0 ; --i)
		if (var==characters[i])
		{
			freq[i]++;
			return ;
		}
	characters[*k]=var;
	freq[*k]=1;
	(*k)++;
}
Tree* connect_nodes(Tree* node_array,Tree* left,Tree* right,int counter_v2)
{
	Tree *temp=&node_array[counter_v2];
    temp->freq = (left->freq)+(right->freq);
	temp->left_zero =left;
	temp->right_one =right;
    temp->harf='@';
	temp=&node_array[counter_v2];
	return node_array;
}
Tree* fill_nodes_array(Tree* node_array,char* characters,int* freq,int counter)
{
	for (int i = 0; i < counter; ++i)
	{
		node_array[i].harf= characters[i];
		node_array[i].freq=freq[i];
		node_array[i].left_zero = NULL;
		node_array[i].right_one = NULL;
	}
	for (int i = counter; i < 2*counter-1; ++i)
		node_array[i].freq=999999;
	return node_array;
}
void sort_nodes(Tree* node_array,int counter)
{
	Tree temp_tree;
	int count=0;
	while(count!=counter-1)
	{
		if (node_array[count].freq > node_array[count+1].freq)
		{
			temp_tree=node_array[count];		
			node_array[count]=node_array[count+1];
			node_array[count+1]=temp_tree;
			count=0;
		}else
			count++;
	}
}
void print_codes(Tree *root,char arr[], int top)
{
	if (root->left_zero!=NULL)
	{
		arr[top] = '0';
		print_codes(root->left_zero, arr, top + 1);
	}
	if (root->right_one!=NULL)
	{
		arr[top] = '1';
		print_codes(root->right_one, arr, top + 1);
	}
	if (root->left_zero==NULL || root->right_one==NULL)
	{
		for (int i = 0; i < top; ++i)
			root->arr[i]=arr[i];
		root->top=top;
		printf("Freq: %3d |->  %c  |",root->freq, root->harf);//To See The Huffman Codes
		print_array(arr,top);
		printf("\n"); 
	}
}
void print_array(char arr[], int n)
{
	for (int i = 0; i < n; ++i)
    	printf("%c", arr[i]);
	printf(" ");
}
void binary_search(FILE* in,char k,Tree* root)
{
	if(root==NULL || root->harf==k)
	{
		fwrite(root->arr,sizeof_array,1,in);
		return;
	}
    if(root->right_one !=NULL)
        binary_search(in,k,root->right_one);
    if (root->left_zero !=NULL)
    	binary_search(in,k,root->left_zero);
}
void encode(Tree* root)
{
	FILE *in=fopen("message.txt","r");
	FILE *out=fopen("encoded.dat","wb");
	char c;
	while(fscanf(in,"%c",&c)==1)
		binary_search(out,c,root);
	fclose(in);
	fclose(out);
}
void decode(Tree* root)
{
	FILE *out=fopen("decoded.txt","w");
	FILE *in=fopen("encoded.dat","rb");
	char arr[sizeof_array];
	int used_b=0;
	while(fread(arr,sizeof_array,1,in)==1)
	{
		search_tree(out,root,arr,0);
		used_b+=sizeof(char);
	}
	printf("File size of 'encoded.dat' :%d\n",used_b*sizeof_array );
	printf("File size of 'decoded.txt' :%d\n",used_b);
	printf("Size of Array: %d\n",sizeof_array);
	printf("The Size Difference : %d\n",used_b*(sizeof_array-1));
	fclose(in);
	fclose(out);
}
void search_tree(FILE* in,Tree* root,char arr[],int top)
{
	if (root->harf != '@')
	{
		fprintf(in,"%c",root->harf);
		return ;
	}
	if (arr[top]== '0')
		search_tree(in,root->left_zero,arr, top + 1);
	else 
		search_tree(in,root->right_one,arr, top + 1);
}