#include<stdio.h>
#include<stdlib.h>

#define STACKSIZE 100
#define INT 1
#define FLOAT 2
#define STRING 3

struct stack
{
    int top;
    int items[STACKSIZE];
};

struct stack s;

void push(struct stack *ps, int x)
{
    if(ps->top == STACKSIZE-1)
        printf("STACK FULL");
    else
    {
        ++(ps->top);
        ps->items[ps->top] = x;
    }
}

int pop(struct stack *ps)
{
    if(ps->top == -1)
        printf("STACK EMPTY");
    else
    {
        int x = ps->items[ps->top];
        --(ps->top);
        return x;
    }
}

int display(struct stack *ps)
{
    if(ps->top == -1)
        printf("STACK EMPTY");
    else
    {
        for(int i = ps->top; i>=0; i--)
        {
            printf("%d",ps->items[i]);
        }
    }
}

int peep(struct stack *ps)
{
    if(ps->top == -1)
        printf("STACK EMPTY");
    else{
        int x = ps->items[ps->top];
        return x;
    }
}

int empty(struct stack *ps)
{
    if(ps->top == -1)
        return 1;
    return 0;
}

int overflow(struct stack *ps)
{
    if(ps->top == STACKSIZE-1)
        return 1;
    return 0;
}
