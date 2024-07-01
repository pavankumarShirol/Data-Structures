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
void display(struct queue );

int count=0;

int main()
{
    struct queue pq;
    int choice,ele,i,n;
    
    
        pq.front=0;
        pq.rear=-1;
        
 
    printf("Enter the number of books\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the height of the %d book",i+1);
        scanf("%d",&ele);
        insert(&pq,ele);
    }
    
   printf("the arrangement of the books as follows,,according to the Heights \n");
   display(pq);
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