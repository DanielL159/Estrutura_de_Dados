#include <stdio.h>
#define n 50

void bubbleSort(int count, int arr[]){

    int aux;
    int contador ;
    contador = count;
    for ( int i = 0; i < contador ; i++)
    {
        for ( int j = 0; j < contador - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
            
        }
        
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
    bubbleSort(count,numero);

    printf("\nArray ordenado:\n");
    for (i = 0; i < count; i++) {
        printf("%d ", numero[i]);
    }
}