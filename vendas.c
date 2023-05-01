#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vendas.h"
#include "loja.h"

// Carrega vendas do arquivo e atualiza a quantidade vendida dos produtos na loja
void carregarVendas(Loja *loja, const char *nome_arquivo)
{
    FILE *file = fopen(nome_arquivo, "r");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo de vendas");
        exit(EXIT_FAILURE);
    }

    Venda venda;
    while (fscanf(file, "%d,%d,%10s", &venda.codigo_produto, &venda.quantidade_vendida, venda.data_venda) == 3)
    {
        Produto *produto = encontrarProdutoPorCodigo(loja, venda.codigo_produto);
        if (produto != NULL)
        {
            produto->quantidade_vendida += venda.quantidade_vendida;
        }
    }

    fclose(file);
}

// insere uma venda no arquivo vendas.csv
void inserirVenda(Loja *loja)
{
    int codigo_produto, quantidade_vendida;
    char data_venda[11];

    printf("Insira o código do produto: ");
    scanf("%d", &codigo_produto);

    Produto *produto = encontrarProdutoPorCodigo(loja, codigo_produto);
    if (produto == NULL)
    {
        printf("Produto não encontrado.\n");
        return;
    }

    printf("Insira a quantidade vendida: ");
    scanf("%d", &quantidade_vendida);

    printf("Insira a data da venda (AAAA-MM-DD): ");
    scanf("%10s", data_venda);

    produto->quantidade_vendida += quantidade_vendida;

    // Salvar venda no arquivo vendas.csv
    FILE *file = fopen("vendas.csv", "a");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo de vendas");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%d,%d,%s\n", codigo_produto, quantidade_vendida, data_venda);
    fclose(file);
}
