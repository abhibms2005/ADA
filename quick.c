#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int a[], int low, int high)
{
    int pivot, i, j, temp;

    pivot = a[high];
    i = low - 1;

    for(j = low; j < high; j++)
    {
        if(a[j] <= pivot)
        {
            i++;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    int pivotIndex;

    if(low < high)
    {
        pivotIndex = partition(a, low, high);

        quickSort(a, low, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, high);
    }
}

int main()
{
    int a[100000], n, i;
    clock_t start, end;
    double t;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        a[i] = rand() % 1000;

    printf("\nUnsorted elements are:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    start = clock();

    quickSort(a, 0, n - 1);

    end = clock();

    printf("\n\nSorted elements are:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    t = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nTime taken = %f seconds\n", t);

    return 0;
}