// program to read the details of the Book and determine the heighest price of book

#include<stdio.h>

struct BOOK{
    char name[10];
    int e;
    float p;
};

void read(struct BOOK [],int);
void display(struct BOOK [],int);
void compute(struct BOOK [],int);

int main()
{ 
     struct BOOK b[10];
     int n;

    printf("Enter the numbers of books\n ");
    scanf("%d",&n);

    printf("Enter the Title,Edition,and Price of the Book\n");
    read(b,n);

    printf("details of book as follows\n");
    display(b,n);

    compute(b,n);
}

void read(struct BOOK b[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("enter the details of %d BOOK\n",i+1);
        scanf("%s%d%f",b[i].name,&b[i].e,&b[i].p);
    }
}
void display(struct BOOK b[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("the details of %d BOOK\n",i+1);
        printf("Name : %s \tEdition : %d\tPrice : %f\n",b[i].name,b[i].e,b[i].p);
    }
}
void compute(struct BOOK b[],int n)
{
    int i,j;
    float high;

    high=b[0].p;

    for(i=1;i<n;i++)
    {
        if(b[i].p>high)
        {
            high=b[i].p;
            j=i;
        }
    }
        

     printf("Highest prize book = %f",high);

     printf("Title of the highest prize Book = %s",b[j].name );
}