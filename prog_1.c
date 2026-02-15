#include <stdio.h>

#define CAPACITY 30

char dataStack[CAPACITY];
int pointer = -1;

void insert(char value)
{
    if (pointer >= CAPACITY - 1)
    {
        printf("Overflow condition!\n");
    }
    else
    {
        pointer++;
        dataStack[pointer] = value;
    }
}

char removeElement()
{
    if (pointer < 0)
    {
        return '\0';
    }
    else
    {
        char temp = dataStack[pointer];
        pointer--;
        return temp;
    }
}

int validPair(char left, char right)
{
    switch(left)
    {
        case '(': return (right == ')');
        case '{': return (right == '}');
        case '[': return (right == ']');
        default:  return 0;
    }
}

int checkBalanced(char str[])
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            insert(str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            char last = removeElement();

            if (last == '\0' || !validPair(last, str[i]))
            {
                return 0;
            }
        }
        i++;
    }

    if (pointer == -1)
        return 1;
    else
        return 0;
}

int main()
{
    char expression[100];

    printf("Enter any expression: ");
    scanf("%s", expression);

    if (checkBalanced(expression))
        printf("Balanced Expression\n");
    else
        printf("Unbalanced Expression\n");

    return 0;
}