#ifndef PRODUTO_SERVICE_H
#define PRODUTO_SERVICE_H

#include "../models/produto.h"

#define MAX_PRODUTOS 100

int cadastrar_produto(Produto *p);
int listar_produtos(Produto *lista, int max);
int buscar_produto(int id, Produto *p);
int baixar_estoque(int id, int quantidade);

#endif