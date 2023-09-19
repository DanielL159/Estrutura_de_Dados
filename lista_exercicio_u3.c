#include <stdio.h>

void insertionSort(int arr[], int count) {
    int i, chave, j;
    for (i = 1; i < count; i++) {
        chave = arr[i];
        j = i - 1;

        // Mova os elementos do arr[0..i-1] que são maiores que chave
        // para uma posição à frente de sua posição atual
        while (j >= 0 && arr[j] < chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

int main (){
    int i,numero[50], count = 0;
    int opcao = 1;

    for ( i = 0; i < 50; i++)
    {
       printf("Me informe uma numero : ");
       scanf("%d",&numero[i]);

        printf("Deseja adicionar mais um numero ? (1)sim (0)nao ");
        scanf("%d",&opcao);

        count++;

        if (opcao == 0)
        {
            break;
        }
    }
    insertionSort(numero,count);

    printf("\nArray ordenado:\n");
    for (i = 0; i < count; i++) {
        printf("%d", numero[i]);
    }
}