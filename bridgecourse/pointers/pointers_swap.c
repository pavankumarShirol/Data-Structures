//to swap two intigers uding a user defined function  :  HAVING POINTERS

#include<stdio.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int a=10,b=20;

    printf("before swaping : %d  %d\n",a,b);

    swap(&a,&b);   //passing the adress of the a,b      //passing the pointers in function....

    printf("after swaping : %d  %d",a,b);
}