#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para mesclar duas sub-listas ordenadas
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Criação de sub-arrays temporários
    int L[n1], R[n2];

    // Copiar dados para os sub-arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Mesclar os sub-arrays temporários de volta no array[l..r]
    i = 0; // Índice inicial do primeiro sub-array
    j = 0; // Índice inicial do segundo sub-array
    k = l; // Índice inicial do array mesclado
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes de L[], se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de R[], se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal do Merge Sort que classifica arr[l..r] usando merge()
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Encontra o ponto médio para dividir o array em duas metades
        int m = l + (r - l) / 2;

        // Classifica a primeira metade
        mergeSort(arr, l, m);

        // Classifica a segunda metade
        mergeSort(arr, m + 1, r);

        // Mescla as duas metades classificadas
        merge(arr, l, m, r);
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
    mergeSort(arr, 0, size - 1);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução para vetor ascendente: %f segundos\n", time_taken);

    // Vetor de 10000 números ordenados de forma descendente
    generateDescending(arr, size);
    start = clock();
    mergeSort(arr, 0, size - 1);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução para vetor descendente: %f segundos\n", time_taken);

    // Vetor de 10000 números desordenados
    generateRandom(arr, size);
    start = clock();
    mergeSort(arr, 0, size - 1);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução para vetor desordenado: %f segundos\n", time_taken);

    return 0;
}
