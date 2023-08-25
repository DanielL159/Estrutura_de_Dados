#include <stdio.h>
#include <string.h>

// Definição da struct Contato
struct Contato {
    char nome[50];
    char telefone[15];
};

// Função para adicionar um contato
void adicionarContato(struct Contato agenda[], int *numContatos) {
    if (*numContatos < 100) {  // Limite de 100 contatos na agenda
        printf("Digite o nome do contato: ");
        scanf("%s", agenda[*numContatos].nome);

        printf("Digite o número de telefone do contato: ");
        scanf("%s", agenda[*numContatos].telefone);

        (*numContatos)++;
        printf("Contato adicionado com sucesso!\n");
    } else {
        printf("A agenda está cheia. Não é possível adicionar mais contatos.\n");
    }
}

// Função para listar todos os contatos
void listarContatos(struct Contato agenda[], int numContatos) {
    printf("Lista de contatos:\n");
    for (int i = 0; i < numContatos; i++) {
        printf("Nome: %s\n", agenda[i].nome);
        printf("Telefone: %s\n", agenda[i].telefone);
        printf("------------------------------\n");
    }
}

// Função para buscar um contato pelo nome
void buscarContato(struct Contato agenda[], int numContatos, char nomeBusca[]) {
    int encontrado = 0;
    for (int i = 0; i < numContatos; i++) {
        if (strcmp(agenda[i].nome, nomeBusca) == 0) {
            printf("Contato encontrado:\n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Contato não encontrado.\n");
    }
}

int main() {
    struct Contato agenda[100]; // Array de contatos
    int numContatos = 0;        // Número atual de contatos na agenda

    int opcao;
    char nomeBusca[50];

    do {
        printf("Menu:\n");
        printf("1. Adicionar contato\n");
        printf("2. Listar contatos\n");
        printf("3. Buscar contato pelo nome\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato(agenda, &numContatos);
                break;
            case 2:
                listarContatos(agenda, numContatos);
                break;
            case 3:
                printf("Digite o nome do contato a ser buscado: ");
                scanf("%s", nomeBusca);
                buscarContato(agenda, numContatos, nomeBusca);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Escolha uma opção válida.\n");
        }
    } while (opcao != 4);

    return 0;
}
