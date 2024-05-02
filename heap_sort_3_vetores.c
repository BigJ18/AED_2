#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para fazer o heapify de uma sub-árvore com raiz em um dado índice
void heapify(int arr[], int n, int i) {
    int largest = i; // Inicializa o maior como raiz
    int left = 2 * i + 1; // Esquerda = 2*i + 1
    int right = 2 * i + 2; // Direita = 2*i + 2

    // Se o filho esquerdo é maior que a raiz
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Se o filho direito é maior que o maior até agora
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Se o maior não é a raiz
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursivamente fazer o heapify para a sub-árvore afetada
        heapify(arr, n, largest);
    }
}

// Função principal que implementa o algoritmo Heap Sort
void heapSort(int arr[], int n) {
    // Constrói o heap (rearranja o array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrai elementos um por um do heap
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual para o final
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Chama max heapify no heap reduzido
        heapify(arr, i, 0);
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
    heapSort(arr, size);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução para vetor ascendente: %f segundos\n", time_taken);

    // Vetor de 10000 números ordenados de forma descendente
    generateDescending(arr, size);
    start = clock();
    heapSort(arr, size);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução para vetor descendente: %f segundos\n", time_taken);

    // Vetor de 10000 números desordenados
    generateRandom(arr, size);
    start = clock();
    heapSort(arr, size);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução para vetor desordenado: %f segundos\n", time_taken);

    return 0;
}
