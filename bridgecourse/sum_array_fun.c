#include<stdio.h>

int sum(int a[],int n)  //declaration
{
    int i,sum=0;

    for(i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
    return sum;

}
int main()
{
    int n,a[100],i,s;

    printf("enter the value of n :");
    scanf("%d",&n);
    printf("enter the %d Elements",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }

    s=sum(a,n);  //sum(a,n);

    printf("sum=%d",s);   //,sum

    return 0;
}