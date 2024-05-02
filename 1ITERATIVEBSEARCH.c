#include <stdio.h>

int iterativeBinarySearch(int a[], int start, int end, int element)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;
        printf("Middle value: %d\n", mid);

        if (a[mid] == element)
        {
            return mid;
        }
        else if (a[mid] < element)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[50];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    int element;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &element);

    int result = iterativeBinarySearch(a, 0, n - 1, element);

    if (result != -1)
    {
        printf("\nThe number exists at index %d. ", result);
    }
    else
    {
        printf("\nThe number does not exist.");
    }

    return 0;
}

