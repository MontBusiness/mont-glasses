#include <stdio.h>
#include "produto_repository.h"

#define ARQUIVO_PRODUTOS "produtos.dat"

int repo_proximo_id_produto(void) {
    FILE *f = fopen(ARQUIVO_PRODUTOS, "rb");
    Produto p;
    int maior = 0;

    if (f == NULL) {
        return 1;
    }
    while (fread(&p, sizeof(Produto), 1, f) == 1) {
        if (p.id > maior) {
            maior = p.id;
        }
    }
    fclose(f);
    return maior + 1;
}

int repo_salvar_produto(Produto *p) {
    p->id = repo_proximo_id_produto();

    FILE *f = fopen(ARQUIVO_PRODUTOS, "ab");
    if (f == NULL) {
        return 0;
    }
    fwrite(p, sizeof(Produto), 1, f);
    fclose(f);
    return 1;
}

int repo_listar_produtos(Produto *lista, int max) {
    FILE *f = fopen(ARQUIVO_PRODUTOS, "rb");
    int total = 0;

    if (f == NULL) {
        return 0;
    }
    while (total < max && fread(&lista[total], sizeof(Produto), 1, f) == 1) {
        total++;
    }
    fclose(f);
    return total;
}