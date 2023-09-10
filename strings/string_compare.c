#include<stdio.h>
void main()
{
    int i,flag = 0;
    char str1[30],str2[30];
    printf("Enter the frist string: \n");
    gets(str1);
    printf("Enter the second string: \n");
    gets(str2);
    for(i = 0; str1[i] != '\0' &&  str2[i] != '\0';i++)
    {
        if(str1[i] != str2[i])
        {
            flag = 1;
            break;
        }
    }
    if(flag)
        printf("The strings are not same/equal\n");
    else
        printf("The string are same / equal.\n");
}