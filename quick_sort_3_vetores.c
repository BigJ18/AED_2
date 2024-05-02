#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para encontrar o pivô correto e dividir o array
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivô
    int i = (low - 1);     // Índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivot) {
            i++; // Incrementa o índice do menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Função principal do algoritmo Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Encontra o pivô correto, arr[] está agora ordenado em relação ao pivô
        int pi = partition(arr, low, high);

        // Ordena os elementos separadamente antes e depois do pivô
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função para gerar o vetor de números ordenados de forma ascendente
void generateAscending(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

// Função para gerar o vetor de números ordenados de forma descendente
void generateDescending(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

// Função para gerar o vetor de números desordenados
void generateRandom(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
}

// Função para imprimir o vetor
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    const int size = 10000;
    int arr[size];

    // Vetor de 10000 números ordenados de forma ascendente
    generateAscending(arr, size);
    clock_t start = clock();
    quickSort(arr, 0, size - 1);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução para vetor ascendente: %f segundos\n", time_taken);

    // Vetor de 10000 números ordenados de forma descendente
    generateDescending(arr, size);
    start = clock();
    quickSort(arr, 0, size - 1);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução para vetor descendente: %f segundos\n", time_taken);

    // Vetor de 10000 números desordenados
    generateRandom(arr, size);
    start = clock();
    quickSort(arr, 0, size - 1);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução para vetor desordenado: %f segundos\n", time_taken);

    return 0;
}
