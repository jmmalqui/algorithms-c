#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#define ARRAY_SIZE(N) ((sizeof N) / (sizeof N[0]))
void debug_array(int array[], int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i != size - 1)
        {
            printf(",");
        }
    }
    printf("]\n");
}
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
            break;
        }
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
    int myarray[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int array_size = ARRAY_SIZE(myarray);
    debug_array(myarray, array_size);
    quicksort_not_recursive(myarray);
    quicksort_recursive(myarray, array_size, 0, array_size - 1);
    debug_array(myarray, array_size);
    return 0;
}
