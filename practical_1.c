#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push an element onto the stack
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

// Pop an element from the stack
int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Perform an arithmetic operation
int operation(int a, int b, char op)
{
    switch (op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '%': return a % b;
        default:
            printf("Invalid operator\n");
            exit(1);
    }
}

// Evaluate postfix expression
int evaluatePostfix(char postfix[])
{
    int i;
    char ch;
    int a, b;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        // If operand, push it onto stack
        if (isdigit(ch))
        {
            push(ch - '0');
        }
        // If operator, pop two operands and perform operation
        else if (ch == '+' || ch == '-' || ch == '*' ||
                 ch == '/' || ch == '%')
        {
            b = pop();
            a = pop();

            push(operation(a, b, ch));
        }
    }

    return pop();
}

int main()
{
    char postfix[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    printf("Result = %d\n", evaluatePostfix(postfix));

    return 0;
}
