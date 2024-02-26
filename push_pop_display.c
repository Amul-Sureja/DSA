#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = item;
        printf("%d pushed to stack\n", item);
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1; 
    } else {
        int item = stack[top];
        top--;
        printf("%d popped from stack\n", item);
        return item;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);

    printf("\nAfter pushing elements:\n");
    display();

    printf("\nPopped item: %d\n", pop());
    printf("Popped item: %d\n", pop());

    printf("\nAfter popping elements:\n");
    display();

    return 0;
}
