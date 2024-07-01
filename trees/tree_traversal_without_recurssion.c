#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

struct node
{
    int info;
    struct node *left;
    struct node *right;
};
struct stack
{
     int a[SIZE];
     int top; 
};


// typedef struct node *NODEPTR;

struct node* insert(struct node*, int);
struct node* getnode();
void inorder(struct node*);
void push(struct stack *,int);
int pop(struct stack *);

int main()
{
    int ele, choice;
    struct node* t;
    struct stack s;
    s.top=-1;
    t = NULL;

    // struct stack s;

    while (1)
    {
        printf("available choices are:\n");
        printf("1.Insert\n2.Display(Inorder traversal)\n");
        printf("Enter the choices\n");
        scanf("%d", &choice);

        
            switch (choice)
            {
            case 1:
                printf("Enter the element to be inserted\n");
                scanf("%d", &ele);
                t = insert(t, ele);
                break;

            case 2:
                printf("Elements of Binary tree are as follows\n");
                inorder(t);
                break;

            default:
                printf("Invalid choice\n");
                exit(0);
            }
    }
}

struct node* insert(struct node* t, int ele)
{
    struct node* p;
    p = getnode();
    p->info = ele;
    p->right = NULL;
    p->left = NULL;

    if (t == NULL)
        return p;

    else
    {
        struct node* prev, curr;
        prev = NULL;
        curr = t;

        while (curr != NULL)
        {
            prev = curr;

            if (ele == curr->info)
            {
                printf("Duplicate Element\n");
                return t;
            }
            else if (ele < curr->info)
                curr = curr->left;

            else
                curr = curr->right;
        }

        if (ele < prev->info)
            prev->left = p;

        else
            prev->right = p;

        return t;
    }
}

struct node* getnode()
{
    struct node* p;

    p = (struct node*)malloc(sizeof(struct node));

    if (p == NULL)
    {
        printf("Memory allocation failed");
        exit(0);
    }

    return p;
}

void inorder(struct node* t)
{
    struct node* curr=t;

    while(curr!=NULL || pop(&s) == -1 )
    {
        while(curr != NULL)
        {
            push(&s,
            curr);
            curr=curr->left;
        }
        curr=pop();
        printf("%d\n",curr->info);

        curr=curr->right;
    }
} 

void push(struct node * s,int element)
{
    if(s->top==SIZE-1)
    printf("Stack is full");

    else
        s->a[++s->top]=element;
}
int pop(struct node* s)
{
    if(s->top==-1)
    return -1;

    else
    return 1;
}