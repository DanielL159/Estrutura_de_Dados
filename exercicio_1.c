#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float altura;
}pessoa;

int main()
{
   pessoa p;

   printf("Qual o nome: ");
   scanf(" %c",&p.nome);

   printf("Qual o idade: ");
   scanf("%d",&p.idade);

   printf("Qual o altura: ");
   scanf("%f",&p.altura);

   printf("\nNome:%c \nIdade:%d \nAltura:%.2f",p.nome,p.idade,p.altura);

}
