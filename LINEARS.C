#include <stdio.h>
#include <conio.h>

int main() {
    int array[100], n, i, key, found = 0;
    clrscr();

    // Input array size
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
	scanf("%d", &array[i]);
    }

    // Input element to be searched
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Linear Search
    for (i = 0; i < n; i++) {
	if (array[i] == key) {
	    printf("Element found at position %d (index %d)\n", i + 1, i);
	    found = 1;
	    break;
	}
    }

    // If not found
    if (!found) {
	printf("Element not found in the array.\n");
    }
    getch();
    return 0;
}
