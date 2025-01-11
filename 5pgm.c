#include <stdio.h>

int insert(int a[], int *n)
{
    int k, x;
    printf("Enter a element to insert:");
    scanf("%d", &x);
    printf("Enter a postion to insert:");
    scanf("%d", &k);
    for (int i = *n; i > k; i--)
    {
        a[i] = a[i - 1];
    }
    a[k] = x;
    (*n)++;

    for (int i = 0; i < *n; i++)
    {
        printf("\t%d", a[i]);
    }
    printf("\n");

    return 1;
}

int delete(int a[], int *n)
{
    int x, k;
    printf("Enter the postion to delete :\n");
    scanf("%d", &k);
    x = a[k];

    for (int i = k; i < (*n) - 1; i++)
    {
        a[i] = a[i + 1];
    }
    (*n)--;
    a[*n] = 0;
    printf("Array after deletion:");
    for (int j = 0; j < (*n); j++)
    {
        printf("\t%d", a[j]);
    }
    printf("\n");
    return 1;
}

int traverse(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[50], n, op;
    printf("Enter the no. of elements:");
    scanf("%d", &n);
    printf("Enter the elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("1.Insert an element to a particular location\n");
    printf("2.Delete an element from a particular location\n");
    printf("3.Traverse\n");
    printf("4.Exit\n");
    do
    {
        printf("Enter a choice:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            insert(a, &n);
            break;
        case 2:
            delete (a, &n);
            break;
        case 3:
            traverse(a, n);
            break;
        case 4:
            printf("Exit");
            break;
        }
    } while (op != 4);
    return 0;
}