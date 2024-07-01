#include<stdio.h>

int main()
{
    int n,a[100],sum=0,i;

    printf("enter the value of n");
    scanf("%d",&n);
    printf("Enter the %d Elements",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("entered elements are \n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    for(i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
    printf("sum=%d",sum);

    return 0;
}