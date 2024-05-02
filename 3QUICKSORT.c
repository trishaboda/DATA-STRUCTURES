#include <stdio.h>

void swap(int a[], int i, int j)     
{                                    
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int a[], int p, int r)
{
    int q, i, j, x;

    q = a[r];
    i = p - 1;

    printf("\nPivot: %d", q);
    printf("\nArray with Pivot %d: ", q);
    for (x = p; x <= r; x++)
    {
        printf(" %d", a[x]);
    }

    for (j = p; j <= r - 1; j++)
    {
        if (a[j] <= q)
        {
            i = i + 1;
            swap(a, i, j);
        }
    }
    swap(a, i + 1, r);
    return i + 1;
}

void quickSort(int a[], int p, int r)
{
    if (p < r)
    {
        int q = partition(a, p, r);
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
    }
}

int main()
{
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Unsorted Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    quickSort(a, 0, n - 1);

    printf("\n\nSorted Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}