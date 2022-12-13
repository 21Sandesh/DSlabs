#include <stdio.h>

int max=5;
int arr[5];
int top = -1;

int isfull()
{
    if (top == max)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(int data)
{
    if (isfull() == 1)
    {
        printf("\nStack is Full!");
    }
    else
    {
        top++;
        arr[top] = data;
    }
}

void pop()  
{
    if (isempty()==1)
    {
        printf("\nStack is Empty!");
    }
    else
    {
        top--;
    }
}

void display()
{
    int i;
    if (isempty()==1)
    {
        printf("\nStack is Empty!");
    }
    else
    {
        for (i=top; i>=0;i--)
        {
            printf("\n\t%d",arr[i]);
        }
    }
}

int main()
{
    int status,data;
    while(1)
    {
        printf("\n1 - Push\n2 - Pop\n3 - Display Stack\n---> ");
        scanf("%d",&status);
        switch(status)
        {
            case 1:
            {
                printf("Enter Data to Push - ");
                scanf("%d",&data);
                push(data);
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
        }
    }    

}