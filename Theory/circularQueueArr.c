#include <stdio.h>
#include <stdlib.h>
#define size 5
int q[size];
int r = -1;
int f = -1;

int qinsert(int x)
{
    // f ,r are pointers to front and rear of the queue, size is the max size of queue
    // check for queue overflow
    if ((r + 1) % size == f)
    {
        printf("Queue Overflow..\n");
        return -1;
    }
    else
    {
        r = (r + 1) % size; // get the rear index
        q[r] = x;           // insert at rear index
        if (f == -1)        // if first element
            f = 0;          // make front point to 0
        return 1;
    }
}
int delete ()
{
    int x;
    if (f == -1 && r == -1)
    {
        printf("Q is empty\n");
        return -1;
    }
    else
    {
        x = q[f];
        if (f == r) // only one element
            f = r = -1;
        else
            f = (f + 1) % size; // increment the front
        return x;
    }
}

void display()
{
    int y = f;
    if (y == -1)
        printf("\nQueue empty..\n");
    else
    {
        while (y != r) // increment front till it reaches rear
        {
            printf("%d ", q[y]);
            y = (y + 1) % size;
        }
        printf("%d\n", q[y]); // display the last element
    }
}

int main()
{
    int n, ch, item, item_del;
    while (1)
    {
        printf("1-Insert\n 2-delete\n 3-display\n 4-exit\n");
        printf("Enter the choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to insert in queue\n ");
            scanf("%d", &item);
            qinsert(item);
            break;
        case 2:
            item_del = delete ();
            printf("Item deleted is %d\n", item_del);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}