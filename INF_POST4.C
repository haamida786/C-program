#include <stdio.h>
#include <ctype.h>   
#include <string.h>
#include <stdlib.h>
#include <conio.h>   
#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch) {
    if (top >= SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = ch;
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

char peek() {
    if (top == -1) {
        return '\0';
    }
    return stack[top];
}

int precedence(char ch) {
    switch (ch) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void infixToPostfix(char *infix, char *postfix) {
    int i, k = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) { 
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (peek() != '(' && top != -1) {
                postfix[k++] = pop();
            }
            pop(); 
        }
        else { 
            while (precedence(ch) <= precedence(peek()) && top != -1) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

   
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0'; 
}

int main() {
    char infix[SIZE], postfix[SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    getch(); 
    return 0;
}
