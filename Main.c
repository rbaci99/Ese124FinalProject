//#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50 
//Main for Final Project Ese 124 Robert Bacigalupo,Melvin Mathew,Adam Zeng



int main() {
	int r,c;
	char temp;
	char maze[SIZE][SIZE];
	FILE *file;

	if ((file = fopen("maze.txt","r")) == NULL){
       printf("Error! opening file");

       // Program exits if returns NULL.
       exit(1);
   }
	else
	{


	fputc(temp,file);
	for (r=0;r<SIZE;r++){ //increments through 2d array 
		for (c=0;c<SIZE;c++)
		{
				if ((temp=fgetc(file))!=EOF)
				{
				fscanf(file,"%c",&maze[r][c]);	
				printf("%c",maze[r][c]);
            	}
            
            }
		}
}
	fclose(file);
}



/*void mazeGen(char mazew[SIZE][SIZE])//preset maze is generated
{
	
}
*/

