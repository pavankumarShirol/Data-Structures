//returning the pointer from the function.,,,
#include<stdio.h>
#include<stdlib.h>

int * return_pointer(int *);

int main()
{
    int a[5]={1,2,3,4,5},*p;

    p=return_pointer(a);     //passing the base address of array,,(1000)

    printf("%d",*p);
}

int * return_pointer(int *p)
{
    p=p+2;    //(1000+2*4=1008) ,, pointer arithmetic..
    return p;
}

