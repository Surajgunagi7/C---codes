#include<stdio.h>
#include<string.h>
void main()
{
    char str[20];
    int i;
    printf("Enter the any text:\n");
    gets(str);
    size_t len = strlen(str);
    printf("%d\n",len);

}