#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct {
    int id;
    char descricao[100];
    float preco;
    int estoque;
} Produto;

#endif