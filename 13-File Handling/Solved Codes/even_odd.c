#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *f1,*f2,*f3;
    int number,i;

    printf("Contents of DATA file\n");
    f1 = fopen("DATA","w");
    for(i = 0;i < 30;i++)
    {
        scanf("%d",&number);
        if(number == -1)
            break;
        putw(number,f1);
    }
    fclose(f1);
    f1 = fopen("DATA","r");
    f2 = fopen("EVEN","w");
    f3 = fopen("ODD","w");

    while((number = getw(f1)) != EOF)
    {
        if(number % 2 == 0)
            putw(number,f2);
        else
            putw(number,f3);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    f2 = fopen("EVEN","r");
    f3 = fopen("ODD","r");

    printf("\n\nContents of even file\n");
    while((number = getw(f2)) != EOF)
        printf("%d\t",number);
    printf("\n\nContents of odd file\n");
    while((number = getw(f3)) != EOF)
        printf("%d\t",number);
    fclose(f2);
    fclose(f3);
}