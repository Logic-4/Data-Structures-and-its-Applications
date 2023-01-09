#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int id;             // ID of user
    int numfren;        // number of friends of user
    char name[MAX];     // name of user
    int *friends;       // friends of user as an array
    struct node *right; // user to the right
    struct node *left;  // user to the left
} node;

void friends(int id, struct node *users)
{
    // CODE HERE
    int a = -1;
    if (users->numfren == 0)
        printf("%d", a);
    else
        printf("%d", users->friends);
}