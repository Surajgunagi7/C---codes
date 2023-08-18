#include <stdio.h>

void inputArray(int *array, int size) 
{
    printf("Enter %d elements of the array:\n", size);
    int i;
    for (i = 0; i < size; i++)
        scanf("%d", (array + i));
}

int linearSearch(int *array, int size, int target) 
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (*(array + i) == target) {
            return i;  // Calculate the index using pointer arithmetic
        }
    }
    return -1;
}

void main()
{
    int numbers[20], searchValue, arraySize, result;

    printf("Enter the size of the array: ");
    scanf("%d", &arraySize);

    inputArray(numbers, arraySize);

    printf("Enter the value to be searched: ");
    scanf("%d", &searchValue);

    result = linearSearch(numbers, arraySize, searchValue);

    if (result == -1)
        printf("The search was unsuccessful. The value was not found.\n");
    else
        printf("The search was successful. The value was found at position %d.\n", result + 1);
    
}
