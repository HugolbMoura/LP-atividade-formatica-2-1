// loja.h
#ifndef LOJA_H
#define LOJA_H

typedef struct
{
    int codigo;
    char designacao[100];
    float preco;
    int quantidade_vendida;
} Produto;

typedef struct
{
    Produto *produtos;
    int quantidade_produtos;
} Loja;
Produto *encontrarProdutoPorCodigo(Loja *loja, int codigo);
void salvarProdutos(Loja *loja, const char *nome_arquivo);
void carregarProdutos(Loja *loja, const char *nome_arquivo);
void adicionarProduto(Loja *loja);
void removerProduto(Loja *loja);
void editarProduto(Loja *loja);
void pesquisarProdutoPorCodigo(Loja *loja);
void pesquisarProdutoPorNome(Loja *loja);
void gerarRelatorioVendas(Loja *loja);

#endif // LOJA_H
