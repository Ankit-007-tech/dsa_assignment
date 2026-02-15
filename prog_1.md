# Checking Balanced Parentheses Using Stack in C

##  Explanation of Data Structures

This program uses a **Stack (LIFO – Last In First Out)** implemented using an array.

- `#define CAPACITY 30` → Defines maximum stack size.
- `char dataStack[CAPACITY];` → Array used as stack to store opening brackets.
- `int pointer = -1;` → Indicates top of stack.
  - `-1` → Stack is empty.
  - Incremented during push.
  - Decremented during pop.


##  Description of Functions

- **insert(char value)** → Pushes an element into the stack (checks overflow).
- **removeElement()** → Pops the top element (returns `'\0'` if empty).
- **validPair(char left, char right)** → Checks matching bracket pairs `()`, `{}`, `[]`.
- **checkBalanced(char str[])** → 
  - Traverses expression.
  - Pushes opening brackets.
  - Pops and verifies closing brackets.
  - Returns `1` if balanced, `0` otherwise.


##  Overview of main() Function

- Declares input array `expression[100]`.
- Takes user input.
- Calls `checkBalanced()` function.
- Displays whether the expression is balanced or not.


##  Sample Output

Example 1:
Enter any expression: {[()]}
Balanced Expression

Example 2:
Enter any expression: {(])
Unbalanced Expression


### Conclusion

The program efficiently checks balanced parentheses using stack operations (push and pop) implemented with an array in C.