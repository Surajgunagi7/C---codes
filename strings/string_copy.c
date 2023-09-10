#include<stdio.h>
void main()
{
    char str[30],str_cpy[30];
    int i,count = 0;
    printf("Enter the line of text or string value: \n");
    gets(str);
    for(i = 0; str[i] != '\0'; i++)
    {
        str_cpy[i] = str[i];
        count++;
    }
    printf("The copies string is : \n");
    puts(str_cpy);
    printf("The length of the copied strings is %d\n",count);
}