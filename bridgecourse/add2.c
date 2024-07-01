//no return type - argument is their

#include<stdio.h>

void compute(int,int);  //fun declsrston

int main()
{
    int a,b;

    printf("Enter the two numbers");
    scanf("%d%d",&a,&b);

    compute(a,b);  //fum call
    return 0;

}

// fun definition
void compute(int a,int b)
{
    int sum;
    sum=a+b;
    printf("sum = %d",sum); 
}