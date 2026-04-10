#include <stdio.h>

void reverseString(char str[]);

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%99s", str);
    printf("You entered: %s\n", str);
    printf("---------\n");
    reverseString(str);
    printf("Reversed string: %s\n", str);


    return 0;
}

void reverseString(char str[]) {
    int length = 0;
    for (; str[length] != '\0'; length++);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}