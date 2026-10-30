
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int freq, left, right, symbol;
} Node;

Node t[2 * MAX];
char symbols[MAX];
int lengths[MAX], code[MAX];
int n, total;

void getLength(int node, int depth) {
    if (t[node].left == -1 && t[node].right == -1) {
        lengths[t[node].symbol] = depth ? depth : 1;
        return;
    }
    getLength(t[node].left, depth + 1);
    getLength(t[node].right, depth + 1);
}

int main() {
    int i, j;

    printf("Enter number of symbols: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter symbol and frequency: ");
        scanf(" %c %d", &symbols[i], &t[i].freq);
        t[i].symbol = i;
        t[i].left = t[i].right = -1;
    }
    total = n;

    for (i = 0; i < n - 1; i++) {
        int a = -1, b = -1;

        for (j = 0; j < total; j++) {
            if (t[j].symbol == -2) continue;
            if (a == -1 || t[j].freq < t[a].freq) {
                b = a;
                a = j;
            } else if (b == -1 || t[j].freq < t[b].freq) {
                b = j;
            }
        }

        t[a].symbol = -2;
        t[b].symbol = -2;

        t[total].freq = t[a].freq + t[b].freq;
        t[total].left = a;
        t[total].right = b;
        t[total].symbol = -1;
        total++;
    }

    getLength(total - 1, 0);

    // Sort symbols by length, then by character
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (lengths[i] > lengths[j] ||
               (lengths[i] == lengths[j] &&
                symbols[i] > symbols[j])) {
                int x = lengths[i];
                lengths[i] = lengths[j];
                lengths[j] = x;

                char c = symbols[i];
                symbols[i] = symbols[j];
                symbols[j] = c;
            }

    unsigned int c = 0;
    int previousLength = lengths[0];

    printf("\nCanonical Huffman Codes:\n");
    for (i = 0; i < n; i++) {
        if (i > 0) {
            c++;
            c <<= lengths[i] - previousLength;
        }

        printf("%c : ", symbols[i]);
        for (j = lengths[i] - 1; j >= 0; j--)
            printf("%d", (c >> j) & 1);

        printf("\n");
        previousLength = lengths[i];
    }

    return 0;
}
