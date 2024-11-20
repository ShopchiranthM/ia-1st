#include<stdio.h>
#include<stdlib.h>
#define size 20

void push(int ele, int *top, int stack[]);
void pop(int *top, int stack[]);
void display(int top, int stack[]);

void main()
{
    int choice, top = -1, ele;
    int stack[size];
    
    for (;;) {
        printf("Enter \n 1. Push \n 2. Pop \n 3. Display \n 4. Exit \n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (top == (size - 1))
                    printf("Stack Overflow!!!\n");
                else {
                    printf("Enter element to be pushed:\n");
                    scanf("%d", &ele);
                    push(ele, &top, stack);
                }
                break;
            case 2:
                if (top == -1)
                    printf("Stack Underflow!!!\n");
                else
                    pop(&top, stack);
                break;
            case 3:
                if (top == -1)
                    printf("Stack Underflow!!!\n");
                else
                    display(top, stack);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
}

void push(int ele, int *top, int stack[]) {
    (*top)++;  // increment top before using it
    stack[*top] = ele;
    printf("Element %d pushed onto stack.\n", ele);
}

void pop(int *top, int stack[]) {
    printf("Element to be deleted: %d\n", stack[*top]);
    (*top)--;  // decrement top after using it
}

void display(int top, int stack[]) {
    int i;
    printf("Elements in stack are:\n");
    for (i = top; i >= 0; i--)
        printf("%d\t", stack[i]);
    printf("\n");
}

