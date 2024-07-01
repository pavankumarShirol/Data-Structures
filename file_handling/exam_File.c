#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,a[10],i,count=0;
    FILE *fp;

    printf("Enter A how many numbers are there\n");
    scanf("%d",&n);

    printf("Enter a %d numbers\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    fp=fopen("divisible.txt","w");

    if(fp==NULL)
    {
        printf("Error cant open a file\n");
        exit(1);
    }

    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {    count++;
             fprintf(fp,"Number = %d\n",a[i]);
        }
    }
    printf("Even Number of elements = %d",count);
}