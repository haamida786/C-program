#include <stdio.h>
#define SIZE 100

int main() {
    int arr[SIZE], n, choice, i, pos, ele;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);

    do {
        printf("\n1. Display\n2. Insert\n3. Delete\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Array elements: ");
                for(i = 0; i < n; i++) printf("%d ", arr[i]);
                printf("\n");
                break;

            case 2:
                if(n == SIZE) {
                    printf("Array is full!\n"); break;
                }
                printf("Enter element and position (0-%d): ", n);
                scanf("%d%d", &ele, &pos);
                if(pos < 0 || pos > n) {
                    printf("Invalid position!\n"); break;
                }
                for(i = n; i > pos; i--) arr[i] = arr[i-1];
                arr[pos] = ele;
                n++;
                printf("Element inserted successfully.\n");
                break;

            case 3:
                if(n == 0) {
                    printf("Array is empty!\n"); break;
                }
                printf("Enter position to delete (0-%d): ", n-1);
                scanf("%d", &pos);
                if(pos < 0 || pos >= n) {
                    printf("Invalid position!\n"); break;
                }
                for(i = pos; i < n-1; i++) arr[i] = arr[i+1];
                n--;
                printf("Element deleted.\n");
                break;

            case 4:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 4);

    return 0;
}
