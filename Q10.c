
#include <stdio.h>
#include <string.h>

#define MAX 100
#define LEN 10000

// Find the maximum overlap between two strings
int findOverlap(char a[], char b[]) {
    int i, lenA = strlen(a), lenB = strlen(b);
    int max = lenA < lenB ? lenA : lenB;

    for (i = max; i > 0; i--) {
        if (strncmp(a + lenA - i, b, i) == 0)
            return i;
    }

    return 0;
}

int main() {
    int n, i, j;
    int bestI, bestJ, bestOverlap, overlap;
    char s[MAX][LEN];
    char merged[LEN];

    printf("Enter number of strings: ");
    scanf("%d", &n);

    if (n < 1 || n >= MAX) {
        printf("Invalid number of strings.\n");
        return 0;
    }

    printf("Enter the strings:\n");

    for (i = 0; i < n; i++) {
        scanf("%9999s", s[i]);
    }

    while (n > 1) {
        bestOverlap = -1;
        bestI = 0;
        bestJ = 1;

        // Find the pair with maximum overlap
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i == j)
                    continue;

                overlap = findOverlap(s[i], s[j]);

                if (overlap > bestOverlap) {
                    bestOverlap = overlap;
                    bestI = i;
                    bestJ = j;
                }
            }
        }

        // Merge the selected pair
        strcpy(merged, s[bestI]);
        strcat(merged, s[bestJ] + bestOverlap);
        strcpy(s[bestI], merged);

        // Remove the second string
        for (i = bestJ; i < n - 1; i++) {
            strcpy(s[i], s[i + 1]);
        }

        n--;
    }

    printf("\nGreedy Superstring: %s\n", s[0]);

    return 0;
}
