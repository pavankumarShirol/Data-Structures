
#include<stdio.h>

void read(int a[],int n)
{
    int i;

    for ( i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    
}
void display(int a[],int n)
{
    int i;

    for ( i = 0; i < n; i++)
    {
        printf("%d",a[i]);
    }
}
int main()
{
    int a[50],n;  //*p;

    printf("Enter the number of elements");
    scanf("%d",&n);


    printf("Enter the elements of an array");

    read(a,n);                       

    printf("the elements are :\n");

    display(a,n);

    return 0;
}