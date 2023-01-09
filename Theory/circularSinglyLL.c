#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* addAtEnd(struct node *tail, int data)
{
    struct node *newP = (struct node*)malloc(sizeof(struct node));
    newP->data = data;
    newP->next = tail->next;
    tail->next = newP;
    tail = newP;

    return tail;
}

struct node* addAtPos(struct node *tail, int data, int pos)
{
    struct node *newP = (struct node*)malloc(sizeof(struct node));
    newP->data = data;
    struct node *ptr;
    ptr = tail->next;
    while(pos>1)
    {
        ptr = ptr->next;
        pos--;
    }
    newP->next = ptr->next;
    ptr->next = newP;
    if(ptr = tail)
    {
        tail = ptr->next;
    }
    return tail;
}

struct node* delAtLast(struct node *tail)
{
    struct node *ptr = tail->next;
    while(ptr->next != tail)
    {
        ptr = ptr->next;
    }
    ptr->next = tail->next;
    free(tail);
    tail = ptr;
    return tail;
}
/*
struct node* delAtPos(struct node *tail, int pos)
{
    struct node *ptr = tail->next;
    while (pos>1)
    {
        ptr = ptr->next;
    }
    ptr->next = ptr->next->next;
}
*/
int main()
{
    
    
    return 0;
}