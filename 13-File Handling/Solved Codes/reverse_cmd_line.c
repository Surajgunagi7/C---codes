#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fs;
    char str[100];  // Increased buffer size to handle larger strings
    int i, n;

    if (argc != 3) {
        printf("Improper number of arguments.\n");
        return 1;
    }

    fs = fopen(argv[1], "at+");
    if (fs == NULL) {
        printf("Source file cannot be opened.\n");
        return 1;
    }

    printf("Enter some characters: ");
    fgets(str, sizeof(str), stdin);
    fprintf(fs, "%s", str);
    fclose(fs);

    n = atoi(argv[2]);
    fs = fopen(argv[1], "r");

    if (fs == NULL) {
        printf("Source file cannot be opened.\n");
        return 1;
    }

    i = 0;
    while (1) {
        int c = fgetc(fs);
        if (c != EOF) {
            str[i] = c;
            i++;
        } else {
            break;
        }
    }
    fclose(fs);

    fs = fopen(argv[1], "r+");
    if (n < 0 || n > i) {
        printf("Incorrect value of n. Program will terminate...\n");
        return 1;
    }
    for (i = n - 1; i >= 0; i--) {
        fputc(str[i], fs);
    }
    fclose(fs);

    fs = fopen(argv[1], "r");
    if (fs == NULL) {
        printf("Source file cannot be opened.\n");
        return 1;
    }
    int c;
    while ((c = fgetc(fs)) != EOF) {
        putchar(c);
    }
    fclose(fs);
    printf("\n%d characters of the file successfully printed in reverse order\n", n);

    return 0;
}