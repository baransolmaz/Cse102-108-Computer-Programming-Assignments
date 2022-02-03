#include <stdio.h>

typedef struct $
{
	char sym;
	int x,y;
}Pixel;

void read_image(Pixel pixels[]);
void fill_canvas(Pixel pixels[], Pixel canvas[][9]);
void draw_image(Pixel canvas[][9]);

int main(void)
{
	int row_number=6,col_number=9;
	int total_pixel_number = row_number * col_number;
	Pixel pixels[total_pixel_number];
	Pixel canvas[row_number][col_number];
	read_image(pixels);
	fill_canvas(pixels, canvas);
	draw_image(canvas);
	return 0;
}
void read_image(Pixel pixels[])
{
	int k=0;
	FILE *in=fopen("image.txt","r");
	for (int i = 0; i < 6; ++i)
		for (int j = 0; j < 9; ++j)
		{
			fscanf(in," %c,%d,%d; ",&pixels[k].sym,&pixels[k].x,&pixels[k].y);
			k++;
		}
}
void fill_canvas(Pixel pixels[], Pixel canvas[][9])
{
	for (int i = 0; i < 54; i++)
		canvas[pixels[i].x][pixels[i].y].sym = pixels[i].sym;
}
void draw_image(Pixel canvas[][9])
{
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 9; ++j)
			printf("%c",canvas[i][j].sym);
		printf("\n");
	}
}