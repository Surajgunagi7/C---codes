#include<stdio.h>
void main()
{
    FILE *fp;int count = 0;
    fp = fopen("INPUT","w");
    char c,str[30];
    printf("Input data\n\n");
    while((c = getchar()) != EOF)
    {
        fputc(c,fp);
    }
    fclose(fp);
    fp = fopen("INPUT","r");
    while((c = fgetc(fp)) != EOF)
    {   
        if(c == '\n')
            count++;
    }
    printf("No of line is %d\n",count);
    fclose(fp);
}
