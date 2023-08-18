#include<stdio.h>
void main()
{
    FILE *fp;
    long n;
    char c;
    fp = fopen("RANDOM", "w");
    printf("Enter the data:\n");
    while((c = getchar()) != EOF)
        fputc(c,fp);

    printf("No of characters entered = %ld\n", ftell(fp));
    fclose(fp);

    fp = fopen("RANDOM","r");
    n = 0L;
    
    while(!feof(fp))
    {
        fseek(fp, n, 0); /* Position to (n+1)th character */ 
        printf("Position of %c is %ld\n", fgetc(fp), ftell(fp)); 
        n = n+5L;
    }
    
    printf("\n");

    fseek(fp,-1L,2);    /* Position to the last character */

    do 
    {
            putchar(getc(fp));
            
    }while(!fseek(fp,-2L,1));
    
    fclose(fp);
}