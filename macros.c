#include <stdio.h>
#include <stdbool.h>


#define SWAP(T,X,Y) { \
    T temp = (X); (X) = (Y); (Y) = temp; \
}

#define SWAP_INTS(X,Y) { \
    (X) = (X) - (Y); \
    (Y) = (Y) + (X); \
    (X) = (Y) - (X); \
}


int f(int x) {
    return x*2;
}

int main(void) {
    // Simple case with no side effects - works as intended

    // bool x = false;
    // bool y = true;
    // SWAP(bool, x, y);
    // printf("After swapping; x is %d, y is %d\n", x, y);


    // Case with side effects

    int i = 1;
    int x = 2;
    int v[] = {1,2,3,4,5};
    int w[] = {6,7,8,9,10};

    // we expect swap v[i++], w[f(x)] to swap the values in v[1] and w[4]
    // BUT the increment of i will happen multiple times, so other indices will be affected!

    SWAP(int, v[i++], w[f(x)]);

    printf("v: [%d,%d,%d,%d,%d]\n", v[0], v[1], v[2], v[3], v[4]);
    printf("w: [%d,%d,%d,%d,%d]\n", w[0], w[1], w[2], w[3], w[4]);



    // Using the version for integers, without a temporary value
    char a = 'a';
    char b = 'b';
    SWAP_INTS(a,b);
    printf("a is %c, b is %c\n", a, b);


    // Test with pointers
    int test = 2;
    int *p = &test;
    int *q = p;
    printf("Value pointed to by p is %d, by q is %d\n", *p, *q);
    SWAP_INTS(*p,*q);
    printf("After swap: Value pointed to by p is %d, by q is %d, test is %d\n", *p, *q, test);
}