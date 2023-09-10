#include<stdio.h>
void line();
void main()
{
    struct Students {
        char Name[20];
        int Roll_no;
        char USN[10];
        int marks[4];
        int total_marks;
    };
        struct Students S[25];
        int n,i,j;
            printf("Enter the Number of students :");
            scanf("%d",&n);
           
        for(i = 0;i < n; i++)    {
            printf("\t\tDetails of %d Student\n",i+1);
                printf("Enter the Roll Number :");
                scanf("%d",&S[i].Roll_no);
                    printf("Enter the USN of the Student :");
                    scanf("%s",S[i].USN);
                        printf("Enter the Name of the Student :");
                        scanf("%s",S[i].Name);

                        S[i].total_marks = 0;
                        for(j = 0;j < 4; j++)   {
                            printf("Enter the marks Scored in S%d Subject of %d Student:",j+1,i+1);
                            scanf("%d",&S[i].marks[j]);
                                S[i].total_marks += S[i].marks[j];
                        }
        }
    

        printf("\n\t\tDetails of the Students as follows\n");
            line();
            printf("| Roll NO | USN        | Name       | S1 | S2 | S3 | S4 | Total Marks |\n");
            line();

        for(i = 0;i < n; i++)    
            printf("|  %4d   |%-12s|%-12s| %-3d| %-3d| %-3d| %-3d|     %-4d    |\n",
                                        S[i].Roll_no,
                                        S[i].USN,
                                        S[i].Name,
                                        S[i].marks[0],S[i].marks[1],S[i].marks[2],S[i].marks[3],
                                        S[i].total_marks);   
        line();
     
        int large,max_index;
        printf("\n\t\tHighest Marks in Individual Subject\n");
        line();
        printf("\n");
        for(i = 0;i < 4; i++)
        {
            large = S[0].marks[i]; max_index = 0;
                for(j = 1;j < n; j++)  {
                    if(large < S[j].marks[i])
                    {
                        large = S[j].marks[i];
                        max_index = j;
                    }
                }
              
            printf("\tHighest marks S%d Subject :\nStudent Details:\n",i+1);
                printf("Highest Marks = %d in S%d Subject.\n",large,i+1);
                    printf("Roll No : %d\nUSN : %s\nName : %s\n",S[max_index].Roll_no,S[max_index].USN,S[max_index].Name);
                line(); 
            printf("\n");   
        }
          
        struct Students temp;
        for(i = 0;i < n - 1; i++)     {

            for(j = 0;j < n - i - 1; j++)     {

                if(S[j].total_marks < S[j+1].total_marks)
                {
                    temp = S[j];
                    S[j] = S[j+1];
                    S[j+1] = temp;
                }
            }
        }
    
    printf("\tDetails of the Students according to Highest Marks Obtained\n");
        line();
        printf("| Roll NO | USN        | Name       | S1 | S2 | S3 | S4 | Total Marks |\n");
        line();
        for(i = 0;i < n; i++)    
            printf("|  %4d   |%-12s|%-12s| %-3d| %-3d| %-3d| %-3d|     %-4d    |\n",S[i].Roll_no,S[i].USN,S[i].Name,S[i].marks[0],S[i].marks[1],S[i].marks[2],S[i].marks[3],S[i].total_marks);   
        line();
}
void line(void)
{
    int i;
    for(i = 0;i < 71; i++)
        printf("_");
    printf("\n");
}
        
