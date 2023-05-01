// loja.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loja.h"

// Função auxiliar para encontrar um produto pelo código
Produto *encontrarProdutoPorCodigo(Loja *loja, int codigo)
{
    for (int i = 0; i < loja->quantidade_produtos; i++)
    {
        if (loja->produtos[i].codigo == codigo)
        {
            return &loja->produtos[i];
        }
    }
    return NULL;
}
// carrega produtos do arquivo e atualiza a quantidade vendida dos produtos na loja
void carregarProdutos(Loja *loja, const char *nome_arquivo)
{
    FILE *file = fopen(nome_arquivo, "r");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo de produtos");
        exit(EXIT_FAILURE);
    }

    // Contar o número de produtos no arquivo
    int count = 0;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        count++;
    }
    fseek(file, 0, SEEK_SET);

    // Alocar memória para os produtos
    loja->produtos = malloc(count * sizeof(Produto));
    loja->quantidade_produtos = count;

    // Ler os produtos do arquivo
    for (int i = 0; i < count; i++)
    {
        fscanf(file, "%d,%[^,],%f\n", &loja->produtos[i].codigo, loja->produtos[i].designacao, &loja->produtos[i].preco);
        loja->produtos[i].quantidade_vendida = 0;
    }

    fclose(file);
}
// Salva os produtos no arquivo produtos.csv
void salvarProdutos(Loja *loja, const char *nome_arquivo)
{
    FILE *file = fopen(nome_arquivo, "w");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo de produtos");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < loja->quantidade_produtos; i++)
    {
        fprintf(file, "%d,%s,%.2f\n", loja->produtos[i].codigo, loja->produtos[i].designacao, loja->produtos[i].preco);
    }

    fclose(file);
}
// adiciona um produto na loja
void adicionarProduto(Loja *loja)
{
    Produto novo_produto;
    printf("Digite o codigo do produto: ");
    scanf("%d", &novo_produto.codigo);
    printf("Digite a designaçao do produto: ");
    scanf("%s", novo_produto.designacao);
    printf("Digite o preço do produto: ");
    scanf("%f", &novo_produto.preco);
    novo_produto.quantidade_vendida = 0;

    loja->quantidade_produtos++;
    loja->produtos = realloc(loja->produtos, loja->quantidade_produtos * sizeof(Produto));
    loja->produtos[loja->quantidade_produtos - 1] = novo_produto;

    // Salvar produtos no arquivo após adicionar um novo produto
    salvarProdutos(loja, "produtos.csv");
    printf("Produto adicionado e arquivo atualizado com sucesso!\n");
}
// remove um produto da loja
void removerProduto(Loja *loja)
{

    int codigo;
    printf("Digite o codigo do produto a ser removido: ");
    scanf("%d", &codigo);

    int index = -1;
    for (int i = 0; i < loja->quantidade_produtos; i++)
    {
        if (loja->produtos[i].codigo == codigo)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        for (int i = index; i < loja->quantidade_produtos - 1; i++)
        {
            loja->produtos[i] = loja->produtos[i + 1];
        }
        loja->quantidade_produtos--;
        loja->produtos = realloc(loja->produtos, loja->quantidade_produtos * sizeof(Produto));

        // Salvar produtos no arquivo após remover um produto
        salvarProdutos(loja, "produtos.csv");

        printf("Produto removido com sucesso!\n");
    }
    else
    {
        printf("Produto nao encontrado.\n");
    }
}
// edita um produto da loja
void editarProduto(Loja *loja)
{
    int codigo;
    printf("Digite o codigo do produto a ser editado: ");
    scanf("%d", &codigo);

    Produto *produto = encontrarProdutoPorCodigo(loja, codigo);
    if (produto != NULL)
    {
        printf("Digite a nova designaçao do produto: ");
        scanf("%s", produto->designacao);
        printf("Digite o novo preço do produto: ");
        scanf("%f", &produto->preco);

        // Salvar produtos no arquivo após editar um produto
        salvarProdutos(loja, "produtos.csv");
        printf("Produto editado e arquivo atualizado com sucesso!\n");
    }
    else
    {
        printf("Produto nao encontrado.\n");
    }
}
// lista todos os produtos da loja por ordem crescente de código
void pesquisarProdutoPorCodigo(Loja *loja)
{
    int codigo;
    printf("Digite o codigo do produto a ser pesquisado: ");
    scanf("%d", &codigo);

    Produto *produto = encontrarProdutoPorCodigo(loja, codigo);
    if (produto != NULL)
    {
        printf("Codigo: %d\n", produto->codigo);
        printf("Designaçao: %s\n", produto->designacao);
        printf("Preço: %.2f\n", produto->preco);
    }
    else
    {
        printf("Produto nao encontrado.\n");
    }
}
// lista todos os produtos da loja por nome
void pesquisarProdutoPorNome(Loja *loja)
{
    char nome[100];
    printf("Digite o nome do produto a ser pesquisado: ");
    scanf("%s", nome);

    for (int i = 0; i < loja->quantidade_produtos; i++)
    {
        if (strcmp(loja->produtos[i].designacao, nome) == 0)
        {
            printf("Codigo: %d\n", loja->produtos[i].codigo);
            printf("Designaçao: %s\n", loja->produtos[i].designacao);
            printf("Preço: %.2f\n", loja->produtos[i].preco);
            return;
        }
    }
    printf("Produto nao encontrado.\n");
}
// gerar relatório de vendas
void gerarRelatorioVendas(Loja *loja)
{
    float total_vendas = 0.0;
    float total_arrecadado = 0.0;

    printf("\nRelatorio de vendas:\n");
    printf("Codigo |   Descricao   | Quantidade vendida | Total arrecadado\n");
    for (int i = 0; i < loja->quantidade_produtos; i++)
    {
        Produto *produto = &loja->produtos[i];
        float arrecadado = produto->quantidade_vendida * produto->preco;
        printf("%6.d | %13s | %18d | %16.2f\n", produto->codigo, produto->designacao, produto->quantidade_vendida, arrecadado);
        total_vendas += produto->quantidade_vendida;
        total_arrecadado += arrecadado;
    }

    printf("\nTotal de vendas: %.0f\n", total_vendas);
    printf("Total arrecadado: %.2f\n\n", total_arrecadado);
}
