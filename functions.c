//Functions for Michael
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"stack.h";
//marks current position as 'p' for pheremone
//make sure to follow all moves by mark
void MARK(int row,int col,char *maze){
	maze[row][col]='p';
	
}//MARK

//moves ant foward by 1 in x direction
void MOVE_F(){
 //add check in main file to see if maze is *   ??should we put check in here instead
 //add in main so that way we can print to file if invalid spot
	int x = stackX[top];
	int y = stackY[top];
	push(x+1,y);
}//MOVE_F

//moves ant backwards by 1 in x direction
void MOVE_B(){
	int x = stackX[top];
	int y = stackY[top];
	push(x-1,y);
}//MOVE_B

//moves ant left by 1 in y direction
void MOVE_L(){
	int x = stackX[top];
	int y = stackY[top];
	push(x,y-1);
}//MOVE_L

//moves ant right by 1 in y direction
void MOVE_R(){
	int x = stackX[top];
	int y = stackY[top];
	push(x,y+1);
}//MOVE_R
//checks for itch to left and returns number of free spaces
int CWL(char *maze){
	
}




