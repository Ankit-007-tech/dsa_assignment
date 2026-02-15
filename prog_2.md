# Program: Infix to Postfix Conversion and Evaluation Using Stack (DSA)

## Explanation of Data Structures

This program uses the **Stack (LIFO – Last In First Out)** data structure implemented using arrays.

#define SIZE 100
char operatorStack[SIZE];
int top = -1;
```

- `SIZE` defines the maximum capacity of the stack.
- `operatorStack[]` is used to store operators and parentheses during conversion.
- `top` keeps track of the top element of the stack.
  - `top = -1` → Stack is empty.
  - Incremented during push.
  - Decremented during pop.

For postfix evaluation, another integer stack is used:

int valueStack[SIZE];
int valueTop = -1;
```

- `valueStack[]` stores operands during evaluation.
- `valueTop` tracks the top of the value stack.

---

##  Description of Functions

### 1. push(char value)
Inserts an operator into the stack.

### 2. pop()
Removes and returns the top element from the stack.

### 3. getPrecedence(char op)
Returns operator precedence:
- `+` and `-` → 1  
- `*` and `/` → 2  
- `^` → 3  

### 4. isOperator(char ch)
Checks whether a character is an operator.

### 5. convertInfixToPostfix(char infix[], char postfix[])
- Traverses the infix expression.
- Operands are directly added to postfix.
- Opening brackets are pushed onto stack.
- Closing brackets cause stack elements to be popped until '(' is found.
- Operators are pushed based on precedence rules.
- Remaining operators are popped at the end.

### 6. evaluatePostfix(char postfix[])
- Traverses postfix expression.
- If operand → push into value stack.
- If operator → pop two operands, apply operation, push result back.
- Final value in stack is returned as result.


## (c) Overview of main() Function

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

- Takes infix expression as input.
- Converts it to postfix form.
- Evaluates the postfix expression.
- Displays both postfix expression and final result.

## Sample Output

Example 1:
Enter an infix expression: 2+3*4
Postfix expression: 234*+
Final evaluated result: 14

Example 2:

Enter an infix expression: (5+2)*3
Postfix expression: 52+3*
Final evaluated result: 21

## Conclusion

This program demonstrates the use of Stack in Data Structures and Algorithms (DSA) for:
- Converting infix expressions to postfix.
- Evaluating postfix expressions efficiently.
- Applying operator precedence and stack operations (push and pop).

It highlights practical implementation of stacks in expression handling.