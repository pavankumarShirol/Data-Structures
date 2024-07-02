#include<stdio.h>
#include<stdlib.h>

int precedence(char);

int main()
{
    char str[20], ch, high = '+'; // Initialize high with a default lowest precedence operator
    int i;

    printf("Enter the expression: ");
    scanf("%s", str);

    for(i = 0; str[i] != '\0'; i++)
    {
        ch = str[i];

        if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')')
        {
            if(ch == '(')
            {
                high = '('; // Update high for '('
            }
            else if(ch == ')')
            {
                break; // Stop scanning further for ')'
            }
            else if(precedence(ch) > precedence(high))
            {
                high = ch; // Update high if current operator has higher precedence
            }
        }
    }

    printf("Highest priority operator is  =  %c\n", high);
    return 0;
}

int precedence(char ch)
{
    if(ch == '+' || ch == '-')
        return 1;
    else if(ch == '*' || ch == '/')
        return 2;
    else // Parentheses or other characters
        return 0;
}
