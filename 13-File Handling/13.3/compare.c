#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writeToFile(FILE *file) {
    char buffer[100];
    printf("Enter data for the file (type 'end' to finish):\n");
    
    while (1) {
        scanf("%s", buffer);
        if (strcmp(buffer, "end") == 0) {
            break;
        }
        fprintf(file, "%s\n", buffer);
    }
}

int compareFiles(FILE *file1, FILE *file2) {
    char ch1, ch2;

    while ((ch1 = fgetc(file1)) != EOF && (ch2 = fgetc(file2)) != EOF) {
        if (ch1 != ch2) {
            return 1;  // Files are not equal
        }
    }
    return 0;  // Files are equal
}
int main() {
    FILE *file1, *file2;
    char fileName1[100], fileName2[100];

    printf("Enter the name of the first file: ");
    scanf("%s", fileName1);

    printf("Enter the name of the second file: ");
    scanf("%s", fileName2);

    file1 = fopen(fileName1, "w");
    file2 = fopen(fileName2, "w");

    if (file1 == NULL || file2 == NULL) {
        perror("Error opening files");
        return 1;
    }

    printf("Enter data for the first file:\n");
    writeToFile(file1);

    printf("Enter data for the second file:\n");
    writeToFile(file2);

    fclose(file1);
    fclose(file2);

    file1 = fopen(fileName1, "r");
    file2 = fopen(fileName2, "r");

    if (file1 == NULL || file2 == NULL) {
        perror("Error opening files");

    }

    int result = compareFiles(file1, file2);
    printf("res = %d\n",result);
    if (result == 0) {
        printf("The files are equal.\n");
    } else {
        printf("The files are not equal.\n");
    }

    fclose(file1);
    fclose(file2);

    return 0;
}
