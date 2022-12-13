#include <stdio.h>
#include <stdlib.h>
#define len 5

int queue[len];
int front = -1;
int rear = -1;

void enque(int data)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = data;
        printf("Enqued Successfully!");
    }
    else
    {
        if ((rear + 1) % len == front)
        {
            printf("Queue is Full!");
        }
        else
        {
            rear = (rear + 1) % len;
            queue[rear] = data;
            printf("Enqued Successfully!");
        }
    }
}

void displayqueue()
{
    int i = 0;
    do
    {
        printf("\t%d", queue[i]);
        i = (i + 1) % len;
    } while (i != (rear+1)%len);
}

void menu()
{
    printf("\n1 - Enque\n2 - Deque\n3 - peek\n4 - Display\n--> ");
}

void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty!");
    }
    else
    {
        printf("%d", queue[front]);
    }
    return queue[front];
}

int dequeue()
{
    if (front == rear == -1)
    {
        printf("Queue is Empty");
    }
    else
    {
        if (front == rear)
        {
            return queue[front];
            front = rear = -1;
            printf("Dequeued Successfully!");
        }
        else
        {
            return queue[front];
            front = (front + 1) % len;
            printf("Dequeued Successfully!");
        }
    }
}

void main()
{
    int status, data;
    system("cls");
    while (1)
    {
        menu();
        scanf("%d", &status);
        switch (status)
        {
        case 1:
        {
            printf("Enter Element: ");
            scanf("%d", &data);
            enque(data);
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