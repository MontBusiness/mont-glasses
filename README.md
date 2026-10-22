# Mont Glasses

Sistema desktop (console) de gestão para óticas, feito em C para o PIM II de ADS (UNIP) na disciplina ESWA.

## Arquitetura em camadas

- `models/` : structs (Cliente, Produto, Venda)
- `repositories/` : leitura e gravação em arquivo
- `services/` : regras de negócio
- `views/` : menus e telas do console
- `main.c` : ponto de entrada

## Como compilar e rodar

```bash
gcc main.c views/menu_view.c services/cliente_service.c repositories/cliente_repository.c -o mont_glasses.exe
mont_glasses.exe
```

## Integrantes

- Jayme de Moraes Ramos
- Rafael Carvalho Lucas Santos
- Inacio Vinicius Sant’Ana dos Santos Malmonge
- Miguel Antunes dos Santos Oliveira
