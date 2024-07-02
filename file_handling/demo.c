#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    int n;
    fp=fopen("Number.txt","w");

    if(fp==NULL)
    {
        printf("Error cant open a file\n");
        exit(1);
    }
    printf("Enter a number\n");
    scanf("%d",&n);
    fprintf(fp,"Number = %d",n);
    fclose(fp); // Close the file after writing to it
    printf("success\n");
    return 0;


}