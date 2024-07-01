// to find large number using pointers and functions .....

#include<stdio.h>

void largest(int a,int b,int *l)
{
    if(a>b)
    {
        *l=a;
    }
    else
        *l=b;
}                                                                   //abcdefghijklmnopqrstuvwxyz
int main()
{
    int a,b,large;

    printf("enter the two numbers :");
    scanf("%d%d",&a,&b);

    largest(a,b,&large);

    printf("largest = %d",large);

    return 0;
}