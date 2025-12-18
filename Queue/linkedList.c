#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int info;
    struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

// defining function
void enque(int data);
int deque();
int peek();
void display();

int main()
{
    int choice, data, n;
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
            break;
        case 2:
            system("cls");
            int dequelResult = deque();
            if (dequelResult == -1)
                break;
            printf("your deleted item %d", dequelResult);
            break;
        case 3:
            system("cls");
            int peekResult = peek();
            if (peekResult == -1)
                break;
            printf("your peek item %d", peekResult);
            break;
        case 4:
            system("cls");
            display();
            break;
        case 5:
            printf("Program Exit");
            exit(0);
        case 6:
            printf("Enter how long fake data you want to enter: ");
            scanf("%d", &n);

            for (int i = 0; i < n; i++)
            {
                int random_num = (rand() % (50) + n * 10) + 10;
                enque(random_num);
            }
            printf("Fake data inserted in queue successfully.");
            break;
        }
    }

    return 0;
}

void enque(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    // while creating a node, memory can be full thats why we checked, 
    if (!temp || temp == NULL)
    {
        printf("memory allocation failed, stack overflowed");
        exit(1);
    }

    // making a node with default data
    temp->info = data;
    temp->link = NULL;

    if (front == NULL) // before adding aany new node, we first need to check if there is already a node or not
    {
        front = temp;
    }
    else // if we have already an node, we just adding them as tail
    {
        rear->link = temp;
    }
    rear = temp;
}

int deque()
{
    if (front == NULL)
    {
        printf("the queue isn't initialized yet. please add data first.");
        return -1;
    }

    int item = front->info;
    struct node *temp;
    temp = front;
    front = front->link;
    free(temp);
    return item;
}

int peek()
{
    if (front == NULL)
    {
        printf("the queue isn't initialized yet. please add data first.");
        return -1;
    }
    return front->info;
}

void display()
{
    if (front == NULL)
    {
        printf("the queue isn't initialized yet. please add data first.");
        return;
    }
    struct node *p = front;
    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->link;
    }
}