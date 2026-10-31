
#include <stdio.h>

#define MAX 1000

int heap[MAX], size = 0;

void push(int x) {
    int i = ++size;
    while (i > 1 && heap[i / 2] < x) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = x;
}

int pop() {
    int result = heap[1], x = heap[size--], i = 1, c;

    while (2 * i <= size) {
        c = 2 * i;
        if (c + 1 <= size && heap[c + 1] > heap[c])
            c++;
        if (heap[c] <= x) break;
        heap[i] = heap[c];
        i = c;
    }

    heap[i] = x;
    return result;
}

int main() {
    int n, d[MAX], f[MAX], i, stops = 0;
    int D, F, position = 0, fuel;

    printf("Enter destination distance and initial fuel: ");
    scanf("%d %d", &D, &F);

    printf("Enter number of stations: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter station distance and fuel: ");
        scanf("%d %d", &d[i], &f[i]);
    }

    fuel = F;

    for (i = 0; i <= n; i++) {
        int next = (i == n) ? D : d[i];
        fuel -= next - position;

        while (fuel < 0 && size > 0) {
            fuel += pop();
            stops++;
        }

        if (fuel < 0) {
            printf("Destination cannot be reached.\n");
            return 0;
        }

        position = next;
        if (i < n)
            push(f[i]);
    }

    printf("Minimum refuelling stops = %d\n", stops);
    return 0;
}
