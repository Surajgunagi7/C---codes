#include<stdio.h>
void main()
{
    char str[30];
    int i;
    printf("Enter the value of the string:");
    gets(str);
    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] >= 97 && str[i] <= 122)
        {
            str[i] -=32;
        }
    }
    str[i] = '\0';
    printf("The entered string in upper case: ");
    puts(str);
    for(i = 0;str[i] != '\0'; i++)
    {
        if(str[i] >= 65 && str[i] <= 97)
        {
            str[i]+= 32;
        }
    }
    str[i] = '\0';
    printf("The entered string in lower case: ");
    puts(str);

}