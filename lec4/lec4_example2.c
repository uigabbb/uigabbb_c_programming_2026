#include <stdio.h>
#include <cmath>

int isGreaterThan(int a, int b);

int main() {
    int a = 3;
    int b = 5;
    if (isGreaterThan(a, b)) {
        printf("%d is greater than %d\n", a, b);
    } else {
        printf("%d is not greater than %d\n", a, b);
    }

    return 0;
}

int isGreaterThan