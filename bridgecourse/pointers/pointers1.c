#include<stdio.h>
int main()
{
    int a=10,*ptr=&a;

    printf("a = %d\n",*ptr);

    printf("adress of a = %u\n",ptr);

     printf("adress of pointer = %u\n",&ptr);
}