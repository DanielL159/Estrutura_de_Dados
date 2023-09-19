#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void ordenarLinha(int linha[], int tamanho) {
    int i, chave, j;
    for (i = 1; i < tamanho; i++) {
        chave = linha[i];
        j = i - 1;
        while (j >= 0 && linha[j] > chave) {
            linha[j + 1] = linha[j];
            j = j - 1;
        }
        linha[j + 1] = chave;
    }
}

int main(){
    int n[4][4];
    int i,j;
    srand(time(NULL));

   for ( i = 0; i < 4; i++)
    {
        for ( j = 0; j < 4; j++)
        {
             n[i][j] = rand()/100;
             printf("%d\t",n[i][j]);
        }
        printf("\n");
    }

  printf("\n");

    for (int i = 0; i < 4; i++) {
        ordenarLinha(n[i], 4);
    } 
  
    for ( i = 0; i < 4; i++)
    {
        for ( j = 0; j < 4; j++)
        {
             printf("%d\t",n[i][j]);
        }
        printf("\n");
    }
    
    
}