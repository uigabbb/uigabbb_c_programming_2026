#include <stdio.h>

int findMax(int arr[], int size);

int main() {
    int arr[] = {3, 5, 2, 8, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    int max = findMax(arr, size);

    printf("Maximum element in the array: %d\n", max);

    return 0;
}

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}