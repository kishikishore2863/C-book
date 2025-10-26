#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of stack

int stack[MAX];
int top = -1;

// Function to push an element to stack
void push(int value) {
    if (top == MAX - 1) {
        printf("\nStack Overflow! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("\n%d pushed to stack\n", value);
    }
}

// Function to pop an element from stack
void pop() {
    if (top == -1) {
        printf("\nStack Underflow! Nothing to pop\n");
    } else {
        printf("\n%d popped from stack\n", stack[top--]);
    }
}

// Function to view the top element
void peek() {
    if (top == -1) {
        printf("\nStack is Empty\n");
    } else {
        printf("\nTop element: %d\n", stack[top]);
    }
}

// Function to display the stack
void display() {
    if (top == -1) {
        printf("\nStack is Empty\n");
    } else {
        printf("\nStack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n\n--- Stack Operations Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid Choice! Try again.\n");
        }
    }
}