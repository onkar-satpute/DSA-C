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

void display(struct node * slist){
    struct node * temp;
    temp = slist;
    if (slist == NULL)
    {
        printf("The linked list is empty..\n\n");
    }
    else{
        printf("The linked list is: \n");
        while (temp!=NULL)
        {
            printf("%d \t", temp->data);
            temp=temp->next;

        }
        
    }
    
}

struct node * insertAtEnd(struct node * slist){
    struct node *temp, *newnode;
    int n;
    newnode = ((struct node *)malloc(sizeof(struct node)));
    printf("Add new value to insert: ");
    scanf("%d", &n);
    newnode->data = n;
    newnode->next = NULL;
    
    if (slist==NULL)
    {
        slist = newnode;
    }
    else{
        temp = slist;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
       temp->next = newnode;
        
    }
    return slist;
    
}
struct node * insertAtBeg(struct node * slist){
    struct node *newnode;
    int n;
    printf("Enter the data for insert: ");
    scanf("%d", &n);
    newnode = ((struct node *)malloc(sizeof(struct node)));
    newnode->data = n;
    if(slist==NULL)
    newnode->next = NULL;
    else
    newnode->next = slist;
    slist = newnode;
    return slist;
}

// struct node * insertAtInter(struct node * slist){
//     struct node * newnode, *temp, *temp1;
//     int i, n, pos;
//     newnode = ((struct node *)malloc(sizeof(struct node)));
//     printf("On which position you have to insert the value: ");
//     scanf("%d", &pos);
//      if(pos==1){
//     slist = insertAtBeg(slist);
//     return slist;
//     }
       
//     else{
//         printf("Enter the value to insert at position %d: ", pos);
//         scanf("%d", &n);
//         newnode->data = n;

//         temp = slist;
//         for(i=0; i<pos-1; i++){
//             temp = temp->next;
//         }
//         temp1 = temp->next->next;
//         temp->next = newnode;
//         newnode->next = temp1;
//     }
//     return slist;
// }
int main(){
    int ch, i, n;
    struct node * slist = NULL;
    do
    {
        printf("Enter your choice: \n1.create\n2.Display\n3.Exit\n4.Insert at End\n5.Insert at Begin\n6.Insert At Intermidiate");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number of nodes to be created: ");
            scanf("%d", &n);
            slist = create(slist,n);
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

        default:
            printf("Enter Valid choice");
            break;
        }
    } while (ch<6);
    return 0;
}


