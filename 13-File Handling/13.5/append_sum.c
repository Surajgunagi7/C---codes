#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *fp;
    int number, sum = 0;
    fp = fopen("LIST","w");

    printf("Input the data of integers\n\n");
    while(number != EOF)
    {
        scanf("%d",&number);
        if(number == -1)
            break;
        fprintf(fp,"%d\n",number);
        sum += number;
    }
        fprintf(fp,"%d\n",sum);
        printf("Appended successfully\n");
    fclose(fp);
}