
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int compare(const void *a, const void *b) {
    return (*(int *)a > *(int *)b) -
           (*(int *)a < *(int *)b);
}

int main() {
    int n, start[MAX], end[MAX];
    int i, j = 0, rooms = 0, maximum = 0;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter start and end time: ");
        scanf("%d %d", &start[i], &end[i]);
    }

    qsort(start, n, sizeof(int), compare);
    qsort(end, n, sizeof(int), compare);

    for (i = 0; i < n; i++) {
        if (start[i] < end[j]) {
            rooms++;
            if (rooms > maximum)
                maximum = rooms;
        } else {
            j++;
        }
    }

    printf("Minimum meeting rooms = %d\n", maximum);
    return 0;
}
