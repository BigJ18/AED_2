#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// Função para o algoritmo de Insertion Sort
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

int main() {
    const int size = 10000;
    int arr[size];

    // Vetor de 10000 números ordenados de forma ascendente
    generateAscending(arr, size);
    clock_t start = clock();
    insertionSort(arr, size);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução para vetor ascendente: %f segundos\n", time_taken);

    // Vetor de 10000 números ordenados de forma descendente
    generateDescending(arr, size);
    start = clock();
    insertionSort(arr, size);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução para vetor descendente: %f segundos\n", time_taken);

    // Vetor de 10000 números desordenados
    generateRandom(arr, size);
    start = clock();
    insertionSort(arr, size);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução para vetor desordenado: %f segundos\n", time_taken);

    return 0;
}
