#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node *next;
};
void push(struct Node **top, int data) {
struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = *top;
*top = newNode;
printf("%d is pushed to stack\n", data);
}
void pop(struct Node **top) {
if (*top == NULL) {
printf("Stack Underflow: Stack is empty\n");
return;
}
struct Node *temp = *top;
*top = (*top)->next;
printf("%d popped from the stack\n", temp->data);
free(temp);
}
void traversal(struct Node *top) {
if (top == NULL) {
printf("Stack is empty\n");
return;
}
printf("STACK: ");
struct Node *temp = top;
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}

int main() {
int op, data;
struct Node *top = NULL;
printf("----Stack Operations----\n1. Push\n2. Pop\n 3. Traversal\n4. Exit\n ");
do {
printf("\nEnter the option: ");
scanf("%d", &op);
switch (op) {
case 1:
printf("Enter the item to push: ");
scanf("%d", &data);
push(&top, data);
break;
case 2:
pop(&top);
break;
case 3:
traversal(top);
break;
case 4:
printf("Exiting...\n");
break;
default:
printf("Invalid option\n");
}
} while (op != 4);
return 0;
}
