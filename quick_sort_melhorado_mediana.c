#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para encontrar a mediana de três elementos
int medianOfThree(int arr[], int left, int right) {
    int mid = left + (right - left) / 2;
    if (arr[left] > arr[mid])
        swap(&arr[left], &arr[mid]);
    if (arr[left] > arr[right])
        swap(&arr[left], &arr[right]);
    if (arr[mid] > arr[right])
        swap(&arr[mid], &arr[right]);
    return mid;
}

// Função para realizar a partição com a mediana de três como pivô
int partition(int arr[], int left, int right) {
    int pivotIndex = medianOfThree(arr, left, right);
    int pivotValue = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[right]); // Move o pivô para o final
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            swap(&arr[i], &arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(&arr[storeIndex], &arr[right]); // Move o pivô de volta para a sua posição correta
    return storeIndex;
}

// Função principal do Quicksort com mediana de três
void quickSortMedianOfThree(int arr[], int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        quickSortMedianOfThree(arr, left, pivotIndex - 1);
        quickSortMedianOfThree(arr, pivotIndex + 1, right);
    }
}

// Função para imprimir o vetor
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função principal
int main() {
    const int size = 10000;
    int arr[size], arrCopy[size];

    // Gerar o vetor desordenado
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size;
        arrCopy[i] = arr[i]; // Fazer uma cópia do vetor desordenado
    }

    // Ordenar usando a versão original do Quicksort
    clock_t start = clock();
    quickSort(arrCopy, 0, size - 1);
    clock_t end = clock();
    double timeOriginal = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Ordenar usando o Quicksort com mediana de três
    start = clock();
    quickSortMedianOfThree(arr, 0, size - 1);
    end = clock();
    double timeMedianOfThree = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Tempo de execução do Quicksort original: %f segundos\n", timeOriginal);
    printf("Tempo de execução do Quicksort com mediana de três: %f segundos\n", timeMedianOfThree);

    return 0;
}
