#ifndef VENDA_REPOSITORY_H
#define VENDA_REPOSITORY_H

#include "../models/venda.h"

int repo_proximo_id_venda(void);
int repo_salvar_venda(Venda *v);
int repo_listar_vendas(Venda *lista, int max);

#endif