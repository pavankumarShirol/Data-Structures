// c progrsme to find higher precedence operator in infix exoression,,.

#include<stdio.h>
#include<stdlib.h>

int precedance(char);

int main()
{
    char str[20],ch,high;
    int i;

    printf("Enter the expression");
    scanf("%s",str);

    for(i=0;str[i]!='\0';i++)
    {
        ch=str[i];

        if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='(' || ch==')')
        {
            if(ch=='(')
            {
                high=0;
            }
            else if(ch==')')
            {
                break;
            }
            else if(precedance(high)<precedance(ch))
            {
                high=ch;
            }
        }
    }

    printf("Highest priority operator is  =  %c",high);
}

int precedance( char ch)
{
    if(ch == '+' || ch == '-')
    return 1;

    else if(ch == '*' || ch == '/')
    return 2;

    return 0;

}