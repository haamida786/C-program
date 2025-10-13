#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 5

int stack[MAX], top = -1;

void push(int val) {
    if(top == MAX - 1)
	printf("Stack Overflow!\n");
    else
	stack[++top] = val;
}

int pop() {
    if(top == -1) {
	printf("Stack Underflow!\n");
	return -1;
    } else
	return stack[top--];
}

void display() {
	int i;
    if(top == -1)
	printf("Stack is empty.\n");
    else {
	printf("Stack elements (Top to Bottom): ");
	for(i = top; i >= 0; i--)
	    printf("%d-> ", stack[i]);
	printf("\n");
    }
}

int main() {
    int ch, val;
    clrscr();
    do {
	printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ");
	scanf("%d", &ch);
	switch(ch) {
	    case 1:
		printf("Enter element to push: ");
		scanf("%d", &val);
		push(val);
		break;
	    case 2:
		val = pop();
		if(val != -1) printf("Popped: %d\n", val);
		break;
	    case 3:
		display();
		break;
	    case 4:
		printf("Exiting...\n");
		break;
	    default:
		printf("Invalid choice.\n");
	}
    } while(ch != 4);
    getch();
    return 0;
}
