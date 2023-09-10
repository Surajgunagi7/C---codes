#include<stdio.h>
void main()
{
    char str[30];
    int len,i,flag = 1;
    printf("Enter the string value: \n");
    gets(str);
    for( len = 0; str[len] != '\0'; len++);

    for(i = 0; i < len; i++)
    {
        if(str[i] != str[len-i-1])
        {
            flag = 0;
            break;
        }
    }
    if(flag==0)
         printf("The %s - string is not palindrome\n",str);
    else
         printf("The %s - string is palindrome\n",str);

}