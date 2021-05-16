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

void getPos(int *xValue, int *yValue){
	*xValue=currX;
	*yValue=currY;
	
}//getPos

void setPos(int *xValue, int *yValue){//use for initial position
	*xValue=currX;
	*yValue=currY;

}//getPos

void MARK(int row,int col,char *maze[]){
	maze[row][col]='p';
	push(row,col);
	
}//MARK

//moves ant foward by 1 in x direction x+1
int MOVE_F(char *maze[]){
 if(maze[currX++][currY]=='p'||maze[currX++][currY]==' '||maze[currX++][currY]=='@'){
	currX++;
 if (maze[currX][currY]=='@')
	return 2;//Gold found
	return 1;//No Gold but valid space
}else
	return 0;//No valid space aka wall
//if check for valid space
}//MOVE_F

//moves ant backwards by 1 in x direction x-1
int MOVE_B(char *maze[]){
 if(maze[currX--][currY]=='p'||maze[currX--][currY]==' '||maze[currX--][currY]=='@'){
	currX--;
 if (maze[currX][currY]=='@')
	return 2;//Gold found
	return 1;//No Gold but valid space
}else
	return 0;//No valid space aka wall
//if check for valid space

}//MOVE_B

//moves ant left by 1 in y direction y-1
int MOVE_L(char *maze[]){

	 if(maze[currX][currY--]=='p'||maze[currX][currY--]==' '||maze[currX][currY--]=='@'){
	currY--;
 if (maze[currX][currY]=='@')
	return 2;//Gold found
	return 1;//No Gold but valid space
}else
	return 0;//No valid space aka wall
//if check for valid space
}//MOVE_L

//moves ant right by 1 in y direction y+1
int MOVE_R(char *maze[]){

	 if(maze[currX][currY++]=='p'||maze[currX][currY++]==' '||maze[currX][currY++]=='@'){
	currX++;
 if (maze[currX][currY]=='@')
	return 2;//Gold found
	return 1;//No Gold but valid space
}else
	return 0;//No valid space aka wall
//if check for valid space
}//MOVE_R
//checks for itch to left and returns number of free spaces although Michael does not see it,used for jumps
int CWL(char **maze){
	int x,y,i=0,itch=0;

	x=currX;
	y=currY;
	while(maze[x][y-i]==' '){
		itch++;
		i++;
	}
	return itch;//returns number of spaces free micheal cant see this but use for Jumps
	//returns 0 for no itch else returns # of itches

}//CWL
//checks for itch to Right and returns number of free spaces
int CWR(char **maze){
	int x,y,i=0,itch=0;
	x=currX;
	y=currY;
//	peek(&x,&y);
	while(maze[x][y+i]==' '){
		itch++;
		i++;
	}
	return itch;//returns number of spaces free micheal cant see this but use for Jumps
	//returns 0 for no itch else returns # of itches
	
}//CWR
//checks for itch to Forward direaction and returns number of free spaces
int CWF(char **maze){
	int x,y,i=0,itch=0;
	//peek(&x,&y);
	x=currX;
	y=currY;
	while(maze[x+i][y]==' '){
		itch++;
		i++;
	}
	return itch;//returns number of spaces free micheal cant see this but use for Jumps
	//returns 0 for no itch else returns # of itches
	
}//CWF
//checks for itch to Backwards direaction and returns number of free spaces
int CWB(char **maze){
	int x,y,i=0,itch=0;
//	peek(&x,&y);
	x=currX;
	y=currY;
	while(maze[x-i][y]==' '){
		itch++;
		i++;
	}
	return itch;//returns number of spaces free micheal cant see this but use for Jumps
	//returns 0 for no itch else returns # of itches
	
}//CWB
//Jumps to furthest itch in specified direction
//returns 1 if jump executed else returns 0
int BJPI(char* maze[],char prev[3]){
//prev is previous CW command to see what direction to jump
int x,y;
//peek(&x,&y);
x=currX;
y=currY;
int num=0;//spaces to jump
char c; //char for switch
//check to make sure previous command was CW command
if(strcmp(prev,"CWR")==0||strcmp(prev,"CWF")==0||strcmp(prev,"CWL")==0||strcmp(prev,"CWB")==0){
c =prev[2];
switch(c){

	case 'L':
		num=CWL(maze);
		if(num==0) return 0;
		currY -=num;
		//push(x,y-num);
		break;
	case 'R':
		num=CWR(maze);
		if(num==0) return 0;
		currY +=num;
		//push(x,y+num);
		break;
	case 'F':
		num=CWF(maze);
		if(num==0) return 0;
		currX +=num;
		//push(x+num,y);
		break;
	case 'B':
		num=CWR(maze);
		if(num==0) return 0;
		//push(x-num,y);
		currX -=num;
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
int CJPI(char* maze[],char prev[3]){
//prev is previous CW command to see what direction to jump
int x,y;
//peek(&x,&y);
x=currX;
y=currY;
int num=0;//check to see if jump allowed
char c; //char for switch
//check to make sure previous command was CW command
if(strcmp(prev,"CWR")==0||strcmp(prev,"CWF")==0||strcmp(prev,"CWL")==0||strcmp(prev,"CWB")==0){
c =prev[2];
switch(c){

	case 'L':
		num=CWL(maze);
		if(num==0||num==1) return 0;//added check to not jump if it cant skip current space
		currY -=2;
		//push(x,y-2);
		break;
	case 'R':
		num=CWR(maze);
		if(num==0||num==1) return 0;
		//push(x,y+2);
		currY +=2;
		break;
	case 'F':
		num=CWF(maze);
		if(num==0||num==1) return 0;
		//push(x+2,y);
		currX +=2;
		break;
	case 'B':
		num=CWR(maze);
		if(num==0||num==1) return 0;
		//push(x-2,y);
		currX -=2;
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
void BACKTRACK(){
	int x,y;
	pop(&x,&y);
	currX=x;
	currY=y;
}//BACKTRACK



