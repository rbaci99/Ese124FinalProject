
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
void intelligenceScanner(){
	char commands[SIZE];
	FILE *file;
	int i;
	if ((file = fopen("intelligence.txt","r")) == NULL){
       printf("Error! opening file");

       // Program exits if returns NULL.
       exit(1);
   }
   for (i=0;i<SIZE;i++)
   {
		fscanf(file,"%c",&commands[i]);
		printf("%c",commands[i]);//for debugging purposes
   }
   fclose(file);
}
