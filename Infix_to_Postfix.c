#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[50];
int top = -1;
char infix[50], postfix[50];

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

char pop()
{
    if (isempty() == 1)
    {
        return 0;
    }
    else
    {
        char data = stack[top];
        top--;
        return data;
    }
}

int push(char data)
{
    top++;
    stack[top] = data;
}

int precedence(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 4;
    case '%':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void infixTopostfix()
{
    int i;
    char symbol, next, j = 0;
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        switch (symbol)
        {
        case '(':
        {
            push(symbol);
            break;
        }
        case ')':
        {
            while ((next = pop()) != '(')
            {
                postfix[j] = next;
                j++;
            }
            break;
        }
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
        {
            while (!isempty() && precedence(stack[top]) >= precedence(symbol))
            {
                postfix[j] = pop();
                j++;
            }
            push(symbol);
            break;
        }
        default:
        {
            postfix[j] = symbol;
            j++;
            break;
        }
        }
    }
    while (isempty() == 0)
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
}

void display()
{
    printf("Postfix Expression is: \n");
    for (int i = 0; i < strlen(postfix); i++)
    {
        printf("%c", postfix[i]);
    }
}

int main()
{
    while (1)
    {
        system("cls");
        printf("Enter Infix Expression: ");
        gets(infix);

        infixTopostfix();
        display();
        getch();
    }
}