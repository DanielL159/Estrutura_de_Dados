#include <stdio.h>
#include <string.h>

// Definição da struct Livro
struct Livro {
    char titulo[100];
    char autor[100];
    int anoPublicacao;
};

// Função para adicionar informações de um livro
void adicionarLivro(struct Livro biblioteca[], int *numLivros) {
    if (*numLivros < 100) {  // Limite de 100 livros na biblioteca
        printf("Digite o título do livro: ");
        scanf(" %[^\n]", biblioteca[*numLivros].titulo);

        printf("Digite o nome do autor do livro: ");
        scanf(" %[^\n]", biblioteca[*numLivros].autor);

        printf("Digite o ano de publicação do livro: ");
        scanf("%d", &biblioteca[*numLivros].anoPublicacao);

        (*numLivros)++;
        printf("Informações do livro adicionadas com sucesso!\n");
    } else {
        printf("A biblioteca está cheia. Não é possível adicionar mais livros.\n");
    }
}

// Função para listar todos os livros
void listarLivros(struct Livro biblioteca[], int numLivros) {
    printf("Lista de livros:\n");
    for (int i = 0; i < numLivros; i++) {
        printf("Título: %s\n", biblioteca[i].titulo);
        printf("Autor: %s\n", biblioteca[i].autor);
        printf("Ano de Publicação: %d\n", biblioteca[i].anoPublicacao);
        printf("------------------------------\n");
    }
}

// Função para buscar livros por autor
void buscarLivroPorAutor(struct Livro biblioteca[], int numLivros, char autorBusca[]) {
    int encontrados = 0;
    printf("Livros do autor '%s':\n", autorBusca);
    for (int i = 0; i < numLivros; i++) {
        if (strcmp(biblioteca[i].autor, autorBusca) == 0) {
            printf("Título: %s\n", biblioteca[i].titulo);
            printf("Ano de Publicação: %d\n", biblioteca[i].anoPublicacao);
            printf("------------------------------\n");
            encontrados = 1;
        }
    }
    if (!encontrados) {
        printf("Nenhum livro encontrado para o autor '%s'.\n", autorBusca);
    }
}

int main() {
    struct Livro biblioteca[100]; // Array de livros
    int numLivros = 0;            // Número atual de livros na biblioteca

    int opcao;
    char autorBusca[100];

    do {
        printf("Menu:\n");
        printf("1. Adicionar livro\n");
        printf("2. Listar livros\n");
        printf("3. Buscar livros por autor\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarLivro(biblioteca, &numLivros);
                break;
            case 2:
                listarLivros(biblioteca, numLivros);
                break;
            case 3:
                printf("Digite o nome do autor para buscar: ");
                scanf(" %[^\n]", autorBusca);
                buscarLivroPorAutor(biblioteca, numLivros, autorBusca);
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
