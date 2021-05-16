//Main for Final Project Ese 124 Robert Bacigalupo,Melvin Mathew,Adam Zeng
//Contains FSM,Scanner,Main,Rp action, and method action <-- helper method to convert state to action
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functions.h"
#include"stack.h"
#define MAX_SIZE 100
//array to hold actions global variable;
char act[MAX_SIZE][10];//To store List of actions from Intelligence file
int itchL=0,itchR=0,itchF=0,itchB=0;//flags for itches


int currX,currY;//current position of Michael the VA

//reset itches every move
/*old states
#define idle 0 //state to say action not carried out
#define itchL 1//cwl executed and itch present
#define itchF 2//cwF executed and itch present
#define itchR 3//cwr executed and itch present
#define itchB 4//cwB executed and itch present
#define Moved 5//Move action executed suscessfully
*/
//states
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
#define IDLE 18 //Used for next_states that dont require actions
//first read in action
//carry out action
//print action to file if carried out
//put action as current state to fsm
//get Next state/action
//carry out action
//repeat
//toString Method for States
char* toString(int state){
	char *str;
	switch(state){
		case(Mark):
			strcpy(str,"Mark");
			break;
		case(cwL):
			strcpy(str,"cwL");
			break;
		case(cwF):
			strcpy(str,"cwF");
			break;
		case(cwR):
			strcpy(str,"cwR");
			break;
		case(cwB):
			strcpy(str,"cwB");
			break;
		case(Move_F):
			strcpy(str,"Move_F");
			break;
		case(Move_B):
			strcpy(str,"Move_B");
			break;
		case(Move_L):
			strcpy(str,"Move_L");
			break;
		case(Move_R):
			strcpy(str,"Move_R");
			break;
		case(Push):
			strcpy(str,"Push");
			break;
		case(Pop):
			strcpy(str,"Pop");
			break;
		case(Peek):
			strcpy(str,"Peek");
			break;
		case(Clear):
			strcpy(str,"Clear");
			break;
		case(BJPI):
			strcpy(str,"BJPI");
			break;
		case(CJPI):
			strcpy(str,"CJPI");
			break;
		case(Back):
			strcpy(str,"Back_track");
			break;
		case(Rp):
			strcpy(str,"Rp");
			break;
		case(IDLE):
			strcpy(str,"Idle");
			break;
		case(END):
			strcpy(str,"End");
			break;
		default: break;

		}//switch
}//toString
int next_state(int current_state,char **maze,int curr_action,FILE *o_fp){

	fprintf(o_fp,"%s\n",state);//need to create method to change state to string
	int next_state=current_state;//holds next state
	int temp;//temp for check
	//0 no itch 1 itch
	if(current_state==cwL){
		if(CWL(*maze)==0){
			itchL=0;
			next_state=cwF;
		}else{
			itchL=1;
		}//check
	
	}//cwl
	else if(current_state==cwF){
			if(CWF(*maze)==0){
			itchF=0;
			next_state=cwR;
		}else{
			itchF=1;
		}//check
	}//cwF
	else if(current_state==cwR){
			if(CWR(*maze)==0){
			itchR=0;
			next_state=cwB;
		}else{
			itchR=1;
		}//check
	}//cwR
	else if(current_state==cwB){
			if(CWB(*maze)==0){
			itchB=0;
			next_state=cwL;
		}else{
			itchB=1;
		}//check
	}//cwB
	else if(current_state==Move_F){
		if(MOVE_F(*maze)==0){
			next_state=IDLE;
		}else{  //new positions reset itches
			next_state=IDLE;
			itchL=0;
			itchR=0;
			itchF=0;
			itchB=0;
		}
		
	}//Move_F
	else if(current_state==Move_B){
		if(MOVE_B(*maze)==0){
			next_state=IDLE;
		}else{  //new positions reset itches
			next_state=IDLE;
			itchL=0;
			itchR=0;
			itchF=0;
			itchB=0;
		}

	}//Move_B
	else if(current_state==Move_L){
		if(MOVE_L(*maze)==0){
			next_state=IDLE;
		}else{  //new positions reset itches
			next_state=IDLE;
			itchL=0;
			itchR=0;
			itchF=0;
			itchB=0;
		}

	}//Move_L
	  else if(current_state==Move_F){
		if(MOVE_F(*maze)==0){
			next_state=IDLE;
		}else{  //new positions reset itches
			next_state=IDLE;
			itchL=0;
			itchR=0;
			itchF=0;
			itchB=0;
		}

	}//Move_F

	else if(current_state==Push){
		push(currX,currY);
		next_state=IDLE;
	}


	else{
		next_state=IDLE;
	}
	if((current_state==cwL ||current_state==cwR ||current_state==cwF ||current_state==cwB )&&itchL==0 && itchR==0 && itchF==0 && itchB==0){
		next_state=Back;
	}else if(itchL+itchR+itchF+itchB>2){
		next_state=Mark;
	}
	return next_state;
}




	//Have check for CW if check failed 3x then back
	//void nextState(current_stat,char map,curr position) ot just curr position
	//								^
	//								input
	//flags are global variables
	// if(current_state ==cwl){
	//	if(map(x+1)(y)==*)
	//	flag=0      <--can use return of functions
	//next state = cwF;
	//	else if ' '
	//	flag =1
	//if all flags dont =1 then go back
	//void output(curr,flags){
	//if all flags are 0 then go back
	//while(1)
	//FSM{
	//read one line of command
	//convert text to current stat
	//current_state = Next_State(current_st,pos)
	//for move functions
	//if valid update else check next direction

=
//update current state from file when IDLE is next state

	//Have check for CW if check failed 3x then back
	//void nextState(current_stat,char map,curr position) ot just curr position
	//								^
	//								input
	//flags are global variables
	// if(current_state ==cwl){
	//	if(map(x+1)(y)==*)
	//	flag=0      <--can use return of functions
	//next state = cwF;
	//	else if ' '
	//	flag =1
	//if all flags dont =1 then go back
	//void output(curr,flags){
	//if all flags are 0 then go back
	//while(1)
	//FSM{
	//read one line of command
	//convert text to current stat
	//current_state = Next_State(current_st,pos)
	//for move functions
	//if valid update else check next direction

//if current state= cwl  intelligence file changes state, input is output from command
//  and wall then output =1
//needs to find entry
int main() {
int max_energy;//Max energy of Michael entered from user
	return 0;
}
