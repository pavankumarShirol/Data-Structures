// priority queue...here 3 different queues are present and filling of elements by the method of first fill 1 queue and then next and next...



#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
bool qfull(struct queue);
bool qempty(struct queue);

int main()
{
    struct queue pq[3];
    int choice,ele,i;

    for(i=0;i<3;i++)   //for initialisation
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
                printf("Enter the element to be inserted\n");
                scanf("%d",&ele);

                if(!qfull(pq[0]))
                    insert(&pq[0],ele);

                else if(!qfull(pq[1]))
                    insert(&pq[1],ele);

                else if(!qfull(pq[2]))
                    insert(&pq[2],ele);

                else
                    printf("All queues are full");
                break;

            case 2:
               if(!qempty(pq[0]))
                {
                    ele=delete(&pq[0]);
                    printf("Element deleted from queue 1 is %d\n",ele);
                }    

                else if(!qempty(pq[1]))
                {
                    ele=delete(&pq[0]);
                    printf("Element deleted from queue 2 is %d\n",ele);
                }    

                else if(!qempty(pq[2]))
                {
                    ele=delete(&pq[0]);
                    printf("Element deleted from queue 3 is %d\n",ele);
                }  

                else
                    printf("All the 3 queue's are Empty");

                break;      


            case 3:
                printf("Elements of the 1 queue are as follows\n");
                    display(pq[0]);

                printf("Elements of the 2 queue are as follows\n");
                    display(pq[1]);

                printf("Elements of the 3 queue are as follows\n");
                    display(pq[2]);

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
        return -1;
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

bool qfull(struct queue q)
{
    if(q.count==SIZE)
        return true;

    else
        return false;
}

bool qempty(struct queue q)
{
    if(q.count==0)
        return true;

    else
        return false;
}