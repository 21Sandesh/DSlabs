#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *nextptr;
};

void menu()
{
    printf("\n1. Create Circular Linked List\n2. Insert at Begining\n3. Insert at End\n4. Insert after a Node\n5. Delete at Beginning\n6. Delete at End\n7. Delete at Position\n8. Reverse the Linked List\n9. Display Linked List\n---> ");
}

void main()
{
    int status, fnstatus;
    struct node *head, *newnode, *temp;
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
            head = NULL;
            printf("Enter Element: ");
            do
            {
                newnode = (struct node *)malloc(sizeof(struct node));
                scanf("%d", &newnode->data);
                if (head == NULL)
                {
                    head = temp = newnode;
                    temp->nextptr = head;
                }
                else
                {
                    temp->nextptr = newnode;
                    temp = newnode;
                    temp->nextptr = head;
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
            
        }

        case 9:
        {
            temp = head;
            if (head == NULL)
            {
                printf("List is Empty!");
                getch();
                system("cls");
                break;
            }
            do
            {
                printf("\t%d",temp->data);
                temp = temp->nextptr;
            }while (temp != head);
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