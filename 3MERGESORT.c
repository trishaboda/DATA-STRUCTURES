#include <stdio.h>
void merge(int a[], int l, int m, int r, int n)
{
    int x;
    static int c = 1;
    int i = l;
    int j = m + 1;
    int k = l;
    int temp[n];
    while (i <= m && j <= r)
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= m)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    while (j <= r)
    {
        temp[k] = a[j];
        j++;
        k++;
    }
    for (int p = l; p <= r; p++)
    {
        a[p] = temp[p];
    }
    printf("\nPass %d: ", c++);
    for (x = 0; x < n; x++)
    {
        printf("%d ", a[x]);
    }
}
void mergeSort(int a[], int l, int r, int n)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m, n);
        mergeSort(a, m + 1, r, n);
        merge(a, l, m, r, n);
    }
}
int main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[50];
    printf("Enter elements of array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Unsorted Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    mergeSort(a, 0, n - 1, n);
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
