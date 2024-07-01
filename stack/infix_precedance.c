// programme to find the higher  precedance of the operator...
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct stack{
    char a[SIZE];
    int top;
};

void push(struct stack *,char);
// int pop(struct stack *);
int precedance(char);

int main()
{
    struct stack s;
    s.top=-1;
    int i;
    char ch;

    char exp[SIZE];

    printf("Enter the Valid Expression");
    scanf("%s",exp);

    for(i=0;exp[i]!='\0';i++)
    {
        ch=exp[i];

        if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        {
            if(precedance(ch)>precedance(s.a[s.top]))
            push(&s,ch);
        }
    }
    printf("Higher = %c",s.a[s.top]);
}
void push(struct stack * s,char ch )
{
    s->a[++s->top]=ch;
}
int precedance(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 2;
    }
}
