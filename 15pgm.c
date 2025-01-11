#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node *next;
};
struct Node *f = NULL;
struct Node *r = NULL;

void enqueue(int data) {
struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
if (r == NULL) {
f = r = newNode;
} else {
r->next = newNode;
r = newNode;
}
printf("Enqueued: %d\n", data);
}
void dequeue() {
if (f == NULL) {
printf("Underflow: Queue is empty!\n");
return;
}
printf("Dequeued: %d\n", f->data);
if (f == r) {
free(f);
f = r = NULL;
} else {
struct Node *nextNode = f->next;
free(f);
f = nextNode;
}
}
void traversal() {
if (f == NULL) {
printf("Queue is empty!\n");
return;
}
struct Node *temp = f;
printf("Queue: ");
while (temp != NULL) {
printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}

int main() {
int op, data;

printf("----Queue Operations----\n1. Enqueue\n2. Dequeue\n3. Traversal\n4. Exit\n ");
do {
printf("\nEnter the option: ");
scanf("%d", &op);
switch (op) {
case 1:
printf("Enter the item to enqueue: ");
scanf("%d", &data);
enqueue(data);
break;
case 2:
dequeue();
break;
case 3:
traversal();
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
