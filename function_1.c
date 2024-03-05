// write a function that swaps two numbers
#include <stdio.h>

// call by value
void swapCallbyValue(int a, int b)
{
    int c;
    printf("before swap: a = %d b = %d \n", a, b);
    c = b;
    b = a;
    a = c;
    printf("after swap call by value: a = %d b = %d \n", a, b);
};

// call by reference
void swapCallbyReference(int *a, int *b)
{
    int c;
    c = *b;
    *b = *a;
    *a = c;
};

int main()
{
    int a, b;
    printf("enter the a and b: ");
    scanf("%d %d", &a, &b);
    swapCallbyValue(a, b);
    swapCallbyReference(&a, &b);
    printf("numbers swapped using call by reference: a = %d b = %d \n", a, b);
    return 0;
}