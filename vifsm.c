#include <stdio.h>
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
    Idle_State,
    On_State,
    Pin_Eentered_State,
    Option_Selected_State,
    Amount_Entered_State,
} eSystemState;



//typedef of function pointer
typedef eSystemState (*pfEventHandler)(void);



//structure of state and event with event handler
typedef struct
{
    eSystemState eStateMachineNextState;
    pfEventHandler pfStateMachineTrasition;
	eSystemState eStateMachineState;
	
} sStateMachine;


//function call to dispatch the amount and return the ideal state
eSystemState offHandler(void)
{
    return Idle_State;
	printf("From on to off\n");
}
//function call to Enter amount and return amount entered state
eSystemState onHandler(void)
{
	printf("From off to on\n");
    return On_State;
}

//Initialize array of structure with states and event with proper handler
sStateMachine asStateMachine [] =
{
    {Idle_State,onHandler,On_State},
	{On_State,offHandler,Idle_State}
};

int main() {
	
}














/* 
void inc(int *a)
{
  
  ++*a;
}


int main() {
	int a;
	int *b;

	a = 10;
	b = &a;
   // printf() displays the string inside quotation
   printf("a: %d\n", a);
   printf("*b: %d\n", *b);
   *b = 22;
   printf("a: %d\n", a);
   inc(&a);
   printf("a: %d\n", a);
   printf("Hello, World!\n");
   return 0;
} */