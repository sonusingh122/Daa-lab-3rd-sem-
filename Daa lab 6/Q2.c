#include <stdio.h>
#include <math.h>

#define MAX 100

// Function to print a matrix
void printMatrix(int A[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

// 1. Matrix Addition - O(n^2)
void addition(int A[][MAX], int B[][MAX],
              int C[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// 2. Matrix Multiplication - O(n^3)
void multiplication(int A[][MAX], int B[][MAX],
                   int C[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;

            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// 3. Check Zero Matrix - O(n^2)
int isZeroMatrix(int A[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] != 0)
            {
                return 0;
            }
        }
    }

    return 1;
}

// 4. Check Symmetric Matrix - O(n^2)
int isSymmetric(int A[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i][j] != A[j][i])
            {
                return 0;
            }
        }
    }

    return 1;
}

// 5. Determinant using cofactor expansion - O(n!)
int determinant(int A[][MAX], int n)
{
    // For 1 x 1 matrix
    if (n == 1)
    {
        return A[0][0];
    }

    // For 2 x 2 matrix
    if (n == 2)
    {
        return A[0][0] * A[1][1]
             - A[0][1] * A[1][0];
    }

    int det = 0;
    int minor[MAX][MAX];

    for (int col = 0; col < n; col++)
    {
        int r = 0;

        // Create minor matrix
        for (int i = 1; i < n; i++)
        {
            int c = 0;

            for (int j = 0; j < n; j++)
            {
                if (j == col)
                {
                    continue;
                }

                minor[r][c] = A[i][j];
                c++;
            }

            r++;
        }

        int sign;

        if (col % 2 == 0)
            sign = 1;
        else
            sign = -1;

        det = det + sign * A[0][col]
              * determinant(minor, n - 1);
    }

    return det;
}

// 6. Transpose in situ - O(n^2)
void transpose(int A[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int temp = A[i][j];

            A[i][j] = A[j][i];

            A[j][i] = temp;
        }
    }
}

// 7. Eigenvalues and Eigenvectors for 2 x 2 matrix
void eigenValuesVectors(int A[][MAX])
{
    double a = A[0][0];
    double b = A[0][1];
    double c = A[1][0];
    double d = A[1][1];

    // Characteristic equation:
    // lambda^2 - (a+d)lambda + (ad-bc) = 0

    double trace = a + d;
    double determinantValue = a * d - b * c;

    double discriminant =
        trace * trace - 4 * determinantValue;

    if (discriminant < 0)
    {
        printf("Complex eigenvalues are obtained.\n");
        return;
    }

    double lambda1 =
        (trace + sqrt(discriminant)) / 2;

    double lambda2 =
        (trace - sqrt(discriminant)) / 2;

    printf("Eigenvalue 1 = %.2f\n", lambda1);
    printf("Eigenvalue 2 = %.2f\n", lambda2);

    printf("\nCorresponding eigenvectors:\n");

    // Eigenvector for lambda1
    printf("For eigenvalue %.2f: ", lambda1);

    if (b != 0)
    {
        printf("v = [%.2f, %.2f]\n", b, lambda1 - a);
    }
    else if (c != 0)
    {
        printf("v = [%.2f, %.2f]\n", lambda1 - d, c);
    }
    else
    {
        printf("v = [1, 0] (one possible vector)\n");
    }

    // Eigenvector for lambda2
    printf("For eigenvalue %.2f: ", lambda2);

    if (b != 0)
    {
        printf("v = [%.2f, %.2f]\n", b, lambda2 - a);
    }
    else if (c != 0)
    {
        printf("v = [%.2f, %.2f]\n", lambda2 - d, c);
    }
    else
    {
        printf("v = [0, 1] (one possible vector)\n");
    }
}

int main()
{
    int A[MAX][MAX];
    int B[MAX][MAX];
    int C[MAX][MAX];

    int n;

    // Input size
    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    // Input Matrix A
    printf("\nEnter elements of Matrix A:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    // Input Matrix B
    printf("\nEnter elements of Matrix B:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    // Display Matrix A
    printf("\nMatrix A:\n");
    printMatrix(A, n);

    // Display Matrix B
    printf("\nMatrix B:\n");
    printMatrix(B, n);

    addition(A, B, C, n);

    printf("\n1. Matrix Addition:\n");
    printMatrix(C, n);

    multiplication(A, B, C, n);

    printf("\n2. Matrix Multiplication:\n");
    printMatrix(C, n);

    if (isZeroMatrix(A, n))
    {
        printf("\n3. Matrix A is a Zero Matrix.\n");
    }
    else
    {
        printf("\n3. Matrix A is NOT a Zero Matrix.\n");
    }

    if (isSymmetric(A, n))
    {
        printf("\n4. Matrix A is Symmetric.\n");
    }
    else
    {
        printf("\n4. Matrix A is NOT Symmetric.\n");
    }

    printf("\n5. Determinant of Matrix A = %d\n",
           determinant(A, n));

    transpose(A, n);

    printf("\n6. Transpose of Matrix A:\n");
    printMatrix(A, n);

    if (n == 2)
    {
        printf("\n7. Eigenvalues and Eigenvectors:\n");

        eigenValuesVectors(A);
    }
    else
    {
        printf("\n7. Eigenvalue/Eigenvector calculation ");
        printf("shown for 2 x 2 matrix only.\n");
        printf("For general n x n matrix, the complexity ");
        printf("depends on the numerical algorithm used.\n");
    }

    return 0;
}