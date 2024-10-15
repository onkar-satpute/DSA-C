#include <stdio.h>
#define max 5

struct queue
{
    int arr[max];
    int front;
    int rear;
};

void init(struct queue *s)
{
    s->front = -1;
    s->rear = -1;
    printf("Queue is initialized..");
}

void display(struct queue *s)
{
    int i;
    for (i = s->rear; i > s->front; i--)
    {
        printf("%d\t", s->arr[i]);
    }
}

int isFull(struct queue *s)
{
    if (s->rear == max - 1)
        return 1;
    return 0;
}

int isEmpty(struct queue *s)
{
    if (s->rear == -1 && s->front == -1)
        return 1;
    return 0;
}
void push(struct queue *s)
{
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);
    if (isFull(s))
        printf("The queue is full");
    else
    {
        s->rear++;
        s->arr[s->rear] = data;
    }
}

int pop(struct queue *s)
{
    if (isEmpty(s))
        return -1;
    
    return s->arr[s->front++];
    
}

void peek(struct queue *s)
{
    printf("front is on %d\n", s->arr[s->front]);
    printf("Rear is on %d\n", s->arr[s->rear]);
}
int main()
{
    struct queue s;
    int ch;
    init(&s);
    do
    {
        printf("Enter the choice\n1.isFull\n2.isEmpty\n3.Push\n4.Pop\n5.Peek\n6.Display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf(isFull(&s) ? "The queue is full.\n" : "The queue is not full.\n");
            break;

        case 2:
            printf(isEmpty(&s) ? "The queue is empty.\n" : "The queue is not empty.\n");
            break;

        case 3:
            push(&s);
            break;

        case 4:
            printf("Popped element: %d\n", pop(&s));
            s.arr[s.front++];
            break;

        case 5:
            peek(&s);
            break;

        case 6:
            display(&s);
            break;

        default:
            printf("Exiting...\n");
            break;
        }
    } while (ch < 7);
    return 0;
}
