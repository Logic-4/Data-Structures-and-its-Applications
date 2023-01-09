#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int queue[20];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    if (front = -1)
    {
        front = 0;
    }
    rear = rear + 1;
    queue[rear] = data;
}

void dequeue()
{
    front++;
}

void display()
{
    int i = 0;
    for (i=front; i<rear+1;i++)
    {
        printf("->");
        printf(" %d ",queue[i]);
    }
    printf("\n");
}

int main()
{
    int a,b;
    printf("Enter number of data: ");
    scanf("%d",&a);
    for (int i=0; i<a; i++)
    {
        printf("\nEnter data:\n");
        scanf("%d",&b);
        enqueue(b);
    }
    display();
    dequeue();
    display();
    return 0;
}