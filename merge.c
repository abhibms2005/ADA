#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int temp[100000];

    while(i <= mid && j <= high)
    {
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i <= mid)
        temp[k++] = a[i++];

    while(j <= high)
        temp[k++] = a[j++];

    for(i = low; i <= high; i++)
        a[i] = temp[i];
}

void mergeSort(int a[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

int main()
{
    int a[100000], n, i;
    clock_t start, end;
    double t;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Generate random elements
    for(i = 0; i < n; i++)
        a[i] = rand() % 1000;

    printf("\nUnsorted elements are:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    start = clock();

    mergeSort(a, 0, n - 1);

    end = clock();

    printf("\n\nSorted elements are:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    t = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n\nTime taken = %f seconds\n", t);

    return 0;
}