#include <stdio.h>

int main() {
    int num;
    int sum = 0;
    while(1) {
        printf("INput number: ");
        scanf("%d", &num);

        sum = sum + num;
        if (num == 0) {
            break;
        }
    }
    printf("Sum: %d\n", sum);

    return 0;
}