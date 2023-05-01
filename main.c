// main.c
#include <stdio.h>
#include "loja.h"
#include "vendas.h"

int main()
{
    Loja loja;
    // Inicializar a loja
    carregarProdutos(&loja, "produtos.csv");
    carregarVendas(&loja, "vendas.csv");
    // Menu
    int opcao;
    do
    {
        printf("1. Adicionar produto\n");
        printf("2. Remover produto\n");
        printf("3. Editar produto\n");
        printf("4. Pesquisar produto por codigo\n");
        printf("5. Pesquisar produto por nome\n");
        printf("6. Inserir Venda\n");
        printf("7. Gerar relatorio de vendas\n");
        printf("0. Sair\n");
        printf("Escolha uma opçao: ");
        scanf("%d", &opcao);
        
        switch (opcao)
        {
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
            inserirVenda(&loja);
            break;
        case 7:
            gerarRelatorioVendas(&loja);
            break;
        case 0:
            printf("A sair...\n");
            break;
        default:
            printf("Opção invalida!\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}
