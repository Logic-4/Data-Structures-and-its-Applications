#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int deque[MAX];
int front = -1;
int rear = -1;

int isempty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}

int isfull()
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        return 1;
    else
        return 0;
}
void ef(int data)
{
    if (isfull())
    {
        printf("queue overflow.\n");
        exit(1);
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
        front = MAX - 1;
    else
        front = front - 1;
    deque[front] = data;
}

void er(int data)
{
    if (isfull())
    {
        printf("queue overflow\n");
        exit(1);
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX - 1)
        rear = 0;
    else
        rear = rear + 1;
    deque[rear] = data;
}

int df()
{
    int data;
    if (isempty())
    {
        printf("queue underflow\n");
        exit(1);
    }
    data = deque[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == MAX - 1)
            front = 0;
        else
            front = front + 1;
    }
    return data;
}

int dr()
{
    int data;
    if (isempty())
    {
        printf("queue underflow\n");
        exit(1);
    }
    data = deque[rear];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (rear == 0)
            rear = MAX - 1;
        else
            rear = rear - 1;
    }
    return data;
}

int peek()
{
    if (isempty())
    {
        printf("queue underflow\n");
        exit(1);
    }
    return deque[front];
}

void print()
{
    int temp;
    if (isempty())
    {
        printf("queue underflow\n");
        exit(1);
    }
    temp = front;
    if (front <= rear)
    {
        while (temp <= rear)
        {
            printf("%d", deque[temp]);
            temp++;
        }
    }

    else
    {
        while (temp <= MAX - 1)
        {
            printf("%d", deque[temp]);
            temp++;
        }
    }
    printf("\n");
}

int main()
{
    int choice, data;
    while (1)
    {
        printf("1.Insert at front\n");
        printf("2.Insert at rear\n");
        printf("3.Delete fron front\n");
        printf("4.Delete from rear\n");
        printf("5. Print the first element\n");
        printf("6.Print all the elements\n");
        printf("7. Quit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the element to be added in the queue:");
            scanf("%d", &data);
            ef(data);
            break;
        case 2:
            printf("enter the element to be added in the queue:");
            scanf("%d", &data);
            er(data);
            break;

        case 3:
            data = dr();
            printf("deleted element is %d\n", data);
            break;
        case 4:
            data = dr();
            printf("deleted element is %d\n", data);
            break;

        case 5:
            printf("first element is %d\n", peek());
            break;

        case 6:
            print();
            break;

        case 7:
            exit(1);
        default:
            printf("wrong choice\n");
        }
    }
}