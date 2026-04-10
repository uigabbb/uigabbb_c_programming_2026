#include <stdio.h>

int main() {
    int abc = 1;

    int other = abc;
    printf("abc: %d\n", abc);
    printf("other: %d\n", other);
    
    printf("--------------------\n");

    abc++;
    printf("abc: %d\n", abc);
    printf("other: %d\n", other);

    printf("--------------------\n");

    other += 2;
    printf("abc: %d\n", abc);
    printf("other: %d\n", other);
    
    return 0;
}