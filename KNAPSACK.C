#include <stdio.h>
#include <conio.h>

#define MAX 20

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int n, int weight[], int value[], int W) {
    int i, w;
    int K[MAX][MAX];

    // Build table K[][] in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weight[i - 1] <= w)
                K[i][w] = max(value[i - 1] + K[i - 1][w - weight[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // Final result
    printf("\nMaximum value in Knapsack = %d\n", K[n][W]);

    // Traceback to find selected items
    printf("Items included:\n");
    w = W;
    for (i = n; i > 0 && w > 0; i--) {
        if (K[i][w] != K[i - 1][w]) {
            printf("Item %d (Weight = %d, Value = %d)\n", i, weight[i - 1], value[i - 1]);
            w -= weight[i - 1];
        }
    }
}

void main() {
    int weight[MAX], value[MAX], n, W, i;
    clrscr();

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights of items:\n");
    for (i = 0; i < n; i++) {
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &weight[i]);
    }

    printf("Enter values of items:\n");
    for (i = 0; i < n; i++) {
        printf("Value of item %d: ", i + 1);
        scanf("%d", &value[i]);
    }

    printf("Enter maximum capacity of knapsack: ");
    scanf("%d", &W);

    knapsack(n, weight, value, W);

    getch();
}
