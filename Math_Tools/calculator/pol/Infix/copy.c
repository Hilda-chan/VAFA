//#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};

// Stack Operations
struct Stack* createStack( unsigned capacity )
{
    struct Stack* stack = (struct Stack*)
        malloc(sizeof(struct Stack));

    if (!stack)
        return NULL;

    stack->top = -1;
    stack->capacity = capacity;

    stack->array = (int*) malloc(stack->capacity *
            sizeof(int));

    return stack;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1 ;
}

char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}

char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}

void push(struct Stack* stack, char op)
{
    stack->array[++stack->top] = op;
}


// A utility function to check if
// the given character is operand
int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') ||
        (ch >= 'A' && ch <= 'Z');
}

// A utility function to return
// precedence of a given operator
// Higher returned value means
// higher precedence
int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

char* spaces(char* exp)
{ 
    size_t j=0;
    char* new=malloc(sizeof(char)*(strlen(exp)*2));
    for(size_t i=0;exp[i]!='\0';i++)
    {
        new[j]=exp[i];
        strcat(new," ");
        j+=2;
    }
    strcat(new,"=");
    return new;
}
char* infixToPostfix(char* exp)
{
    int i, k;

    // Create a stack of capacity
    // equal to expression size
    struct Stack* stack = createStack(strlen(exp));
    if(!stack) // See if stack was created successfully
        return NULL;

    for (i = 0, k = -1; exp[i]; ++i)
    {

        // If the scanned character is
        // an operand, add it to output.
        if (isOperand(exp[i]))
        {
            exp[++k] = exp[i];

        }
        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (exp[i] == '(')
            push(stack, exp[i]);

        // If the scanned character is an ‘)’,
        // pop and output from the stack
        // until an ‘(‘ is encountered.
        else if (exp[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[k++] = pop(stack);
            pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return NULL; // invalid expression			
            else
                pop(stack);
        }
        else // an operator is encountered
        {
            while (!isEmpty(stack) &&
                    Prec(exp[i]) >= Prec(peek(stack)))
                exp[k++] = pop(stack);
            push(stack, exp[i]);
        }

    }

    // pop all the operators from the stack
    while (!isEmpty(stack))
        exp[k++] = pop(stack );

    exp[k] = '\0';
    //printf( "%s", exp );
    char* res=spaces(exp);
    return res;
}


char * Infix(char * src)
{

    char expr4[100];
    strcpy(expr4, src);
    return infixToPostfix(expr4);
}
