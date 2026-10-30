
#include <stdio.h>

#define MAX 1000

int heap[MAX], size = 0;

void insert(int x) {
    int i = ++size;
    while (i > 1 && heap[i / 2] > x) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = x;
}

int removeMin() {
    int ans = heap[1], x = heap[size--], i = 1, c;

    while (2 * i <= size) {
        c = 2 * i;
        if (c + 1 <= size && heap[c + 1] < heap[c])
            c++;
        if (heap[c] >= x) break;
        heap[i] = heap[c];
        i = c;
    }

    heap[i] = x;
    return ans;
}

int main() {
    int n, i, a, b, sum, cost = 0;

    printf("Enter number of sticks: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insert(x);
    }

    while (size > 1) {
        a = removeMin();
        b = removeMin();

        sum = a + b;
        cost += sum;
        insert(sum);
    }

    printf("Minimum total cost = %d\n", cost);
    return 0;
}
