#include<stdio.h>

void Read_input(int *list,int size)     /* function read the elements of the array in a sorted order*/
{
        int i;
        printf("Enter the %d elements of the list of numbers in a sorted order:",size);
                for(i = 0;i< size;i++)
                        scanf("%d",(list+i));
}
int Binary_search(int *list,int size,int key)   /* function definition to implement binary search */
{
        int high,low,mid;
                low = 0; high = size - 1;
                        while(high >= low)  
                        {
                             mid = (low+high)/2;    /* Calculating the middle index value */

                                if(*(list+mid) == key)
                                    return mid+1;       /* returning the index of search element if found*/
                                else if(*(list + mid ) > key)
                                    high = mid - 1;    /* Initialising the mid index value as the last index */
                                else
                                    low = mid + 1;  /* Initialising the mid index value as the first index */
                        }
        return -1;
}
void main()
{
        /* function Declarations */
        void Read_input(int *,int);     
        int Binary_search(int *,int,int);     
                int B[50],i,n,search_element,result;
                        printf("Enter the number of elements in the list:");
                        scanf("%d",&n);

                Read_input(B,n);        /* funtion call to read the value to be searched */

                        printf("Enter the element to be searched :");
                        scanf("%d",&search_element);

                result = Binary_search(B,n,search_element); /* Function call of Binary search function */

        if(result != -1)
                printf("%d is Present at %d Position\n",search_element,result);
        else
                printf("Unsucessful Search element not Found\n");

}