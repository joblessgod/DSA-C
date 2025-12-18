#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    struct node *front;
    int info;
    struct node *rear;
};

// defining function
struct node *enque(struct node *start, int data);
int deque(struct node *start);
int peek(struct node *start);
void display(struct node *start);

int main()
{
    struct node *start = NULL;
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

            start = enque(start, data);
            display(start);
            break;
        case 2:
            system("cls");
            start = deque(start);
            // printf("your deleted item %d", deque());
            display(start);
            break;
        case 3:
            system("cls");
            int result = peek(start);
            if (result == -1)
                break;
            printf("your peek item %d", result);
            break;
        case 4:
            system("cls");
            display(start);
            break;
        case 5:
            printf("Program Exit");
            exit(0);
        case 6:
            // for (int i = 0; i < MAX; i++)
            // {
            //     int random_num = (rand() % (50)) + 10;
            //     enque(random_num);
            // }
        }
    }

    return 0;
}

struct node *enque(struct node *front, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode || newNode == NULL) {
        printf("memory allocation failed");
        exit(1);
    }
    newNode->info = data;
    
}