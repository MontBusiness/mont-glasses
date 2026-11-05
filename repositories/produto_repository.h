#ifndef PRODUTO_REPOSITORY_H
#define PRODUTO_REPOSITORY_H

#include "../models/produto.h"

int repo_proximo_id_produto(void);
int repo_salvar_produto(Produto *p);
int repo_listar_produtos(Produto *lista, int max);

#endif