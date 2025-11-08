#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;
void push(int item) {
  if (top >= MAX_SIZE - 1) {
    printf("Stack Overflow\n");
    exit(1);
  }
  stack[++top] = item;
}
int pop() {
  if (top < 0) {
  printf("Stack Underflow\n");
  exit(1);
  }
  return stack[top--];
}
int evaluatePostfix(char* exp) {
  int i, operand1, operand2, result;
  for (i = 0; exp[i] != '\0'; i++) {
    if (isdigit(exp[i])) {
      push(exp[i] - '0');
    }
    else {
      operand2 = pop();
      operand1 = pop();
      switch (exp[i]) {
        case '+': result = operand1 + operand2; break;
        case '-': result = operand1 - operand2; break;
        case '*': result = operand1 * operand2; break;
        case '/': result = operand1 / operand2; break;
      }
      push(result);
    }
  }
  return pop();
}

int main() {
  char postfix[MAX_SIZE];
  clrscr();
  printf("Enter a postfix expression: ");
  scanf("%s", postfix);
  printf("Evaluated result: %d\n", evaluatePostfix(postfix));
  getch();
  return 0;
}




