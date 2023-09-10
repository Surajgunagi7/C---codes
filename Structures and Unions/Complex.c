#include <stdio.h>

struct complex      /* Structure to represent a complex number */
{
    int real;       // Real part of the complex number
    int img;        // Imaginary part of the complex number
};

struct complex read(struct complex n)
{
    printf("Enter the complex number as real part and imaginary part:\n");
    scanf("%d %d", &n.real, &n.img);
    return n;
}

struct complex sum(struct complex n1, struct complex n2)
{
    struct complex temp;
    temp.real = n1.real + n2.real;   // Calculate the sum of real parts
    temp.img = n1.img + n2.img;      // Calculate the sum of imaginary parts
    return temp;
}

struct complex multiply(struct complex n1, struct complex n2)
{
    struct complex temp;
    temp.real = n1.real * n2.real - n1.img*n2.img;   // Calculate the product of real parts
    temp.img = n1.real * n2.img + n2.real*n1.img;      // Calculate the product of imaginary parts
    return temp;
}

void display(struct complex n, struct complex m)
{
    printf("Sum = %d + i%d\n", n.real, n.img);
    printf("Product = %d + i%d\n", m.real, m.img);
}

void main()
{
    struct complex c1, c2, result;

    c1 = read(c1);    // Read the first complex number from the user
    c2 = read(c2);    // Read the second complex number from the user

    result = sum(c1, c2);    // Calculate the sum of the complex numbers

    // Display the sum and product of the complex numbers
    display(result, multiply(c1, c2));
}
