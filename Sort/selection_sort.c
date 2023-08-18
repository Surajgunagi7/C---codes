#include <stdio.h>

void readArray(int *array, int size) {
    int i;
    printf("Enter the %d elements to sort\n",size);
    for (i = 0; i < size; i++) {
        scanf("%d",(array + i));
    }
}

void selectionSort(int *arr, int n)
{
	int i, j, min_idx,temp;
    for (i = 0; i < n-1; i++)      // One by one move boundary of unsorted subarray
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i+1; j < n; j++)
        {
		    if (*(arr + j) < *(arr + min_idx))
			    min_idx = j;
		}

		// Swap the found minimum element with the first element
		if(min_idx != i)
		{
			temp = *(arr + min_idx);
			*(arr + min_idx) = *(arr + i);
			*(arr + i) = temp;
		}
	}
}

void displayArray(int *array, int size) {
    int i;
    printf("Sroted Array:\n");
    for (i = 0; i < size; i++) {
        printf("%d\t",*(array+i));
    }
    printf("\n");
}

void main() 
{
    int size, numbers[50];
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    readArray(numbers, size);
    selectionSort(numbers, size);
    displayArray(numbers, size);
}
