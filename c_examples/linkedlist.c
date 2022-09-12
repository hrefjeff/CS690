// Linked list implementation in C

#include <stdio.h>
#include <stdlib.h>

// Creating a node
typedef struct node {
  int value;
  struct node *next;
} node;

// print the linked list value
void printLinkedlist(node *p) {
  while (p != NULL) {
    printf("%d ", p->value);
    p = p->next;
  }
  printf("\n");
}

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
Name      : insertBeginning
Writer(s) : Jeffrey Allen
Purpose   : adds a node to the beginning of the list
Params    : Pointer to a pointer of a node, value
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
void insertBeginning(node **head, int val){

  // Allocate mem for new node
  node *newNode;
  newNode = malloc(sizeof(node));

  // Assign vals
  newNode->value = val;
  newNode->next = *head;

  // Change the location where head points to
  *head = newNode;
}

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
Name      : insertEnd
Writer(s) : Jeffrey Allen
Purpose   : adds a node to the end of the list
Params    : Pointer to a node, value
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
void insertEnd(node *head, int val){

  // Allocate mem for new node
  node *newNode;
  newNode = malloc(sizeof(node));

  // Assign vals
  newNode->value = val;
  newNode->next = NULL;

  // Begin traversal of list and find end
  node *temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  
  // Assign the last node's next to newly created node
  temp->next = newNode;
}

void delete(node *p){
  
}

int main() {
  // Initialize nodes
  node *head = NULL;
  node *one = NULL;
  node *two = NULL;
  node *three = NULL;

  // Allocate memory
  one = malloc(sizeof(node));
  two = malloc(sizeof(node));
  three = malloc(sizeof(node));

  // Assign value values
  one->value = 1;
  two->value = 2;
  three->value = 3;

  // Connect nodes
  one->next = two;
  two->next = three;
  three->next = NULL;

  // printing node-value
  head = one;
  printLinkedlist(head);
  insertEnd(head, 5);
  insertBeginning(&head, 0);
  printLinkedlist(head);
}