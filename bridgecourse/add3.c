//retuen type - no argument

#include<stdio.h>

int compute(); //fun declaration

int main()

{
    int sum;

    sum = compute();
    printf("the sum =%d",sum);

}
int compute()
{
    int a,b;
    printf("Enter the two numbers");
    scanf("%d%d",&a,&b);
    return a+b;

}