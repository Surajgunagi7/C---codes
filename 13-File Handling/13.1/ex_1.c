#include <stdio.h>
#include <stdlib.h>
void main() {
    FILE *sourceFile, *destFile;
    char ch;

    sourceFile = fopen("source", "w");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        exit(1);
    }
    printf("Enter the input data :");
    while((ch = getchar()) != EOF)
        fputc(ch,sourceFile);
    fclose(sourceFile);

    sourceFile = fopen("source","r");
    destFile = fopen("destination", "w");
    if (destFile == NULL) {
        perror("Error opening destination file");
        fclose(sourceFile);
        exit(1);
    }

    // Copy the contents character by character
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    // Close both files
    fclose(sourceFile);
    fclose(destFile);

    printf("File copied successfully.\n");
}
