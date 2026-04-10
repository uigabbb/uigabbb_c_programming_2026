#include <stdio.h>

void swap(int* x, int* y);

int main() {
    int a = 5;
    int b = 3;

    printf("a: %d // %p\n", a, &a);
    printf("b: %d // %p\n", b, &b);
    
    swap(&a, &b);
    printf("-----------------\n");

    printf("a: %d // %p\n", a, &a);
    printf("b: %d // %p\n", b, &b);
    
    return 0;
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}