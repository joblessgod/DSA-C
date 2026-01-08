#include <stdio.h>

void selectionSort(int *arr, int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        printf("\nPass - %d", i + 1);

        for (int j = i + 1; j < n; j++)
        {
            printf("\n\tCompared %d with %d. ", arr[i], arr[j]);
            if (arr[i] > arr[j])
            {
                min = j;
                printf("min changed to \"%d\".", min);
            }
            else
                printf("It is okay. SKIPPED");
        }
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            printf("\n\tFinally, Swapped %d and %d. few few", arr[min], arr[i]);
        }
    }

    // TODO: Learn Hashing
}

void display(int *arr, int n)
{
    printf("\n\n>> Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}
int main()
{
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    int array[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter %d element: ", i + 1);
        scanf("%d", &array[i]);
    }

    selectionSort(array, size);
    display(array, size);
}
