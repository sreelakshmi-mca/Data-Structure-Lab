#include <stdio.h>
#define n 5
void push(int a[], int *top, int item)
{
    if (*top == n - 1)
    {
        printf("Stack is full!\n");
    }
    else
    {
        *top += 1;
        a[*top] = item;
        printf("%d is pushed to stack\n", item);
    }
}

void pop(int a[], int *top)
{
    if (*top < 0)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        int x = a[*top];
        *top -= 1;
        printf("%d is popped from the stack\n", x);
    }
}

int display(int a[], int top)
{
    if (top < 0)
    {
        printf("Stack is empty!\n");
    }
    printf("Stack:  ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[n], op, top = -1, item;
    printf("-----Stack Operations-----\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
    do
    {
        printf("Enter the option:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter item to push:\n");
            scanf("%d", &item);
            push(a, &top, item);
            break;
        case 2:
            pop(a, &top);
            break;
        case 3:
            display(a, top);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        deafult:
            printf("Invalid option\n");
        }
    } while (op != 4);
    return 0;
}