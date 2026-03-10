#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vendedor {
    int id;
    char nome[50];
};

void cadastrar() {
    FILE *file = fopen("vendedores.txt", "a");
    struct Vendedor v;

    printf("ID do vendedor: ");
    scanf("%d", &v.id);

    printf("Nome do vendedor: ");
    scanf(" %[^\n]", v.nome);

    fprintf(file, "%d %s\n", v.id, v.nome);
    fclose(file);

    printf("Vendedor cadastrado com sucesso!\n");
}

void listar() {
    FILE *file = fopen("vendedores.txt", "r");
    struct Vendedor v;

    printf("\nLista de vendedores:\n");

    while (fscanf(file, "%d %[^\n]", &v.id, v.nome) != EOF) {
        printf("ID: %d | Nome: %s\n", v.id, v.nome);
    }

    fclose(file);
}

int main() {

    int opcao;

    do {
        printf("\nSistema de Vendas\n");
        printf("1 - Cadastrar vendedor\n");
        printf("2 - Listar vendedores\n");
        printf("0 - Sair\n");

        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrar();
                break;

            case 2:
                listar();
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida\n");
        }

    } while(opcao != 0);

    return 0;
}
