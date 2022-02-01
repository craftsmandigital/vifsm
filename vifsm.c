#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
// some reshources
// Finite state mashine dock on C
// https://aticleworld.com/state-machine-using-c
// https://stackoverflow.com/questions/50165534/finite-state-machines-in-c
// Linked list explanation
// https://www.youtube.com/watch?v=MCIwn7mY4jY
// cd '/c/Users/jviks/My Documents/OneDrive - Mikaelkirken/dev/c/vifsm'	

//Different state of ATM machine
typedef enum
{
    Insert_State,
    Maybe_Normal_State,
    Normal_State
} eSystemState;



//typedef of function pointer
typedef eSystemState (*pfEventHandler)(char);



//structure of state and event with event handler
typedef struct
{
    eSystemState eStateMachineState;
    pfEventHandler pfStateMachineTrasition;
	eSystemState eStateMachineNextState;
	
} sStateMachine;



void printState(eSystemState state)
{
   switch(state) {

   case Insert_State  :
      printf("Insert_State\n");
      break; /* optional */

   case Normal_State:
      printf("Normal_State\n");
      break; /* optional */
	
   case Maybe_Normal_State :
      printf("Maybe_Normal_State\n");
      break; /* optional */
  
   /* you can have any number of case statements */
   default : /* Optional */
   printf("State %d is not valid\n", state);
	}
}



eSystemState intoNormalHandler(char c)
{
    if (c == 'j') {
		return EXIT_SUCCESS;
	}
	else {
		return EXIT_FAILURE;
	}
}

eSystemState outOfNormalHandler(char c)
{
    if (c == 'i') {
		return EXIT_SUCCESS;
	}
	else {
		return EXIT_FAILURE;
	}
}


//function call to Enter amount and return amount entered state
eSystemState stdHandler(char c)
{
	// No action required. This handler needs to be the last for current state
	// It chould have been tested on "i" or "j"
   return EXIT_SUCCESS;
}

//Initialize array of structure with states and event with proper handler
sStateMachine asStateMachine [] =
{
    {Insert_State, intoNormalHandler, Maybe_Normal_State},
    {Insert_State, stdHandler, Insert_State},
    {Maybe_Normal_State, intoNormalHandler, Normal_State},
    {Maybe_Normal_State, stdHandler, Insert_State},
    {Normal_State, outOfNormalHandler, Insert_State},
    {Normal_State, stdHandler, Normal_State},
	{-1, NULL, -1}
};

eSystemState goToNextState(eSystemState eNextState, char input)
{
	int i = 0, validState;
			
	while(asStateMachine[i].eStateMachineState != -1)
    {

		if (asStateMachine[i].eStateMachineState == eNextState)
		{
			validState = (*asStateMachine[i].pfStateMachineTrasition)(input);
			if (validState == EXIT_SUCCESS)
			{
				return asStateMachine[i].eStateMachineNextState;
			}
		}
		i++;
    }
}


int main() {
 	char input;

	eSystemState eNextState = asStateMachine[0].eStateMachineState;


    while(input != 'q')
    {
		input = getch();
		printf("Input char: %c --> ", input);
		eNextState = goToNextState(eNextState, input);
		printState(eNextState);

	}
    return 0;
}