
#include <stdio.h>
#include <stdbool.h>

int is_prime(int num) {
    if (num <= 1)
        return 0;
    
    for (int i = 2; i <= num/2; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    FILE *inputFile, *primeFile, *nonPrimeFile;
    int num;
    
    inputFile = fopen("input.txt", "w");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    
    // Read integer values from the user and store in input.txt
    printf("Enter integer values (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &num);
        if (num == -1)
            break;
        fprintf(inputFile, "%d\n", num);
    }
    fclose(inputFile);
    
    primeFile = fopen("prime.txt", "w");
    nonPrimeFile = fopen("nonprime.txt", "w");
    
    if (primeFile == NULL || nonPrimeFile == NULL) {
        printf("Error opening output files.\n");
        return 1;
    }
    
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    
    // Read numbers from input file, classify them, and write to appropriate output file
    while (fscanf(inputFile, "%d", &num) != EOF) {
        if (is_prime(num)) {
            fprintf(primeFile, "%d\n", num);
        } else {
            fprintf(nonPrimeFile, "%d\n", num);
        }
    }
    
    fclose(inputFile);
    fclose(primeFile);
    fclose(nonPrimeFile);
    
    // Print the contents of prime.txt
    printf("Prime numbers:\n");
    primeFile = fopen("prime.txt", "r");
    while (fscanf(primeFile, "%d", &num) != EOF) {
        printf("%d\n", num);
    }
    fclose(primeFile);
    
    // Print the contents of nonprime.txt
    printf("Non-prime numbers:\n");
    nonPrimeFile = fopen("nonprime.txt", "r");
    while (fscanf(nonPrimeFile, "%d", &num) != EOF) {
        printf("%d\n", num);
    }
    fclose(nonPrimeFile);
    
    return 0;
}
