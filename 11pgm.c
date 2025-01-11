#include <stdio.h>
int count = 0;
void enqueue_CQ(int q[], int *r, int *f, int max, int item)
{

    if (count == max)
    {
        printf("Circular queue is full!\n");
    }
    else
    {
        if (*f == -1 && *r == -1)
        {
            *f = *r = 0;
        }
        else
        {
            *r = (*r + 1) % max;
        }
        q[*r] = item;
        count++;
        printf("%d is enqueued to Circular Queue\n", item);
    }
}

void dequeue_CQ(int q[], int *r, int *f, int max)
{
    if (count == 0)
    {
        printf("Circular queue id empty!\n");
    }
    else
    {
        int item = q[*f];
        if (*f == *r)
        {
            *f = *r = -1;
        }
        else
        {
            *f = (*f + 1) % max;
        }
        printf("%d is dequeued from Circular Queue\n", item);
        count--;
    }
}

void display(int q[], int r, int f, int max)
{
    if (count == 0)
    {
        printf("Circular queue id empty!\n");
    }
    else
    {
        printf("CIRCULAR QUQUE:  ");
        int i = f;
        for (int c = 0; c < count; c++)
        {
            printf("%d  ", q[i]);
            i = (i + 1) % max;
        }
        printf("\n");
    }
}

int main()
{
    int n, op, f = -1, r = -1, item;
    printf("Enter the size of circular queue:");
    scanf("%d", &n);
    int q[n];
    printf("----Circular Queue Operations----\n");
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    do
    {
        printf("Enter the choice: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter the item to enqueue: ");
            scanf("%d", &item);
            enqueue_CQ(q, &r, &f, n, item);
            break;
        case 2:
            dequeue_CQ(q, &r, &f, n);
            break;
        case 3:
            display(q, r, f, n);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    } while (op != 4);
    return 0;
}