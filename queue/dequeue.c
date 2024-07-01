// implementation of dequeue...

#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct queue
{
    int a[SIZE];
    int front;
    int rear;
};

void insertfront(struct queue*,int);
void insertrear(struct queue*,int);
int deletefront(struct queue*);
int deleterear(struct queue*);
void display(struct queue);

int count = 0;

int main()
{
    struct queue dq;
    dq.front=-1;
    dq.rear=-1;

    int ele,choice;

    while(1)
    {
        printf("\nEnter the choice\n");
        printf("1.Insert front\n2.Insert rear\n3.Delete front\n4.Delete rear\n5.Display\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 :printf("Enter the element to be inserted\n");
                    scanf("%d",&ele);
                    insertfront(&dq,ele);
                    break;

            case 2 :printf("Enter the element to be inserted\n");
                    scanf("%d",&ele);
                    insertfront(&dq,ele);
                    break;

            case 3 :ele=deletefront(&dq);
                    printf("removed element is = %d\n",ele);
                    break;

            case 4 :ele=deletefront(&dq);
                    printf("removed element is = %d\n",ele);
                    break;

            case 5 :printf("Elements are as follows\n");
                    display(dq);
                    break;
            default : printf("Invalid choice\n");
                    exit(0);

        }

    }
}

void insertfront(struct queue *dq,int ele)                 //f--
{
    if(count==SIZE)
    printf("queue is Full\n");

    else if(dq->front = -1 && dq->rear == -1)
    {
        dq->front=dq->rear=0;
        dq->a[dq->front]=ele;
        count++;
    }
    else if(dq->front == 0)
    {
        dq->front=(SIZE-1);
        dq->a[dq->front]=ele;
        count++;
    }
    else
    {
        dq->front--;
        dq->a[dq->front]=ele;
        count++;
    }

}
void insertrear(struct queue *dq,int ele)        // rear++
{
    if(count==SIZE)
    printf("Queue is full\n");

    else if(dq->front = -1 && dq->rear == -1)
    {
        dq->front=dq->rear=0;
        dq->a[dq->front]=ele;
        count++;
    }
    else if(dq->rear=(SIZE-1))
    {
        dq->rear=0;
        dq->a[dq->rear]=ele;
        count++;
    }    
    else
    {
        dq->rear++;
        dq->a[dq->rear]=ele;
        count++;
    }
}
int deletefront(struct queue *dq)       //f++
{   int ele;
    ele=dq->a[dq->front];

    if(count==0)
    printf("Queue is Empty\n");

    else if(dq->front=dq->rear)
    {
        dq->front=dq->rear=-1;
        count--;
    }
    else if(dq->front=(SIZE-1))
    {
        dq->front=0;
        count--;
    }
    else
    {
        dq->front++;
        count--;
    }    

    return ele;    
}

int deleterear(struct queue *dq)  //rear--
{   int ele;
    ele=dq->a[dq->rear];

    if(count==0)
    printf("Queue is Empty\n");

    else if(dq->front=dq->rear)
    {
        dq->front=dq->rear=-1;
        count--;
    }
    else if(dq->rear==0)
    {
        dq->rear=(SIZE-1);
        count--;
    }
    else
    {
        dq->rear--;
        count--;
    }
    return ele;
}    
void display(struct queue dq)
{
    
    int j,i;

   
    for(i=dq.front,j=0;j<count;i=(i+1)%SIZE,j++)
    {
        printf("%d\t",dq.a[i]);
    }
}  

