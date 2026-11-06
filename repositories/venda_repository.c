#include <stdio.h>
#include "venda_repository.h"

#define ARQUIVO_VENDAS "vendas.dat"

int repo_proximo_id_venda(void) {
    FILE *f = fopen(ARQUIVO_VENDAS, "rb");
    Venda v;
    int maior = 0;

    if (f == NULL) {
        return 1;
    }
    while (fread(&v, sizeof(Venda), 1, f) == 1) {
        if (v.id > maior) {
            maior = v.id;
        }
    }
    fclose(f);
    return maior + 1;
}

int repo_salvar_venda(Venda *v) {
    v->id = repo_proximo_id_venda();

    FILE *f = fopen(ARQUIVO_VENDAS, "ab");
    if (f == NULL) {
        return 0;
    }
    fwrite(v, sizeof(Venda), 1, f);
    fclose(f);
    return 1;
}

int repo_listar_vendas(Venda *lista, int max) {
    FILE *f = fopen(ARQUIVO_VENDAS, "rb");
    int total = 0;

    if (f == NULL) {
        return 0;
    }
    while (total < max && fread(&lista[total], sizeof(Venda), 1, f) == 1) {
        total++;
    }
    fclose(f);
    return total;
}