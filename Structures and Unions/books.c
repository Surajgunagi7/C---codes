#include<stdio.h>
#include<string.h>
void line(void)         /*Function to print lines*/
{
        int i;
        for(i = 0;i < 75;i++)
                printf("_");
        printf("\n");
}
        struct time     {               /*Structure template that represents month and year of the book*/
                char month[10];
                int year;
        };
        struct records          /*Structure template to represent the details of the book*/
        {
                char title[30];
                char author[20];
                struct time date;
                char publication[20];
                int copies;
                float price;
        };
int look_up(struct records list[],char s1[],char s2[],int size); /*Fucntion prototype to search for a book*/
void main()
{
        char title[30],author[20],res,flag,flag_2;
        int quantity,i = 3,size = 0,index, s = 0;
         struct records books[20] = {{"ANSI C","Balaguruswamy","May",1977,"Macmillan",10,45.25,},
                                    {"C language","Ritche","January",1984,"TMH",25,35.00},
                                    {"Cobol","Balaguruswamy","December",1988,"PHI",5,50.15}};
                line();
        while(s != 1)
        {
                printf("Do yo wish to add books to the records (Y?N)? ");
                scanf(" %c",&flag);
           if(flag == 'Y' || flag == 'y')
           {
                printf("Enter the number of books to add to the list :");
                scanf("%d",&size);
        do  {                   /*Looping construct to read the inputs of book details*/
                getchar();
                        printf("\tEnter the details of the %d book\n",(i-3)+1);
                                printf("Book Title : ");
                                gets(books[i].title);
                                printf("Author : ");
                                gets(books[i].author);
                                printf("Month and Year of the book : ");
                                scanf("%s %d",books[i].date.month,&books[i].date.year);
                                printf("Publication : ");        getchar();
                                gets(books[i].publication);
                                printf("Number of the copies : ");
                                scanf("%d",&books[i].copies);
                                printf("Price : ");
                                scanf("%f",&books[i].price);
                        i++;    line();
        }while(i < size+3);
        }
        if(flag == 'N' || flag == 'n')
        {
         do{    /*Looping construct to read details from the user for the book to be searched */
                line();
                size += 3;
                printf("%d\n",size);
                printf("Enter the details of the book to be searched: \n");
                printf("Title : ");     getchar();
                gets(title);
                printf("Author : ");
                gets(author);

                index = look_up(books,title,author,size); /*funt call to comfirm the availability of book in records*/

        if(index != -1)
        {
                line(); /*Printing the details of the searched book*/
                printf("\t\tDetails of the Book\n");
                printf("Title : %s\nAuthor : %s\n%s  %d\nPublication : %s\nNo of copies : %d\nPrice : %f\n",
                                books[index].title,
                                books[index].author,
                                books[index].date.month,
                                books[index].date.year,
                                books[index].publication,
                                books[index].copies,
                                books[index].price );
                line();
                printf("Enter the number of copies required :");
                scanf("%d",&quantity);
                if( quantity <= books[index].copies)
                 {
                        printf("The total price of the %d copies is %f\n",quantity,books[index].price*quantity);
                        books[index].copies -= quantity;
                }
                else
                        printf("The copies are out of stock\n");
        }
        else
                printf("The book not found\n");

        printf("Do you want to search for another book(Y/N) ? \n");
        scanf(" %c", &res);
    }while(res == 'Y' || res == 'y');
        line();
        }
        printf("Do you want to continue (Y/N) ");
        scanf(" %c",&flag_2);
        if(flag_2 == 'n' || flag_2 == 'N')
                s = 1;
}
}
int look_up(struct records list[],char s1[],char s2[],int size)  /*Funct def of Lool_up */
{
        int i;
        for(i = 0;i < size; i++) /*Using string compare function to confirm the availability of the book*/
        {
                if((strcmp(s1,list[i].title)) == 0 && (strcmp(s2,list[i].author)) == 0)
                        return i; /* Returning the index of book found in records */
        }
        return -1; /*Returning -1 if book not found */
}
