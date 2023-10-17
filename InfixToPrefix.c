#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int isAlphaNum(char x)
{
     return ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z') || (x >= '0' && x <= '9'));
}
int isOperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

int precedence(char symbol) {
    if (symbol == '+' || symbol == '-') {
        return 1;
    } else if (symbol == '*' || symbol == '/') {
        return 2;
    }
    return 0;
}

void infixToPrefix(char infix[], char prefix[]) {
    int i, j = 0;
    char temp;
    strrev(infix);
    
    for (i = 0; i < strlen(infix); i++) 
    {
        if (isAlphaNum(infix[i])) 
        {
            prefix[j++] = infix[i];
        }
        else if (infix[i] == ')') 
        {
            push(infix[i]);
        } 
        else if (infix[i] == '(') 
        {
            while (stack[top] != ')') 
            {
                prefix[j++] = pop();
            }
            // pop the '('
            temp = pop();
        } 
        else if (isOperator(infix[i])) 
        {
            while (precedence(stack[top]) >= precedence(infix[i]))
            {
                prefix[j++] = pop();
            }
            push(infix[i]);
        }
    }
    
    while (top != -1) 
    {
        prefix[j++] = pop();
    }
    
    prefix[j] = '\0';
    strrev(prefix);
}

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}
