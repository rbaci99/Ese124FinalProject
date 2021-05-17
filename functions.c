//Functions (excluding stack functions as well as RP n t) for Michael

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100
#include"stack.h"
//marks current position as 'p' for pheremone
//make sure to follow all moves by mark
int currX;//current x position
int currY;//current y position
//??maybe put this in main or make another stack for it or get rid of completely;
//char[MAX_SIZE][];//use this to store commands made for back track method

void getPos(int *x,int *y){
	*x=currX;
	*y=currY;
}
void setPos(int x,int y){
	currX=x;;
	currY=y;;
}
void MARK(int row,int col,char *maze[]){
	maze[row][col]='p';
	
}//MARK

//moves ant foward by 1 in x direction
void MOVE_F(){
 //add check in main file to see if maze is *   ??should we put check in here instead
 //add in main so that way we can print to file if invalid spot
	int x,y;
	peek(&x,&y);
	push(x+1,y);
}//MOVE_F

//moves ant backwards by 1 in x direction
void MOVE_B(){
	int x,y;
	peek(&x,&y);
	push(x-1,y);
}//MOVE_B

//moves ant left by 1 in y direction
void MOVE_L(){
	int x,y;
	peek(&x,&y);
	push(x,y-1);
}//MOVE_L

//moves ant right by 1 in y direction
void MOVE_R(){
	int x,y;
	peek(&x,&y);
	push(x,y+1);
}//MOVE_R
//checks for itch to left and returns number of free spaces although Michael does not see it,used for jumps
int CWL(char *maze[]){
	int x,y,i=0,itch=0;
	peek(&x,&y);
	while(maze[x][y-i]==' '){
		itch++;
		i++;
	}
	return itch;//returns number of spaces free micheal cant see this but use for Jumps
	//returns 0 for no itch else returns # of itches
	//??may change to just boolean and use while loop in BJMP
	//look at lecture from tuesday week13 time 55 min for reference of difference bewteen jumps
}//CWL
//checks for itch to Right and returns number of free spaces
int CWR(char *maze[]){
	int x,y,i=0,itch=0;
	peek(&x,&y);
	while(maze[x][y+i]==' '){
		itch++;
		i++;
	}
	return itch;//returns number of spaces free micheal cant see this but use for Jumps
	//returns 0 for no itch else returns # of itches
	//??may change to just boolean and use while loop in BJMP
	//look at lecture from tuesday week13 time 55 min for reference of difference bewteen jumps
}//CWR
//checks for itch to Forward direaction and returns number of free spaces
int CWF(char *maze[]){
	int x,y,i=0,itch=0;
	peek(&x,&y);
	while(maze[x+i][y]==' '){
		itch++;
		i++;
	}
	return itch;//returns number of spaces free micheal cant see this but use for Jumps
	//returns 0 for no itch else returns # of itches
	//??may change to just boolean and use while loop in BJMP
	//look at lecture from tuesday week13 time 55 min for reference of difference bewteen jumps
}//CWF
//checks for itch to Backwards direaction and returns number of free spaces
int CWB(char *maze[]){
	int x,y,i=0,itch=0;
	peek(&x,&y);
	while(maze[x-i][y]==' '){
		itch++;
		i++;
	}
	return itch;//returns number of spaces free micheal cant see this but use for Jumps
	//returns 0 for no itch else returns # of itches
	//??may change to just boolean and use while loop in BJMP
	//look at lecture from tuesday week13 time 55 min for reference of difference bewteen jumps
}//CWB
//Jumps to furthest itch in specified direction
//returns 1 if jump executed else returns 0
int BJPi(char* maze[],char prev[3]){
//prev is previous CW command to see what direction to jump
int x,y;
peek(&x,&y);
int num=0;//spaces to jump
char c; //char for switch
//check to make sure previous command was CW command
if(strcmp(prev,"CWR")==0||strcmp(prev,"CWF")==0||strcmp(prev,"CWL")==0||strcmp(prev,"CWB")==0){
c =prev[2];
switch(c){

	case 'L':
		num=CWL(maze);
		if(num==0) return 0;
		push(x,y-num);
		break;
	case 'R':
		num=CWR(maze);
		if(num==0) return 0;
		push(x,y+num);
		break;
	case 'F':
		num=CWF(maze);
		if(num==0) return 0;
		push(x+num,y);
		break;
	case 'B':
		num=CWR(maze);
		if(num==0) return 0;
		push(x-num,y);
		break;
	default:return 0;
}//switch
	
}else{
printf("Invalid Previous Command");
return 0;
}//if
return 1;//if func gets to here it means Jump was executed
}//BJPI

//Jumps to over one space in itched direction
//returns 1 if jump executed else returns 0
int CJPi(char* maze[],char prev[3]){
//prev is previous CW command to see what direction to jump
int x,y;
peek(&x,&y);
int num=0;//check to see if jump allowed
char c; //char for switch
//check to make sure previous command was CW command
if(strcmp(prev,"CWR")==0||strcmp(prev,"CWF")==0||strcmp(prev,"CWL")==0||strcmp(prev,"CWB")==0){
c =prev[2];
switch(c){

	case 'L':
		num=CWL(maze);
		if(num==0||num==1) return 0;//added check to not jump if it cant skip current space
		push(x,y-2);
		break;
	case 'R':
		num=CWR(maze);
		if(num==0||num==1) return 0;
		push(x,y+2);
		break;
	case 'F':
		num=CWF(maze);
		if(num==0||num==1) return 0;
		push(x+2,y);
		break;
	case 'B':
		num=CWR(maze);
		if(num==0||num==1) return 0;
		push(x-2,y);
		break;
	default:return 0;
}//switch

}else{
printf("Invalid Previous Command");
return 0;
}//if
return 1;//if func gets to here it means Jump was executed
}//CJPI
//BACKTRACK METHOD ??nO iDea if this is correct
void BACKTRACK(int x,int y){
	pop(&x,&y);
	//??Since we are using the top of the stack as current position pop would
	//??bring michael back to the last position but idk if this is correct
	//??if we need a separate variable to hold the current position
	//??then this needs a major rework
}//BACKTRACK



