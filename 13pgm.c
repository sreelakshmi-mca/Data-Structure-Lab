#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node *next;
};
struct Node* create(struct Node **head, int data) {
struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
struct Node *last = *head;
newnode->data = data;
newnode->next = NULL;
if (*head == NULL) {
*head = newnode;
} else {
while (last->next != NULL) {
last = last->next;
}
last->next = newnode;
}
return *head;
}
void deleteFirst(struct Node **head) {
if (*head == NULL) {
printf("Underflow\n");
return;
}
struct Node *temp = *head;
*head = (*head)->next;
free(temp);
printf("First node is deleted\n");
}
void deleteEnd(struct Node **head) {
if (*head == NULL) {
printf("Underflow\n");
return;
}
struct Node *temp = *head, *prev;
if (temp->next == NULL) {
free(temp);
*head = NULL;
printf("Last node is deleted\n");
return;
}

while (temp->next != NULL) {
prev = temp;
temp = temp->next;
}
prev->next = NULL;
free(temp);
printf("Last node is deleted\n");
}
void deleteMid(struct Node **head, int pos) {
if (*head == NULL) {
printf("Underflow\n");
return;
}
struct Node *temp = *head;
if (pos == 0) {
*head = temp->next;
free(temp);
return;
}
for (int i = 0; temp != NULL && i < pos - 1; i++) {
temp = temp->next;
}
if (temp == NULL || temp->next == NULL) {
printf("Position does not exist\n");
return;
}
struct Node *next = temp->next->next;
free(temp->next);
temp->next = next;
}
void traversal(struct Node *head) {
struct Node *temp = head;
if (temp== NULL) {
printf("List is empty\n");
return;
}
while (temp != NULL) {
printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}

int main() {
int op, data, pos;
struct Node *head = NULL;
printf("----Singly Linked List----\n1. Insert\n2. Delete at First\n3. Delete at End\n4. Delete from particular node\n5. Traversal\n6. Exit\n");
do {
printf("\nEnter the option: ");
scanf("%d", &op);
switch (op) {
case 1:
printf("Enter the item: ");
scanf("%d", &data);
create(&head, data);
break;
case 2:
deleteFirst(&head);
break;
case 3:
deleteEnd(&head);
break;
case 4:
printf("Enter the position to delete: ");
scanf("%d", &pos);
deleteMid(&head, pos);
break;
case 5:
printf("Traversal: ");
traversal(head);
break;
case 6:
printf("Exiting...\n");
break;
default:
printf("Invalid option\n");
}
} while (op != 6);
return 0;
}
