/*Implement Queue using c */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100  

typedef struct {
    int items[MAX];
    int front, rear;
} Queue;


void initialize(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}


int isEmpty(Queue *queue) {
    return queue->front == -1;
}


int isFull(Queue *queue) {
    return queue->rear == MAX - 1;
}


void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d\n", value);
    } else {
        if (queue->front == -1) {
            queue->front = 0;  
        }
        queue->items[++queue->rear] = value;
        printf("Enqueued %d\n", value);
    }
}


int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1;
    } else {
        int value = queue->items[queue->front];
        if (queue->front >= queue->rear) {  
            queue->front = queue->rear = -1;
        } else {
            queue->front++;
        }
        return value;
    }
}


int peek(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot peek\n");
        return -1;
    } else {
        return queue->items[queue->front];
    }
}


int main() {
    Queue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);

    printf("Front element is %d\n", peek(&queue));

    printf("Dequeued element is %d\n", dequeue(&queue));
    printf("Dequeued element is %d\n", dequeue(&queue));
    printf("Dequeued element is %d\n", dequeue(&queue));

    if (isEmpty(&queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }

    return 0;
}
