#include <stdio.h>

// Definição da struct Estudante
struct Estudante {
    char nome[50];
    int matricula;
    float nota1;
    float nota2;
    float nota3;
};

// Função para calcular a média das notas
float calcularMedia(struct Estudante aluno) {
    return (aluno.nota1 + aluno.nota2 + aluno.nota3) / 3;
}

// Função para determinar se o aluno está aprovado
int estaAprovado(struct Estudante aluno) {
    float media = calcularMedia(aluno);
    return media >= 7;
}

int main() {
    // Criando uma instância da struct Estudante
    struct Estudante aluno1;
    
    // Preenchendo os dados do aluno
    printf("Digite o nome do aluno: ");
    scanf("%s", aluno1.nome);
    
    printf("Digite a matrícula do aluno: ");
    scanf("%d", &aluno1.matricula);
    
    printf("Digite as notas do aluno nas três disciplinas:\n");
    scanf("%f %f %f", &aluno1.nota1, &aluno1.nota2, &aluno1.nota3);
    
    // Verificando se o aluno está aprovado
    if (estaAprovado(aluno1)) {
        printf("O aluno %s foi aprovado!\n", aluno1.nome);
    } else {
        printf("O aluno %s foi reprovado.\n", aluno1.nome);
    }
    
    return 0;
}
