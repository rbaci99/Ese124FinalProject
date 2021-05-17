//Main for Final Project Ese 124 Robert Bacigalupo,Melvin Mathew,Adam Zeng
//Contains FSM,Scanner,Main,Rp action, and method action <-- helper method to convert state to action
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functions.h"
#include"stack.h"
#define MAX_SIZE 100
//Global variables
char act[MAX_SIZE][10];//To store List of actions from Intelligence file
int itchL=0,itchR=0,itchF=0,itchB=0;//flags for itches //0 no itch 1 itch
int Max_energy;//Max energy of Michael entered from user
int x,y; //temp variables to store, mostly to discard popped values in pop state
int currX,currY;//current position of Michael the VA
int cnt=0;//counter for rp

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
			strcpy(str,"Pushed current position");
			break;
		case(Pop):
			strcpy(str,"Popped");
			break;
		case(Peek):
			strcpy(str,"Peeked");
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
int next_state(int current_state,char **maze,int curr_action,FILE *o_fp,int n,int t){
	char state[]=;
	int next_state=IDLE;//holds next state
	int temp;//temp for check
	//0 no itch 1 itch
	if(current_state==Mark){
		MARK(currX,currY,*maze);
		Max_energy-=3;
		next_state=IDLE;
	}else if(current_state==cwL){
	strcpy(state,toString(current_state));
	fprintf(o_fp,"%s\n",state);
		if(CWL(*maze)==0){
			itchL=0;
			next_state=cwF;
		}else{
			itchL=1;
		}//check
	Max_energy--;
	}//cwl
	else if(current_state==cwF){
	strcpy(state,toString(current_state));
	fprintf(o_fp,"%s\n",state);
			if(CWF(*maze)==0){
			itchF=0;
			next_state=cwR;
		}else{
			itchF=1;
		}//check
		Max_energy--;
	}//cwF
	else if(current_state==cwR){
	strcpy(state,toString(current_state));
	fprintf(o_fp,"%s\n",state);
			if(CWR(*maze)==0){
			itchR=0;
			next_state=cwB;
		}else{
			itchR=1;
		}//check
		Max_energy--;
	}//cwR
	else if(current_state==cwB){
	strcpy(state,toString(current_state));
	fprintf(o_fp,"%s\n",state);
			if(CWB(*maze)==0){
			itchB=0;
			next_state=cwL;
		}else{
			itchB=1;
		}//check
		Max_energy--;
	}//cwB
	else if(current_state==Move_F){
		if(MOVE_F(*maze)==0){
			next_state=IDLE;//move didnt happen
		}else{  //move happened new position reset itches
			strcpy(state,toString(current_state));
			fprintf(o_fp,"%s\n",state);
			next_state=IDLE;
			itchL=0;
			itchR=0;
			itchF=0;
			itchB=0;
			Max_energy-=3;
		}
		
	}//Move_F
	else if(current_state==Move_B){

		if(MOVE_B(*maze)==0){
			next_state=IDLE;
		}else{  //new positions reset itches
			strcpy(state,toString(current_state));
			fprintf(o_fp,"%s\n",state);
			next_state=IDLE;
			itchL=0;
			itchR=0;
			itchF=0;
			itchB=0;
			Max_energy-=3;
		}
	}//Move_B
	else if(current_state==Move_L){
		if(MOVE_L(*maze)==0){
			next_state=IDLE;
		}else{  //new positions reset itches
			strcpy(state,toString(current_state));
			fprintf(o_fp,"%s\n",state);
			next_state=IDLE;
			itchL=0;
			itchR=0;
			itchF=0;
			itchB=0;
			Max_energy-=3;
		}
		
	}//Move_L
	else if(current_state==Move_R){
		if(MOVE_R(*maze)==0){
			next_state=IDLE;
		}else{  //new positions reset itches
		strcpy(state,toString(current_state));
		fprintf(o_fp,"%s\n",state);
			next_state=IDLE;
			itchL=0;
			itchR=0;
			itchF=0;
			itchB=0;
			Max_energy-=3;
		}
	}//Move_R
	else if(current_state==Push){
		if(full()!=1){
		strcpy(state,toString(current_state));
		fprintf(o_fp,"%s\n",state);
		push(currX,currY);
		next_state=IDLE;
		Max_energy-=4;
	}else{
		next_state=Clear;
	}
	}//Push
	else if(current_state==Pop){
		if(empty!=1){
		strcpy(state,toString(current_state));
		fprintf(o_fp,"%s ",state);
		pop(&x,&y);
		fprintf("Forgot position (%d,%d)\n",x,y);
		Max_energy-=4;
	}//if stack is not empty
		next_state=IDLE;
	}//Pop
	else if(current_state=Peek){
		if(empty()!=1)
		{
		strcpy(state,toString(current_state));
		fprintf(o_fp,"%s ",state);
		peek(&x,&y);
		fprintf(o_fp,"(%d,%d)\n",x,y);
		Max_energy-=2;
	}
		next_state=IDLE;
	}//Peek
	else if(current_state=Clear){
		strcpy(state,toString(current_state));
		fprintf(o_fp,"%s\n",stat
		clear();
		next_state=IDLE;
		Max_energy-=2;
	}//Clear
	else if (current_state==Back){
		if(empty()!=0){
			BACKTRACK();
			fprintf(o_fp,"BackTrack");
		}
		next_state=IDLE;
	}//BackTrack
	else if(current_state==BJPI){
		if(BJPI(*maze,act[curr_action-1])==1){
			Max_energy-=5;
		}
		next_state=IDLE;
	}//BJPI
	else if(current_state==CJPI){
		if(CJPI(*maze,act[curr_action-1])==1){
			Max_energy-=3;
		}
		next_state=IDLE;
	}//CJPI
	else if(current_state==Rp){
		if(curr_action-n>=0 && cnt<t){
		cnt++;
		curr_action =curr_action-n;
		strcpy(state,toString(current_state));
		fprintf(o_fp,"%s\n",stat
	}//if
	if(cnt==t)
		cnt=0;
		next_state=IDLE;
	}//Rp
	else if(currentState==END){
		strcpy(state,toString(current_state));
		fprintf(o_fp,"%s\n",stat
		next_state=END;//check outside of program
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


//have check to see if stack full

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
	int gold=0;//count of gold
	int r,c;
	int current_state,next_state;
	char temp;
	char maze[SIZE][SIZE];
	FILE *file,*o_fp;
	int ch=getc(file);
//open output
if ((file = fopen("output.txt","w")) == NULL){
       printf("Error! with Output file");

       // Program exits if returns NULL.
       exit(1);
   }
//open Maze
if ((file = fopen("maze.txt","r")) == NULL){
       printf("Error! opening Maze file");

       // Program exits if returns NULL.
       exit(1);
   }
for (r=0;r<SIZE;r++){ //increments through 2d array
	for (c=0;c<=SIZE;c++)
		{
			//	if ((temp=fgetc(file))!=EOF)
				if (fscanf(file,"%c",&maze[r][c])!=EOF);	//checks for end of the file
			{
			//	fscanf(file,"%c",&maze[r][c]);
				printf("%c",maze[r][c]);
            }

		}
}
	fclose(file);
printf("Enter Max Energy");
scanf("%d",&max_energy);
printf("MaxEnergy:%d",max_energy);
while(max_energy>0&&current_state!=END){

}
	return 0;
}
