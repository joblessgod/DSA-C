#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *prev;
    struct node *next;
};

void insert_at_begin(struct node **start, int data);
void insert_at_end(struct node **start, int data);
void insert_at_position(struct node **start, int data, int pos);
void delete_at_begin(struct node **start);
void delete_at_end(struct node **start);
void delete_at_position(struct node **start, int pos);
void display(struct node *start);
int count_nodes(struct node *start);

void insert_at_begin(struct node **start, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    temp->info = data;
    temp->prev = NULL;
    temp->next = *start;

    if (*start != NULL)
        (*start)->prev = temp;

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
    temp->next = NULL;

    if (*start == NULL)
    {
        temp->prev = NULL;
        *start = temp;
        return;
    }

    p = *start;
    while (p->next != NULL)
        p = p->next;

    p->next = temp;
    temp->prev = p;
}

int count_nodes(struct node *start)
{
    int count = 0;
    while (start != NULL)
    {
        count++;
        start = start->next;
    }
    return count;
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
    for (i = 1; i < pos - 1 && p != NULL; i++)
        p = p->next;

    if (p == NULL)
    {
        printf("Position out of range\n");
        free(temp);
        return;
    }

    temp->next = p->next;
    temp->prev = p;

    if (p->next != NULL)
        p->next->prev = temp;

    p->next = temp;
}

void delete_at_begin(struct node **start)
{
    struct node *temp;

    if (*start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = *start;
    *start = (*start)->next;

    if (*start != NULL)
        (*start)->prev = NULL;

    free(temp);
}

void delete_at_end(struct node **start)
{
    struct node *p;

    if (*start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if ((*start)->next == NULL)
    {
        free(*start);
        *start = NULL;
        return;
    }

    p = *start;
    while (p->next != NULL)
        p = p->next;

    p->prev->next = NULL;
    free(p);
}

void delete_at_position(struct node **start, int pos)
{
    int i;
    int n = count_nodes(*start);
    struct node *p;

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
    for (i = 1; i < pos && p != NULL; i++)
        p = p->next;

    if (p == NULL)
    {
        printf("Position out of range\n");
        return;
    }

    if (p->next != NULL)
        p->next->prev = p->prev;

    if (p->prev != NULL)
        p->prev->next = p->next;

    free(p);
}

void display(struct node *start)
{
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("List elements (forward): ");
    while (start != NULL)
    {
        printf("%d ", start->info);
        start = start->next;
    }
    printf("\n");
}

int main(void)
{
    struct node *start = NULL;
    int choice, data, pos;

    while (1)
    {
        printf("\n--- Doubly Linked List ---\n");
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
