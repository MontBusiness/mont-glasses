#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu_view.h"
#include "../services/cliente_service.h"
#include "../services/produto_service.h"

static void ler_texto(const char *rotulo, char *destino, int tamanho) {
    printf("%s", rotulo);
    if (fgets(destino, tamanho, stdin) != NULL) {
        destino[strcspn(destino, "\n")] = '\0';
    }
}

static int ler_inteiro(const char *rotulo) {
    char buffer[20];
    ler_texto(rotulo, buffer, sizeof(buffer));
    return atoi(buffer);
}

static float ler_decimal(const char *rotulo) {
    char buffer[30];
    ler_texto(rotulo, buffer, sizeof(buffer));
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == ',') {
            buffer[i] = '.';
        }
    }
    return (float)atof(buffer);
}

static void pausar(void) {
    char buffer[10];
    printf("\nPressione ENTER para continuar...");
    fgets(buffer, sizeof(buffer), stdin);
}

void tela_cadastrar_cliente(void) {
    Cliente c;
    int resultado;

    printf("\n--- CADASTRAR CLIENTE ---\n");
    ler_texto("Nome: ", c.nome, sizeof(c.nome));
    ler_texto("Telefone: ", c.telefone, sizeof(c.telefone));
    ler_texto("E-mail (opcional): ", c.email, sizeof(c.email));

    resultado = cadastrar_cliente(&c);
    if (resultado == 1) {
        printf("\nCliente cadastrado com ID %d.\n", c.id);
    } else if (resultado == -1) {
        printf("\nErro: o nome nao pode ficar vazio.\n");
    } else if (resultado == -2) {
        printf("\nErro: telefone invalido (use 10 ou 11 digitos).\n");
    } else {
        printf("\nErro ao gravar o cliente.\n");
    }
    pausar();
}

void tela_listar_clientes(void) {
    Cliente lista[MAX_CLIENTES];
    int total = listar_clientes(lista, MAX_CLIENTES);

    printf("\n--- CLIENTES CADASTRADOS (%d) ---\n", total);
    if (total == 0) {
        printf("Nenhum cliente cadastrado.\n");
    }
    for (int i = 0; i < total; i++) {
        printf("%d | %s | %s | %s\n",
               lista[i].id, lista[i].nome, lista[i].telefone, lista[i].email);
    }
    pausar();
}

void tela_buscar_cliente(void) {
    Cliente c;
    int id;

    printf("\n--- BUSCAR CLIENTE ---\n");
    id = ler_inteiro("ID do cliente: ");

    if (buscar_cliente(id, &c)) {
        printf("\nID: %d\nNome: %s\nTelefone: %s\nE-mail: %s\n",
               c.id, c.nome, c.telefone, c.email);
    } else {
        printf("\nCliente nao encontrado.\n");
    }
    pausar();
}

void tela_cadastrar_produto(void) {
    Produto p;
    int resultado;

    printf("\n--- CADASTRAR PRODUTO ---\n");
    ler_texto("Descricao: ", p.descricao, sizeof(p.descricao));
    p.preco = ler_decimal("Preco (ex: 199.90): ");
    p.estoque = ler_inteiro("Quantidade em estoque: ");

    resultado = cadastrar_produto(&p);
    if (resultado == 1) {
        printf("\nProduto cadastrado com ID %d.\n", p.id);
    } else if (resultado == -1) {
        printf("\nErro: a descricao nao pode ficar vazia.\n");
    } else if (resultado == -2) {
        printf("\nErro: o preco precisa ser maior que zero.\n");
    } else if (resultado == -3) {
        printf("\nErro: o estoque nao pode ser negativo.\n");
    } else {
        printf("\nErro ao gravar o produto.\n");
    }
    pausar();
}

void tela_listar_produtos(void) {
    Produto lista[MAX_PRODUTOS];
    int total = listar_produtos(lista, MAX_PRODUTOS);

    printf("\n--- PRODUTOS CADASTRADOS (%d) ---\n", total);
    if (total == 0) {
        printf("Nenhum produto cadastrado.\n");
    }
    for (int i = 0; i < total; i++) {
        printf("%d | %s | R$ %.2f | estoque: %d\n",
               lista[i].id, lista[i].descricao, lista[i].preco, lista[i].estoque);
    }
    pausar();
}

void exibir_menu_principal(void) {
    int opcao;

    do {
        system("cls");
        printf("=============================\n");
        printf("        MONT GLASSES\n");
        printf("=============================\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Listar clientes\n");
        printf("3 - Buscar cliente\n");
        printf("4 - Cadastrar produto\n");
        printf("5 - Listar produtos\n");
        printf("0 - Sair\n");
        opcao = ler_inteiro("\nEscolha uma opcao: ");

        switch (opcao) {
            case 1: tela_cadastrar_cliente(); break;
            case 2: tela_listar_clientes(); break;
            case 3: tela_buscar_cliente(); break;
            case 4: tela_cadastrar_produto(); break;
            case 5: tela_listar_produtos(); break;
            case 0: printf("\nAte logo!\n"); break;
            default:
                printf("\nOpcao invalida.\n");
                pausar();
        }
    } while (opcao != 0);
}