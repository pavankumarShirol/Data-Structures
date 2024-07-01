#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 100

struct stack{
    char a[SIZE];
    int top;
};

void push(struct stack*,char);
char pop(struct stack*);
int priority(char);

int main()
{
    struct stack s;
    char str[SIZE],ch,x;
    int i;
    s.top=-1;

    printf("Enter the expression");
    scanf("%s",str);

    for(i=0;str[i]!='\0';i++)
    {
        ch=str[i];

        if(isalnum(ch))
        printf("%c",ch);

        else if(ch=='(')
        push(&s,ch);

        else if(ch==')')
        {
            while((x = pop(&s)) != '(')
                printf("%c",x);
        }
        else
        {
            while(priority(s.a[s.top]) >= priority(ch))
                printf("%c",pop(&s));

            push(&s,ch);
        }
    }
    
    while(s.top != -1)
    {
        printf("%c",pop(&s));  
    }
    
}
void push(struct stack* s,char ch)
{
     if(s->top==(SIZE-1))
     printf("Stack is full");

    else
    s->a[++s->top]=ch;
}
char pop(struct stack* s)
{
     if(s->top == -1)
     return -1;
    
    else
    return s->a[s->top--];
}
int priority(char ch)
{
    if(ch == '(' )
    return 0;

    else if(ch == '+' || ch == '-')
    return 1;

    else if(ch == '*' || ch == '/')
    return 2;

    else 
    return 0;
}
