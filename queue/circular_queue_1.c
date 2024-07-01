// c programe to implement the circular queue using normal method..

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
void display(struct queue);

int main()
{
    struct queue cq;
    int ele,choice;
    cq.front=-1;
    cq.rear=-1;

    printf("Enter the choice\n");
    printf("1.Insert\n2.Delete\n3.Display\n4.exit\n");

    while(1)
    {
        printf("Enter the choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted\n");
                scanf("%d",&ele);
                insert(&cq,ele);   //calling the function
                break;

            case 2:
                ele=delete(&cq);
                printf("Removed element is = %d\n",ele);
                break;

            case 3:
                printf("Queue elements are as follows\n");
                display(cq);
                break;
            
            case 4:
                exit(0);
        }
    }
}

void insert(struct queue *cq,int ele)
{
     if(cq->rear==(SIZE-1) && cq->front != 0)   // element is present in the last position but front is not 0,means queue is still empty for some space..
    {
        cq->rear=0;
        cq->a[cq->rear]=ele;
    }
    
    else if(cq->rear==(SIZE-1) || (cq->rear==(cq->front-1)%SIZE))  // to check empty conditions in normal & circular
    {
        printf("Circular Queue is FULL");
    }

    else if(cq->rear==-1)   // for inserting the first element
    {
        cq->front=cq->rear=0;

        cq->a[cq->rear]=ele;
    }



    else     // for other normal conditions
        cq->a[++cq->rear]=ele;
}

int delete(struct queue *cq)
{
    int ele;

    if(cq->front==-1)
    {
        printf("Circular Queue is Empty");
    }    

    else
    {
        ele=cq->a[cq->front];  //to store the element  first and then,,increse the front

        if(cq->front==cq->rear)  //for only one element present in the circular queue...and the move front & rear to initial state
        {
            cq->rear=cq->rear=-1;
        }

        else if(cq->front==(SIZE-1))   //for element present in the last position,,,and also some elements present in queue..we need to start from cicular
        {
            cq->rear=0;
        }

        else
            cq->front++;

        return ele;    
        
    }
}

void display(struct queue cq)
{  
    int i;

    if(cq.front==-1)
    {
        printf("Circular Queue is Empty");
    }  

    else
    {
        if(cq.front<=cq.rear)    //for normal conditon
        {   
            for(i=cq.front;i<=cq.rear;i++)
            printf("%d\n",cq.a[i]);
        }
        else
        {
            for(i=cq.front;i<=(SIZE-1);i++)    //for circular
            printf("%d\n",cq.a[i]);

            for(i=0;i<=cq.rear;i++)
             printf("%d\n",cq.a[i]);
        }
    }

}