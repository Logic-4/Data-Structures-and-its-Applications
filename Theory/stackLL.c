#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} *top = NULL;

void push(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Stack Overflow");
        exit(1);
    }

    newnode->data = data;
    newnode->link = top;
    top = newnode;
}

int isEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

int pop()
{
    struct node *temp;
    temp = top;
    int val;

    if (isEmpty())
    {
        printf("Stack Underflow/Empty");
        exit(1);
    }

    val = temp->data;
    top = top->link;
    free(temp);
    temp = NULL;
    return val;
}

void display()
{
    struct node *temp = top;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->link;
    }
}

int main()
{
    int op, d;
    while (1)
    {
        printf("\nEnter\n1. Push\n2.Pop\n3.Display\n4.Quit\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            printf("\nEnter data\n");
            scanf("%d", &d);
            push(d);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Enter proper value");
        }
    }
}