#include<stdio.h>
#include<stdlib.h>

struct node
{
  int info;
  struct node *next;
};

typedef struct node* NODEPTR;

NODEPTR getnode();
void freenode(NODEPTR);
NODEPTR insertfront(NODEPTR,int);
NODEPTR delfront(NODEPTR);
void display(NODEPTR);
NODEPTR insbeforekey(NODEPTR,int,int);

int main()
{
 int ele,choice,key;
 NODEPTR l;
 l=NULL;

 while(1)
 {
  printf("Slect the choices\n");
  printf("1.Insert at front\n2.Delete from Front\n3.Display List\n4.Insert before key..\n5.Exit\n");
  scanf("%d",&choice);

   switch(choice)
   {
     case 1:printf("Enter the element to be inserted\n");
            scanf("%d",&ele);
            l=insertfront(l,ele);
            break;

     case 2:l=delfront(l);
            break;

     case 3:printf("Elements of Link lists as Follows\n");
            display(l);
            break;

     case 4:printf("Enter the key element\n");
            scanf("%d",&key);
            printf("Enter the element to be insertd\n");
            scanf("%d",&ele);
            l=insbeforekey(l,key,ele);
            break;
            

     default:printf("Invalid choice"); 
            exit(0);
   }
 }
}
NODEPTR insertfront(NODEPTR l,int ele)
{
 NODEPTR p;
 p=getnode();
 p->info=ele;
 p->next=NULL;

 if(l==NULL)
 {
   l=p;
 }
 else
 {
   p->next=l;
    l = p;
 }

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
  printf("Link List is Empty");
  return NULL;
 }
 else if(l->next==NULL)
 {
  ele=l->info;
  printf("Deleted element is %d\n",ele);
  return NULL;
 }
 else
 {
   ele=l->info;
   printf("deleted element is  %d\n",ele);
   l=l->next;
   free(p);
   return l;
 }
}

void freenode(NODEPTR p)
{
 free(p);
}

NODEPTR insbeforekey(NODEPTR l,int key,int ele)
{
  NODEPTR p,q,r;
  
  p=getnode();
  p->info=ele;
  p->next=NULL;
  
  if(key==l->info)
  {
    p->next=l;
    l=p;
    return l;
  }
  else
  {
    for(q=l;q!=NULL;q=q->next)
    {
      r=q->next;
      
     if(r==NULL)
      {
        printf("Key element not found\n");
        return l;
      }        
      else if(key==r->info)
      {
        p->next=r;
        q->next=p;
        return l;
      }
      
    }    
    
  } 
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
       temp=temp->next;
      }
   }

}