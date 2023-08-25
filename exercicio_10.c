#include <stdio.h>

// Definição da struct Moeda
struct Moeda {
    float dolares;
    float euros;
};

// Função para converter de dólares para euros
float dolaresParaEuros(float dolares, float taxa) {
    return dolares * taxa;
}

// Função para converter de euros para dólares
float eurosParaDolares(float euros, float taxa) {
    return euros / taxa;
}

int main() {
    // Taxa de câmbio atual (valor de 1 dólar em euros)
    float taxaCambio = 0.85; // Exemplo de taxa, você pode ajustar conforme a taxa real atual
    
    // Criando uma instância da struct Moeda
    struct Moeda moeda;
    
    // Solicitando valores em dólares e euros ao usuário
    printf("Digite o valor em dólares: ");
    scanf("%f", &moeda.dolares);
    
    printf("Digite o valor em euros: ");
    scanf("%f", &moeda.euros);
    
    // Solicitando a conversão desejada ao usuário
    int escolha;
    float valorConvertido;
    
    printf("Escolha a conversão:\n");
    printf("1 - Converter dólares para euros\n");
    printf("2 - Converter euros para dólares\n");
    scanf("%d", &escolha);
    
    switch (escolha) {
        case 1:
            valorConvertido = dolaresParaEuros(moeda.dolares, taxaCambio);
            printf("%.2f dólares equivalem a %.2f euros.\n", moeda.dolares, valorConvertido);
            break;
        case 2:
            valorConvertido = eurosParaDolares(moeda.euros, taxaCambio);
            printf("%.2f euros equivalem a %.2f dólares.\n", moeda.euros, valorConvertido);
            break;
        default:
            printf("Escolha inválida.\n");
            break;
    }
    
    return 0;
}
