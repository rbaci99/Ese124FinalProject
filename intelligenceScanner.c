
#define Mark 0
#define CwL 1
#define CwF 2
#define CwR 3
#define CwB 4
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
		
				



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
void intelligenceScanner(int commands[SIZE],int n, int t){
	FILE *file;
	int i=0;
	char temp[10];
	if ((file = fopen("intelligence.txt","r")) == NULL){
       printf("Error! opening file");

       // Program exits if returns NULL.
       exit(1);
   }
   while(fscanf(file,"%s",temp)!=EOF){
   	if (strcmp(temp,"MARK")==0) {
			commands[i]=Mark;
			
		}else
		if (strcmp(temp,"CWL")==0) {
			commands[i]=CwL;
			
		}else
		if (strcmp(temp,"CWF")==0) {
				commands[i]=CwF;
		}else
		if (strcmp(temp,"CWR")==0) {
			commands[i]=CwR;
		}else
		if (strcmp(temp,"CWB")==0) {
			commands[i]=CwB;
		}else

		if (strcmp(temp,"MOVE_F")==0) {
			commands[i]=Move_F;
		}else
		if (strcmp(temp,"MOVE_B")==0) {
			commands[i]=Move_B;
		}else
		if (strcmp(temp,"MOVE_L")==0) {
			commands[i]=Move_L;
		}else
		if (strcmp(temp,"MOVE_R")==0) {
			commands[i]=Move_R;
		}else
		if (strcmp(temp,"PUSH")==0) {
			commands[i]=Push;
		}else
		if (strcmp(temp,"POP")==0) {
			commands[i]=Pop;
		}else
		if (strcmp(temp,"PEEK")==0) {
			commands[i]=Peek;
		}else
		if (strcmp(temp,"CLEAR")==0) {
			commands[i]=Clear;
		}else
		if (strcmp(temp,"BJPI")==0) {
			commands[i]=BJPI;
		}else
		if (strcmp(temp,"CJPI")==0) {
			commands[i]=CJPI;
		}else
		if (strcmp(temp,"BACKTRACK")==0) {
			commands[i]=Back;
		}else
		if (temp[0]=='R' && temp[1]=='P') {
			commands[i]=Rp;
			n = temp[3];
			t = temp[5];
			
		}
		i++;
   }
  
}

