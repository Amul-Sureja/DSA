#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ch[100];
char infix[100], posfix[100], stack[100];
int top = -1;
char item;

void push(char item)
{
    if (top >= 99)
    {
        printf("stack is overflow");
    }
    else
    {
        top++;
        stack[top] = item;
    }
}

char pop()
{
    if (top == -1)
    {
        printf("stack overflow");
        return -1;
    }
    else
    {
        item = stack[top];
        top--;
        return item;
    }
}

int check(char symbol)
{
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '^' || symbol == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pre(char symbol)
{
    if (symbol == '^')
    {
        return 3;
    }
    else if (symbol == '*' || symbol == '/')
    {
        return 2;
    }
    else if (symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void in_to_po(char infix[], char posfix[])
{
    int i = 0, j = 0;
    char item, x;
    push('(');
    strcat(infix, ")");
    item = infix[i];
    while (item != '\0')
    {
        if (item == '(')
        {
            push(item);
        }
        else if (isdigit(item) || isalpha(item))
        {
            posfix[j] = item;
            j++;
        }
        else if (check(item) == 1)
        {
            x = pop();
            while (check(item) == 1 && pre(x) >= pre(item))
            {
                posfix[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        }
        else if (item == ')')
        {
            x = pop();
            while (x != '(')
            {
                posfix[j] = x;
                j++;
                x = pop();
            }
        }
        else
        {
            printf("invalid expression");
        }
        i++;
        item = infix[i];
    }
    if (top != -1)
    {
        printf("invalid expression");
    }
    posfix[j] = '\0';
}

int main()
{
    printf("enter an infix expretion : ");
    gets(infix);
    in_to_po(infix, posfix);
    printf("Postfix expression is:");
    puts(posfix);
    // printf("enter an infix expression : ");
    // fgets(infix, sizeof(infix), stdin);
    // infix[strcspn(infix, "\n")] = '\0'; // Remove the newline character from input
    // in_to_po(infix, posfix);
    // printf("Postfix expression: %s\n", posfix);
    return 0;
}