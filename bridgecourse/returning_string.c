//returning string from the function...

#include<stdlib.h>
#include<stdio.h>

char * display();

int main()
{
    char *p;
    p=display();  // storing the address of the string , , ,
    p[1]='z';  //for modifing the string,,, 
    printf("%s",p);  
}

char * display()                 //reeturn type is the address(pointer to the first char)
{
    static char c[10];
    printf("Enter the string");
    scanf("%s",c);

    return c;   // returning the address ,,
}