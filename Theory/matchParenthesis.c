#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int pop = -1;
char stack[];

void push(int data)
{
    
}

int match(char a, char b)
{
    if(a=='{' && b=='}')
        return 1;
    if(a=='(' && b==')')
        return 1;
    if(a=='[' && b==']')
        return 1;
    else
        return 0;
}

int main()
{
    for(int i=0; i<strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            
        }
    }
}

