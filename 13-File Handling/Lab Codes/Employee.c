#include<stdio.h>
void main()
{
    FILE *fp;
    int age,i; float salary,tax; char emp_name[20];
    printf("\t\tINPUT DETAILS OF THE EMPLOYEES\n");
        fp = fopen("emp","w");
    fprintf(stdout,"Employe Name\tAge\tBasic-Salary\n");
    for(i = 0;i < 3;i++)
    {
        fscanf(stdin,"%s %d %f",emp_name,&age,&salary);
        fprintf(fp,"%s %d %.2f\n",emp_name,age,salary);
    }
    fclose(fp);
    fp = fopen("emp","r");
    printf("\t\tTax Deduction\n");
    printf("-----------------------------------------------------\n");
    printf("| Employee name | Age | Bais-salary | Tax-Deduction |\n");
    printf("|---------------------------------------------------|\n");
    for(i = 0;i < 3;i++)
    {
        fscanf(fp,"%s %d %f",emp_name,&age,&salary);
        if(salary >= 10000 && salary <= 15000)
            tax = salary*0.1;
        else if(salary >= 15000 && salary <= 25000)
            tax = salary*0.2;
        fprintf(stdout,"|     %-10s| %-3d | %-12.2f| %-14.2f|\n",emp_name,age,salary,tax);

    }
    fclose(fp);
    
    
}