#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *Source_file,*target_file;
    char s_fileName[10],t_fileName[10],c,del_char;

    void delete(FILE *,FILE *,char);

    printf("Enter the filename of the source file:");
    scanf("%s",s_fileName);
    printf("Enter the filename of the target file:");
    scanf("%s",t_fileName);

    Source_file = fopen(s_fileName,"w");
    printf("\nInput data in the %s file\n",s_fileName);
    while((c = getchar()) != EOF)
        fputc(c,Source_file);
    fclose(Source_file);

    Source_file = fopen(s_fileName,"r");
    target_file = fopen(t_fileName,"w");

    while((c = fgetc(Source_file)) != EOF)
        fputc(c,target_file);
    fclose(target_file);
    fclose(Source_file);

    printf("Enter the character to be deleted from the soucrce file:");
    scanf(" %c",&del_char);
    Source_file = fopen(s_fileName,"w");
    target_file = fopen(t_fileName,"r");
    delete(Source_file,target_file,del_char);
}
void delete(FILE *s,FILE *t, char del)     // Function to delete the specified character from the line of text
{
    char c;
    while((c = fgetc(t)) != EOF)  
    {   
        if(c == del)
            continue;
        else
            fputc(c,s);
    }
    printf("File modifiction successful\n");
}