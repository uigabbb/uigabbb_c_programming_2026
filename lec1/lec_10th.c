#include <stdio.h>

int main() {
    int a = 3;
    ++a;
    printf("a: %d\n", ++a);
    printf("a: %d\n", a++);
    printf("a: %d\n", a);
    return 0;
}