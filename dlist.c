#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *create(struct node *dlist, int n)
{
    struct node *newnode, *temp;
    dlist = NULL;
    for (int i = 0; i < n; i++)
    {
        newnode = ((struct node *)malloc(sizeof(struct node)));
        printf("Enter the data:  ");
        scanf("%d", &newnode->data);
        newnode->next = newnode->prev = NULL;
        if (dlist == NULL)
        {
            dlist = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
    return dlist;
}

void display(struct node *dlist)
{
    struct node *temp;
    temp = dlist;
    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }

    printf("\nThe reversed list is :\n");
    while(dlist && dlist->next != NULL){
        dlist = dlist->next;
    }

    temp = dlist;
    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    struct node *dlist;
    dlist = create(dlist, 5);
    printf("\n Your list is : \n");
    display(dlist);
}