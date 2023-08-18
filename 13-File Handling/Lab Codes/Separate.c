#include<stdio.h>
void main()
{
    FILE *fp;
    char c;     int upper_case = 0,lower_case = 0,others = 0;
    printf("Input Data\n\n");
    fp = fopen("INPUT","w");

    while((c = getchar()) != EOF)
    {   
        putc(c,fp);
    }
    fclose(fp);
    fp = fopen("INPUT","r");
     while((c = fgetc(fp)) != EOF)
     {
        if(c >= 'A' && c <= 'Z')
            upper_case++;
        else if(c >= 'a' && c <= 'z')
            lower_case++;
        else    
                others++;
     }
     printf("Number of upper case characters = %d\n",upper_case);
     printf("Number of lower case characters = %d\n",lower_case);
     printf("Number of other characters = %d\n",others);


}