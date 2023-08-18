#include<stdio.h>
void main()
{
        FILE *fp;
        int number,quantity,i,n;
        float price,value;   char item[10],file_name[10];
        printf("Enter the input file : ");
        scanf("%s",file_name);
        fp = fopen(file_name,"w");
        printf("\tEnter the inventory details\n");
        printf("Item_name\tNumber\tPrice\tQuantity\n");
        for(i = 0;i < 3; i++)
        {
                fscanf(stdin,"%s %d %f %d",item,&number,&price,&quantity);
                fprintf(fp,"%s %d %.2f %d\n",item,number,price,quantity);
        }
        fclose(fp);
        fprintf(stdout,"\n\n");

        fp = fopen(file_name,"r");
        printf("item name   number   price   quantity   value\n");
        for(i = 0; i < 3;i++)
        {
                fscanf(fp,"%s%d%f%d",item,&number,&price,&quantity);
                value = price*quantity;
                fprintf(stdout,"%-*s %-*d %-*.2f %-*d %-*f\n",10,item,8,number,7,price,9,quantity,6,value);
        }
        fclose(fp);

        //SECOND PART OF THE PROBLEM STATEMENT
        
         fp = fopen(file_name,"a");
        printf("Enter the number of data to append into the file :");
        scanf("%d",&n);
        printf("Item_name\tNumber\tPrice\tQuantity\n");
        for( i = 0; i < n;i++)
        {
                fscanf(stdin,"%s %d %f %d",item,&number,&price,&quantity);
                fprintf(fp,"%s %d %.2f %d",item,number,price,quantity);
        }
        fclose(fp);
        fp = fopen(file_name,"r");
        printf("item name  number  price  quantiy  value\n");
        for(i = 0;i < n+3;i++)
        {
                fscanf(fp,"%s%d%f%d",item,&number,&price,&quantity);
                value = price*quantity;
                fprintf(stdout,"%-10s %3d %9.2f %5d %12.2f\n",item,number,price,quantity,value);
        }
        fclose(fp);
}
                         