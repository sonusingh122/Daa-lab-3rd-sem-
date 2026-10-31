
#include <stdio.h>

#define MAX 100

int main() {
    int n, i, j, k, len;
    int w[MAX], prefix[MAX];
    long long cost[MAX][MAX];
    long long best, sum;

    printf("Enter number of weights: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
        prefix[i] = prefix[i - 1] + w[i];
        cost[i][i] = 0;
    }

    for (len = 2; len <= n; len++) {
        for (i = 1; i + len - 1 <= n; i++) {
            j = i + len - 1;
            sum = prefix[j] - prefix[i - 1];
            best = -1;

            for (k = i; k < j; k++) {
                long long current =
                    cost[i][k] + cost[k + 1][j] + sum;

                if (best == -1 || current < best)
                    best = current;
            }

            cost[i][j] = best;
        }
    }

    printf("Minimum alphabetic tree cost = %lld\n",
           cost[1][n]);

    return 0;
}
