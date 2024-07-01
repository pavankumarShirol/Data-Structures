#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
// #define bool int
#include<stdbool.h>


struct stack{
    char str[SIZE];
    int top;
};

void push(struct stack *,char);
char pop(struct stack*);
bool check(char *);

int main ()
{
    char s[SIZE];

    printf("enter the expression : ");
    scanf("%s",s);

    if(check(s))
    {
        printf("Paranthesis is   BALANCED");
    }
    else
    {
        printf("Panathesis is NOT BALANCED");
    }

}

bool check(char *s)
{
    struct stack st;
    st.top=-1;
    char ch;

    int i;

    for(i=0;s[i]!='\0';i++)
    {
        
        
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                push(&st,s[i]);
            }
            else if(s[i]==')' || s[i]==']' || s[i]=='}')
            {
               ch= pop(&st);
               {
                   if(ch=='('&& s[i]==')')
                     continue;

                   else if(ch=='['&& s[i]==']')
                     continue;

                   else if(ch=='{'&& s[i]=='}')
                     continue;

                   else
                   {
                       printf("Paranthesis is not balancd");
                       exit(0);
                   }   
               }
            }
            else {}
            // return 0;
        
    }

    if(st.top==-1)
        return true;
    
    else
        return false;
    
}

void push(struct stack *ps,char ch)
{
    if(ps->top==SIZE-1)
    {
        printf("Stack is FULL");
    }
    else{
        ps->str[++ps->top]=ch;
    }
}



char pop(struct stack *ps)
{
    if(ps->top==-1)
    {
        printf("Paranthesis is NOT BALANCED");
        exit(0);   
    }
    else{
        
        return ps->str[ps->top--];

    }
}