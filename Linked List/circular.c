#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

void insert_at_begin(struct node **start, int data);
void insert_at_end(struct node **start, int data);
void insert_at_position(struct node **start, int data, int pos);
void delete_at_begin(struct node **start);
void delete_at_end(struct node **start);
void delete_at_position(struct node **start, int pos);
void display(struct node *start);
int count_nodes(struct node *start);

int count_nodes(struct node *start)
{
    int count = 0;
    struct node *p;

    if (start == NULL)
        return 0;

    p = start;
    do
    {
        count++;
        p = p->link;
    } while (p != start);

    return count;
}

void insert_at_begin(struct node **start, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *p;

    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    temp->info = data;

    if (*start == NULL)
    {
        temp->link = temp;
        *start = temp;
        return;
    }

    p = *start;
    while (p->link != *start)
        p = p->link;

    temp->link = *start;
    p->link = temp;
    *start = temp;
}

void insert_at_end(struct node **start, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *p;

    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    temp->info = data;

    if (*start == NULL)
    {
        temp->link = temp;
        *start = temp;
        return;
    }

    p = *start;
    while (p->link != *start)
        p = p->link;

    temp->link = *start;
    p->link = temp;
}

void insert_at_position(struct node **start, int data, int pos)
{
    int i;
    int n = count_nodes(*start);
    struct node *temp, *p;

    if (pos < 1 || pos > n + 1)
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        insert_at_begin(start, data);
        return;
    }

    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    temp->info = data;

    p = *start;
    for (i = 1; i < pos - 1; i++)
        p = p->link;

    temp->link = p->link;
    p->link = temp;
}

void delete_at_begin(struct node **start)
{
    struct node *p, *temp;

    if (*start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if ((*start)->link == *start)
    {
        free(*start);
        *start = NULL;
        return;
    }

    p = *start;
    while (p->link != *start)
        p = p->link;

    temp = *start;
    *start = (*start)->link;
    p->link = *start;
    free(temp);
}

void delete_at_end(struct node **start)
{
    struct node *p, *q;

    if (*start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if ((*start)->link == *start)
    {
        free(*start);
        *start = NULL;
        return;
    }

    p = *start;
    while (p->link != *start)
    {
        q = p;
        p = p->link;
    }

    q->link = *start;
    free(p);
}

void delete_at_position(struct node **start, int pos)
{
    int i;
    int n = count_nodes(*start);
    struct node *p, *q;

    if (pos < 1 || pos > n)
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        delete_at_begin(start);
        return;
    }

    p = *start;
    for (i = 1; i < pos; i++)
    {
        q = p;
        p = p->link;
    }

    q->link = p->link;
    free(p);
}

void display(struct node *start)
{
    struct node *p;

    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("List elements: ");
    p = start;
    do
    {
        printf("%d ", p->info);
        p = p->link;
    } while (p != start);
    printf("\n");
}

int main(void)
{
    struct node *start = NULL;
    int choice, data, pos;

    while (1)
    {
        printf("\n--- Circular Singly Linked List ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
            break;

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insert_at_begin(&start, data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insert_at_end(&start, data);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &pos);
            insert_at_position(&start, data, pos);
            break;
        case 4:
            delete_at_begin(&start);
            break;
        case 5:
            delete_at_end(&start);
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);
            delete_at_position(&start, pos);
            break;
        case 7:
            display(start);
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
