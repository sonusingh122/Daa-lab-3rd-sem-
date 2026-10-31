
#include <stdio.h>

#define MAX 1000

int heap[MAX], size = 0;

void insert(int x) {
    int i = ++size;
    while (i > 1 && heap[i / 2] < x) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = x;
}

int removeMax() {
    int ans = heap[1], x = heap[size--], i = 1, c;

    while (2 * i <= size) {
        c = 2 * i;
        if (c + 1 <= size && heap[c + 1] > heap[c])
            c++;
        if (heap[c] <= x) break;
        heap[i] = heap[c];
        i = c;
    }

    heap[i] = x;
    return ans;
}

int main() {
    int n, i, x, mn = 1000000000;
    int mx, deviation, answer = 1000000000;

    printf("Enter array size: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);

        if (x % 2 == 1)
            x *= 2;

        insert(x);
        if (x < mn)
            mn = x;
    }

    while (size > 0) {
        mx = heap[1];

        if (mx - mn < answer)
            answer = mx - mn;

        if (mx % 2 == 1)
            break;

        mx = removeMax();
        mx /= 2;

        if (mx < mn)
            mn = mx;

        insert(mx);
    }

    printf("Minimum deviation = %d\n", answer);
    return 0;
}
