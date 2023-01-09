#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int stack[MAX];
char infix[MAX];
char infix1[MAX];
char infix2[MAX];
int top = -1;

void push(int);
int pop();
int isEmpty();
void intopre();
int space(char);
void print();
int precedence(char);
int post_eval();
int power(int, int);

int main()
{
    int result;
    printf("Enter the infix expression: ");
    gets(infix1);
    strcpy(infix,strrev(infix1));

    intopre();
    result = post_eval();
    print();

    printf("The result obtained after prefix evaluation is: ");
    printf("%d", result);

    return 0;
}

int post_eval()
{
    int i, a, b;
    for (i = 0; i < strlen(infix2); i++)
    {
        if (infix2[i] >= '0' && infix2[i] <= '9')
            push(infix2[i] - '0');
        else
        {
            a = pop();
            b = pop();
            switch (infix2[i])
            {
            case '+':
                push(b + a);
                break;
            case '-':
                push(b - a);
                break;
            case '*':
                push(b * a);
                break;
            case '/':
                push(b / a);
                break;
            case '^':
                push(power(b, a));
                break;
            }
        }
    }
    return pop();
}

int power(int a, int b)
{
    int i, multi = 1;
    for (i = 0; i < b; i++)
        multi *= a;
    return multi;
}

int space(char c)
{
    if (c == ' ' || c == '\t')
        return 1;
    else
        return 0;
}

void print()
{
    int i = strlen(infix2) - 1;
    printf("The equivalent prefix expression is: ");
    while (i>=0)
    {
        printf("%c", infix2[i--]);
    }
    printf("\n");
}

void push(int c)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top] = c;
}

int pop()
{
    char c;
    if (top == -1)
    {
        printf("stack underflow\n");
        exit(1);
    }
    c = stack[top];
    top = top - 1;
    return c;
}

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int precedence(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void intopre()
{
    int i, j = 0;
    char symbol, next;
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        if (!space(symbol))
        {
            switch (symbol)
            {
            case ')':
                push(symbol);
                break;

            case '(':
                while ((next = pop()) != ')')
                    infix2[j++] = next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (!isEmpty() && precedence(stack[top]) > precedence(symbol))
                    infix2[j++] = pop();
                push(symbol);
                break;
            default:
                infix2[j++] = symbol;
            }
        }
    }
    while (!isEmpty())
        infix2[j++] = pop();
    infix2[j] = '\0';
}