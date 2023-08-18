#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char fileName[100];
    char character;

    // Prompt user for file name
    printf("Enter the filename: ");
    scanf("%s", fileName);

    // Open the file in write mode
    file = fopen(fileName, "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read characters from user and write them into the file
    printf("Enter characters (press Ctrl+Z to stop):\n");
    while ((character = getchar()) != EOF) {
        if(character == '\n')
            continue;
        fputc(character, file);
    }

    // Close the file
    fclose(file);

    // Open the file in read mode
    file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read characters from the file and print their ASCII codes
    printf("ASCII codes of characters in the file:\n");
    while ((character = fgetc(file)) != EOF) {
        printf("Character: %c, ASCII Code: %d\n", character, character);
    }

    // Close the file
    fclose(file);

    return 0;
}
