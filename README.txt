READ ME
The maze for Michael the VA is populated from the maze.txt file and displayed on the program showing * for walls and @ for gold bags in the main.c. The user is also prompted to input the desired maximum energy for Michael. This means 
that every action michael carries out utilizes energy. This energy consumption depends on the action that he is carrying out. He must collect as many bags of gold as possible
before running out of energy
Prewritten commands in the intelliegnce.txt file are what Michael uses in his actions
All possible commands for Michael exist in the functions.c program
These files are then imported into the program 
Intelligence file commands act as inputs to the FSM present in the main()
Each input command imported from the intelligence.txt file brings FSM to state with corresponding input name
FSM then carries out action of State
Stack.c manages the various stack commands present in the functions.c
EOS ends the FSM program
Each action takes required amount of energy
Every time Michael encounters gold, the counter for gold increments
If all energy used the program again ends
The program will output a total list of actions that Michael carried out as well as the number of gold bags that he picked up as well



//way to check all of maze:
keep checking for left
mark everytime more than one itch
BackTrack when dead end reached

