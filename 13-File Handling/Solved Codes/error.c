#include<stdio.h>
#include<stdlib.h>
void main()
{
    char filename[10];
    FILE *fp;
    int i,number;

    fp = fopen("TEST","w");
    for( i = 10;i <= 100; i += 10)
         putw(i,fp);
    fclose(fp);

    printf("\nInput Filename\n");
    scanf("%s",filename);

    if((fp = fopen(filename,"r")) == NULL)
    {
            printf("Cannot open this file.\n");
            exit(1);
    }
    else
    {
        for(i = 1; i <= 20;i++)
        {
            number = getw(fp);
            if(feof(fp))
            {
                printf("Ran out of data.\n");
                exit(1);
            }
            else
                printf("%d\n",number);
        }
    }
    fclose(fp);
}