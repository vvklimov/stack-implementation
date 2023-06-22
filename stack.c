#include "stack.h"


void StackInit(Stack *stack)
{
    stack->top = NULL;
}

void PUSHS(Stack *stack, char *data)
{
    StackTopPtr lastone = (StackTopPtr)malloc(sizeof(struct StackTop));
    if (lastone != NULL)
    {
        lastone->data = data;
        if (stack->top == NULL)
            lastone->previousElement = NULL;
        else
            lastone->previousElement = stack->top;
        stack->top = lastone;
    }
}
char* POPS(Stack *stack, char *value)
{
    if (stack->top != NULL)
    {   
        value = stack->top->data;
        StackTopPtr previous = stack->top->previousElement;
        free(stack->top);
        stack->top = previous;
        return value;
    }
    else
        printf("chyba 56\n");
}
void CLEARS (Stack *stack)
{
    if (stack->top != NULL)
	{
        StackTopPtr obliterable = stack->top;
		while(stack->top != NULL) 
		{	
			stack->top = obliterable->previousElement;
            free(obliterable);
            obliterable = stack->top;
		}
	}
}
void ShowStack(Stack *stack)
{
    if (stack->top != NULL)
    {   
        StackTopPtr element = stack->top;
        while (element != NULL)
        {
            printf("%s\n", element->data);
            element = element->previousElement;
        }
    }
    else
        printf("Stack is empty\n");
}
void ShowTop(Stack *stack)
{   
    if (stack->top != NULL)
        printf("%s\n", stack->top->data);
    else 
        printf("Stack is empty\n");
}


int main()
{   //test
    char *str1 = "1111";
    char *str2 = "2222";
    char *str3 = "3333";
    char *str4 = "4444";
    Stack stack;
    Stack *stack_test = &stack;
    StackInit(stack_test);
    /*test0*/
    printf("test0:\n\n");
    printf("Expected:\n");
    printf("Stack is empty\n");
    printf("\nGot:\n");
    ShowStack(stack_test);
    printf("---------------------------------------------------------------------------------------------\n");
    /*test1*/
    char *t = NULL;
    printf("test1:\n\n");
    printf("Expected:\n");
    printf("chyba 56\n");
    printf("\nGot:\n");
    POPS(stack_test, t);
    printf("---------------------------------------------------------------------------------------------\n");
    /*test2*/
    PUSHS(stack_test, str1);
    PUSHS(stack_test, str2);
    PUSHS(stack_test, str3);
    printf("test2:\n\n");
    printf("Expected:\n");
    printf("3333\n2222\n1111\n");
    printf("\nGot:\n"); 
    ShowStack(stack_test); 
    printf("---------------------------------------------------------------------------------------------\n");
    /*test3*/
    printf("test3:\n\n");
    printf("Expected:\n");
    printf("3333\n");
    printf("Got:\n"); 
    ShowTop(stack_test);
    printf("---------------------------------------------------------------------------------------------\n");
    printf("test4:\n\n");
    printf("Expected:\n");
    printf("3333\n2222\n");
    printf("Got:\n"); 
    t = POPS(stack_test, t);
    /*var t has value of the element we just popped, meanwhile now at the top of the stack is 2222 element*/ 
    printf("%s\n", t);
    ShowTop(stack_test);
    printf("---------------------------------------------------------------------------------------------\n");
    printf("test5:\n\n");
    printf("Expected:\n");
    printf("2222\n2222\n1111");
    printf("\nGot:\n"); 
    ShowTop(stack_test); // 2222
    ShowStack(stack_test); // 2222 1111
    printf("---------------------------------------------------------------------------------------------\n");
    printf("test6:\n\n");
    printf("Expected:\n");
    printf("4444\n2222\n1111");
    printf("\nGot:\n");
    PUSHS(stack_test, str4);
    ShowStack(stack_test);
    printf("---------------------------------------------------------------------------------------------\n");
    printf("test7:\n\n");
    printf("Expected:\n");
    printf("Stack is empty\n");
    printf("\nGot:\n");
    CLEARS(stack_test);
    ShowStack(stack_test);
    printf("---------------------------------------------------------------------------------------------\n");
    //has to be empty
    return 0;
}
