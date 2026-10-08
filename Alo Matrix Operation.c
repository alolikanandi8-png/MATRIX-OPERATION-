#include <stdio.h>

/* Function to input a matrix */
void inputMatrix(int matrix[10][10], int rows, int cols)
{
    int i, j;

    printf("\nEnter the elements of the matrix:\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

/* Function to display a matrix */
void displayMatrix(int matrix[10][10], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
}

/* Function for Matrix Addition */
void addMatrix(int A[10][10], int B[10][10],
               int result[10][10], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

/* Function for Matrix Multiplication */
void multiplyMatrix(int A[10][10], int B[10][10],
                    int result[10][10],
                    int r1, int c1, int c2)
{
    int i, j, k;

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            result[i][j] = 0;

            for (k = 0; k < c1; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

/* Function for Matrix Transpose */
void transposeMatrix(int A[10][10],
                     int result[10][10],
                     int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            result[j][i] = A[i][j];
        }
    }
}

int main()
{
    int A[10][10], B[10][10], result[10][10];

    int r1, c1, r2, c2;
    int choice;

    do
    {
        printf("\n====================================");
        printf("\n       MATRIX OPERATIONS");
        printf("\n====================================");
        printf("\n1. Matrix Addition");
        printf("\n2. Matrix Multiplication");
        printf("\n3. Matrix Transpose");
        printf("\n4. Exit");
        printf("\n====================================");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                printf("\n--- Matrix Addition ---\n");

                printf("Enter rows and columns of Matrix A: ");
                scanf("%d %d", &r1, &c1);

                printf("Enter rows and columns of Matrix B: ");
                scanf("%d %d", &r2, &c2);

                if (r1 != r2 || c1 != c2)
                {
                    printf("\nError: Matrix addition requires");
                    printf(" both matrices to have the same dimensions.\n");
                    break;
                }

                inputMatrix(A, r1, c1);
                inputMatrix(B, r2, c2);

                addMatrix(A, B, result, r1, c1);

                printf("\nMatrix A:\n");
                displayMatrix(A, r1, c1);

                printf("\nMatrix B:\n");
                displayMatrix(B, r2, c2);

                printf("\nResult of Addition:\n");
                displayMatrix(result, r1, c1);

                break;


            case 2:

                printf("\n--- Matrix Multiplication ---\n");

                printf("Enter rows and columns of Matrix A: ");
                scanf("%d %d", &r1, &c1);

                printf("Enter rows and columns of Matrix B: ");
                scanf("%d %d", &r2, &c2);

                if (c1 != r2)
                {
                    printf("\nError: Matrix multiplication is not possible.\n");
                    printf("Columns of Matrix A must equal rows of Matrix B.\n");
                    break;
                }

                inputMatrix(A, r1, c1);
                inputMatrix(B, r2, c2);

                multiplyMatrix(A, B, result, r1, c1, c2);

                printf("\nMatrix A:\n");
                displayMatrix(A, r1, c1);

                printf("\nMatrix B:\n");
                displayMatrix(B, r2, c2);

                printf("\nResult of Multiplication:\n");
                displayMatrix(result, r1, c2);

                break;


            case 3:

                printf("\n--- Matrix Transpose ---\n");

                printf("Enter rows and columns of Matrix: ");
                scanf("%d %d", &r1, &c1);

                inputMatrix(A, r1, c1);

                transposeMatrix(A, result, r1, c1);

                printf("\nOriginal Matrix:\n");
                displayMatrix(A, r1, c1);

                printf("\nTranspose Matrix:\n");
                displayMatrix(result, c1, r1);

                break;


            case 4:

                printf("\nThank you for using Matrix Operations!\n");
                printf("Program exited successfully.\n");

                break;


            default:

                printf("\nInvalid choice! Please select 1 to 4.\n");
        }

    } while (choice != 4);

    return 0;
}