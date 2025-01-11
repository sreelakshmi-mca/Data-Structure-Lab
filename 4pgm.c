#include <stdio.h>
void sum1();
void sum2(int a, int b);
int sum3();
int sum4(int a, int b);

int main()
{
    int ch;
    int num1, num2;

    do
    {
        printf("Choose an option:\n");
        printf("1.Sum Function without argument and no return type\n");
        printf("2.Sum function with argument and no return type\n");
        printf("3.Sum function without argument and return type\n");
        printf("4.Sum function with argument and return type\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            sum1();
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            sum2(num1, num2);
            break;
        case 3:
            num1 = sum3();
            printf("Sum from sum3(): %d\n", num1);
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);

            printf("Sum from sum4(): %d\n", sum4(num1, num2));
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }

    } while (ch > 0 && ch < 5);

    return 0;
}

void sum1()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Sum: %d\n", a + b);
}

void sum2(int a, int b)
{
    printf("Sum: %d\n", a + b);
}

int sum3()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    return a + b;
}

int sum4(int a, int b)
{
    return a + b;
}
