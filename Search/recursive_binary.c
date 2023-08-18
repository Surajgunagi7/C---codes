#include <stdio.h>

int binarySearch(int *arr, int low, int high, int target) {
    static int count;
    ++count;
    if (low <= high) {
        int mid = (high + low) / 2;

        if (*(arr+mid) == target) {
            printf("Count = %d\n", count);
            return mid;
        }

        if (*(arr+mid) < target) {
            return binarySearch(arr, mid + 1, high, target);
        }

        return binarySearch(arr, low, mid - 1, target);
    }

    return -1; // Target element not found
}

int main() {
    int size,arr[20],i,target;
    printf("Enter number no elements to store : ");
    scanf("%d", &size);
    printf("Enter the elements in sorted order :\n");
    for ( i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter key element to search : ");
    scanf("%d", &target);
    int result = binarySearch(arr, 0, size-1, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result+1);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}