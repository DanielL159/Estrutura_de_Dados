#include <stdio.h>

// Definição da struct ContaBancaria
struct ContaBancaria {
    char nomeTitular[50];
    int numeroConta;
    float saldo;
};

// Função para depositar dinheiro na conta
void depositar(struct ContaBancaria *conta, float valor) {
    conta->saldo += valor;
    printf("Depósito de %.2f realizado com sucesso.\n", valor);
}

// Função para sacar dinheiro da conta
void sacar(struct ContaBancaria *conta, float valor) {
    if (valor > conta->saldo) {
        printf("Saldo insuficiente.\n");
    } else {
        conta->saldo -= valor;
        printf("Saque de %.2f realizado com sucesso.\n", valor);
    }
}

// Função para verificar o saldo da conta
float verificarSaldo(struct ContaBancaria conta) {
    return conta.saldo;
}

int main() {
    // Criando uma instância da struct ContaBancaria
    struct ContaBancaria minhaConta;
    
    // Inicializando os dados da conta
    printf("Digite o nome do titular da conta: ");
    scanf("%s", minhaConta.nomeTitular);
    
    printf("Digite o número da conta: ");
    scanf("%d", &minhaConta.numeroConta);
    
    minhaConta.saldo = 0;  // Inicializando o saldo com zero
    
    // Realizando operações na conta
    depositar(&minhaConta, 1000);
    sacar(&minhaConta, 500);
    
    // Verificando o saldo da conta
    printf("Saldo atual: %.2f\n", verificarSaldo(minhaConta));
    
    return 0;
}
