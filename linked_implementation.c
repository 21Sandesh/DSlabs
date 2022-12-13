#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>

struct node
{
    int data;
    struct node *nextptr;
};

void menu()
{
    printf("\n1. Create Linked List\n2. Insert at Begining\n3. Insert at End\n4. Insert after a Node\n5. Delete at Beginning\n6. Delete at End\n7. Delete at Position\n8. Reverse the Linked List\n9. Display Linked List\n---> ");
}

void main()
{
    system("cls");
    int status, fnstatus;
    struct node *head, *temp, *newnode;
    while (1)
    {
        menu();
        scanf("%d", &status);
        switch (status)
        {
        case 1:
        {
            head = NULL;
            printf("Enter First Element: ");
            do
            {
                newnode = (struct node *)malloc(sizeof(struct node));
                scanf("%d", &newnode->data);
                newnode->nextptr = NULL;
                if (head == NULL)
                {
                    head = temp = newnode;
                }
                else
                {
                    temp->nextptr = newnode;
                    temp = newnode;
                }
                printf("\n1 - To add New Node\n2 - Go Back\n---> ");
                scanf("%d", &fnstatus);
                printf("Enter the Element: ");
            } while (fnstatus == 1);
            system("cls");
            break;
        }

        case 2:
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Element to be Inserted at the Beginning: ");
            scanf("%d", &newnode->data);
            newnode->nextptr = head;
            head = newnode;
            printf("Inserted Successfully!");
            getch();
            break;
        }

        case 3:
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Element to be Inserted at the End: ");
            scanf("%d", &newnode->data);
            temp = head;
            while (temp->nextptr != NULL)
            {
                temp = temp->nextptr;
            }
            temp->nextptr = newnode;
            newnode->nextptr = NULL;
            printf("Inserted Successfully!");
            getch();
            system("cls");
            break;
        }

        case 4:
        {
            int pos, poscounter = 0, i = 1;
            temp = head;
            while (temp != NULL)
            {
                poscounter++;
                temp = temp->nextptr;
            }
            printf("Enter the Position of after which Node is to be Inserted: ");
            scanf("%d", &pos);
            if (pos > poscounter)
            {
                printf("Number Overflowed!");
                getch();
                system("cls");
                break;
            }
            else
            {
                temp = head;
                while (i < pos)
                {
                    temp = temp->nextptr;
                    i++;
                }
                newnode = (struct node *)malloc(sizeof(struct node));
                printf("Enter the Element to be Inserted: ");
                scanf("%d", &newnode->data);
                newnode->nextptr = temp->nextptr;
                temp->nextptr = newnode;
                printf("Inserted Successfully!");
                getch();
                system("cls");
                break;
            }
        }

        case 5:
        {
            temp = head;
            head = temp->nextptr;
            free(temp);
            printf("Deleted Successfully!");
            getch();
            system("cls");
            break;
        }

        case 6:
        {
            struct node *prevnode;
            temp = head;
            while (temp->nextptr != NULL)
            {
                prevnode = temp;
                temp = temp->nextptr;
            }
            if (temp == head)
            {
                head = NULL;
                free(temp);
            }
            else
            {
                prevnode->nextptr = NULL;
                free(temp);
            }
            printf("Deleted Successfully!");
            getch();
            system("cls");
            break;
        }

        case 7:
        {
            struct node *nextnode;
            int pos, poscounter = 0, i = 1;
            temp = head;
            while (temp != NULL)
            {
                poscounter++;
                temp = temp->nextptr;
            }
            temp = head;
            printf("Enter the Position of Node to be Deleted: ");
            scanf("%d", &pos);
            if (pos > poscounter)
            {
                printf("Number Overflowed!");
                getch();
                system("cls");
                break;
            }
            else
            {
                while (i < pos - 1)
                {
                    temp = temp->nextptr;
                    i++;
                }
                nextnode = temp->nextptr;
                temp->nextptr = nextnode->nextptr;
                free(nextnode);
                printf("Deleted Successfully!");
                getch();
                system("cls");
                break;
            }
        }

        case 8:
        {
            struct node *prevnode, *nextnode;
            prevnode = NULL;
            temp = nextnode = head;
            while (nextnode != NULL)
            {
                nextnode = nextnode->nextptr;
                temp->nextptr = prevnode;
                prevnode = temp;
                temp = nextnode;
            }
            head = prevnode;
            printf("Linked List Reversed Successfully!");
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
                temp = temp->nextptr;
            }
            printf("\n");
            getch();
            system("cls");
            break;
        }

        default:
        {
            printf("Invalid Input");
            getch();
            system("cls");
        }
        }
    }
}