#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void busca (int numero, int n[4][4]){
    int i,j,acho=0;

    for ( i = 0; i < 4; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            if (numero == n[i][j])
            {
                printf("Numero %d encontrado na possicao da memoria [%d][%d]",numero,i+1,j+1);
                acho =1;
            }
            
        }
        
    }
    if (acho == 0)
    {
       printf("Numero %d nao encontrado ",numero);
    }
}

int main(){
    int n[4][4],numero;
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
    printf("Qual numero procura: ");
    scanf("%d",&numero);

    busca(numero,n);
}