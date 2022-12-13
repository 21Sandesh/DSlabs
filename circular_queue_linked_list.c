#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int idata)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = idata;
    newnode->next = 0;
    if (rear == 0)
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
    printf("Enqued Successfully!");
}

void dequeue()
{
    struct node *temp;
    temp = front;
    if (front == 0 && rear == 0)
    {
        printf("Underflow!");
    }
    else
    {
        if (front == rear)
        {
            front = rear = 0;
            free(temp);
        }
        else
        {
            front = front->next;
            rear->next = front;
            free(temp);
        }
        printf("Dequed Successfully!");
    }
}
void peek()
{
    if (front == 0 && rear == 0)
    {
        printf("Queue is Empty!");
    }
    else
    {
        printf("%d",front->data);
    }
}

void displayqueue()
{
    struct node *temp;
    temp = front;
    if (front == 0 && rear == 0)
    {
        printf("Queue is Empty!");
    }
    else
    {
        do
        {
            printf("\t%d",temp->data);
            temp = temp->next;
        } while (temp != front);
    }
}

void menu()
{
    printf("\n1 - Enque\n2 - Deque\n3 - peek\n4 - Display\n--> ");
}

void main()
{
    int status;
    system("cls");
    while (1)
    {
        menu();
        scanf("%d", &status);
        switch (status)
        {
        case 1:
        {
            int idata;
            printf("Enter Element: ");
            scanf("%d", &idata);
            enqueue(idata);
            getch();
            system("cls");
            break;
        }

        case 2:
        {
            dequeue();
            getch();
            system("cls");
            break;
        }

        case 3:
        {
            peek();
            getch();
            system("cls");
            break;
        }

        case 4:
        {
            displayqueue();
            getch();
            system("cls");
            break;
        }

        default:
        {
            printf("Invalid Input!");
            getch();
            system("cls");
            break;
        }
        }
    }
}