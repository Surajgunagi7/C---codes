#include<stdio.h>
void main()
{
    char str[30],temp;
    int len,i,flag = 0;
    printf("Enter the string value: \n");
    gets(str);
    for(len = 0; str[len] != '\0'; len++);

    for(i = 0; i < len/2; i++)
    {
        temp = str[i];
        str[i] = str[len -i-1];
        str[len-i-1] = temp;
    }

    printf("reverse string :");
    puts(str);
}