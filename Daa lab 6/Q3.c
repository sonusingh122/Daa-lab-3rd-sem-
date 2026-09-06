#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct
{
    double real;
    double imag;
} Complex;

/* Complex addition */
Complex add(Complex a, Complex b)
{
    Complex c;

    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;

    return c;
}

/* Complex subtraction */
Complex subtract(Complex a, Complex b)
{
    Complex c;

    c.real = a.real - b.real;
    c.imag = a.imag - b.imag;

    return c;
}

/* Complex multiplication */
Complex multiply(Complex a, Complex b)
{
    Complex c;

    c.real = a.real * b.real - a.imag * b.imag;
    c.imag = a.real * b.imag + a.imag * b.real;

    return c;
}

/* Divide and Conquer FFT */
void FFT(Complex a[], int n, int inverse)
{
    if (n == 1)
        return;

    Complex *even = malloc((n / 2) * sizeof(Complex));
    Complex *odd = malloc((n / 2) * sizeof(Complex));

    /* Divide */
    for (int i = 0; i < n / 2; i++)
    {
        even[i] = a[2 * i];
        odd[i] = a[2 * i + 1];
    }

    /* Conquer */
    FFT(even, n / 2, inverse);
    FFT(odd, n / 2, inverse);

    /* Combine */
    double angle = 2 * PI / n;

    if (inverse)
        angle = -angle;

    Complex w;
    w.real = 1;
    w.imag = 0;

    Complex wn;
    wn.real = cos(angle);
    wn.imag = sin(angle);

    for (int k = 0; k < n / 2; k++)
    {
        Complex t = multiply(w, odd[k]);

        a[k] = add(even[k], t);

        a[k + n / 2] = subtract(even[k], t);

        w = multiply(w, wn);
    }

    free(even);
    free(odd);
}

/* Inverse FFT */
void inverseFFT(Complex a[], int n)
{
    FFT(a, n, 1);

    for (int i = 0; i < n; i++)
    {
        a[i].real = a[i].real / n;
        a[i].imag = a[i].imag / n;
    }
}

/* Find next power of 2 */
int nextPowerOfTwo(int x)
{
    int p = 1;

    while (p < x)
        p *= 2;

    return p;
}

/* Convolution using FFT */
void convolution(int A[], int m, int B[], int n)
{
    int resultSize = m + n - 1;

    int size = nextPowerOfTwo(resultSize);

    Complex *FA = calloc(size, sizeof(Complex));
    Complex *FB = calloc(size, sizeof(Complex));

    /* Store A */
    for (int i = 0; i < m; i++)
    {
        FA[i].real = A[i];
        FA[i].imag = 0;
    }

    /* Store B */
    for (int i = 0; i < n; i++)
    {
        FB[i].real = B[i];
        FB[i].imag = 0;
    }

    /* FFT(A) */
    FFT(FA, size, 0);

    /* FFT(B) */
    FFT(FB, size, 0);

    /* Multiply FFT(A) and FFT(B) */
    for (int i = 0; i < size; i++)
    {
        FA[i] = multiply(FA[i], FB[i]);
    }

    /* Inverse FFT */
    inverseFFT(FA, size);

    /* Print result */
    printf("\nConvolution Result:\n");

    for (int i = 0; i < resultSize; i++)
    {
        printf("%.0f ", FA[i].real);
    }

    printf("\n");

    free(FA);
    free(FB);
}

int main()
{
    int m, n;

    printf("Enter size of vector A: ");
    scanf("%d", &m);

    int *A = malloc(m * sizeof(int));

    printf("Enter elements of A:\n");

    for (int i = 0; i < m; i++)
        scanf("%d", &A[i]);

    printf("Enter size of vector B: ");
    scanf("%d", &n);

    int *B = malloc(n * sizeof(int));

    printf("Enter elements of B:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &B[i]);

    /* Q3 condition */
    if (n < m)
    {
        printf("Please ensure n >= m.\n");

        free(A);
        free(B);

        return 0;
    }

    printf("\nVector A: ");

    for (int i = 0; i < m; i++)
        printf("%d ", A[i]);

    printf("\nVector B: ");

    for (int i = 0; i < n; i++)
        printf("%d ", B[i]);

    convolution(A, m, B, n);

    free(A);
    free(B);

    return 0;
}