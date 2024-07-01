#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
#include<stdbool.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
};
struct stack
{
    struct node* a[SIZE];

    int top;
};
typedef struct node* NODEPTR;

NODEPTR insert(NODEPTR, int);
NODEPTR getnode();
void inorder(NODEPTR);
void push(struct stack*,struct node*);
struct node* pop(struct stack *s);
bool isempty(struct stack);

int main()
{
    int ele, choice;
    NODEPTR t;
    struct stack s;
    s.top=-1;
    t = NULL;

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

NODEPTR insert(NODEPTR t, int ele)
{
    NODEPTR p;
    p = getnode();
    p->info = ele;
    p->right = NULL;
    p->left = NULL;

    if (t == NULL)
        return p;

    else
    {
        NODEPTR prev, curr;
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

NODEPTR getnode()
{
    NODEPTR p;

    p = (NODEPTR)malloc(sizeof(struct node));

    if (p == NULL)
    {
        printf("Memory allocation failed");
        exit(0);
    }

    return p;
}

void inorder(NODEPTR t)
{
    NODEPTR p = t;
    struct stack s;
    s.top=-1;
    
    while(p!=NULL || isempty(s)==false)
    {
        while(p!=NULL)
        {
            push(&s,p);
            p=p->left;
        }
        p=pop(&s);
        printf("%d\n",p->info);
        p=p->right;
    }
}
void push(struct stack *s,struct node* p)
{
     if(s->top==SIZE-1)
    printf("Stack is full");

    else
        s->a[++s->top]=p;
}
struct node* pop(struct stack *s)
{
    return s->a[s->top--];
}
bool isempty(struct stack s)
{
    if(s.top==-1)
    return true;

    else
    return false;
}