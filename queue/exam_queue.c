// c programe to implement a dessending linear queue....
// arrangment of the books accoriding to the height of the book ,,,
// highest height is at the left most side..


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
                
                printf("The Elements of queue is as follows\n");

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
    else if(pq->rear < pq->front)
    {
            pq->a[++pq->rear]=ele;
            // pq->rear=pq->rear+1;
            count++;
    }
    
    else
    {
        i=pq->front;
        while(ele<=pq->a[i] && k!=count)
        {
            i++;
            k++;
        }

        j=pq->rear;
        while(j>=i)
        {
            pq->a[j+1]=pq->a[j];
            j--;
        }

        pq->a[i]=ele;
        pq->rear=pq->rear+1;
        count++;
    }       
}

int delete(struct queue *pq)
{    
    int ele,i;
    if(count==0)
    {
        printf("Queue is Empty\n");
    }
    else
    {   
      return pq->a[pq->front++];

       count --;  
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
        for(i=pq.front;i<=pq.rear;i++)
        printf("%d\n",pq.a[i]);    
    }
}