#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numbers;

    numbers = (int *)calloc(2, sizeof(int));

    if (numbers == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the first number: ");
    scanf("%d", &numbers[0]);

    printf("Enter the second number: ");
    scanf("%d", &numbers[1]);

    int sum = numbers[0] + numbers[1];
    printf("The sum of %d and %d is: %d\n", numbers[0], numbers[1], sum);

    // Free allocated memory
    free(numbers);

    return 0;
}
