//Stack for Michael
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100

//variables for stack
int stackX[MAX_SIZE];//stack for x values   ?? maybe consolidate into 2d array
int stackY[MAX_SIZE];//stack for y values
int top=0;//top of the stack

//determines if stack is empty
//1 = empty else 0
int empty () {

	return (top == 0)? 1: 0;

} // empty

//determines is stack is full
//returns 1 if full else =0;
int full () {

	return (top == MAX_SIZE)? 1: 0;

} // full

// empties the stack
void clear () {

	top = 0;

}//clear
//returns values of top of stack without removing them using "Call by address" method to return both values
//parameters are where you liked to store value in main must be in form of (&xValue,&yValue);
//?? could also do this by making two separate methods or using integer div
//??i.e multplying x by 10 and adding it to y and return that value to decode into x and y
void peek(int *xValue, int *yValue){
	if(empty() !=1){
	*xValue = stackX[top-1];
	*yValue = stackY[top-1];
}else printf("Nothing to peek,Stack Empty\n");
	
}//peek
//returns values of top of stack,also remvoing them, using "Call by address" method to return both values
//parameters are where you liked to store value in main must be in form of (&xValue,&yValue);
void pop(int *xValue, int *yValue){
	if(empty() !=1){
	*xValue = stackX[top-1];
	*yValue = stackY[top-1];
	top--;
	}else printf("Nothing to pop,Stack Empty\n");

}//pop
//push x and y values to respective stacks
void push(int x, int y){
	stackX[top]=x;
	stackY[top]=y;
	top++;
	
}//push


	








