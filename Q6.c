
#include <stdio.h>
#include <string.h>

#define SIZE 256

int main() {
    char s[1000], result[1000];
    int freq[SIZE] = {0};
    int last[SIZE];
    int n, k, i, j, best, bestFreq;

    printf("Enter string: ");
    scanf("%999s", s);

    printf("Enter K: ");
    scanf("%d", &k);

    n = strlen(s);

    if (k <= 1) {
        printf("Rearranged string = %s\n", s);
        return 0;
    }

    for (i = 0; i < SIZE; i++)
        last[i] = -k;

    for (i = 0; i < n; i++)
        freq[(unsigned char)s[i]]++;

    for (i = 0; i < n; i++) {
        best = -1;
        bestFreq = 0;

        for (j = 0; j < SIZE; j++) {
            if (freq[j] > bestFreq && last[j] <= i - k) {
                best = j;
                bestFreq = freq[j];
            }
        }

        if (best == -1) {
            printf("Impossible to rearrange.\n");
            return 0;
        }

        result[i] = (char)best;
        freq[best]--;
        last[best] = i;
    }

    result[n] = '\0';
    printf("Rearranged string = %s\n", result);

    return 0;
}
