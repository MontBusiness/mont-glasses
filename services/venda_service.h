#ifndef VENDA_SERVICE_H
#define VENDA_SERVICE_H

#include "../models/venda.h"

#define MAX_VENDAS 100

int registrar_venda(Venda *v);
int consultar_vendas(Venda *lista, int max);

#endif