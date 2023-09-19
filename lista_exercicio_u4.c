 #include <stdio.h>

// Função para trocar dois elementos de um vetor
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para escolher o pivô (usando o último elemento da matriz)
int escolherPivo(int arr[], int low, int high) {
    return arr[high];
}

// Função para particionar o vetor e colocar os elementos menores à esquerda e os maiores à direita do pivô
int particionar(int arr[], int low, int high) {
    int pivot = escolherPivo(arr, low, high);
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Função de ordenação quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = particionar(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int linhas, colunas;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);

    int matriz[100][100];

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Concatenar a matriz em um único vetor
    int vetor[10000];
    int index = 0;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            vetor[index++] = matriz[i][j];
        }
    }

    // Ordenar o vetor usando o algoritmo quicksort
    int tamanho = linhas * colunas;
    quicksort(vetor, 0, tamanho - 1);

    // Atualizar a matriz ordenada
    index = 0;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = vetor[index++];
        }
    }

    printf("\nMatriz ordenada:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
