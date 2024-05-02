#include <stdio.h>

void bubbleSort(int a[], int n)
{
    int i, j, temp, c = 1, x;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        printf("Pass: %d: ", c++);
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

        bubbleSort(a, n);

    printf("\nSorted Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
