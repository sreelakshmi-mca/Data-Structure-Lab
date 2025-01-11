#include <stdio.h>
void linear(int a[], int n);
void binary(int a[], int n);
int main()
{
    int i, n, op;
    printf("Enter the no. of elements:");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    do
    {
        printf("Choose the option:\n1.Linear Search\n2.Binary Search\n3.Exit\n");
        printf("Enter the option:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            linear(a, n);
            break;
        case 2:
            binary(a, n);
            break;
        case 3:
            printf("Exiting...");
            break;
        }
    } while (op != 3);
}

void linear(int a[], int n)
{
    int i, x, f = 0;
    printf("Enter the element to search:");
    scanf("%d", &x);
    for (i = 0; i < n; i++)
    {
        if (x == a[i])
        {
            f = 1;
            printf("Element found at position %d\n", i);
            break;
        }
    }
    if (f == 0)
    {
        printf("Not found\n");
    }
}

void binary(int a[], int n)
{
    int i, j, temp, pos = -1;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("Sorted Array:");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");

    int x, lb = 0, ub = n - 1, mid;
    printf("Enter the element to search:");
    scanf("%d", &x);
    while (lb <= ub)
    {
        mid = (lb + ub) / 2;
        if (a[mid] == x)
        {
            pos = mid;
            printf("Element found at position %d\n", mid);
            break;
        }
        else if (x > a[mid])
        {
            lb = mid + 1;
        }
        else
        {
            ub = mid - 1;
        }
    }
    if (pos == -1)
    {
        printf("Element not found \n");
    }
}