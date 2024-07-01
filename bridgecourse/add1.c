//no return type - no argument

#include<stdio.h>

void compute();  //fun declaration

int main()
{
    compute(); //fun call
    return 0;

}

//fun definition

void compute()
{
    int a,b,sum;
    printf("enter the two numbers");
    scanf("%d%d",&a,&b);

    sum=a+b;

    printf("sum=%d",sum);

}

