#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

void deleteAlt(struct Node *head)
{
    if (head == NULL)
        return;

    struct Node *prev = head;
    struct Node *node = head->link;

    while (prev != NULL && node != NULL)
    {
        prev->link = node->link;
        free(node);
        prev = prev->link;
        if (prev != NULL)
            node = prev->link;
    }
}

struct Node *createNode(struct Node *head, int x)
{
    struct Node *ptr = head;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = temp;
    }

    return head;
}

void show(struct Node *head)
{
    struct Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->link;
        if (ptr != NULL)
            printf(" -> ");
    }
}

int main()
{
    struct Node *head = NULL;

    head = createNode(head, 1);
    head = createNode(head, 2);
    head = createNode(head, 3);
    head = createNode(head, 4);
    head = createNode(head, 5);

    printf("\nLinked List before deleting alternate nodes:\n");
    show(head);

    deleteAlt(head);

    printf("\nLinked List after deleting alternate nodes:\n");
    show(head);

    return 0;
}