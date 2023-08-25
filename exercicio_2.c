#include <stdio.h>

typedef struct {
    int i;
    float f;
    char c;
} Tipo ;

void imprime(Tipo t){
    
    printf("Inteiro: %d\nFloat: %.2f\nLetra: %c\n\n",t.i,t.f,t.c);
}



int main (){
    Tipo t;
    printf("Me informe um numero inteiro: ");
    scanf("%i",&t.i);

    printf("Me informe um numero float: ");
    scanf("%f",&t.f); 

    printf("Me informe um letra: ");
    fflush(stdin);
    scanf("%c",&t.c); 
    imprime(t);
 return 1;
}