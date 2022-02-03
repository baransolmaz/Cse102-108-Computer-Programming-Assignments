#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int draw_triangle(int side1,int side2,int side3)//The Function that checks the triangle can be drawn
	{
		int a = side1-side3;
		if (abs(a)<side2 && side2<(side3+side1))
			{
				return 1;
			}else
				return 0;
	}
void type_triangle(int side1,int side2,int side3)//The Function that decides the triangle's type
	{
		if (side1==side2 && side1==side3 )
			{
				printf("It is a Equilateral Triangle.\n");
			}else if (side1==side2||side1==side3||side2==side3)
				{
					printf("It is a Isosceles Triangle.\n");
				}else
					printf("It is a Scelene Triangle.\n");
		
		return;
	}
int perimeter_triangle(int side1,int side2,int side3)//The Function that sums all of the triangle's sides
	{
		return side1+side2+side3;
	}
double area_triangle(int side1,int side2,int side3,int perimeter)//The Function that calculates the area of the triangle
	{
		double area;
		float half_p = (float)perimeter / 2 ;
		double root= half_p*(half_p-side1)*(half_p-side2)*(half_p-side3);
		area = sqrt(root);
		return area;
	}
int main()//MAIN
	{
		int side1,side2,side3,T,perimeter;
		double area ;

		printf("Enter first side:\n");
		scanf("%d",&side1);
		printf("Enter second side:\n");
		scanf("%d",&side2);
		printf("Enter third side:\n");
		scanf("%d",&side3);

		T=	draw_triangle(side1,side2,side3);
		printf("According to the triangle inequality theorem,");
		if (T== 1)
			{
				printf("this triangle can be drawn.\n");
				perimeter=perimeter_triangle(side1,side2,side3);
				printf("The perimeter of the triangle:%d.\n",perimeter);
				area =area_triangle(side1,side2,side3,perimeter);
				printf("The area of the triangle:%lf.\n",area);
			}else
				printf("this triangle cannot be drawn.\n");

		return 0;
}
