// rpn.c: reverse polish notation calculator

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define NUMBER  '0'     /* indicates number found */
#define TOOBIG  '9'     /* indicates string is too big */

int getop(char *dest, int limit);

double toto(char * input, int * error);

char * Calculus(char * expr)
{

    int * e = 0;
    double res = toto(expr, e);
    if(e == 0)
    {
        char * buffer = malloc(sizeof(char)*40);
        snprintf(buffer, 40, "%f", res);
        return buffer;
    }
    else
        return "Wrong expression or unable to compute";
}



double toto(char *input, int * error)
{
    double op2;
    int i = 0;
    while (i < 20)
    {
        switch (*input)
        {
        case '0':
            push1(atof(input));
            break;
        case '1':
            push1(atof(input));
            break;
        case '2':
            push1(atof(input));
            break;
        case '3':
            push1(atof(input));
            break;
        case '4':
            push1(atof(input));
            break;
        case '5':
            push1(atof(input));
            break;
        case '6':
            push1(atof(input));
            break;
        case '7':
            push1(atof(input));
            break;
        case '8':
            push1(atof(input));
            break;
        case '9':
            push1(atof(input));
            break;
        case '+':
            push1(pop1() + pop1());
            break;
        case '*':
            push1(pop1() * pop1());
            break;
        case '-':
            op2 = pop1();
            push1(pop1() - op2);
            break;
        case '/':
            op2 = pop1();
            if ( op2 == 0.0 )
                printf("Divide by zero.\n");
            else
                push1(pop1() / op2);
            break;
        case '=':
            {
                return push1(pop1());
            }
            break;
        case 'c':
            clear_stack1();
            break;

        default:
            input++;
            continue;
        }
        i++;
        input++;
    }
    *error = 1;
    exit(0);
}

int getop(dest, limit)
char *dest;                     // alternative way to specify argument types
int limit;
{
   int i, c;

   while ( (c = getchar()) == ' ' || c == '\t' || c == '\n' )
      ;
   if ( c != '.' && (c < '0' || c > '9') )
      return c;
   dest[0] = c;
   for(i = 1; (c = getchar()) >= '0' && c <= '9'; ++i)
      if ( i < limit )
         dest[i] = c;
   if ( c == '.' ) 
   { // collect fractional portion
      if ( i < limit )
         dest[i] = c;
      for(i++; (c = getchar()) >= '0' && c <= '9'; ++i)
         if ( i < limit )
            dest[i] = c;
   }
   if ( i < limit ) 
   { /* number is ok */
      ungetc(c, stdin);
      dest[i] = '\0';
      return NUMBER;
   } 
   else 
   { /* input is too big; skip rest of line */
      while ( c != '\n' && c != EOF )
         c = getchar();
      dest[limit - 1] = '\0';
      return TOOBIG;
   }
}
