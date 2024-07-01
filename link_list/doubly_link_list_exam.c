// doubly link list...search a element if element not found append it at end of the link list,..

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
  int info;
  struct node *left;
  struct node *right;

};

typedef struct node* NODEPTR;

NODEPTR getnode();
void freenode(NODEPTR);
NODEPTR insertfront(NODEPTR,int);
NODEPTR delfront(NODEPTR);
NODEPTR insertrear(NODEPTR,int);
bool search(NODEPTR,int);
void display(NODEPTR);

int main()
{
 int ele,choice,key,flag;
 NODEPTR l;
 l=NULL;

    while(1)
    {
        printf("Slect the choices\n");
        printf("1.Insert at front\n2.Delete from Front\n3.search\n4.Display\n5.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the element to be inserted\n");
                    scanf("%d",&ele);
                    l=insertfront(l,ele);
                    break;

            case 2:l=delfront(l);
                    break;

            case 3:printf("Enter the element to be searched\n");
                    scanf("%d",&key);
                    flag=search(l,key);
                    if(flag!=1)
                    {
                     l=insertrear(l,key);
                    }
                   break;

            case 4:printf("Elements are as follows\n");
                    display(l);
                    break;

            default:printf("Invalid choice\n");
                    exit(0);

        }

    }

}
NODEPTR insertfront(NODEPTR l,int ele)
{
 NODEPTR p;
 p=getnode();
 p->info=ele;
 p->left = NULL;
 p->right=NULL;

 if(l==NULL)
 return p;

 else
 {
   p->right=l;
   l->left=p;
 }

 l = p;

 return l;
}

NODEPTR getnode()
{
 NODEPTR p;
 p=(NODEPTR)malloc(sizeof(struct node));

 if(p==NULL)
 {
  printf("Memory allocation Failed");
  exit(0);
 }
 return p;
}
NODEPTR delfront(NODEPTR l)
{
 int ele;
 NODEPTR p=l;

 if(l==NULL)
 {
  printf("Link List is Empty\n");
  return NULL;
 }
 else if(l->right==NULL)
 {
  ele=l->info;
  freenode(l);
  printf("Deleted element is %d\n",ele);
  return NULL;
 }
 else
 {
   ele=l->info;
   printf("deleted element is  %d\n",ele);
   l=l->right;
    l->left=NULL;
   free(p);
   return l;
 }
}
void freenode(NODEPTR p)
{
 free(p);
}

void display(NODEPTR l)
{
  NODEPTR temp;
  temp=l;

  if(l==NULL)
   printf("List is empty\n");

  else
   {
     while(temp!=NULL)
      {
       printf("%d\n",temp->info);
       temp=temp->right;
      }
   }

}
NODEPTR insertrear(NODEPTR l,int ele)
{
  NODEPTR p,q;

  p=getnode();
  p->info=ele;
  p->right=NULL;
  p->left=NULL;

  if(l==NULL)
  {
    l=p;
   }
  else
  {
    for(q=l;q->right!=NULL;q=q->right)
       ;
     q->right=p;
     p->left=q;
  }
 return l;
}
bool search(NODEPTR l,int key)
{
   NODEPTR p;
   int count=0;

   for(p=l;p!=NULL;p=p->right)
   { count++;
     if(key==p->info)
     {
         printf("Search is Successfull\n");
         printf("Position of the element is = %d\n",count);
         return 1;
         break;
         
     }
     
   }
   
}
