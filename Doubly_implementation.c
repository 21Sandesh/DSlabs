#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *nextnode;
    struct node *prevnode;
};

void menu()
{
    printf("\n1 - To Create Linked List\n2 - Insert at Beginning\n3 - Insert at End\n4 - Insert at Position\n5 - Delete at Beginning\n6 - Delete at End\n7 - Delete at Position\n8 - Reverse Doubly Linked List\n9 - Display Linked List\n---> ");
}

void main()
{
    int status, fnstatus, len = 0;
    struct node *head, *temp, *newnode, *tail;
    head = NULL;
    system("cls");
    while (1)
    {
        menu();
        scanf("%d", &status);
        switch (status)
        {
        case 1:
        {
            do
            {
                newnode = (struct node *)malloc(sizeof(struct node));
                newnode->prevnode = NULL;
                newnode->nextnode = NULL;
                printf("Enter the Element: ");
                scanf("%d", &newnode->data);
                if (head == NULL)
                {
                    head = tail = newnode;
                }
                else
                {
                    tail->nextnode = newnode;
                    newnode->prevnode = tail;
                    tail = newnode;
                }
                printf("\n1 - To add New Node\n2 - Go Back\n---> ");
                scanf("%d", &fnstatus);
            } while (fnstatus == 1);
            printf("\nDoubly Linked List Created Successfully!");
            getch();
            system("cls");
            break;
        }

        case 2:
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->prevnode = NULL;
            newnode->nextnode = NULL;
            printf("Enter the Element: ");
            scanf("%d", &newnode->data);
            head->prevnode = newnode;
            newnode->nextnode = head;
            head = newnode;
            printf("Element Inserted Successfully!");
            getch();
            system("cls");
            break;
        }

        case 3:
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->prevnode = NULL;
            newnode->nextnode = NULL;
            printf("Enter the Element: ");
            scanf("%d", &newnode->data);
            tail->nextnode = newnode;
            newnode->prevnode = tail;
            tail = newnode;
            printf("Element Inserted Successfully!");
            getch();
            system("cls");
            break;
        }

        case 4:
        {
            int pos, i = 1;
            temp = head;
            newnode = (struct node *)malloc(sizeof(struct node));
            while (temp != NULL)
            {
                len++;
                temp = temp->nextnode;
            }
            temp = head;
            printf("Enter the Position: ");
            scanf("%d", &pos);
            if (pos < 0 || pos > len)
            {
                printf("Number Overflowed!");
                getch();
                system("cls");
                break;
            }
            if (pos == 1)
            {
                newnode->prevnode = NULL;
                newnode->nextnode = NULL;
                printf("Enter the Element: ");
                scanf("%d", &newnode->data);
                head->prevnode = newnode;
                newnode->nextnode = head;
                head = newnode;
                printf("Element Inserted Successfully!");
                getch();
                system("cls");
                break;
            }
            else
            {
                printf("Enter the ELement: ");
                scanf("%d", &newnode->data);
                while (i < pos - 1)
                {
                    i++;
                    temp = temp->nextnode;
                }
                newnode->nextnode = temp->nextnode;
                newnode->prevnode = temp;
                temp->nextnode = newnode;
                newnode->nextnode->prevnode = newnode;
            }
            printf("Element Inserted Successfully!");
            getch();
            system("cls");
            break;
        }

        case 5:
        {
            temp = head;
            temp->nextnode->prevnode = head;
            head = head->nextnode;
            free(temp);
            printf("Element Deleted Successfully!");
            getch();
            system("cls");
            break;
        }

        case 6:
        {
            temp = tail;
            temp->prevnode->nextnode = tail;
            tail = tail->prevnode;
            tail->nextnode = NULL;
            free(temp);
            printf("Element Deleted Successfully!");
            getch();
            system("cls");
            break;
        }

        case 7:
        {
            int pos, i = 1;
            temp = head;
            while (temp != NULL)
            {
                len++;
                temp = temp->nextnode;
            }
            temp = head;
            printf("Enter the Position: ");
            scanf("%d", &pos);
            if (pos < 0 || pos > len)
            {
                printf("Number Overflowed!");
                getch();
                system("cls");
                break;
            }
            if (pos == 1)
            {
                temp = head;
                temp->nextnode->prevnode = head;
                head = head->nextnode;
                free(temp);
                printf("Element Deleted Successfully!");
                getch();
                system("cls");
                break;
            }
            if (pos == len)
            {
                temp = tail;
                temp->prevnode->nextnode = tail;
                tail = tail->prevnode;
                tail->nextnode = NULL;
                free(temp);
                printf("Element Deleted Successfully!");
                getch();
                system("cls");
                break;
            }
            else
            {
                temp = head;
                while (i < pos)
                {
                    i++;
                    temp = temp->nextnode;
                }
                temp->prevnode->nextnode = temp->nextnode;
                temp->nextnode->prevnode = temp->prevnode;
                free(temp);
                printf("Element Deleted Successfully!");
                getch();
                system("cls");
                break;
            }
        }

        case 8:
        {
            temp = head;
            struct node *next;
            while (temp != NULL)
            {
                next = temp->nextnode;
                temp->nextnode = temp->prevnode;
                temp->prevnode = next;
                temp = next;
            }
            next = head;
            head = tail;
            tail = next;
            printf("Doubly Linked List Reversed Successfully!");
            getch();
            system("cls");
            break;
        }

        case 9:
        {
            temp = head;
            while (temp != NULL)
            {
                printf("\t%d", temp->data);
                temp = temp->nextnode;
            }
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