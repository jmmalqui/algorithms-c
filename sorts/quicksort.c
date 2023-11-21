#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#define ARRAY_SIZE(N) ((sizeof N) / (sizeof N[0]))

int quicksort_recursive(int array[], int array_size, int begin, int end)
{
    if (end <= begin)
    {
        return 0;
    }
    int pivot_d = end;
    int i = begin - 1;
    int j = begin;
    int temp = 0;
    while (true)
    {

        if (j == end)
        {
            i++;
            temp = array[i];
            array[i] = array[pivot_d];
            array[pivot_d] = temp;
            pivot_d = i;
            printf("i: %d, j: %d, begin: %d, end: %d {", i, j, begin, end);
            for (int i = 0; i < array_size; i++)
            {
                printf("%d ", array[i]);
            }
            printf("}\n");
            break;
        }

        printf("i: %d, j: %d, begin: %d, end: %d, pivot: %d {", i, j, begin, end, pivot_d);
        for (int i = 0; i < array_size; i++)
        {
            printf("%d ", array[i]);
        }
        printf("}\n");
        if (array[j] < array[pivot_d])
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            j++;
            continue;
        }
        else
        {
            j++;
            continue;
        }
    }
    printf("\n\n");
    quicksort_recursive(array, array_size, begin, pivot_d - 1);
    quicksort_recursive(array, array_size, pivot_d + 1, end);
    return 0;
}

int quicksort_not_recursive(int array[])
{
    // h o w
    return 0;
}

int main(int argc, char const *argv[])
{
    int myarray[] = {1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int array_size = ARRAY_SIZE(myarray);
    quicksort_not_recursive(myarray);
    quicksort_recursive(myarray, array_size, 0, array_size - 1);
    return 0;
}
