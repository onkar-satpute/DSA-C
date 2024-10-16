#include <stdio.h>
#define SIZE 5

struct cqueue {
    int arr[SIZE];
    int front;
    int rear;
};

void init(struct cqueue *q) {
    q->front = q->rear = -1;
}

int isFull(struct cqueue *q) {
    return (q->rear + 1) % SIZE == q->front;
}

int isEmpty(struct cqueue *q) {
    return q->front == -1;
}

void enqueue(struct cqueue *q, int data) {
    if (isFull(q)) {
        printf("Your queue is Full\n");
    } else {
        if (q->front == -1) {
            q->front = 0; 
        }
        q->rear = (q->rear + 1) % SIZE;
        q->arr[q->rear] = data;
        printf("%d inserted in queue\n", data);
    }
}

int dequeue(struct cqueue *q) {
    if (isEmpty(q)) {
        printf("The queue is Empty..\n");
        return -1; 
    } else {
        int data = q->arr[q->front];
        if (q->rear == q->front) {
          
            q->front = q->rear = -1; 
        } else {
            q->front = (q->front + 1) % SIZE;
        }
        printf("%d is deleted from queue\n", data);
        return data; 
    }
}

void display(struct cqueue *q) {
    if (isEmpty(q)) {
        printf("The queue is empty..\n");
    } else {
        printf("Queue elements: ");
        int i = q->front;
        while (1) {
            printf("%d ", q->arr[i]);
            if (i == q->rear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    struct cqueue q;
    init(&q); 
    int ch, data;

    do {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting..\n");
                break; 
            default:
                printf("Enter a valid choice\n");
        }
    } while (ch != 4);

    return 0;
}
