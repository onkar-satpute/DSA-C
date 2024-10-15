# Linked list all operations
``` c
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
// creating the singly linked list
struct node *create(struct node *slist, int n)
{
    int i;
    struct node *temp, *newnode;
    slist = NULL;
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data part");
        scanf("%d", &newnode->data);
        newnode->next = NULL:
        if (slist == NULL)
        {
            slist = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return slist;
}

void display(struct node *slist)
{
    struct node *temp;
    temp = slist;
    if (slist == NULL)
    {
        printf("The linked list is empty..\n\n");
    }
    else
    {
        printf("The linked list is: \n");
        while (temp != NULL)
        {
            printf("%d \t", temp->data);
            temp = temp->next;
        }
    }
}

struct node *insertAtEnd(struct node *slist)
{
    struct node *temp, *newnode;
    int n;
    newnode = ((struct node *)malloc(sizeof(struct node)));
    printf("Add new value to insert: ");
    scanf("%d", &n);
    newnode->data = n;
    newnode->next = NULL;

    if (slist == NULL)
    {
        slist = newnode;
    }
    else
    {
        temp = slist;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return slist;
}
struct node *insertAtBeg(struct node *slist)
{
    struct node *newnode;
    int n;
    printf("Enter the data for insert: ");
    scanf("%d", &n);
    newnode = ((struct node *)malloc(sizeof(struct node)));
    newnode->data = n;
    if (slist == NULL)
        newnode->next = NULL;
    else
        newnode->next = slist;
    slist = newnode;
    return slist;
}

struct node *insertAtInter(struct node *slist)
{
    int i, pos;
    struct node *temp, *temp1, *newnode;
    printf("Enter the position : ");
    scanf("%d", &pos);
    newnode = ((struct node *)malloc(sizeof(struct node)));
    printf("Enter the data part: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    temp = slist;
    for (i = 1; i < pos - 1; i++)
        temp = temp->next;
    temp1 = temp->next;
    newnode->next = temp1;
    temp->next = newnode;
    return slist;
}

struct node *deletebeg(struct node *slist)
{
    struct node *temp;
    temp = slist;
    slist = temp->next;
    free(temp);
    return slist;
}

struct node *deleteend(struct node *slist)
{
    struct node *temp, *temp1;
    temp = slist;
    while (temp->next != NULL)
    {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = NULL;
    free(temp);
    return slist;
}

struct node *deleteinter(struct node *slist)
{
    int pos, i;
    struct node *temp, *temp1;
    temp = slist;
    printf("Enter the position you want to delete: ");
    scanf("%d", &pos);
    for (i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
    return slist;

}

int count(struct node * slist){
    int cnt=0;
    struct node * temp;
    temp = slist;
    while(temp!=NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int main()
{
    int ch, i, n, result;
    struct node *slist = NULL;
    do
    {
        printf("Enter your choice: \n1.create\n2.Display\n3.Exit\n4.Insert at End\n5.Insert at Begin\n6.Insert At Intermidiate\n7.Delete begining\n8.Delete from end\n9.Delete from Intermediate\n10.Count the nodes of your linked list");
        scanf("%d", &ch);
        switch (ch)
        {
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

            slist = insertAtEnd(slist);
            break;

        case 5:
            slist = insertAtBeg(slist);
            break;

        case 6:
            slist = insertAtInter(slist);
            break;

        case 7:
            slist = deletebeg(slist);
            break;

        case 8:
            slist = deleteend(slist);
            break;

        case 9:
            slist = deleteinter(slist);
            break;

        case 10:
            result = count(slist);
            printf("%d nodes pressent in the list..", result);
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
