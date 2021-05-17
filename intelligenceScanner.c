
#define Mark 0
#define cwL 1
#define cwF 2
#define cwR 3
#define cwB 4
#define Move_F 5
#define Move_B 6
#define Move_L 7
#define Move_R 8
#define Push 9
#define Pop 10
#define Peek 11
#define Clear 12
#define BJPI 13
#define CJPI 14
#define Back 15
#define Rp 16
#define END 17
#define IDLE 18 // states

	FILE *intel;
	char i[10];
	if ( (intel=fopen("intelligence.txt", "r")) == NULL )
	{
		printf("Error! Cannot open the file.");
		exit(1);
	}
	
	fscanf(intel, "%s", i);
	while(i != EOF)
	{
		if (strcmp(i,"MARK")==0) {
			column= 0;
			 MARK();
		}
		
		if (strcmp(i,"CWL")==0) {
			column= 1;
			 CWL();
		}
		if (strcmp(i,"CWF")==0) {
			column= 2;
			 CWF();
		}
		if (strcmp(i,"CWR")==0) {
			column= 3;
			 CWR();
		}
		if (strcmp(i,"CWB")==0) {
			column= 4;
			 CWB();
		}
		
		if (strcmp(i,"MOVE_F")==0) {
			column= 5;
			 MOVE_F();
		}
		if (strcmp(i,"MOVE_B")==0) {
			column= 6;
			 MOVE_B();
		}
		if (strcmp(i,"MOVE_L")==0) {
			column= 7;
			 MOVE_L();
		}
		if (strcmp(i,"MOVE_R")==0) {
			column= 8;
			 MOVE_R();
		}
		
		if (strcmp(i,"PUSH")==0) {
			column= 9;
			 push();
		}
		if (strcmp(i,"POP")==0) {
			column= 10;
			 pop();
		}
		if (strcmp(i,"PEEK")==0) {
			column= 11;
			 peek();
		}
		if (strcmp(i,"CLEAR")==0) {
			column= 12;
			 clear();
		}
		
		if (strcmp(i,"BJPI")==0) {
			column= 13;
			 BJPI();
		}
		if (strcmp(i,"CJPI")==0) {
			column= 14;
			 CJPI();
		}
		
		if (strcmp(i,"BACKTRACK")==0) {
			column= 15;
			 BACKTRACK();
		}
		if (strcmp(i,"RP")==0) {
			column= 16;
			();
		}
		if (strcmp(i,"END")==0) {
			column= 17;
		}
		if (strcmp(i,"IDLE")==0) {
			column= 18;
		}
		
		
		
		
		}//while
		
				



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

