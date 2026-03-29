#include <stdio.h>

int main() {
    float a = 10.0;
    int b = 3;

    int c = b / a;
    printf("%d / %f = %d\n", b, a, c);

    float d = b / a;
    printf("%d / %f = %f\n", b, a, d);

    int e = 10;
    float f = b / e;
    printf("%d / %d = %f\n", b, e, f);


    return 0;
}