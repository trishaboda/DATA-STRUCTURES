#include <stdio.h>

void linearSearch(int a[], int n, int m){
    int occ = 0;
    printf("Elements exist at indices: ");
    
    for (int i = 0; i < n; i++){
        if (a[i] == m){
            occ++;
            printf("%d ", i);
        }
    }

    if (occ == 0){
        printf("Element not found.");
    }
    else{
        printf("\nTotal occurrences: %d", occ);
    }
}

int main(){
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[50];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    printf("Array elements: ");
    for (i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    int k;
    printf("\nEnter the element to be searched for: ");
    scanf("%d", &k);

    linearSearch(a, n, k);

    return 0;
}
