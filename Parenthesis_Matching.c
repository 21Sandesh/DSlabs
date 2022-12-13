#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>


int stack[50];
int top = -1;

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

int push(char parenthesis)
{
    top++;
    stack[top] = parenthesis;
}

char pop()
{
    char data;
    if (isempty() == 1)
    {
        printf("Stack is Empty!");
        return 0;
    }
    else
    {
        data = stack[top];
        top--;
        return data;
    }
}

int main()
{
    int len, i;
    char expression[50], check, popped;

    while (1)
    {
        system("cls");
        printf("Enter Expression: ");
        gets(expression);

        int flag = 1;
        len = strlen(expression);
        for (i = 0; i < len; i++)
        {
            check = expression[i];
            if (check == '(' || check == '[' || check == '{')
            {
                push(check);
            }
            else
            {
                if (check == ')' || check == ']' || check == '}')
                {
                    if (isempty() == 1)
                    {
                        printf("\nInvalid Parenthesis!\nReason: Excess Right Parenthesis!");
                        break;
                    }
                    popped = pop();
                    if (popped == '(' && check == ')')
                    {
                        flag = 0;
                    }
                    else
                    {
                        if (popped == '[' && check == '}')
                        {
                            flag = 0;
                        }
                        else
                        {
                            if (popped == '[' && check == ']')
                            {
                                flag = 0;
                            }
                            else
                            {
                                flag++;
                            }
                        }
                    }
                }
            }
        }
        if (flag == 0)
        {
            printf("\nValid Equation!");
        }
        else
        {
            printf("\nInvalid Equation!");
        }
        getch();
    }
}