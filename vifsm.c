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
    eSystemState eStateMachineNextState;
    pfEventHandler pfStateMachineTrasition;
	eSystemState eStateMachineState;
	
} sStateMachine;


//function call to dispatch the amount and return the ideal state
eSystemState maybeNormalHandler(char c)
{
    printf("Maybe_Normal_State\n");
	return EXIT_SUCCESS;
	// EXIT_FAILURE
}
//function call to Enter amount and return amount entered state
eSystemState insertHandler(char c)
{
	printf("Insert_State\n");
    return EXIT_SUCCESS;
}

//function call to Enter amount and return amount entered state
eSystemState normalHandler(char c)
{
	printf("Normal_State\n");
    return EXIT_SUCCESS;
}

//Initialize array of structure with states and event with proper handler
sStateMachine asStateMachine [] =
{
    {Insert_State, maybeNormalHandler, Maybe_Normal_State},
    {Insert_State, insertHandler, Insert_State},
    {Maybe_Normal_State, normalHandler, Normal_State},
    {Maybe_Normal_State, insertHandler, Insert_State},
    {Normal_State, normalHandler, Normal_State},
    {Normal_State, insertHandler, Insert_State},
	{-1, NULL, -1}
};

int main() {
    int i;
	char input;
	eSystemState eNextState; //= On_State;
    while(asStateMachine[i].eStateMachineNextState != -1)
    {
		input = getch();
		eNextState = (*asStateMachine[i].pfStateMachineTrasition)(input);
		i++;
    }
    return 0;
}