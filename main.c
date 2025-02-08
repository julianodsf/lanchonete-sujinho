#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pedido {
    int id;
    float valorTotal;
    char tipoEntrega; // 'L' para Local e 'D' para Delivery
    struct Pedido* proximo; // 
} Pedido;

typedef struct Fila {
    Pedido* frente; // Para a ordem de encaminhamento p cozinha
    Pedido* tras; // Para remover os ultimos pedidos
    int tamanho; // para contar o numero de pedidos na fila
} Fila;


Pedido* inicioFila = NULL;
int nPedidos = 0;


void cadastrarPedido() {
    Pedido* novoPedido = (Pedido*)calloc(1, sizeof(Pedido));
    if (novoPedido == NULL) {
        printf("Erro ao alocar memória para o novo pedido.\n");
        return;
    }
    
    printf("Digite o ID do pedido: ");
    scanf("%d", &novoPedido->id);
    getchar();
    
    printf("Digite o valor total do pedido: R$");
    scanf("%f", &novoPedido->valorTotal);
    getchar();
    
    printf("Digite o tipo de entrega do pedido ('L' para Local/'D' para Delivery): ");
    scanf("%c", &novoPedido->tipoEntrega);
    
    novoPedido->proximo = NULL;
    
    if (inicioFila == NULL) {
        inicioFila = novoPedido;
    } else {
        Pedido* atual = inicioFila;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoPedido;
    }
    
    nPedidos++;
    printf("Pedido cadastrado com sucesso.\n");
    
}

void visualizarCadastrados() { 
    if (inicioFila == NULL) {
        printf("\nNenhum pedido cadastrado.\n");
        return;
    }

    Pedido* atual = inicioFila; // Começa pelo início da fila
    printf("Pedidos na fila:\n");
    while (atual != NULL) {
        printf("ID: %d\n", atual->id);
        printf("Valor Total: R$%.2f\n", atual->valorTotal);
        printf("Tipo de Entrega ('L' para Local/'D' para Delivery): %c\n", atual->tipoEntrega);
        atual = atual->proximo; // Move para a próxima pessoa
    }
}

void alterarPedido() {
    if(inicioFila == NULL) {
        printf("Nenhum pedido foi registrado ainda.\n");
        return;
    }
    
    int idPedido;
    printf("Digite o ID do pedido que quer alterar: ");
    scanf("%d", &idPedido);
    getchar();
    
    Pedido* atual = inicioFila;
    while (atual != NULL) {
        if (atual->id == idPedido) {
            printf("Pedido selecionado.\n");
            
            printf("Digite o novo valor total do pedido: R$");
            scanf("%f", &atual->valorTotal);
            
            // a mudanca no tipo de entrega nao esta funcionando
            printf("Digite o novo tipo de entrega do pedido('L' para Local/'D' para Delivery): ");
            scanf("%c", &atual->tipoEntrega);
            
            printf("Pedido alterado com sucesso.\n");
            return;
        }
        atual = atual->proximo;
    }
    
    printf("Pedido com ID %d não encontrado.\n", idPedido);
}

void cancelarPedido() { // falta verificar se o pedido ja foi preparado ou nao
    if(inicioFila == NULL) {
        printf("Nenhum pedido foi registrado ainda.\n");
        return;
    }
    
    int idPedido;
    printf("Digite o ID do pedido que quer alterar: ");
    scanf("%d", &idPedido);
    getchar();
    
    Pedido* cancelado = inicioFila;
    while (cancelado != NULL) {
        if (cancelado->id == idPedido) {
            printf("Pedido selecionado: %d\n", cancelado->id);
            inicioFila = inicioFila->proximo;
            free(cancelado);
            nPedidos--;
            printf("Pedido cancelado com sucesso.\n");
        }
        cancelado = cancelado->proximo;
    }
}


void prepararPedido() {
    
}

void visualizarProntos() {
    
}

void entregarPedido() {
    
}

int main () {
    int opcao;

    do {
        printf("Escolha uma opcao:\n");
        printf("1 - Cadastrar pedido\n");
        printf("2 - Visualizar pedidos cadastrados\n");
        printf("3 - Alterar pedido\n");
        printf("4 - Cancelar pedido\n");
        printf("5 - Preparar pedido\n");
        printf("6 - Visualizar pedidos prontos\n");
        printf("7 - Entregar pedido\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                cadastrarPedido();
                break;
            case 2:
                visualizarCadastrados();
            break;
            case 3:
                alterarPedido();
                break;
            case 4:
                cancelarPedido();
                break;
            case 5:
                prepararPedido();
                break;
            case 6:
                visualizarProntos();
            break;
            case 7:
                entregarPedido();
                break;
            case 0:
                printf("Desligando o sistema...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
