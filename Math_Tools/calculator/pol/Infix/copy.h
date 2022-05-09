#ifndef _copy_h
#define _copy_h

struct Stack
{
	int top;
	unsigned capacity;
	int* array;
};

struct Stack* createStack( unsigned capacity );
int isEmpty(struct Stack* stack);
char peek(struct Stack* stack);
char pop(struct Stack* stack);
void push(struct Stack* stack, char op);
int isOperand(char ch);
int Prec(char ch);
char* spaces(char* exp);
char* infixToPostfix(char* exp);


#endif
