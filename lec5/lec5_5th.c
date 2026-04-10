#include <stdio.h>

void decompose(
    const double x,
    long* inner_int_part,
    double* inner_frac_part);

int main() {
    double pi = 3.141592;
    long int_part;
    double frac_part;

    decompose(pi,
        &int_part, &frac_part);
    printf("pi int part: %ld\n", int_part);
    printf("pi int part: %lf\n", frac_part);

    return 0;
}

void decompose(
    const double x,
    long* inner_int_part2,
    double* inner_frac_part2) {
        *inner_int_part2 = (long)x;
        *inner_frac_part2 = x - *inner_int_part2;

}