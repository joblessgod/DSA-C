#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// defining global variable to allow multiple functions to access and modify the same data structure easily without using points and passing address using arguments
#define MAX 5
int queue_arr[MAX];
int front = -1, rear = -1;

// defining function
void enque(int data);
int deque();
int peek();
void display();

int main()
{
    int choice, data;
    while (1)
    {
        printf("\n1. Enque data");
        printf("\n2. Deque data");
        printf("\n3. peek data");
        printf("\n4. display data");
        printf("\n5. exit");
        printf("\n6. add fake data in queue");

        printf("\nenter your choice\n>> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            printf("Enter data: ");
            scanf("%d", &data);

            enque(data);
            display();
            break;
        case 2:
            system("cls");
            printf("your deleted item %d", deque());
            display();
            break;
        case 3:
            system("cls");
            if (peek() == -1)
                break;
            printf("your peek item %d", peek());
            break;
        case 4:
            system("cls");
            display();
            break;
        case 5:
            printf("Program Exit");
            exit(0);
        case 6:
            for (int i = 0; i < MAX; i++)
            {
                int random_num = (rand() % (50)) + 10;
                enque(random_num);
            }
        }
    }

    return 0;
}

void enque(int data)
{
    // checking if the array is already full or not before adding any new item
    if (rear == MAX - 1)
    {
        printf("Array is fulled with overflowed condition.");
        return;
    }
    if (front == -1)
        front += 1;         // moving "front" to use deletion data from queue
    rear += 1;              // moving the "rear" to one step ahead
    queue_arr[rear] = data; // assigning the given value in queue
}

int deque()
{
    // checking if the array of queue is empty or already initialized or not before deleting item
    if (front == -1 || front == rear + 1)
    {
        printf("Array of queue is empty, please add data before deletion. System underflow condition");
        return -1;
    }
    int item = queue_arr[front];
    front += 1;
    return item;
}

int peek()
{
    // checking if the array of queue is empty or not before peeking it
    if (front == -1 || front == rear + 1)
    {
        printf("The queue is epmty. please provide information first before peeking");
        return -1;
    }
    return queue_arr[front]; // we choose "front" because we count peek where deletio is performing. In this case front side is our deletion.
}

void display()
{
    //  reason of checking: if data is not available we won't be able to display it.
    if (front == -1 || front == rear + 1)
    {
        printf("The queue is epmty. please provide information first.");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d, ", queue_arr[i]);
    }
}