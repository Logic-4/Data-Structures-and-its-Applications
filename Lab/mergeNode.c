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

void merge(struct node *head1, struct node *head2)
{
    struct node *ptr = head1;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = head2;
    head2->prev = ptr;
    struct node *head3 = head1;
}

void Sort(struct node *head)
{
    int swap, i;
    struct node *ptr1;
    struct node *ptr2 = NULL;

    do
    {
        swap = 0;
        ptr1 = head;

        while (ptr1->next != ptr2)
        {
            if (ptr1->data > ptr1->next->data)
            {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swap = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swap);
}

int main()
{
    struct node *head1 = NULL;
    head1 = addToEmpty(head1,13);
    addAtEnd(head1,22);
    addAtEnd(head1,3);
    addAtEnd(head1,11);
    addAtEnd(head1,10);
    printf("\nData of First Doubly Linked List is:\n\n");
    display(head1);
    printf("\nData of First Doubly Linked List after sorting:\n\n");
    Sort(head1);
    display(head1);

    struct node *head2 = NULL;
    head2 = addToEmpty(head2,63);
    addAtEnd(head2,77);
    addAtEnd(head2,18);
    addAtEnd(head2,29);
    addAtEnd(head2,16);
    printf("\nData of Second Doubly Linked List is:\n\n");
    display(head2);
    printf("\nData of Second Doubly Linked List after sorting:\n\n");
    Sort(head2);
    display(head2);

    printf("\nData of Merged Two Sorted Linked Lists:\n\n");
    merge(head1, head2);
    display(head1);

    return 0;
}