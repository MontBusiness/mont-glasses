#include "cliente_service.h"
#include "../repositories/cliente_repository.h"

static int texto_vazio(const char *s) {
    while (*s) {
        if (*s != ' ') {
            return 0;
        }
        s++;
    }
    return 1;
}

static int telefone_valido(const char *tel) {
    int digitos = 0;
    for (int i = 0; tel[i] != '\0'; i++) {
        if (tel[i] >= '0' && tel[i] <= '9') {
            digitos++;
        } else if (tel[i] != ' ' && tel[i] != '-' && tel[i] != '(' && tel[i] != ')') {
            return 0;
        }
    }
    return digitos >= 10 && digitos <= 11;
}

int cadastrar_cliente(Cliente *c) {
    if (texto_vazio(c->nome)) {
        return -1;
    }
    if (!telefone_valido(c->telefone)) {
        return -2;
    }
    return repo_salvar_cliente(c);
}

int listar_clientes(Cliente *lista, int max) {
    return repo_listar_clientes(lista, max);
}

int buscar_cliente(int id, Cliente *c) {
    Cliente lista[MAX_CLIENTES];
    int total = repo_listar_clientes(lista, MAX_CLIENTES);

    for (int i = 0; i < total; i++) {
        if (lista[i].id == id) {
            *c = lista[i];
            return 1;
        }
    }
    return 0;
}