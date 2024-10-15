#include <stdio.h>
#define max 5

struct stack {
    int arr[max];
    int top;
};

void init(struct stack* s) {
    s->top = -1;
}

void display(struct stack* s) {
    int i;
    for (i = s->top; i > -1; i--) {
        printf("%d\n", s->arr[i]);
    }
}

int isEmpty(struct stack* s) {
    if(s->top==-1)
    return 1;
    return 0;
}

int isFull(struct stack* s) {
    if(s->top==max-1)
    return 1;
    return 0;
}

void push(struct stack* s) {
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);
    if (isFull(s)) {
        printf("The stack is overflow..\n");
    } else {
        s->top++;
        s->arr[s->top] = data;
    }
}

int pop(struct stack* s) {
    if (isEmpty(s)) {
        printf("The stack is empty..\n");
        return -1;
    }
    return s->arr[s->top--];
}

void peek(struct stack* s) {
    if (isEmpty(s)) {
        printf("The stack is empty..\n");
    } else {
        printf("Top element is: %d\n", s->arr[s->top]);
    }
}

int main() {
    struct stack s;
    int ch;
    init(&s);
    printf("Stack Initialized\n");
    do {
        printf("Enter the choice\n1.isFull\n2.isEmpty\n3.Push\n4.Pop\n5.Peek\n6.Display\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf(isFull(&s) ? "The stack is full.\n" : "The stack is not full.\n");
                break;

            case 2:
                printf(isEmpty(&s) ? "The stack is empty.\n" : "The stack is not empty.\n");
                break;

            case 3:
                push(&s);
                break;

            case 4:
                printf("Popped element: %d\n", pop(&s));
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
