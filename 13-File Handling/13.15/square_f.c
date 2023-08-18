#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *main_file,*result_file;
    int number,n;

    main_file = fopen("MAIN", "w");
    if (main_file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    printf("Enter the list of integer values(Enter -1 to terminate).\n\n");
    while(1)
    {
        fscanf(stdin,"%d",&number);
        if(number == -1)
            break;
        fprintf(main_file,"%d\n",number);
    }
    fclose(main_file);

    main_file = fopen("MAIN","r");
    result_file = fopen("RESULT","w");

    while(fscanf(main_file,"%d",&n) == 1)
    {
        number = n*n;
        fprintf(result_file, "Original: %d, Square: %d\n", n,number);

    }
    printf("File operation successful.\n");

    fclose(main_file);
    fclose(result_file);
}