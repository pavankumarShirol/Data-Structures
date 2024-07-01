//passing 2D array to the function...

#include<stdio.h>

void read(int a[][100], int m,int n)
{
    int i,j;
    printf("we are within read function\n");

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
int main()
{
    int m,n,a[100][100];

    printf("enter the number of rows and coloumns of the matrix :");
    scanf("%d%d",&m,&n);

    printf("enter the %d*%d elements of the matrix" ,m,n);

    read(a,m,n);

    display(a,m,n);

}