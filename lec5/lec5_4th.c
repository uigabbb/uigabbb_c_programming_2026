#include <stdio.h>

int main() {
    int abc = 1;
    int* other = &abc;
    int* other2 = other;

    printf("abc: %d\n", abc);
    printf("other: %d\n", *other);
    printf("other: %d\n", *other2);
    
    printf("--------------------\n");

    abc++;
    printf("abc: %d\n", abc);
    printf("other: %d\n", *other);
    printf("other: %d\n", *other2);

    printf("--------------------\n");

    (*other2)++;
    printf("abc: %d\n", abc);
    printf("other: %d\n", *other);
    printf("other: %d\n", *other2);
    
    return 0;
}