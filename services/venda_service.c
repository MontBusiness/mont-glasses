#include "venda_service.h"
#include "cliente_service.h"
#include "produto_service.h"
#include "../repositories/venda_repository.h"

/* Retornos de registrar_venda:
   1  = venda registrada com sucesso
   0  = erro ao gravar
  -1  = quantidade invalida (precisa ser maior que zero)
  -2  = cliente nao encontrado
  -3  = produto nao encontrado
  -4  = estoque insuficiente */
int registrar_venda(Venda *v) {
    Cliente c;
    Produto p;

    if (v->quantidade <= 0) {
        return -1;
    }
    if (!buscar_cliente(v->id_cliente, &c)) {
        return -2;
    }
    if (!buscar_produto(v->id_produto, &p)) {
        return -3;
    }
    if (p.estoque < v->quantidade) {
        return -4;
    }

    v->total = p.preco * v->quantidade;

    if (!baixar_estoque(v->id_produto, v->quantidade)) {
        return 0;
    }
    if (!repo_salvar_venda(v)) {
        return 0;
    }
    return 1;
}

int consultar_vendas(Venda *lista, int max) {
    return repo_listar_vendas(lista, max);
}