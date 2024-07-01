//Construct a binary search tree Display the total number of nodes and leaf nodes...
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
};

typedef struct node *NODEPTR;

NODEPTR insert(NODEPTR, int);
NODEPTR getnode();
void inorder(NODEPTR);
int nodecount(NODEPTR);
int leafnode(NODEPTR);

int main()
{
    int ele, choice,nodes,leafnodes;
    NODEPTR t;
    t = NULL;

    while (1)
    {
        printf("available choices are:\n");
        printf("1.Insert\n2.Display\n3.Count the number of nodes\n4.Count the leaf nodes\n5.Exit\n");
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

            case 3:
                nodes = nodecount(t);
                printf("Total number of nodes = %d\n",nodes);
                break;

            case 4:
                leafnodes = leafnode(t);
                printf("Total number of Leaf nodes = %d\n",leafnodes);
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

    if (p == NULL)
        return;

    inorder(p->left);
    printf("%d\n", p->info);
    inorder(p->right);
}

int nodecount(NODEPTR t)
{
    NODEPTR p=t;

    if(p==NULL)
    return 0;

    else
    return 1 + nodecount(p->left) + nodecount(p->right);
}

int leafnode(NODEPTR t)
{
    NODEPTR p=t;

    if(p==NULL)
    return 0;

    else
    {
        if(p->left==NULL && p->right==NULL)
        return 1;

        else
        return leafnode(p->left) + leafnode(p->right);
    }
    
}



// void preorder(NODEPTR t)
// {
//  NODEPTR p=t;

//  if(p==NULL)
//  return;

//  printf("%d\n",p->info);
//  preorder(p->left);
//  postorder(p->right);
// }

// void postorder(NODEPTR t)
// {
//  NODEPTR p=t;

//  if(p==NULL)
//  return;

//  postorder(p->left);
//  postorder(p->right);
//  printf("%d\n",p->info);
// }
