#include <stdio.h>
#include <stdlib.h>

void mergeFiles(FILE *file1, FILE *file2, FILE *outputFile) {
    int num1, num2;

    // Read the first number from both files
    fscanf(file1, "%d", &num1);
    fscanf(file2, "%d", &num2);

    while (!feof(file1) && !feof(file2)) {
        if (num1 < num2) {
            fprintf(outputFile, "%d\n", num1);
            fscanf(file1, "%d", &num1);
        } else {
            fprintf(outputFile, "%d\n", num2);
            fscanf(file2, "%d", &num2);
        }
    }

    // Copy any remaining numbers from file1
    while (!feof(file1)) {
        printf("num1 = %d\n",num1);
        fprintf(outputFile, "%d\n", num1);
        fscanf(file1, "%d", &num1);
    }

    // Copy any remaining numbers from file2
    while (!feof(file2)) {
        printf("num2 = %d\n",num2);
        fprintf(outputFile, "%d\n", num2);
        fscanf(file2, "%d", &num2);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s file1 file2 outputfile\n", argv[0]);
        return 1;
    }

    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");
    FILE *outputFile = fopen(argv[3], "w");

    if (file1 == NULL || file2 == NULL || outputFile == NULL) {
        perror("Error opening files");
        return 1;
    }

    mergeFiles(file1, file2, outputFile);

    printf("Merged and sorted list written to %s\n", argv[3]);

    fclose(file1);
    fclose(file2);
    fclose(outputFile);

    return 0;
}
