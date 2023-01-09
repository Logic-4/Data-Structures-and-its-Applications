#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct tree
{
    struct node *root;
};

void init(struct tree *pt)
{
    pt->root = NULL;
};

void create(struct tree *pt)
{
    struct node *temp, *p, *q;
    int wish;

    printf("Enter root info:\n");
    pt->root = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&pt->root->data);
    pt->root->left = NULL;
    pt->root->right = NULL;

    do{
        printf("Enter element:\n");
        temp = (struct node*)malloc(sizeof(struct node));
        scanf("%d",&temp->data);
        temp->left = NULL;
        temp->right = NULL;
        q = NULL;
        p = pt->root;

        while(p != NULL)
        {
            q = p;
            if(temp->data < p->data)
                p = p->left;
            else 
                p = p->right;
        }
        if(temp->data < q->data)
            q->left = temp;
        else
            q->right = temp;
        printf("Do you wish to add another:\n");
        scanf("%d",&wish);
    }while(wish);
}

int main()
{
    struct tree t;
    create(&t);
}