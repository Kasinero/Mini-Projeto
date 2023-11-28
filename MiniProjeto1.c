#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_PEDIDOS 145
#define MAX_NOME 50
#define MAX_TIPO 20

typedef struct {
    char nome[MAX_NOME];
    int quantidade;
    char tipo[MAX_TIPO];
    float valor;
} Pedido;

Pedido pedidos[MAX_PEDIDOS];
int totalPedidos = 0;

void registrarPedido() {
    if (totalPedidos >= MAX_PEDIDOS) {
        printf("Não é possível registrar mais pedidos.\n");
        return;
    }

    printf("Digite o nome do quitute: ");
    scanf("%s", pedidos[totalPedidos].nome);
    printf("Digite a quantidade: ");
    scanf("%d", &pedidos[totalPedidos].quantidade);
    printf("Digite o tipo da quantidade (unidade, porção, kilograma): ");
    scanf("%s", pedidos[totalPedidos].tipo);
    printf("Digite o valor: ");
    scanf("%f", &pedidos[totalPedidos].valor);

    totalPedidos++;
}

void listarPedidos() {
    for (int i = 0; i < totalPedidos; i++) {
        printf("Pedido %d\n", i + 1);
        printf("Nome: %s\n", pedidos[i].nome);
        printf("Quantidade: %d\n", pedidos[i].quantidade);
        printf("Tipo: %s\n", pedidos[i].tipo);
        printf("Valor: %.2f\n", pedidos[i].valor);
        printf("\n");
    }
}

int main() {
    int opcao;

    do {
        printf("1. Registrar pedido\n");
        printf("2. Listar pedidos\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registrarPedido();
                break;
            case 2:
                listarPedidos();
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 3);

    return 0;
}
