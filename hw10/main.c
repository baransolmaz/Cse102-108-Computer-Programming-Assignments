#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265
#define Rad 180/PI

struct Point
{
	float x;//X coordinate of point 
	float y;//y coordinate of point
};
struct Line
{
	struct Point first;//first point of line
	struct Point last;//end point of line	
};
struct Polygon
{
	struct Line line;
	struct Polygon *next_line;
	struct Point point;
	struct Polygon *next_point;
};

double distance_p_to_p(struct Point a,struct Point b);//calculates the distance between two points
double distance_p_to_l(struct Point a,struct Line b);//calculates the distance between point and line
double minimum_distance(struct Point a,struct Line b);//finds the minimum distance point to both first and end points of line
void satir_atlama(FILE* in);//reads unnecesarry characters until the end of line
double length(struct Line a);//finds the length of line
double length_poly(struct Polygon a,int type);//Finds the perimeter of polygon
double rotate(struct Point a,struct Line b);//rotates the line re-sends to distance_p_to_l function
double angle(struct Line a);//calculates the angle between line and horizontal line 
double area(struct Polygon PG ,int type);//Calculates the area of polygon
int main()
{
	float fx,fy ;
	char typec,c,arr[10],type1,type2 ,output_file[30];
	int first_point,last_point,number,data_number,action_number,n1,n2;
	struct Point p[5];
	struct Line l[5];

	struct Polygon *PG1 = (struct Polygon*)malloc(sizeof(struct Polygon));
	struct Polygon *temp1=PG1;

	struct Polygon *PG2 = (struct Polygon*)malloc(sizeof(struct Polygon));
	struct Polygon *temp=PG2;

	FILE *in = fopen("commands.txt","r");
	fscanf(in,"%s",arr);
	if (strcmp(arr,"data")==0)
	{
		fscanf(in,"%d",&data_number);
		for(int i=0; i<data_number/2-1;++i)
		{
			if(fscanf(in," %f%f %c%d",&fx,&fy,&type1,&number))//nokta formatı	
			{
				p[number].x=fx;
				p[number].y=fy;
				satir_atlama(in);
			}
		}
		for (int i = 0; i < data_number/2-1; ++i)
		{
			if(fscanf(in,"%c%d %c%d %c%d",&type1,&first_point,&type2,&last_point,&typec,&number))//çizgi formatı
			{
				l[number/10].first=p[first_point];
				l[number/10].last=p[last_point];
				satir_atlama(in);
			}
		}
		for (int i = 0; i < data_number-2*(data_number/2-1); ++i)
		{
			while(c!='G')
			{
				fscanf(in,"%c",&type1);
				switch(type1)
				{
					case 'P':fscanf(in,"%c",&c);
							if (c=='G')
							{
								fscanf(in,"%d",&number);
							}else{
								temp1->point =p[c-'0'];
								temp1->next_point = (struct Polygon*)malloc(sizeof(struct Polygon));
								temp1->next_line=NULL;
								temp1=temp1->next_point;
							}
							break;
					case 'L':fscanf(in,"%c",&c);
							if (c=='G')
							{
								fscanf(in,"%d",&number);
							}else{
								temp->line =l[c-'0'];
								temp->next_line = (struct Polygon*)malloc(sizeof(struct Polygon));
								temp->next_point=NULL;
								temp=temp->next_line;
							}
							break;
				}
			}
			satir_atlama(in);
			c='\0';			
		}
		temp1->next_point=NULL;
		temp->next_line=NULL;
		temp1=PG1;
		temp=PG2;
	}
	fscanf(in,"%s",arr);
	if(strcmp(arr,"actions")==0)
	{
		fscanf(in,"%s",output_file);
		FILE *out=fopen(output_file,"w+");
		fscanf(in,"%d",&action_number);
		for (int i = 0; i < action_number; ++i)
		{
			fscanf(in,"%s",arr);
			if(strcmp(arr,"Distance")==0)
			{
				fscanf(in," %c%d %c%d",&type1,&n1,&type2,&n2);
				satir_atlama(in);
				if(type1=='P' && type2=='P'){
					fprintf(out,"Distance(%c%d,%c%d)= %.3lf\n",type1,n1,type2,n2,distance_p_to_p(p[n1],p[n2]));
				}else if (type1=='P' && type2=='L')
					fprintf(out,"Distance(%c%d,%c%d)= %.3lf\n",type1,n1,type2,n2,distance_p_to_l(p[n1],l[n2/10]));
			}else if(strcmp(arr,"Angle")==0)
			{
				fscanf(in," %c%d %c%d",&type1,&n1,&type2,&n2);
				satir_atlama(in);
				if(type1=='L' && type2=='L')
					fprintf(out,"Angle(%c%d,%c%d)= %.1lf\n",type1,n1,type2,n2,fabs(angle(l[n2/10])-angle(l[n1/10])));
			}else if(strcmp(arr,"Length")==0)
			{
				fscanf(in," %c%c%d",&type1,&type2,&n1);
				satir_atlama(in);
					if(n1==1){
						fprintf(out,"Length(%c%c%d)= %.1lf\n",type1,type2,n1,length_poly(*PG1,1));
					}else
						fprintf(out,"Length(%c%c%d)= %.1lf\n",type1,type2,n1,length_poly(*PG2,2));
			}else if(strcmp(arr,"Area")==0)
			{
				fscanf(in," %c%c%d",&type1,&type2,&n1);
				satir_atlama(in);
				if(n1==1){
					fprintf(out,"Area(%c%c%d)= %.1lf\n",type1,type2,n1,fabs(area(*PG1,1)));
				}else
					fprintf(out,"Area(%c%c%d)= %.1lf\n",type1,type2,n1,fabs(area(*PG2,2)));
			}else{
				fprintf(out,"NOT_IMPLEMENTED\n");
				satir_atlama(in);
			}
		}
	}
	printf("All the actions have been done and printed in the wanted output file\n");
	return 1;
}
void satir_atlama(FILE* in )
{
	int a=1;
	char c;
	while(a != 0)	
	{
		fscanf(in,"%c",&c);
		if (c == '\n')
			a=0;
	}
}
double distance_p_to_p(struct Point a,struct Point b)
{
	double dx,dy;
	dx=(a.x)-(b.x);
	dy=(a.y)-(b.y);
	return sqrt((dx*dx)+(dy*dy));
}
double minimun_distance(struct Point a,struct Line b)
{
	float d1,d2;
	d1=distance_p_to_p(a,b.first);
	d2=distance_p_to_p(a,b.last);
	if (d1>=d2)
	{
		return d2;
	}else
		return d1;
}
double distance_p_to_l(struct Point a,struct Line b)
{
	if ((int)angle(b)==0)
	{
		if ((b.first.x <=a.x && a.x <= b.last.x))
		{
			return fabs(a.y-b.first.y);
		}else
			return minimun_distance(a,b);

	}else if ((int)angle(b)==90)
	{
		if ((b.first.y <=a.y && a.y <= b.last.y)){
			return fabs(a.x-b.first.x);
		}else
			return minimun_distance(a,b);
	}else
		return rotate(a,b);
	
}
double rotate(struct Point a,struct Line b)
{
	struct Point new_p;
	struct Line new_l;
	float deg;
	deg=fabs(90-angle(b))*PI/180;//degree that the point and line will rotate
	new_l.last.x=(b.last.x)*cos(deg)-((b.last.y)*sin(deg));//rotates and makes the line vertical if the line is not vertical or horizontal
	new_l.last.y=(b.last.x)*sin(deg)+((b.last.y)*cos(deg));
	new_l.first.x=b.first.x;
	new_l.first.y=b.first.y;
	new_p.x=(a.x*cos(deg))-((a.y*sin(deg)));//also rotates the point's coordinates
	new_p.y=(a.x*sin(deg))+((a.y*cos(deg)));

	return distance_p_to_l(new_p,new_l);
}
double length_poly(struct Polygon a ,int type)
{ 
	float len=0;
	struct Polygon *temp=&a;
	if (type==1)//Polygon with points
	{
		while(temp->next_point != NULL)
		{
			len+=distance_p_to_p(temp->point,temp->next_point->point);
			temp=temp->next_point;
		}
		len+=distance_p_to_p(temp->point,a.point);
	}else if (type==2)//Polygon with lines
		while(temp->next_line != NULL)
		{
			len+=length(temp->line);
			temp=temp->next_line;
		}
	return len;
}
double length(struct Line a)
{ 
	return distance_p_to_p(a.first,a.last);//Basicly length means distance between two points
}
double angle(struct Line a)
{
	double d1,dx,dy;
	dx=a.last.x-a.first.x;
	dy=a.last.y-a.first.y;
	if(dx!=0){
		d1=dy/dx;
		d1=atan(d1)*Rad;//radian to degree
	}else
		d1=90.0;
	return d1;
}
double area(struct Polygon PG,int type)
{
	float A=0;
	struct Polygon *temp=&PG;
	if (type==1)//For Polygons With Points
	{
		while(temp->next_point->next_point !=NULL)
	    {
	    	A+=((temp->point.x)*(temp->next_point->point.y))-((temp->point.y)*(temp->next_point->point.x));//X(n)*Y(n+1)-X(n+1)*Y(n)
	    	temp=temp->next_point;
	    }
	    A+=((temp->next_point->point.x)*(PG.point.y))-((temp->next_point->point.y)*(PG.point.x));
	}else if (type==2)//For Polygons With Lines
	{
		while(temp->next_line->next_line !=NULL)
	    {
	    	A+=((temp->line.first.x)*(temp->next_line->line.first.y))-((temp->line.first.y)*(temp->next_line->line.first.x));
	    	temp=temp->next_line;
	    }
	    A+=((temp->next_line->line.first.x)*(PG.line.first.y))-((temp->next_line->line.first.y)*(PG.line.first.x));
	}
    return A/2;
}