#include <stdio.h>
void enqueue(int q[], int *f, int *r, int item, int n)
{
    if (*r == n - 1)
    {
        printf("Overflow: Queue is full!\n");
    }
    else
    {
        if (*f == -1 && *r == -1)
        {
            *f = *r = 0;
        }
        else
        {
            *r += 1;
        }
        q[*r] = item;
        printf("%d is enqueued to the queue\n", item);
    }
}

void dequeue(int q[], int *f, int *r)
{
    if (*f == -1 && *r == -1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        int item = q[*f];
        printf("%d dequeued from the queue\n", item);
        if (*f == *r)
        {
            *f = *r = -1;
        }
        else
        {
            *f = *f + 1;
        }
    }
}

void display(int q[], int f, int r)
{
    if (f == -1 && r == -1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("QUEUE:  ");
        for (int i = f; i <= r; i++)
        {
            printf("%d  ", q[i]);
        }
        printf("\n");
    }
}

int main()
{
    int op, n, f = -1, r = -1, item;
    printf("Enter size of queue:");
    scanf("%d", &n);
    int q[n];
    printf("-----Queue Operations----\n");
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n ");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter item to enqueue: ");
            scanf("%d", &item);
            enqueue(q, &f, &r, item, n);
            break;
        case 2:
            dequeue(q, &f, &r);
            break;
        case 3:
            display(q, f, r);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }

    } while (op != 4);
    return 0;
}
