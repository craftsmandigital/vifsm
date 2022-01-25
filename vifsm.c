#include <stdio.h>
// some reshources
// Linked list explanation
// https://www.youtube.com/watch?v=MCIwn7mY4jY
// cd '/c/Users/jviks/My Documents/OneDrive - Mikaelkirken/dev/c/vifsm'

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
}