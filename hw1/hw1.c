#include<stdio.h>
#include<math.h>

float function_value(int a,int b,int c,float x);//Declarations of my functions that I used
float derivative_value(int a,int b,float x);
float next_x(float x,float f,float f1);

void find_root()//Question 1
{
	int a,b,c;
	float D,r1,r2;	
		printf("Enter first coefficient:\n");
		scanf("%d",&a);
		printf("Enter second coefficient:\n");
		scanf("%d",&b);
		printf("Enter third coefficient:\n");
		scanf("%d",&c);

		printf("Your equation is (%dx^2) + (%dx) + (%d) and ",a,b,c);
	
		D=(b*b)-(4*a*c);//Discriminant
			if( D >= 0 )
			{
				r1= (-b - sqrt(D))/2*a;
				r2= (-b + sqrt(D))/2*a;
				printf("the roots are {%.2f}-{%.2f}\n\n",r1,r2);
			}else
				printf("does not have any real root.\n\n");
		return;
}
void find_newtonian_root()//Question 2
{
	int a,b,c;
	float x0,x1,x2,x3,x4,x5;// x for the values that I used for finding the root;
	float y0,y1,y2,y3,y4,y5;//y for the x's values in the function"f(x)";
	float D0,D1,D2,D3,D4;//D for the derivatives of the function;
		printf("Enter first coefficient:\n");
		scanf("%d",&a);
		printf("Enter second coefficient:\n");
		scanf("%d",&b);
		printf("Enter third coefficient:\n");
		scanf("%d",&c);
		printf("Enter initial:\n");
		scanf("%f",&x0);
		printf("Your equation is (%dx^2) + (%dx) + (%d) and iterations are\n ",a,b,c);
		
		printf("\tStep\t -x- \t  -f(x)- \t Difference\n");
		
		y0= function_value(a,b,c,x0);
		D0= derivative_value(a,b,x0);
		x1= next_x(x0,y0,D0);

		y1=function_value(a,b,c,x1);
		D1=derivative_value(a,b,x1);
		x2=next_x(x1,y1,D1);

		y2=function_value(a,b,c,x2);
		D2=derivative_value(a,b,x2);
		x3=next_x(x2,y2,D2);

		y3=function_value(a,b,c,x3);
		D3=derivative_value(a,b,x3);
		x4=next_x(x3,y3,D3);

		y4=function_value(a,b,c,x4);
		D4=derivative_value(a,b,x4);
		x5=next_x(x4,y4,D4);

		y5=function_value(a,b,c,x5);

		printf("\t 1\t %.4f \t %.4f \t %.4f\n",x1,y1,x1-x5 );
		printf("\t 2\t %.4f \t %.4f \t %.4f\n",x2,y2,x2-x5 );
		printf("\t 3\t %.4f \t %.4f \t %.4f\n",x3,y3,x3-x5 );
		printf("\t 4\t %.4f \t %.4f \t %.4f\n",x4,y4,x4-x5 );
		printf("\t 5\t %.4f \t %.4f \t %.4f\n\n",x5,y5,x5-x5 );

		return;
}
float function_value(int a,int b,int c,float x)//f(x)
{
	float f= (a*x*x)+(b*x)+c;//Equation
	 return f;
}
float derivative_value(int a,int b,float x)//f'(x)
{
	float f1=(2*a*x)+b;//Derivative of the Equation
	 return f1;
}
float next_x(float x,float f,float f1)//New x
{
	float next = x -( f / f1);//Newton's Method
	 return next;
}

int find_multiple_closest(int a,int b)//Question 3
{
	int k;								
		k= a%b;
		if (k<(b/2))
		{			
			return a-k;// the greatest multiple of b less than a; 
		}else
			return a-k+b;//the lowest multiple of b more than a;
}
int main()
{
	int i1,i2,closest;
		printf("Question 1\n");
			find_root();
		printf("Question 2\n");
			find_newtonian_root();
		printf("Question 3\n");
			printf("Enter first integer:\n");
			scanf("%d",&i1);
			printf("Enter second integer:\n");
			scanf("%d",&i2);
			closest=find_multiple_closest( i1, i2);
			printf("Closest number to %d that is multiple of %d is %d.",i1,i2,closest);
	
}
