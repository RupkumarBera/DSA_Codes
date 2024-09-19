/*Implement  the  stack  by c progtaming*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100  


typedef struct {
    int items[MAX];
    int top;
} Stack;


void initialize(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}


int isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push %d\n", value);
    } else {
        stack->items[++stack->top] = value;
        printf("Pushed %d onto the stack\n", value);
    }
}


int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop\n");
        return -1;
    } else {
        return stack->items[stack->top--];
    }
}


int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek\n");
        return -1;
    } else {
        return stack->items[stack->top];
    }
}


int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack,40);

    printf("Top element is %d\n", peek(&stack));

    printf("Popped element is %d\n", pop(&stack));
    printf("Popped element is %d\n", pop(&stack));
    printf("Popped element is %d\n", pop(&stack));

    if (isEmpty(&stack)) {
        printf("Stack is empty\n");
    }
    else {
        printf("The value  in the stack %d",stack);
    }

    return 0;
}
