// main.c
#include <stdio.h>
#include "loja.h"

int main() {
    Loja loja;

    carregarProdutos(&loja, "produtos.csv");
    carregarVendas(&loja, "vendas.csv");

    int opcao;
    do {
        printf("1. Adicionar produto\n");
        printf("2. Remover produto\n");
        printf("3. Editar produto\n");
        printf("4. Pesquisar produto por código\n");
        printf("5. Pesquisar produto por nome\n");
        printf("6. Gerar relatório de vendas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(&loja);
                break;
            case 2:
                removerProduto(&loja);
                break;
            case 3:
                editarProduto(&loja);
                break;
            case 4:
                pesquisarProdutoPorCodigo(&loja);
                break;
            case 5:
                pesquisarProdutoPorNome(&loja);
                break;
            case 6:
                gerarRelatorioVendas(&loja);
                break;
            case 0:
                printf("A sair...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
