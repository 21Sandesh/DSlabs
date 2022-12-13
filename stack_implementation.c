#include <stdio.h>
#include <stdlib.h>

#define len 5

int stack[len];
int top = -1,data;

void menu()
{
    printf("");
}

void push(int data)
{
    if (top>=len-1)
    {
        printf("Overflow!");
        return 0;
    }
    else
    {
        top++;
        stack[top]=data;
    }
}

void main()
{
    printf("Enter Data: ");
    scanf("%d",&data);
}