
#include <stdio.h>

#define MAX 1000

int main() {
    int n, rating[MAX], candy[MAX];
    int i, total = 0;

    printf("Enter number of children: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &rating[i]);
        candy[i] = 1;
    }

    // Left to right
    for (i = 1; i < n; i++) {
        if (rating[i] > rating[i - 1])
            candy[i] = candy[i - 1] + 1;
    }

    // Right to left
    for (i = n - 2; i >= 0; i--) {
        if (rating[i] > rating[i + 1] &&
            candy[i] <= candy[i + 1])
            candy[i] = candy[i + 1] + 1;
    }

    for (i = 0; i < n; i++)
        total += candy[i];

    printf("Minimum candies = %d\n", total);

    printf("Candy distribution: ");
    for (i = 0; i < n; i++)
        printf("%d ", candy[i]);

    printf("\n");
    return 0;
}
