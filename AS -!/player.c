#include<stdio.h>
#include<stdlib.h>
#define SIZE 50




struct PLAYER{
    char name[SIZE];
    int s1,s2,s3;

};
typedef struct PLAYER P;

void read(P [],int );
void diaplay(P [],int );
void compute(P [],int);

int main()
{
    P p[SIZE];
    int n,i;
    float a;

    printf("Enter the number of players");
    scanf("%d",&n);

    printf("Enter the NAME, Score-1, Score-2, Score-3\n ");
    read(p,n);

    compute(p,n);

    // printf("Details of the students are as Follows :")
    // dispaly(&p,n);




}

void read(P p[],int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        printf("Entervthe details of %d player",i+1);
        scanf("%s%d%d%d",p[i].name,&p[i].s1,&p[i].s2,&p[i].s3);
    }
}
void display(P p[],int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        printf("NAME : %s,Score-1 : %d,Score-2 : %d,Score-3 : %d",p[i].name,p[i].s1,p[i].s2,p[i].s3);
    }
}
void compute(P p[],int n)
{   float a;
    int i;

    for(i=0;i<n;i++)
    {
        a=(p[i].s1+p[i].s2+p[i].s3)/3.0;
        printf("Avarege %d = %f",i+1,a);
    }
}