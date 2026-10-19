#include <stdio.h>
#include "cliente_repository.h"

#define ARQUIVO "clientes.dat"

int repo_proximo_id(void) {
    FILE *f = fopen(ARQUIVO, "rb");
    Cliente c;
    int maior = 0;

    if (f == NULL) {
        return 1;
    }
    while (fread(&c, sizeof(Cliente), 1, f) == 1) {
        if (c.id > maior) {
            maior = c.id;
        }
    }
    fclose(f);
    return maior + 1;
}

int repo_salvar_cliente(Cliente *c) {
    c->id = repo_proximo_id();

    FILE *f = fopen(ARQUIVO, "ab");
    if (f == NULL) {
        return 0;
    }
    fwrite(c, sizeof(Cliente), 1, f);
    fclose(f);
    return 1;
}

int repo_listar_clientes(Cliente *lista, int max) {
    FILE *f = fopen(ARQUIVO, "rb");
    int total = 0;

    if (f == NULL) {
        return 0;
    }
    while (total < max && fread(&lista[total], sizeof(Cliente), 1, f) == 1) {
        total++;
    }
    fclose(f);
    return total;
}