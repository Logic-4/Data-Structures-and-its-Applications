#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void display(struct node*);
void count_of_nodes(struct node*);
void add_at_end(struct node *,int);

int main()
{
    struct node *head;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 45;
    head->link = (struct node*)malloc(sizeof(struct node));
    head->link->data = 98;
    head->link->link = (struct node*)malloc(sizeof(struct node));
    head->link->link->data = 3;
    head->link->link->link = NULL;

    printf("\n----------------------\n");
    display(head);
    count_of_nodes(head);
    printf("\n----------------------\n");
    add_at_end(head,52);
    display(head);
    count_of_nodes(head);
    printf("\n----------------------\n");

    return 0;
}

void display(struct node *head)
{
    struct node *ptr;
    ptr = head;

    if (head == NULL)
        printf("Nothing to display");
    else
    {   
        int i=1;
        while(ptr!=NULL)
        {   
            printf("Data in node %d is %d\n",i,ptr->data);
            ptr = ptr->link;
            i++;
        }
    }

}

void count_of_nodes(struct node *head)
{
    struct node *ptr;
    ptr = head;

    if (head == NULL)
        printf("No Nodes");
    else
    {
        int i=0;
        while(ptr!=NULL)
        {
            ptr = ptr->link;
            ++i;
        }
        printf("No of Nodes is %d",i);
    }
}

void add_at_end(struct node *head,int data)
{
    struct node *ptr = head;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    while(ptr->link!=NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}