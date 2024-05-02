#include <stdio.h>

void insertionSort(int a[], int n)
{
    int i, j, temp, c = 1, x;
    for (i = 0; i < n; i++)
    {
        j = i;

        while (j <= i && j > 0)
        {
            if (a[j] < a[j - 1])
            {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
            j--;
        }
        printf("Pass %d: ", c++);
        for (x = 0; x < n; x++)
        {
            printf("%d ", a[x]);
        }
        printf("\n");
    }
}

int main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Unsorted Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    insertionSort(a, n);

    printf("Sorted Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}