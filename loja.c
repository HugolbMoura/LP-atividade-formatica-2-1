// loja.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loja.h"

void carregarProdutos(Loja *loja, const char *nome_arquivo) {
    // Implementar a leitura do arquivo CSV e armazenar os dados na estrutura Loja
    printf("Carregando produtos...\n");
}

void carregarVendas(Loja *loja, const char *nome_arquivo) {
    // Implementar a leitura do arquivo CSV e atualizar os dados dos produtos em Loja
    printf("Carregando vendas...\n");
}

void adicionarProduto(Loja *loja) {
    // Implementar a adição de um novo produto
    printf("Adicionando produto...\n");
}

void removerProduto(Loja *loja) {
    // Implementar a remoção de um produto
    printf("Removendo produto...\n");
}

void editarProduto(Loja *loja) {
    // Implementar a edição de um produto existente
    printf("Editando produto...\n");
}

void pesquisarProdutoPorCodigo(Loja *loja) {
    // Implementar a pesquisa de um produto por código
    printf("Pesquisando produto por código...\n");
}

void pesquisarProdutoPorNome(Loja *loja) {
    // Implementar a pesquisa de um produto por nome
    printf("Pesquisando produto por nome...\n");
}

void gerarRelatorioVendas(Loja *loja) {
    // Implementar a geração do relatório de vendas
    printf("Gerando relatório de vendas...\n");
}
