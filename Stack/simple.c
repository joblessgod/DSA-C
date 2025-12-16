#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack_arr[MAX];
int top = -1;

void push(int data);
int pop();
int peek();
void display();
void checkStackValidation()
{
    if (top == -1)
    {
        printf("This is 'underflow' condition. Please try again later!");
        return;
    }
    else if (top == MAX - 1)
    {
        printf("This is 'overflow' condition. Please try again later!");
        return;
    }
}

int main()
{
    while (1)
    {
        int choice, data;
        printf("== Stack Menu ==");
        printf("1. push the data into stack");
        printf("2. pop the data from stack");
        printf("3. peek the data from stack");
        printf("4. display the stack");
        printf("5. Exit");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data you want to add in stack:\n>> ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            printf("Removed value from stack is %d", pop());
            break;
        case 3:
            printf("Top value of stack is %d", peek());
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("\nPlease make a valid choice.\n");
            break;
        }
    }

    return 0;
}

void push(int data)
{
    checkStackValidation();
    top++;
    stack_arr[top] = data;
}

int pop()
{
    checkStackValidation();
    int data = stack_arr[MAX - 1];
    top--;
    return data;
}