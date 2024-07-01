#include<stdio.h>

void read(int a[][100],int m,int n)
{
    int i,j;

    for(i=0;i<m;i++)      //
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

}
void display(int a[][100], int m,int n)
{
    int i,j;

    printf("entered Matrix is \n");

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    
}
int trace(int a[][100],int m,int n)
{   
    int i,j,sum=0;

    printf("within Trace function");

     for(i=0;i<n;i++)
     {
         sum=sum+a[i][i];
     }

     return sum;
}
int main()
{
    int a[100][100],m,n;

    printf("enter the number of rows and coloums");
    scanf("%d%d",&m,&n);

    printf("enter the %d*%d elements of the matrix",m,n);

    read(a,m,n);

    display(a,m,n);

    printf("the sum of Diagonal Elements = %d",trace(a,m,n));

    return 0;

}