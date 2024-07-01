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
NODEPTR delrear(NODEPTR);
bool search(NODEPTR,int);
void display(NODEPTR);

int main()
{
 int ele,choice,key;
 NODEPTR l;
 l=NULL;

 while(1)
 {
  printf("Slect the choices\n");
  printf("1.Insert at front\n2.Delete from Front\n3.Insert at rear\n4.Delete at rear\n5.search\n6.Display\n7.Exit\n");
  scanf("%d",&choice);
   switch(choice)
   {
     case 1:printf("Enter the element to be inserted\n");
            scanf("%d",&ele);
            l=insertfront(l,ele);
            break;

     case 2:l=delfront(l);
            break;

     case 3:printf("Enter the element to be inserted\n");
            scanf("%d",&ele);
            l=insertrear(l,ele);
            break;

     case 4:l=delrear(l);
             break;

     case 5:printf("Enter the element to be searched\n");
            scanf("%d",&key);
            if(search(l,key))
             printf("search is sussessful\n");
            else
             printf("search is unsuccessful\n");
            break;

     case 6:printf("Elements are as follows\n");
            display(l);
            break;

     default:printf("Invalid choice\n");
             exit(0);

   }

 }

}
ODEPTR insertfront(NODEPTR l,int ele)
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

 //  else  if(l->next==NULL)
 //  printf("%d\n",l->info);
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

NODEPTR delrear(NODEPTR l)
{
  int ele;
  NODEPTR p,q;

  if(l==NULL)
  {
   printf("List is Empty\n");
   return NULL;
  }
  else if(l->right==NULL)
  {
    ele=l->info;
    printf("Deleted Element is  %d\n",ele);
    freenode(l);
    return NULL;
  }
  else
  {
   for(p=l;p->right!=NULL;p=p->right)
        ;
   ele=p->info;
   printf("Deleted element is  %d\n",ele);

   q=p->left;
   q->right=NULL;
   freenode(p);
   return l;
  }
}

bool search(NODEPTR l,int key)
{
   NODEPTR p;

   for(p=l;p!=NULL;p=p->right)
   {
     if(key==p->info)
     return true;
   }
   return false;
}
