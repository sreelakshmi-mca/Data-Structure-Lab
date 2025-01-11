#include <stdio.h>
int input(int r, int c, int m[r][c], char matrix);
void add();
void sub();
void mul();

int main()
{
    int op;
    printf("----Matrix Operations----\n1.Addition\n2.Substraction\n3.Multiplication\n4.Exit\n");
    do
    {
        printf("Enter the option:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            add();
            break;
        case 2:
            sub();
            break;
        case 3:
            mul();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice");
            break;
        }
    } while (op != 4);
    return 0;
}

int input(int r, int c, int m[r][c], char matrix)
{
    printf("Enter the elements in Matrix %c:\n", matrix);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }
}

void add()
{
    int r, c;
    printf("Enter the no. of rows and columns:\n");
    scanf("%d%d", &r, &c);
    if (r <= 0 || c <= 0)
    {
        printf("Invalid dimensions for the matrices!\n");
        return;
    }
    int a[r][c], b[r][c], x[r][c];
    input(r, c, a, 'A');
    input(r, c, b, 'B');

    printf("Result:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            x[i][j] = a[i][j] + b[i][j];
            printf("%d   ", x[i][j]);
        }
        printf("\n");
    }
}

void sub()
{
    int r, c;
    printf("Enter the no. of rows and columns:\n");
    scanf("%d%d", &r, &c);
    if (r <= 0 || c <= 0)
    {
        printf("Invalid dimensions for the matrices!\n");
        return;
    }
    int a[r][c], b[r][c], x[r][c];
    input(r, c, a, 'A');
    input(r, c, b, 'B');

    printf("Result:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            x[i][j] = a[i][j] - b[i][j];
            printf("%d   ", x[i][j]);
        }
        printf("\n");
    }
}

void mul()
{
    int r1, c1, r2, c2, k;
    printf("Enter the no. of rows and columns for A:\n");
    scanf("%d%d", &r1, &c1);
    printf("Enter the no. of rows and columns for B:\n");
    scanf("%d%d", &r2, &c2);
    if (c1 != r2)
    {
        printf("Matrix multiplication not possible, since c2 is not equal to r1\n");
        return;
    }
    int a[r1][c1], b[r2][c2], x[r1][c2];
    input(r1, c1, a, 'A');
    input(r2, c2, b, 'B');
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            x[i][j] = 0;
            for (k = 0; k < c1; k++)
            {
                x[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("Result:\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d   ", x[i][j]);
        }
        printf("\n");
    }
}