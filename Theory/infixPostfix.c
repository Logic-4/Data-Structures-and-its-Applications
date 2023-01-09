#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int stack[MAX];
char infix[MAX];
char postfix[MAX];
int top=-1;

void push(int);
int pop();
int isEmpty();
void intopost();
int space(char);
void print();
int precedence(char);
int post_eval();
int power(int,int);

int main()
{
	int result;
	printf("Enter the infix expression:");
	gets(infix);
	
	intopost();
	result=post_eval(); 
	print();
	
	printf("the result obtained after postfix evaluation is:");
	printf("%d",result);
	
	return 0;
}

int post_eval()
{
	int i,a,b;
	for(i=0;i<strlen(postfix);i++)
	{
		if(postfix[i]>='0' && postfix[i]<='9')
			push(postfix[i]-'0');
		else
		{
			a=pop();
			b=pop();
			switch(postfix[i])
			{
				case '+': 	push(b+a);
							break;
				case '-':	push(b-a);
							break;
				case '*':	push(b*a);
							break;
				case '/':	push(b/a);
							break;
				case '^':	push(power(b,a));
							break;
			}
		}
	}
	return pop();
}

int power(int a,int b)
{
		int i,multi=1;
		for(i=0;i<b;i++)
			multi *=a;
		return multi;
}

int space(char c)
{
	if(c==' '||c=='\t')
		return 1;
	else
		return 0;
}

void print()
{
	int i=0;
	printf("The equivalent postfix expression is:");
	while(postfix[i])
	{
		printf("%c",postfix[i++]);
	}
	printf("\n");
}

void push(int c)
{
	if(top==MAX-1)
	{
		printf("stack overflow\n");
		return;
	}
	top++;
	stack[top]=c;
}

int pop()
{
	char c;
	if(top==-1)
	{
		printf("stack underflow\n");
		exit(1);
	}
	c=stack[top];
	top=top-1;
	return c;
}

int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

int precedence(char symbol)
{
	switch(symbol)
	{
		case '^':	return 3;
		case '/':
		case '*':	return 2;
		case '+':
		case '-':	return 1;
		default :	return 0;
	}
}

void intopost()
{
	int i,j=0;
	char symbol,next;
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		if(!space(symbol))
		{
			switch(symbol)
			{
				case '(':	push(symbol);
							break;
			
				case ')':	while((next=pop())!='(')
							postfix[j++]=next;
							break;
				case '+':
				case '-':
				case '*':
				case '/':
				case '^':
							while(!isEmpty() && precedence(stack[top])>=precedence(symbol))
							postfix[j++]=pop();
							push(symbol);
							break;
				default:	postfix[j++]=symbol;
			}
		}
	}
	while(!isEmpty())
		postfix[j++]=pop();
	postfix[j]='\0';
}