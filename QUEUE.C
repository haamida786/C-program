#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void insert(int val) {
    if(rear == MAX - 1)
        printf("Queue Full!\n");
    else {
        if(front == -1) front = 0;
        queue[++rear] = val;
    }
}

void delete() {
    if(front == -1)
        printf("Queue Empty!\n");
    else {
        printf("Deleted element: %d\n", queue[front++]);
        if(front > rear)
            front = rear = -1;
    }
}

void display() {
	int i;
    if(front == -1)
        printf("Queue Empty!\n");
    else {
        printf("Queue elements: ");
	for(i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int ch, val;
    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Program terminated.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(ch != 4);
    return 0;
}
