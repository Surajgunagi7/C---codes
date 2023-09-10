#include<stdio.h>
void main()
{
    struct point{
        int x,y;
    }P,Q;
    printf("Enter the Coordinates of the Pint P: ");
        scanf("%d%d",&P.x,&P.y);
            printf("Enter the Coordinates of the Pint Q: ");
                scanf("%d%d",&Q.x,&Q.y);
            if(P.y == Q.y)
                printf("Horizontal\n");
            else if(Q.x == P.x)
                printf("Vertical\n");
            else
                printf("Oblique\n");
}