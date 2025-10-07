#include <stdio.h>
#include <conio.h>

void sortActivities(int n, int start[], int finish[])
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (finish[i] > finish[j]) {
                // Swap finish times
                temp = finish[i];
                finish[i] = finish[j];
                finish[j] = temp;

                // Swap start times to keep pair intact
                temp = start[i];
                start[i] = start[j];
                start[j] = temp;
            }
        }
    }
}

void activitySelection(int n, int start[], int finish[])
{
    int i, last = 0;

    printf("Selected activities (0-based index):\n");
    printf("%d ", 0); // Always select first activity

    for (i = 1; i < n; i++) {
        if (start[i] >= finish[last]) {
            printf("%d ", i);
            last = i;
        }
    }
}

void main()
{
    int n, i, start[50], finish[50];

    clrscr();
    printf("Enter number of activities: ");
    scanf("%d", &n);

    printf("Enter start times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &start[i]);
    }

    printf("Enter finish times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &finish[i]);
    }

    sortActivities(n, start, finish);
    activitySelection(n, start, finish);

    getch();
}
