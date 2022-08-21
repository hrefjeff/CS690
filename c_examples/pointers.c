// Pointer refresher
// compilation instruction: gcc pointers.c -o pointers

#include <stdio.h>

int main()
{
    int* p1;
    int *p2;
    int * p3;
    int* p4, p5; // p4 is a pointer, and p5 is simply an int


    // 1. basics
    int var = 5;

    printf("var: %d\n", var);
    printf("address of var: %d\n", &var);


    // 2. Assigning addresses to pointers
    int *pc, c;
    c = 5;
    pc = &c;
    // 5 is assigned the value of 5
    // The address of c is assigned to the pc pointer

    // 3. Getting the value of the thing pointed to
    //    by the pointer
    int *pointer1, x;
    x = 10;
    pointer1 = &x;
    printf("Value of pointer is %d\n", *pointer1);

    // 4. Changing the value pointed by pointers
    int* pointer2, y;
    y = 15;
    pointer2 = &y;
    y = 1;
    printf("y has value of %d\n", y);
    printf("pointer2 has value of %d\n", *pointer2);
    // I assigned the address of y to pointer2
    // Then I changed the value of y to 1
    // Since pointer2 and the address of y is the same, *pointer2 gives me 1

    int* pointer3, z;
    z = 20;
    pointer3 = &z;
    *pointer3 = 2;
    printf("z has value of %d\n", z);
    printf("pointer3 points to the value of %d\n", *pointer3);
    // I assigned the address of z to pointer3
    // Then I assigned the value 3 of where pointer3 is pointing to
    // Since pointer 3 is pointing to z's address
    // They both are assigned the value of 2

    /*
    *
    *        pc        c
    *    _________   ______
    *    |        | |      |
    *    |        | |      |
    *    |        | |  5   |
    *    |        | |      |
    *    |________| |______|
    *        |
    *        |
    *        V
    */


    return 0;
}