#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file1, *file2;
    char data;
    
    // Open the first file in write mode
    file1 = fopen("file1", "w");
    if (file1 == NULL) {
        printf("Error opening file1.");
        return 1;
    }

    // Read data from the user and write to the first file
    printf("Enter data for file1:\n");
    while ((data = getchar()) != EOF) {
        fputc(data, file1);
    }

    // Close the first file
    fclose(file1);

    // Open the second file in write mode
    file2 = fopen("file2", "w");
    if (file2 == NULL) {
        printf("Error opening file2.");
        return 1;
    }

    // Read data from the user and write to the second file
    printf("Enter data for file2:\n");
    while ((data = getchar()) != EOF) {
        fputc(data, file2);
    }

    // Close the second file
    fclose(file2);

    // Append the content of file2.txt to file1.txt
    file1 = fopen("file1", "a");
    file2 = fopen("file2","r");

    if (file1 == NULL || file2 == NULL) {
        perror("Error opening files.");
        return 1;
    }

    while ((data = fgetc(file2)) != EOF) {
        fputc(data, file1);
    }

    // Close both files
    fclose(file1);
    fclose(file2);

    printf("Data appended successfully.\n");

    return 0;
}
