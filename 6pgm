#include <stdio.h>
int sort(int *arr, int *n)
{
    int temp;
    for (int i = 0; i < (*n) - 1; i++)
    {
        for (int j = 0; j < (*n) - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    }
    return *arr;
}

int main()
{
    int a[50], i, n;
    printf("Enter the size of array:");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    a[i] = sort(a, &n);
    printf("Sorted Array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}