#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX 100

typedef struct node
{
    int id;             // ID of user
    int numfren;        // number of friends of user
    char name[MAX];     // name of user
    int *friends;       // friends of user as an array
    struct node *right; // user to the right
    struct node *left;  // user to the left
} node;

struct node *retUser(char str[MAX])
{
    char name[MAX];
    char ID[MAX];
    char strfriends[MAX];

    // copied ID
    char *token = strtok(str, ",");
    strcpy(ID, token);

    // copied Name
    token = strtok(NULL, ",");
    strcpy(name, token);

    // copied friends' ID
    token = strtok(NULL, ",");
    strcpy(strfriends, token);
    // printf("%s\n",(strfriends));

    // creating user nodes
    int id = atoi(ID);
    struct node *user = malloc(sizeof(struct node));
    user->id = id;
    user->friends = (int *)malloc(MAX * sizeof(int));
    strcpy(user->name, name);

    // adding user's friend's IDs
    token = strtok(strfriends, "|");
    int i = 0;
    while (token != NULL)
    {

        int temp = atoi(token);
        user->friends[i] = temp;
        i++;
        token = strtok(NULL, "|");
    }
    user->numfren = i;
    if (i == 0)
    {
        user->friends[i] = -1;
    }
    return user;
}

// search for user with id=key
struct node *search(int key, struct node *users) // done
{
    if (users == NULL || users->id == key)
        return users;
    else if (users->id < key)
        return search(key, users->right);
    else if (users->id > key)
        return search(key, users->left);
    else
        return NULL;
}

// see document for explanattion
struct node *refineUser(struct node *user, struct node *users) // done
{
    // CODE HERE
    while (search(user->id, users) != NULL)
    {
        user->id = user->id + 1;
    }
    int i, a, ec = 0;
    node *ef;
    for (i = 0; i < user->numfren; i++)
    {
        ef = search(user->friends[i], users);
        if (ef != NULL)
        {
            ef->friends[ef->numfren++] = user->id;
            ec++;
        }
        else
        {
            user->friends[i] = -2;
        }
    }
    if (ec == 0)
    {
        user->friends[0] = -1;
        user->numfren = 0;
    }
    else
    {
        int i = 0;
        while (i < user->numfren)
        {
            if (user->friends[i] == -2)
            {
                int a = i;
                while (a < user->numfren)
                {
                    user->friends[a] = user->friends[a + 1];
                    a++;
                }
                user->numfren--;
            }
            i++;
        }
    }
    return user;
}

// insert user with id
struct node *insertUser(struct node *root, int id, struct node *user)
{
    user->right = NULL;
    user->left = NULL;
    if (root == NULL)
    {
        root = user;
        return root;
    }
    node *eu = root;
    while (true)
    {
        if (id < eu->id)
        {
            if (eu->left == NULL)
            {
                eu->left = user;
                break;
            }
            else
            {
                eu = eu->left;
            }
        }
        else if (id > eu->id)
        {
            if (eu->right == NULL)
            {
                eu->right = user;
                break;
            }
            else
            {
                eu = eu->right;
            }
        }
    }
    return root;
}

// prints friends list
void friends(int id, struct node *users)
{
    // int a = -1;
    node *eu = search(id, users);
    if (eu->numfren == 0)
    {
        printf("-1\n");
        return;
    }
    if (users->numfren != 0)
    {
        for (int i = 0; i < eu->numfren; i++)
        {
            printf("%d\n", eu->friends[i]);
        }
    }
}

// find child node with minimum value (inorder successor) - helper to delete node
struct node *minValueNode(struct node *node) // done
{
    struct node *ptr = node;
    while (ptr->left != NULL)
    {
        ptr = ptr->left;
    }
    return ptr;
}

// deletes itself from its friend's nodes
struct node *deleteFriends(int key, struct node *users) // done
{
    // CODE HERE
    int S;
    node *eu, *ef;
    eu = search(key, users);
    for (int i = 0; i < eu->numfren; i++)
    {
        S = eu->friends[i];
        ef = search(S, users);
        int a;
        for (a = 0; a < ef->numfren; a++)
        {
            if (ef->friends[a] == S)
            {
                break;
            }
        }
        while (a < eu->numfren)
        {
            ef->friends[a] = ef->friends[a + 1];
            a++;
        }
        ef->numfren--;
    }
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) // done
{
    if (root == NULL)
    {
        return root;
    }
    else if (key > root->id)
    {
        root->right = deleteNode(root->right, key);
    }
    else if (key < root->id)
    {
        root->left = deleteNode(root->left, key);
    }
    else
    {
        if (root->right == NULL)
        {
            struct node *ptr = root->left;
            free(root);
            return ptr;
        }
        else if (root->left == NULL)
        {
            struct node *ptr = root->right;
            free(root);
            return ptr;
        }
        struct node *ptr = minValueNode(root->right);
        root->id = ptr->id;
        strcpy(root->name, ptr->name);
        root->friends = ptr->friends;
        root->numfren = ptr->numfren;
        root->right = deleteNode(root->right, ptr->id);
    }
    return root;
}

// Print USER's IDs in ascending order
void printInOrder(node *myusers) // done
{
    if (myusers == NULL)
        return;

    printInOrder(myusers->left);
    printf("%d %s\n", myusers->id, myusers->name);
    printInOrder(myusers->right);
}

int main(int argc, char **argv)
{
    node *users = NULL;
    while (1)
    {

        int opt, id;
        fflush(stdin);
        scanf("%d", &opt);
        char str[MAX];
        switch (opt)
        {
        case 1:

            scanf("%s", str);
            struct node *tbins = retUser(str);
            tbins = refineUser(tbins, users);
            users = insertUser(users, tbins->id, tbins);
            break;

        case 2:

            scanf("%d", &id);
            deleteFriends(id, users);
            users = deleteNode(users, id);
            break;

        case 3:

            scanf("%d", &id);
            node *result = search(id, users);
            if (result == NULL)
                printf("USER NOT IN TREE.\n");
            else
            {
                printf("%d\n", result->id);
            }
            break;

        case 4:
            scanf("%d", &id);
            friends(id, users);
            break;

        case 5:
            printInOrder(users);
            break;

        case 6:
            exit(0);
            break;

        default:
            printf("Wrong input! \n");
            break;
        }
    }
    return 0;
}