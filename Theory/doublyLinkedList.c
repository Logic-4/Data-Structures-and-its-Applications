#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node* addToEmpty(struct node *head, int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

struct node* addAtStart(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    temp->data = data;

    head->prev = temp;
    temp->next = head;
    head = temp;

    return head;
}

struct node* addAtEnd(struct node *head, int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    temp->data = data;
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    
    return head;
}

struct node* addAtPos(struct node *head, int data, int pos)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    temp->data = data;
    struct node *ptr = head;

    while(pos>2)
    {
        ptr = ptr->next;
        pos--;
    }

    struct node *temp2 = ptr->next;
    ptr->next = temp;
    temp2->prev = temp;
    temp->prev = ptr;
    temp->next = temp2;

    return head;
}

struct node* delAtEnd(struct node *head)
{
    struct node *temp = head;
    struct node *temp2;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp2 = temp->prev;
    free(temp);
    temp2->next = NULL;

    return head;
}

struct node* delAtStart(struct node *head)
{
    head = head->next;
    free(head->prev);
    head->prev = NULL;
    return head;
}

struct node* delAtPos(struct node *head, int pos)
{
    struct node *temp = head;
    struct node *temp2;
    while (pos>1)
    {
        temp = temp->next;
        pos--;
    }
    temp2 = temp->prev;
    temp2->next = temp->next;
    temp->next->prev = temp2;

    free(temp);
    return head;
}

struct node* display(struct node *head)
{
    struct node *temp = head;
    int i = 1;
    while (temp != NULL)
    {
        printf("Data at node %d is %d\n",i,temp->data);
        temp = temp->next;
        i++;
    }
}

int main()
{
    struct node *head = NULL;
    head = addToEmpty(head,1);
    addAtEnd(head,2);
    addAtEnd(head,3);
    addAtEnd(head,5);
    addAtPos(head,4,4);
    delAtPos(head,3);
    display(head);
    return 0;
}