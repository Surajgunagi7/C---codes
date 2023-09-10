#include<stdio.h>
#include<math.h>
struct rect
{
    int x,y;
    int c;
};
struct polar
{
    float r,theta;
};
void main()
{
    struct polar rect_to_polar(struct rect *);
    struct rect r1;        
    struct polar p1;
    printf("Enter the coordinates of the point in recatngular form :");
    scanf("%d%d",&r1.x,&r1.y);
    p1 = rect_to_polar(&r1);
    printf("The coordinats of the point in polar form :\n");
    printf("%f %f",p1.r,p1.theta);
}
struct polar rect_to_polar(struct rect *r1)
{
    struct polar temp;
    temp.r = sqrt(((r1->x)*(r1->x))+(r1->y)*(r1->y));
    temp.theta = (float)atan((r1->y/r1->x));
    return temp;
}