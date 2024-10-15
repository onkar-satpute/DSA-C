# Reverse Singly Linked List
```c
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Creating the singly linked list
struct node *create(struct node *slist, int n) {
    int i;
    struct node *temp, *newnode;
    slist = NULL;
    for (i = 0; i < n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data part: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;  // Ensure next is initialized
        if (slist == NULL) {
            slist = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return slist;
}

void display(struct node *slist) {
    struct node *temp;
    temp = slist;
    if (slist == NULL) {
        printf("The linked list is empty..\n\n");
    } else {
        printf("The linked list is: \n");
        while (temp != NULL) {
            printf("%d \t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

struct node *reverse(struct node *slist) {
    struct node *prev = NULL;
    struct node *current = slist;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next; 
        current->next = prev;  
        prev = current;      
        current = next;
    }
    return prev; 
}

int main() {
    int ch, n;
    struct node *slist = NULL;
    do {
        printf("Enter your choice: \n1.create\n2.Display\n3.Exit\n4.Reverse\n");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter the number of nodes to be created: ");
            scanf("%d", &n);
            slist = create(slist, n);
            break;

        case 2:
            display(slist);
            printf("\n");
            break;

        case 3:
            return 0;

        case 4:
            slist = reverse(slist);
            printf("The linked list has been reversed.\n");
            break;

        default:
            printf("Enter Valid choice\n \n ");
            break;
        }
    } while (ch < 11);
    printf("Exited");
    return 0;
}
```