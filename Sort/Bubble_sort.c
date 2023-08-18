#include <stdio.h>

void readArray(int size, int *array) // Function to read integer elements into an array
{
    int i;
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", (array + i));
    }
}

void bubbleSort(int n, int *arr) // Function to sort an array using bubble sort
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if(*(arr + j) > *(arr + j + 1)) 
            {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

void displayArray(int size, int *array)// Function to display the sorted array
{
    int i;
    printf("Sorted array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", *(array + i));
    }
    printf("\n");
}

void main() 
{
    int size, i, numbers[50];
    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Read, sort, and display the array
    readArray(size, numbers);
    bubbleSort(size, numbers);
    displayArray(size, numbers);

}
