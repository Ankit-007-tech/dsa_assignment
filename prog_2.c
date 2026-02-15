#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define SIZE 100

char operatorStack[SIZE];
int top = -1;

void push(char value)
{
    operatorStack[++top] = value;
}

char pop()
{
    if (top == -1)
        return -1;
    return operatorStack[top--];
}

int getPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void convertInfixToPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char temp;

    while (infix[i] != '\0')
    {
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((temp = pop()) != '(')
                postfix[j++] = temp;
        }
        else if (isOperator(infix[i]))
        {
            while (top != -1 && getPrecedence(operatorStack[top]) >= getPrecedence(infix[i]))
                postfix[j++] = pop();

            push(infix[i]);
        }
        i++;
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[])
{
    int valueStack[SIZE];
    int valueTop = -1;
    int i = 0;

    while (postfix[i] != '\0')
    {
        if (isdigit(postfix[i]))
        {
            valueStack[++valueTop] = postfix[i] - '0';
        }
        else if (isOperator(postfix[i]))
        {
            int second = valueStack[valueTop--];
            int first = valueStack[valueTop--];

            switch (postfix[i])
            {
                case '+': valueStack[++valueTop] = first + second; break;
                case '-': valueStack[++valueTop] = first - second; break;
                case '*': valueStack[++valueTop] = first * second; break;
                case '/': valueStack[++valueTop] = first / second; break;
                case '^': valueStack[++valueTop] = pow(first, second); break;
            }
        }
        i++;
    }

    return valueStack[valueTop];
}

int main()
{
    char infixExpression[SIZE];
    char postfixExpression[SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infixExpression);

    convertInfixToPostfix(infixExpression, postfixExpression);

    printf("Postfix expression: %s\n", postfixExpression);

    int result = evaluatePostfix(postfixExpression);

    printf("Final evaluated result: %d\n", result);

    return 0;
}