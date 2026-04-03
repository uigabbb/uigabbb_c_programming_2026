#include <stdio.h>

int isPrime(int n);

int main() {
    int num = 9;
    if (isPrime(num)) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }

    return 0;
}

int isPrime(int n) {
    if (n <= 1) {
        return 0; // Not Prime
    }
    for (int i = 2; i <=n / 2; i++) {
        if (n % i == 0) {
            return 0; // Not Prime
        }
    }
    return 1; // Prime5
}