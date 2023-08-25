#include <stdio.h>
#include <time.h>

// Definição da struct Funcionario
struct Funcionario {
    char nome[50];
    char cargo[50];
    float salario;
    struct tm dataAdmissao;  // Usando a struct tm da biblioteca time.h para armazenar a data de admissão
};

// Função para dar um aumento de salário
void darAumento(struct Funcionario *funcionario, float aumento) {
    funcionario->salario += aumento;
    printf("Aumento de %.2f aplicado com sucesso.\n", aumento);
}

// Função para calcular o tempo de trabalho na empresa (em anos)
int calcularTempoTrabalho(struct Funcionario funcionario) {
    time_t currentTime;
    time(&currentTime);  // Obtendo a hora atual em segundos
    struct tm *dataAtual = localtime(&currentTime);  // Convertendo para a struct tm local
    
    int anos = dataAtual->tm_year + 1900 - funcionario.dataAdmissao.tm_year;
    int meses = dataAtual->tm_mon - funcionario.dataAdmissao.tm_mon;
    
    if (meses < 0) {
        anos--;
        meses += 12;
    }
    
    return anos;
}

int main() {
    // Criando uma instância da struct Funcionario
    struct Funcionario funcionario1;
    
    // Preenchendo os dados do funcionário
    printf("Digite o nome do funcionário: ");
    scanf("%s", funcionario1.nome);
    
    printf("Digite o cargo do funcionário: ");
    scanf("%s", funcionario1.cargo);
    
    printf("Digite o salário do funcionário: ");
    scanf("%f", &funcionario1.salario);
    
    printf("Digite a data de admissão do funcionário (ano mês dia): ");
    scanf("%d %d %d", &funcionario1.dataAdmissao.tm_year, &funcionario1.dataAdmissao.tm_mon, &funcionario1.dataAdmissao.tm_mday);
    funcionario1.dataAdmissao.tm_year -= 1900;
    funcionario1.dataAdmissao.tm_mon -= 1;
    
    // Realizando operações com o funcionário
    darAumento(&funcionario1, 200);
    
    int anosTrabalho = calcularTempoTrabalho(funcionario1);
    printf("O funcionário trabalhou na empresa por %d anos.\n", anosTrabalho);
    
    return 0;
}
