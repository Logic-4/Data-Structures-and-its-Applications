#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n,i,k,count;
    scanf("%d",&n);
    scanf("%d",&k);
    struct node *start = malloc(sizeof(struct node));
    start->data = 1;
    start->next = NULL;
    struct node *ptr = start;

    for(i=2;i<=n;i++)
    {
        struct node *temp = malloc(sizeof(struct node));
        temp->data = i;
        ptr->next = temp;
        temp->next = start;
        ptr = temp;
    }

    for(count=n; count>1; count--)
    {
        for(i=0;i<k-1;++i)
        {
            ptr = ptr->next;
        }
        struct node *cpt = ptr->next;
        ptr->next = ptr->next->next;
        free(cpt);
        cpt = NULL; 
    }

}