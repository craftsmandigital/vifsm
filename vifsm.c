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


//function call to dispatch the amount and return the ideal state
eSystemState maybeNormalHandler(char c)
{
    if (c == 'j') {
		printf("Maybe_Normal_State\n");
		return EXIT_SUCCESS;
	}
	else {
		return EXIT_FAILURE;
	}
}

eSystemState intoNormalHandler(char c)
{
    if (c == 'j') {
		printf("Normal_State\n");
		return EXIT_SUCCESS;
	}
	else {
		return EXIT_FAILURE;
	}
}

eSystemState outOfNormalHandler(char c)
{
    if (c == 'i') {
		printf("Insert_State\n");
		return EXIT_SUCCESS;
	}
	else {
		return EXIT_FAILURE;
	}
}


//function call to Enter amount and return amount entered state
eSystemState insertHandler(char c)
{
	// No action required. This handler needs to be the last for current state
	// It chould have been tested on "i" or "j"
	printf("Insert_State\n");
    return EXIT_SUCCESS;
}

//function call to Enter amount and return amount entered state
eSystemState normalHandler(char c)
{
	// No action required. This handler needs to be the last for current state
	// It chould have been tested on "i" or "j"
	printf("Normal_State\n");
    return EXIT_SUCCESS;
}

//Initialize array of structure with states and event with proper handler
sStateMachine asStateMachine [] =
{
    {Insert_State, maybeNormalHandler, Maybe_Normal_State},
    {Insert_State, insertHandler, Insert_State},
    {Maybe_Normal_State, intoNormalHandler, Normal_State},
    {Maybe_Normal_State, insertHandler, Insert_State},
    {Normal_State, outOfNormalHandler, Insert_State},
    {Normal_State, normalHandler, Normal_State},
	{-1, NULL, -1}
};

int main() {
 	char input;

	eSystemState eNextState = asStateMachine[0].eStateMachineState;


    while(input != 'q')
    {
		int i = 0, validState;
		input = getch();			
		printf("Input char: %c --> ", input);
		
	while(asStateMachine[i].eStateMachineState != -1)
    {

		if (asStateMachine[i].eStateMachineState == eNextState)
		{
			validState = (*asStateMachine[i].pfStateMachineTrasition)(input);
			if (validState == EXIT_SUCCESS)
			{
				printf("  Loop counter: %d --> ", i);
				printf("  From state: %d --> ", eNextState);
				eNextState = asStateMachine[i].eStateMachineNextState;
				printf("  To state: %d --> ", eNextState);
				break;
			}
		}
		i++;
    }
	}
    return 0;
}




/* 
int main() {
    int i, validState;
	char input;
	eSystemState eNextState = asStateMachine[0].eStateMachineState;
    while(asStateMachine[i].eStateMachineState != -1)
    {
		if (asStateMachine[i].eStateMachineState == eNextState)
		{
			input = getch();			
			printf("Input char: %c --> ", input);
			
			validState = (*asStateMachine[i].pfStateMachineTrasition)(input);
			if (validState == EXIT_SUCCESS)
			{
				printf("Loop counter: %d --> ", i);
				printf("From state: %d --> ", eNextState);
				eNextState = asStateMachine[i].eStateMachineNextState;
				printf("To state: %d --> ", eNextState);
				
				i = 0;
			}
		}
		i++;
    }
    return 0;
} */