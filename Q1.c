#include <stdio.h>

#define MAX 100

typedef struct {
    double value, weight, decay;
} Item;

int main() {
    Item a[MAX];
    int n, i, j;
    double W, time = 0, total = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value, weight, decay rate: ");
        scanf("%lf %lf %lf",&a[i].value, &a[i].weight, &a[i].decay);
    }

    printf("Enter knapsack capacity: ");
    scanf("%lf", &W);

    // Greedy ordering by initial value density
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            double r1 = a[i].value / a[i].weight;
            double r2 = a[j].value / a[j].weight;

            if (r2 > r1) {
                Item temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for (i = 0; i < n && W > 0; i++) {
        double take = a[i].weight;
        if (take > W)
            take = W;

        double density = a[i].value / a[i].weight
                         - a[i].decay * time;

        if (density > 0)
            total += take * density;

        time += take;
        W -= take;
    }

    printf("Greedy simulated value = %.2f\n", total);
    return 0;
}
