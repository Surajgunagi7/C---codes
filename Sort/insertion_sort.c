#include<stdio.h>
main()
{
        /* Function Declarations*/
        void read(int *,int);
        void insertion(int *,int);
        void display(int *,int);

        int A[50],i,n;

        printf("Enter the number of elements to sort:");
        scanf("%d",&n);

                /* Function calls with array_name and size as acutual parameter*/
                read(A,n);
                insertion(A,n);
                display(A,n);
}
void read(int *str,int size)            /* function that reads the unsorted array from user */
{
        int i;
        printf("Enter the %d numbers to sort:",size);
        for(i=0;i<size;i++)
                scanf("%d",(str+i));
}
void insertion(int *srt,int size)       /* fucntion that implements that insertion sort process */
{
        int i,j,temp;
        for(i=0;i<size;i++)     /* To Access the array value through the index i and assigning to Temp variable */
        {
                temp = *(srt+i);   /* Temporarily store the value of current element used for insertion into the sorted part of the array.*/
                j = i-1;

                  while(j>=0 && *(srt+j)> temp)  // Moving the Array element that are greator than temp greater than temp,
                  {                              // to one position ahead of their current position.
                        *(srt+j+1) = *(srt+j);         
                          j--;
                  }

                *(srt+j+1) = temp;
        }
}
void display(int *str,int size)                /* function that Displays the sorted array */
{
        int i;
        printf("The sorted list of numbers are :\n");
        for(i=0;i<size;i++)
                printf("%d\t",*(str+i));
        printf("\n");
}