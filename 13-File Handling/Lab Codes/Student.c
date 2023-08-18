#include<stdio.h>
void main()
{
    struct Details
    {
        char st_name[20],USN[10];
        int marks[3],CTA,total;
    };
    struct Details student[3];
    int i,j;        FILE *fp;
        fp = fopen("Exam","w");
    printf("\t\tInput Details of the Student\n");
    for(i = 0;i < 3;i++)
    {
        printf("\tDetails of the %d Student\n",i+1);
        printf("Name :");
        scanf("%s",student[i].st_name);
        printf("USN :");
        scanf("%s",student[i].USN);
        printf("\tInternal Assesment Marks\n");
        for(j = 0;j < 3;j++)
        {
            printf("IA - %d:",j+1);
            scanf("%d",&student[i].marks[j]);
        }printf("\n");
        printf("CTA:");
        scanf("%d",&student[i].CTA);
        fprintf(fp,"%s %s ",student[i].st_name,student[i].USN);
        for(j = 0;j<3;j++)
              fprintf(fp,"%d ",student[i].marks[j]);
        fprintf(fp,"%d\n",student[i].CTA);
    }
    fclose(fp);
    fp = fopen("Exam","r");
    printf("\t\tDetails of Student with Total marks\n");
    printf("| Student Name |    USN     | IA - 1 | IA - 2 | IA - 3 | CTA | Total-Marks |\n");
    printf("|--------------------------------------------------------------------------|\n");
    for(i = 0;i < 3;i++)
    {
      fscanf(fp,"%s %s",student[i].st_name,student[i].USN);
            student[i].total = 0;
        for(j = 0;j<3;j++){
            fscanf(fp,"%d ",&student[i].marks[j]);
            student[i].total += student[i].marks[j];
        }
        fscanf(fp,"%d\n",&student[i].CTA);
        printf("|  %-12s| %-11s|  %-6d|  %-6d|  %-6d| %-4d|     %-8d|\n",
                                student[i].st_name,
                                student[i].USN,
                                student[i].marks[0],
                                student[i].marks[1],
                                student[i].marks[2],
                                student[i].CTA,
                                student[i].total);
    }
    fclose(fp);
}