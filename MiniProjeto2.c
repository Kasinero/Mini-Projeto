#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_PEDIDOS 145
#define MAX_NOME 50
#define MAX_TIPO 20
#define MAX_MESAS 20
#define DELIVERY_START 100

typedef struct {
    char nome[MAX_NOME];
    int quantidade;
    char tipo[MAX_TIPO];
    float valor;
    int mesa;
} Pedido;

Pedido pedidos[MAX_PEDIDOS];
int totalPedidos = 0;

void registrarPedido() {
    if (totalPedidos >= MAX_PEDIDOS) {
        printf("Não é possível registrar mais pedidos.\n");
        return;
    }

    printf("Digite o número da mesa (ou número de delivery): ");
    scanf("%d", &pedidos[totalPedidos].mesa);
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
    int mesa;
    printf("Digite o número da mesa: ");
    scanf("%d", &mesa);

    for (int i = 0; i < totalPedidos; i++) {
        if (pedidos[i].mesa == mesa) {
            printf("Pedido %d\n", i + 1);
            printf("Nome: %s\n", pedidos[i].nome);
            printf("Quantidade: %d\n", pedidos[i].quantidade);
            printf("Tipo: %s\n", pedidos[i].tipo);
            printf("Valor: %.2f\n", pedidos[i].valor);
            printf("\n");
        }
    }
}

void fecharConta() {
    int mesa;
    float total = 0.0;
    printf("Digite o número da mesa: ");
    scanf("%d", &mesa);

    for (int i = 0; i < totalPedidos; i++) {
        if (pedidos[i].mesa == mesa) {
            float subtotal = pedidos[i].quantidade * pedidos[i].valor;
            printf("Pedido %d\n", i + 1);
            printf("Nome: %s\n", pedidos[i].nome);
            printf("Quantidade: %d\n", pedidos[i].quantidade);
            printf("Tipo: %s\n", pedidos[i].tipo);
            printf("Valor: %.2f\n", pedidos[i].valor);
            printf("Subtotal: %.2f\n", subtotal);
            printf("\n");
            total += subtotal;
        }
    }

    printf("Total da mesa %d: %.2f\n", mesa, total);
}

int main() {
    int opcao;

    do {
        printf("1. Registrar pedido\n");
        printf("2. Listar pedidos\n");
        printf("3. Fechar conta\n");
        printf("4. Sair\n");
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
                fecharConta();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 4);

    return 0;
}
