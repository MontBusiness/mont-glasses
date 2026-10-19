#ifndef CLIENTE_REPOSITORY_H
#define CLIENTE_REPOSITORY_H

#include "../models/cliente.h"

int repo_proximo_id(void);
int repo_salvar_cliente(Cliente *c);
int repo_listar_clientes(Cliente *lista, int max);

#endif