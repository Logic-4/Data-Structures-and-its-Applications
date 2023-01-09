#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 20

typedef struct
{
    int S1[MAXSIZE]; // stack used for enqueue
    int S2[MAXSIZE]; // stack used for dequeue
    int top1;            // top element position of S1
    int top2;            // top element position of S2
} MyQueue;

void push(int *stackk, int *top, int doa)
{
    (*top)++;
    stackk[*top] = doa;
}

int pop(int *stackk, int *top)
{
    if (*top == -1)
        return -1;
    int ptr = stackk[*top];
    (*top)--;
    return ptr;
}

// check if the queue is empty
bool empty(MyQueue *q)
{
    if (q->top1 == -1)
        return true;
    else
        return false;
}

// push the element x to the rear end of the queue
void enqueue(MyQueue *q, int x)
{
    push(q->S1, &(q->top1), x);
}

// retrieve and remove the element from the front end of the queue
int dequeue(MyQueue *q)
{
    if (empty(q))
        return -1;
    while (q->top1 != -1)
    {
        int doa = pop(q->S1, &(q->top1));
        push(q->S2, &(q->top2), doa);
    }
    int x = pop(q->S2, &(q->top2));
    while (q->top2 != -1)
    {
        int doa = pop(q->S2, &(q->top2));
        push(q->S1, &(q->top1), doa);
    }
    return x;
}

// retrieve the element from the front end of the queue
int peek(MyQueue *q)
{
    if (empty(q))
        return -1;
    while (q->top1 != -1)
    {
        int doa = pop(q->S1, &(q->top1));
        push(q->S2, &(q->top2), doa);
    }
    int x = q->S2[q->top2];
    while (q->top2 != -1)
    {
        int doa = pop(q->S2, &(q->top2));
        push(q->S1, &(q->top1), doa);
    }
    return x;
}

int validate(MyQueue *q, int pops)
{
    if (q->top2 != -1 || q->top1 < pops)
    {
        return -1;
    }

    int x = pops, ele = -1;
    while (x > 0 && q->top1 != -1)
    {
        q->S2[++q->top2] = q->S1[q->top1--];
        x--;
    }

    if (q->top1 != -1)
    {
        ele = q->S1[q->top1];
    }

    x = pops;
    while (x > 0 && q->top2 != -1)
    {
        q->S1[++q->top1] = q->S2[q->top2--];
        x--;
    }

    return ele;
}

int main()
{
    MyQueue q;
    q.top1 = -1;
    q.top2 = -1;

    int no_of_operations;
    scanf("%d", &no_of_operations);

    int ele, correct_ele, no_of_pops;
    char operation;

    for (int i = 0; i < no_of_operations; i++)
    {
        scanf(" %c", &operation);
        switch (operation)
        {
        case 'E':
            scanf("%d", &ele);
            enqueue(&q, ele);
            printf("1 ");
            break;

        case 'D':
            ele = dequeue(&q);
            printf("%d ", ele);
            break;

        case 'P':
            ele = peek(&q);
            printf("%d ", ele);
            break;

        case 'V':
            scanf("%d", &no_of_pops);
            printf("%d ", validate(&q, no_of_pops));
            break;
        }
    }

    return 0;
}