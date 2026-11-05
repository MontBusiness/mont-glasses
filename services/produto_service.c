#include <string.h>
#include "produto_service.h"
#include "../repositories/produto_repository.h"

/* Retornos de cadastrar_produto:
   1  = cadastrado com sucesso
   0  = erro ao salvar no arquivo
  -1  = descrição vazia
  -2  = preço inválido (precisa ser maior que zero)
  -3  = estoque inválido (não pode ser negativo) */
int cadastrar_produto(Produto *p) {
    if (strlen(p->descricao) == 0) {
        return -1;
    }
    if (p->preco <= 0) {
        return -2;
    }
    if (p->estoque < 0) {
        return -3;
    }
    return repo_salvar_produto(p);
}

int listar_produtos(Produto *lista, int max) {
    return repo_listar_produtos(lista, max);
}

int buscar_produto(int id, Produto *p) {
    Produto lista[MAX_PRODUTOS];
    int total = repo_listar_produtos(lista, MAX_PRODUTOS);

    for (int i = 0; i < total; i++) {
        if (lista[i].id == id) {
            *p = lista[i];
            return 1;
        }
    }
    return 0;
}