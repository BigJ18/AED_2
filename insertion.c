#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    insertionSort(arr, n);
    printf("\nArray ordenado: \n");
    printArray(arr, n);
    return 0;
}
