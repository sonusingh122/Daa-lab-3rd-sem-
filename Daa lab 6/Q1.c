#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* Print Array */
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

/* (i) Maximum - O(n) */
int findMax(int a[], int n) {
    int max = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }

    return max;
}

/* (ii) First and Second Largest - O(n) */
void findFirstSecond(int a[], int n) {
    int largest, second;

    if (a[0] > a[1]) {
        largest = a[0];
        second = a[1];
    } else {
        largest = a[1];
        second = a[0];
    }

    for (int i = 2; i < n; i++) {
        if (a[i] > largest) {
            second = largest;
            largest = a[i];
        }
        else if (a[i] > second && a[i] != largest) {
            second = a[i];
        }
    }

    printf("Largest = %d\n", largest);
    printf("Second Largest = %d\n", second);
}

/* (iii) Mean - O(n) */
double findMean(int a[], int n) {
    double sum = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum / n;
}

/* Merge for Merge Sort */
void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];

    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1)
        a[k++] = L[i++];

    while (j < n2)
        a[k++] = R[j++];

    free(L);
    free(R);
}

/* Merge Sort - O(n log n) */
void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

/* (iv) Median - O(n log n) */
double findMedian(int a[], int n) {
    mergeSort(a, 0, n - 1);

    if (n % 2 != 0)
        return a[n / 2];

    return (a[n / 2 - 1] + a[n / 2]) / 2.0;
}

/* (v) Standard Deviation - O(n) */
double standardDeviation(int a[], int n) {
    double sum = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    double mean = sum / n;

    double variance = 0;

    for (int i = 0; i < n; i++) {
        double diff = a[i] - mean;
        variance += diff * diff;
    }

    variance /= n;

    return sqrt(variance);
}

/* (vi) Mode - O(n^2) */
int findMode(int a[], int n) {
    int mode = a[0];
    int maxCount = 1;

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (a[i] == a[j])
                count++;
        }

        if (count > maxCount) {
            maxCount = count;
            mode = a[i];
        }
    }

    return mode;
}

/* (vii) Remove Duplicates - O(n^2) */
int removeDuplicates(int a[], int n) {
    int newSize = n;

    for (int i = 0; i < newSize; i++) {

        for (int j = i + 1; j < newSize; j++) {

            if (a[i] == a[j]) {

                for (int k = j; k < newSize - 1; k++)
                    a[k] = a[k + 1];

                newSize--;
                j--;
            }
        }
    }

    return newSize;
}

/* (viii) Reverse - O(n) */
void reverseArray(int a[], int n) {
    int i = 0;
    int j = n - 1;

    while (i < j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        i++;
        j--;
    }
}

/* (ix) Partition - O(n) */
void partitionArray(int a[], int n, int pivot) {
    int i = 0;
    int j = n - 1;

    while (i <= j) {

        while (i < n && a[i] >= pivot)
            i++;

        while (j >= 0 && a[j] < pivot)
            j--;

        if (i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;

            i++;
            j--;
        }
    }
}

int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));

    printf("Enter %d unsorted elements:\n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nOriginal Array: ");
    printArray(a, n);

    /* (i) Maximum */
    printf("\n(i) Maximum = %d\n", findMax(a, n));

    /* (ii) First and Second Largest */
    printf("\n(ii) First and Second Largest:\n");
    findFirstSecond(a, n);

    /* (iii) Mean */
    printf("\n(iii) Mean = %.2f\n", findMean(a, n));

    /* (iv) Median */
    int *temp = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        temp[i] = a[i];

    printf("\n(iv) Median = %.2f\n", findMedian(temp, n));

    free(temp);

    /* (v) Standard Deviation */
    printf("\n(v) Standard Deviation = %.2f\n",
           standardDeviation(a, n));

    /* (vi) Mode */
    printf("\n(vi) Mode = %d\n", findMode(a, n));

    /* (vii) Remove Duplicates */
    temp = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        temp[i] = a[i];

    int newSize = removeDuplicates(temp, n);

    printf("\n(vii) Array after removing duplicates: ");
    printArray(temp, newSize);

    free(temp);

    /* (viii) Reverse */
    temp = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        temp[i] = a[i];

    reverseArray(temp, n);

    printf("\n(viii) Reversed Array: ");
    printArray(temp, n);

    free(temp);

    /* (ix) Partition */
    temp = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        temp[i] = a[i];

    int pivot;

    printf("\nEnter pivot element: ");
    scanf("%d", &pivot);

    partitionArray(temp, n, pivot);

    printf("(ix) Array after partitioning: ");
    printArray(temp, n);

    free(temp);
    free(a);

    return 0;
}