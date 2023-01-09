#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
struct link
{
    int coeff;
    int powx;
    int powy;
    struct link *next;
};
struct link *poly1 = NULL, *poly2 = NULL, *poly = NULL;
void create(struct link *node)
{
    char ch;
    do
    {
        printf("\nEnter coefficient:");
        scanf("%d", &node->coeff);
        printf("\nEnter power of x:");
        scanf("%d", &node->powx);
        printf("\nEnter power of y:");
        scanf("%d", &node->powy);
        node->next = (struct link *)malloc(sizeof(struct link));
        node = node->next;
        node->next = NULL;
        printf("\nContinue(y/n):");
        ch = getch();
    } while (ch == 'y' || ch == 'Y');
}
void show(struct link *node)
{
    while (node->next != NULL)
    {
        printf("%dx^%dy^%d", node->coeff, node->powx, node->powy);
        node = node->next;
        if (node->next != NULL)
            printf(" + ");
    }
}
void polyadd(struct link *poly1, struct link *poly2, struct link *poly)
{
    while (poly1->next && poly2->next)
    {
        if (poly1->powx > poly2->powx)
        {
            poly->powx = poly1->powx;
            poly->powy = poly1->powy;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if (poly1->powx < poly2->powx)
        {
            poly->powx = poly2->powx;
            poly->powy = poly2->powy;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else if(poly1->powx == poly2->powx && poly1->powy == poly2->powy)
        {
            poly->powx = poly1->powx;
            poly->powy = poly1->powy;
            poly->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        poly->next = (struct link *)malloc(sizeof(struct link));
        poly = poly->next;
        poly->next = NULL;
    }
    while (poly1->next || poly2->next)
    {
        if (poly1->next)
        {
            poly->powx = poly1->powx;
            poly->powy = poly1->powy;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2->next)
        {
            poly->powx = poly2->powx;
            poly->powy = poly2->powy;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly->next = (struct link *)malloc(sizeof(struct link));
        poly = poly->next;
        poly->next = NULL;
    }
}
int main()
{
    char ch;
    do
    {
        poly1 = (struct link *)malloc(sizeof(struct link));
        poly2 = (struct link *)malloc(sizeof(struct link));
        poly = (struct link *)malloc(sizeof(struct link));
        printf("\nEnter 1st Polynomial:");
        create(poly1);
        printf("\nEnter 2nd Polynomial:");
        create(poly2);
        printf("\n1st Polynomial:");
        show(poly1);
        printf("\n2nd Polynommial:");
        show(poly2);
        polyadd(poly1, poly2, poly);
        printf("\nAdded polynomial:");
        show(poly);
        printf("\nAdd two more Polynomials:");
        ch = getch();
    } while (ch == 'y' || ch == 'Y');
    return 0;
}