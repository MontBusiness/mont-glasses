#ifndef CLIENTE_SERVICE_H
#define CLIENTE_SERVICE_H

#include "../models/cliente.h"

#define MAX_CLIENTES 500

/* Retorna: 1 = ok, 0 = erro ao gravar, -1 = nome vazio, -2 = telefone invalido */
int cadastrar_cliente(Cliente *c);
int listar_clientes(Cliente *lista, int max);
/* Retorna 1 se encontrou (e preenche c), 0 se nao encontrou */
int buscar_cliente(int id, Cliente *c);

#endif