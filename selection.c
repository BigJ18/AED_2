#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 90, 45, 77, 88, 33};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array original: \n");
    printArray(arr, n);
    selectionSort(arr, n);
    printf("\nArray ordenado: \n");
    printArray(arr, n);
    return 0;
}
