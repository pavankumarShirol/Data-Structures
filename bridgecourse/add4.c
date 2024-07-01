//return type - argument

#include<stdio.h>

int compute(int,int);

int main()
{
    int a,b,sum;

    printf("Enter two numbers");
    scanf("%d%d",&a,&b);

    sum=compute(a,b);

    printf("sum=%d",sum);
    return 0;
}
int compute(int a,int b)
{
    return a+b;
}