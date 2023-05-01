#ifndef VENDAS_H
#define VENDAS_H
#include "loja.h"

typedef struct
{
    int codigo_produto;
    int quantidade_vendida;
    char data_venda[11]; // formato AAAA-MM-DD
} Venda;

// Carrega vendas do arquivo e atualiza a quantidade vendida dos produtos na loja
void carregarVendas(Loja *loja, const char *nome_arquivo);

// Salva uma venda no arquivo
void inserirVenda(Loja *loja);

#endif // VENDAS_H
