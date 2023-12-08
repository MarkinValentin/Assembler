#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

extern void f(int32_t *array, int32_t n, int32_t shift);

int main()
{
    srand(time(NULL));

    // user input
    int32_t n, shift;

    printf("Enter array length (n > 1): ");
    if (scanf("%d", &n) != 1 || n <= 1)
    {
        printf("Error, please enter a valid integer greater than 1.\n");
        return -1;
    }

    printf("Enter shift (0 < shift < n): ");
    if (scanf("%d", &shift) != 1 || shift <= 0 || shift >= n)
    {
        printf("Error, please enter a valid integer for shift (0 < shift < n).\n");
        return -1;
    }

    // memory allocation for array
    int32_t *array = malloc(n * sizeof(int32_t));

    int32_t lowerBound, upperBound;
    printf("Enter the lower limit of the range: ");
    if (scanf("%d", &lowerBound) != 1)
    {
        printf("Error, please enter a valid integer for the lower limit.\n");
        return -1;
    }

    printf("Enter the upper limit of the range: ");
    if (scanf("%d", &upperBound) != 1 || lowerBound > upperBound)
    {
        printf("Error, please enter a valid integer for the upper limit that is greater than the lower limit.\n");
        return -1;
    }

    if (array)
    {
        printf("Array before: \n");
        for (int i = 0; i < n; ++i)
        {
            // populate array
            array[i] = rand() % (upperBound - lowerBound + 1) + lowerBound;
            printf("%d ", array[i]);
        }

        f(array, n, shift);

        // print array
        printf("\nArray after: \n");
        for (int i = 0; i < n; ++i)
            printf("%d ", array[i]);
    }

    free(array);
    return 0;
}
