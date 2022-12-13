#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root;

struct node * Create()
{
    int data;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter Data in the Root Node: ");
    scanf("%d", &data);
    if (data == -1)
    {
        return 0;
    }
    newnode->data = data;
    printf("Enter Left Child of %d - ",data);
    newnode->left = Create();
    printf("Enter Right Child of %d - ",data);
    newnode->right = Create();

    return newnode;
}

void display(struct node *root)
{
    if (root == NULL)
    {
        return ;
    }
    printf("\t%d",root->data);
    display(root->left);
    display(root->right);
}


int main()
{
    int status, data;
    root = NULL;
    struct node *newnode;
    while (1)
    {
        system("cls");
        printf("\n1 - Create Node\n2 - Display\n---> ");
        scanf("%d", &status);
        switch (status)
        {
        case 1:
        {
            root = Create();
            printf("Root Created Successfully!");
            break;
        }
        case 2:
        {
            display(root);
            break;
        }
        }
        getch();
    }
}



/*

int Insert(struct node *root, int data)
{
    if (root == NULL)
    {
        root = Create(data);
    }
    else
    {
        if (data <= root->data)
        {
            root->left = Insert(root->left, data);
        }
        else
        {
            root->right = Insert(root->right, data);
        }
    }
    return root;
}

int Search(struct node *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        if (root->data == data)
        {
            return 1;
        }
        else
        {
            if (data<root->data)
            {
                return Search(root->left,data);
            }
            else
            {
                return Search(root->right, data);
            }
        }
    }
}

void display(struct node *root)
{
    if (root == NULL)
    {
        return ;
    }
    else
    {
        display(root->left);
        printf("%d",root->data);
        display(root->right);
    }
}
*/