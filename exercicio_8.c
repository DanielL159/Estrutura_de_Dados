#include <stdio.h>

// Definição da struct Produto
struct Produto {
    char nome[50];
    float preco;
    int quantidadeEstoque;
};

// Função para calcular o total da compra
float calcularTotalCompra(struct Produto produto, int quantidade) {
    return produto.preco * quantidade;
}

// Função para atualizar o estoque após a compra
void atualizarEstoque(struct Produto *produto, int quantidade) {
    produto->quantidadeEstoque -= quantidade;
}

int main() {
    // Criando instâncias das structs Produto
    struct Produto produtos[3];  // Você pode definir mais produtos se quiser
    
    // Preenchendo dados dos produtos
    for (int i = 0; i < 3; i++) {
        printf("Digite o nome do produto %d: ", i+1);
        scanf("%s", produtos[i].nome);
        
        printf("Digite o preço do produto %d: ", i+1);
        scanf("%f", &produtos[i].preco);
        
        printf("Digite a quantidade em estoque do produto %d: ", i+1);
        scanf("%d", &produtos[i].quantidadeEstoque);
    }
    
    // Realizando a compra
    int produtoEscolhido, quantidade;
    float totalCompra = 0;
    
    while (1) {
        printf("\nProdutos disponíveis:\n");
        for (int i = 0; i < 3; i++) {
            printf("%d - %s\n", i+1, produtos[i].nome);
        }
        
        printf("Escolha o número do produto que deseja comprar (ou 0 para sair): ");
        scanf("%d", &produtoEscolhido);
        
        if (produtoEscolhido == 0) {
            break;
        } else if (produtoEscolhido < 1 || produtoEscolhido > 3) {
            printf("Escolha inválida.\n");
            continue;
        }
        
        printf("Digite a quantidade que deseja comprar: ");
        scanf("%d", &quantidade);
        
        if (quantidade > produtos[produtoEscolhido - 1].quantidadeEstoque) {
            printf("Quantidade em estoque insuficiente.\n");
        } else {
            float totalProduto = calcularTotalCompra(produtos[produtoEscolhido - 1], quantidade);
            totalCompra += totalProduto;
            atualizarEstoque(&produtos[produtoEscolhido - 1], quantidade);
            printf("Produto %s adicionado ao carrinho. Total: R$%.2f\n", produtos[produtoEscolhido - 1].nome, totalProduto);
        }
    }
    
    printf("Total da compra: R$%.2f\n", totalCompra);
    
    return 0;
}
