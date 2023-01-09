#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *rear;
struct node *front;

void enqueue(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    
    if(rear == NULL)
        front = rear = temp;
    else
    {
        rear->link = temp;
        rear = temp;
    }
}

void dequeue()
{
    struct node *temp = front;
    int data;
    data = front->data;
    front = front->link;
    free(temp);
    temp = NULL;
}

void display()
{
    struct node *temp = front;
    while (temp != NULL)
    {
        printf("->");
        printf(" %d ",temp->data);
        temp = temp->link;
    }
}

int main()
{
    enqueue(4);
    enqueue(3);
    enqueue(2);
    dequeue();
    display();
    return 0;
}