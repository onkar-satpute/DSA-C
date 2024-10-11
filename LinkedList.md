# Creating and Display Singly Linked List
``` c
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create(struct node *slist, int n) {
    struct node *temp, *newnode;
    int i;
    slist = NULL;
    for (i = 1; i <= n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node)); // Allocate memory for new node
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return slist;
        }
        printf("Enter data part of newnode\n");
        scanf("%d", &newnode->data); // Input data for new node
        newnode->next = NULL; // Initialize next pointer

        if (slist == NULL) {
            slist = temp = newnode; // If it's the first node, initialize slist
        } else {
            temp->next = newnode; // Link previous node to new node
            temp = newnode; // Move temp to new node
        }
    }
    return slist;
}

void display(struct node *slist) {
    struct node *temp;
    temp = slist;
    if (slist == NULL)
        printf("Linked list is empty\n\n");
    else {
        printf("Linked list is:\n");
        while (temp != NULL) {
            printf("%d\t", temp->data); // Display data of current node
            temp = temp->next; // Move to the next node
        }
        printf("\n"); // Add newline at the end
    }
}

int main() {
    int ch, n;
    struct node *slist = NULL;
    do {
        printf("\nEnter your Choice\n");
        printf("1. Create\n2. Display\n3. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter number of nodes to be created\n");
                scanf("%d", &n);
                slist = create(slist, n);
                break;
            case 2:
                printf("Display function\n");
                display(slist);
                break;
            case 3:
                return 0;
        }
    } while (ch < 4);
    return 0;
}

```
# Create and Display Doubly Linked List
``` c
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in a doubly linked list
struct node {
   int data;                 // Data part of the node
   struct node *prev;        // Pointer to the previous node
   struct node *next;        // Pointer to the next node
};

// Declare pointers to manage the doubly linked list
struct node *dlist = NULL;   // Head pointer (start of the list)
struct node *temp = NULL;    // Temporary pointer for traversing the list
struct node *current = NULL; // Current pointer (not used in this program)

// Function to insert a new node at the end of the doubly linked list
void insert(int data) {
   // Allocate memory for new node
   struct node *newnode = (struct node*) malloc(sizeof(struct node));

   // Set the data and initialize previous and next pointers
   newnode->data = data;
   newnode->prev = NULL;
   newnode->next = NULL;

   // If the list is empty, make the new node the head of the list
   if(dlist == NULL) {
      dlist = newnode;  // The new node becomes the head (first node)
      return;
   }

   // Start traversing the list from the head
   temp = dlist;

   // Traverse to the last node of the list
   while(temp->next != NULL)
      temp = temp->next;

   // Insert the new node at the end of the list
   temp->next = newnode;   // Link last node to new node
   newnode->prev = temp;   // Link new node to previous last node
}

// Function to print the doubly linked list from head to tail
void printList() {
   struct node *ptr = dlist;  // Start from the head of the list

   // Print the head marker
   printf("\n[head] <=>");

   // Traverse the list and print each node's data
   while(ptr->next != NULL) {
      printf(" %d <=>", ptr->data);  // Print current node's data
      ptr = ptr->next;               // Move to the next node
   }

   // Print the last node's data
   printf(" %d <=>", ptr->data);
   
   // Print the tail marker
   printf(" [head]\n");
}

int main() {
   // Insert nodes with data into the doubly linked list
   insert(10);  // Insert node with value 10
   insert(20);  // Insert node with value 20
   insert(30);  // Insert node with value 30
   insert(1);   // Insert node with value 1
   insert(40);  // Insert node with value 40
   insert(56);  // Insert node with value 56
   
   // Print the current state of the list
   printList();
   
   return 0;  // Exit program
}

```
