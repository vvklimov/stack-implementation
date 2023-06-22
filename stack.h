#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct StackTop {
    char *data;
    struct StackTop *previousElement;
} *StackTopPtr;

typedef struct {
	StackTopPtr top;
} Stack;

void StackInit(Stack *);
void PUSHS(Stack *, char *data);
char *POPS(Stack *, char *);
void CLEARS (Stack *);
void ShowStack(Stack *);
void ShowTop(Stack *);

#endif