//To find npr & ncr 

#include<stdio.h>

int fact(int num)
{
    int fact=1;
    int i;

    for(i=2;i<=num;i++){
        fact=fact*i;
    }

    return fact;
}

int main()
{
    int n,r,npr;  //ncr

    printf("enter the values of n & r");
    scanf("%d%d",&n,&r);

    npr=fact(n)/fact(n-r);

    //ncr=npr/fact(r)

    printf("npr=%d",npr);
}