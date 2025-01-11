#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *create(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insertFront(struct Node **head, int data)
{
    struct Node *newnode = create(data);
    newnode->next = *head;
    *head = newnode;
}

void insertEnd(struct Node **head, int data)
{
    struct Node *newnode = create(data);
    struct Node *temp = *head;
    while (temp != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertMid(struct Node **head, int data, int prev)
{
    struct Node *newnode = create(data);
    struct Node *temp = *head;
    while (temp != NULL && temp->data != prev)
    {
        temp = temp->next;
    }
    newnode->next = temp;
    temp->next = newnode;
}

void traversal(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {

        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void search(struct Node *head, int key)
{
    int position = 1;
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Node with data %d is found at");
            temp = temp->next;
            position++;
        }
        printf("Node with data %d not found.\n", key);
    }
}
// Main function with menu-driven program
int main()
{
    struct Node *head = NULL;
    int choice, data, prev;

    printf("\nMenu:\n");
    printf("1. Insert at Front\n");
    printf("2. Insert at End\n");
    printf("3. Insert After a Node\n");
    printf("4. Traverse List\n");
    printf("5. Search for a Node\n");
    printf("6. Exit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert at front: ");
            scanf("%d", &data);
            insertFront(&head, data);
            break;
        case 2:
            printf("Enter data to insert at end: ");
            scanf("%d", &data);
            insertEnd(&head, data);
            break;
        case 3:
            printf("Enter the data of the node after which to insert: ");
            scanf("%d", &prev);
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertMid(&head, data, prev);
            break;
        case 4:
            printf("Linked List: ");
            traversal(head);
            break;
        case 5:
            printf("Enter data to search: ");
            scanf("%d", &data);
            search(head, data);
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}