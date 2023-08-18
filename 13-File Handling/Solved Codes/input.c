#include<stdio.h>
void main()
{
    FILE *fp;
    char c;
    printf("Input Data\n\n");
    fp = fopen("INPUT","w");

    while((c = getchar()) != EOF)
    {   
        putc(c,fp);
    }
    fclose(fp);
    printf("Output Data\n\n");
    fp = fopen("INPUT","r");
    
    while((c = getc(fp)) != EOF)
    {
        putchar(c);  /* Display output*/
    }
    fclose(fp);
}