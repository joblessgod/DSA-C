#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int arr[], int n)
{
    int temp, sorted;
    for (int i = 0; i < n - 1; i++)
    {
        sorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                sorted = 0;
            }
        }
        if (sorted)
            return;
    }
}

void getArrayData(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter the %d data: ", i + 1);
        scanf("%d", &array[i]);
    }
}

void display(int arr[], int n)
{
    printf(">> Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arraySize;
    printf("Enter size of array: ");
    scanf("%d", &arraySize);

    if (arraySize <= 0)
    {
        printf("Invalid array size!!!");
        return 0;
    }

    int array[arraySize];
    getArrayData(array, arraySize);
    bubbleSort(array, arraySize);
    display(array, arraySize);
    return 0;
}