#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void createGraph(struct node **, int);
void insert(struct node**, int, int);
void display(struct node **,int);
int inDegree(struct node **, int, int);
int outDegree(struct node **, int);
 
int main()
{
    struct node *a[100];
    int v, ch, i, n;
    printf("Enter the numbers of vertices\n");
    scanf("%d",&n);
    createGraph(a,n);
    while(1)
    {
        printf("1. Indegree...\n");
        printf("2. Outdegree...\n");
        printf("3. Display...\n");
        }
}

void createGraph(struct node **a, int n)
{
    int i,j;

}

void insert(struct node **a, int i, int j)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = j;

    temp->next = a[i];
    a[i] = temp;
}

int inDegree(struct node **a, int n, int v)
{
    struct node *temp;
    int i,j,count;
    count = 0;

    for(i=1; i<=n; i++)
    {
        temp = a[i];
        while(temp != NULL)
        {
            if(temp->data == v)
                count++;
            temp = temp->next;
        }
    }
    return count;
}

int outDegree(struct node **a, int n, int v)
{
    struct node *temp;
    int i,j;
    int count;

    temp = a[v];
    count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void display(struct node **a, int n)
{
    
}