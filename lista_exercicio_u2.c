#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar um array de inteiros aleatórios
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }
}

// Função para imprimir um array (apenas para verificar a ordenação)
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função de ordenação por bolha
void bubbleSort(int arr[], int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função de particionamento para o quicksort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Função de ordenação quicksort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função para mesclar dois subarrays
void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Arrays temporários
    int L[n1], R[n2];

    // Copiar dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[middle + 1 + j];
    }

    // Mesclar os arrays temporários de volta em arr[left..right]
    i = 0;
    j = 0;
    k = left;
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

    // Copiar os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função de ordenação mergesort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    int sizes[] = {1000, 5000, 10000, 20000}; // Tamanhos diferentes de arrays

    for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        int size = sizes[i];
        int *arr = (int *)malloc(size * sizeof(int));
        int *arr_copy = (int *)malloc(size * sizeof(int));

        generateRandomArray(arr, size);

        printf("Array gerado aleatoriamente para %d elementos:\n", size);
        // Para verificar a ordenação, você pode comentar essa linha ao medir o tempo de execução
        // printArray(arr, size);

        // Copie o array gerado aleatoriamente para uma cópia antes de ordenar
        for (int j = 0; j < size; j++) {
            arr_copy[j] = arr[j];
        }

        // Medir o tempo de execução para o Bubble Sort
        clock_t start_time = clock();
        bubbleSort(arr, size);
        clock_t end_time = clock();
        double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Bubble Sort para %d elementos: %.4f segundos\n", size, elapsed_time);

        // Copie o array de volta para a cópia antes de ordenar novamente
        for (int j = 0; j < size; j++) {
            arr[j] = arr_copy[j];
        }

        // Medir o tempo de execução para o Quick Sort
        start_time = clock();
        quickSort(arr, 0, size - 1);
        end_time = clock();
        elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Quick Sort para %d elementos: %.4f segundos\n", size, elapsed_time);

        // Copie o array de volta para a cópia antes de ordenar novamente
        for (int j = 0; j < size; j++) {
            arr[j] = arr_copy[j];
        }

        // Medir o tempo de execução para o Merge Sort
        start_time = clock();
        mergeSort(arr, 0, size - 1);
        end_time = clock();
        elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Merge Sort para %d elementos: %.4f segundos\n", size, elapsed_time);

        free(arr);
        free(arr_copy);
    }

    return 0;
}
