#include<stdio.h>

int minimum(int a[],int n)      //insted of a[]  we can also write as *a
{
    int i,min;

    min=a[0];

    for(i=1;i<n;i++)
    {
        if(a[i]<min)
        min=a[i];
    }
    return min;
}

int maximum(int a[],int n)
{
    int i,max;

    max=a[0];

    for(i=1;i<n;i++)
    {
        if(a[i]>max)
        max=a[i];
    }
    return max;
}

void read(int a[],int n)      //*a
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}

int main()
{
    int n,a[100];  //mini,maxi                         

    printf("enter the value of n :");
    scanf("%d",&n);

    printf("enter the elements of an array");

    read(a,n);    

    printf("minimum =%d",minimum(a,n));   // or assign the min in one variable and then print on printf          //minimum(a,n); mini=min;

    printf("maximun=%d",maximum(a,n));


}