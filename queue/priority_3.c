// priority by Inserting...in assending order.....

#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct queue
{
    int a[SIZE];
    int front;
    int rear;
    
};

void insert(struct queue *,int);
int delete(struct queue *);
void display(struct queue );

int count=0;

int main()
{
    struct queue pq;
    int choice,ele,i;
    
    
        pq.front=0;
        pq.rear=-1;
        
 

    printf("Enter the choices");
    printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");

    while(1)
    {
        printf("Enter the choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted\n");
                scanf("%d",&ele);
                insert(&pq,ele);
                break;

            case 2:
                ele = delete(&pq);
                printf("removed element is : %d ",ele);
                break;

            case 3:
                
                printf("The Elements of  %d  queue is as follows\n",i+1);

                display(pq);
                 
                break;

            default :
                printf("Wrong choice");
                exit(0);    
            
        }
    }
    return 0;
}

void insert(struct queue *pq,int ele)
{   
    int i,j,k=0;
    if(count==SIZE)
    {
        printf("Queue is FULL\n");
    }
    else if(pq->front==((pq->rear+1)%SIZE))
    {

        pq->rear=(pq->rear+1)%SIZE;

        pq->a[pq->rear]=ele;

        count ++;
    }
    else
    {                       // to find address of element where to be inserted..
        i=pq->front;
        while(ele>=pq->a[i] && k!=count)
        {
            i=(i+1)%SIZE;
            k++;
        }
            

        j=pq->rear;
        while(j>=i)
        {
            
            pq->a[(j+1)%SIZE]=pq->a[j];
            j--;
        }

        pq->a[i]=ele;
        pq->rear=(pq->rear+1)%SIZE;
        count ++;
    }
        
}

int delete(struct queue *pq)
{    
    int ele,i;
    if(count==0)
    {
        printf("Queue is Empty\n");
        return -1;
    }
    else
    {   
        ele=pq->a[pq->front];

        pq->front=(pq->front+1)% SIZE;

        count --;

        return ele;
    }
    
}

void display(struct queue pq)
{   
    int j,i;
    if(count==0)
    {
        printf("Queue is Empty\n");
    }

    else
    {
        for(i=pq.front,j=0;j<count;i=(i+1)%SIZE,j++)

        printf("%d\n",pq.a[i]);
        
    }
}