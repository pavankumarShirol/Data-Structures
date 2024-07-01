/* c programe of priority queue ...     there are 3 different queue's are present...*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct queue
{
    int a[SIZE];
    int front;
    int rear;
    int count;
};

void insert(struct queue *,int);
int delete(struct queue *);
void display(struct queue );

int main()
{
    struct queue pq[3];
    int choice,qno,ele,i;

    for(i=1;i<=3;i++)   //for initialisation
    {
        pq[i].front=0;
        pq[i].rear=-1;
        pq[i].count=0;
    }

    printf("Enter the choices");
    printf("\n1.Insert\n2.Delete\3.Display\n4.Exit\n");

    while(1)
    {
        printf("Enter the choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter the Queue numbwr : \n");
                scanf("%d",&qno);
                printf("Enter the element to be inserted\n");
                scanf("%d",&ele);
                insert(&pq[qno],ele);
                break;

            case 2:
                printf("Enter the Queue number\n");
                scanf("%d",&qno);

                ele = delete(&pq[qno]);
                printf("removed element is : %d  , from  %d  queue\n",ele,qno);
                break;

            case 3:
                for(i=1;i<=3;i++)
                {
                    printf("The Elements of  %d  queue is as follows\n",i+1);

                    display(pq[i]);
                }  
                break;

            default :
                exit(0);    
            
        }
    }
}

void insert(struct queue *pq,int ele)
{   
    int i;
    if(pq->count==SIZE)
    {
        printf("Queue is FULL\n");
    }
    else
    {

        pq->rear=(pq->rear+1)%SIZE;


        pq->a[pq->rear]=ele;

        pq->count ++;
    }
    
}

int delete(struct queue *pq)
{    
    int ele,i;
    if(pq->count==0)
    {
        printf("Queue is Empty\n");
    }
    else
    {   
        ele=pq->a[pq->front];

        pq->front=(pq->front+1)% SIZE;

        pq->count --;

        return ele;
    }
    
}

void display(struct queue pq)
{   
    int j,i;
    if(pq.count==0)
    {
        printf("Queue is Empty\n");
    }

    else
    {
        for(i=pq.front,j=0;j<pq.count;i=(i+1)%SIZE,j++)

        printf("%d\n",pq.a[i]);
        
    }
}