// stack.c: implementation of stack

#include "stack.h"
#include <stdio.h>

#define MAXSIZE 100

static int sp = 0;              /* stack pointer */
static double values[MAXSIZE];  /* stack */

double push1(double number) {
   if ( sp < MAXSIZE )
      values[sp++] = number;
   else
      printf("Error: push on full stack.\n");
   return number;
}

double pop1() {
   if ( sp > 0 )
      return values[--sp];
   else {
      printf("Error: pop from empty stack.\n");
      clear_stack1();
      return 0;
   }
}

void clear_stack1() {
   sp = 0;
}
