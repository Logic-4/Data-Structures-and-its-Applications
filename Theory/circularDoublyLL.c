#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct data *next;
};

struct node* addAtStart(struct node *tail, int data)
{
    struct node *newP = (struct node*)malloc(sizeof(struct node));
    newP->data = data;
    newP->next = tail->next;
    tail->next->prev = newP;
    newP->prev = tail;
    tail->next = newP;

    return tail;
}

struct node* addAtEnd(struct node *tail, int data)
{
    struct node *newP = (struct node*)malloc(sizeof(struct node));
    tail->next->prev = newP;
    newP->next = tail->next;
    tail->next = newP;
    newP->prev = tail;
    tail = newP;
    return tail;
}

struct node* addAtPos(struct node *tail, int data, int pos)
{
    struct node *newP = (struct node*)malloc(sizeof(struct node));
    struct node *ptr = tail;
    while (pos>1)
        {
            ptr = ptr->next;
            pos--;
        }

    newP->next = ptr->next;
    ptr->next->prev = newP;
    ptr->next = newP;
    newP->prev = ptr;

    return tail;
}

struct node* delAtStart(struct node *tail)
{
    struct node *ptr = tail->next;
    ptr->next->prev = NULL;
    free(ptr);

    return tail;
}


int main()
{
    struct node *tail = (struct node*)malloc(sizeof(struct node));

    return 0;
}