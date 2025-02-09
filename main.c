#include <stdio.h>
#include <stdlib.h>

struct node {
	int id;
	float valorTotal;
	int tipo;
	struct node *prox;
};

typedef struct node pedido;

pedido *cozinha, *local, *deliveryNormal, *deliveryEconomico, *registroSaida;
int proxId = 0, tamPilhaDeliveryEconomico = 0;
char *tipos[] = {"local", "delivery normal", "delivery economico", "cancelado"};

void cadastrarPedido () {
	int numTipo;
	pedido *p;
	p = malloc (sizeof (pedido));
	p->prox = cozinha->prox;
	cozinha->prox = p;
	do {
		printf ("Digite o valor total do pedido: R$ ");
		scanf ("%f", &cozinha->valorTotal);
	} while (cozinha->valorTotal <= 0);
	do {
		printf ("Digite o tipo do pedido (0 = local, 1 = delivery normal, 2 = delivery economico): ");
		scanf ("%d", &numTipo);
	} while (numTipo < 0 || numTipo > 2);
	cozinha->id = proxId++;
	cozinha->tipo = numTipo;
	cozinha = p;
}

void exibirPedidosCozinha () {
	pedido *p;
	p = cozinha->prox;
	printf ("== LISTA DE PEDIDOS NA COZINHA (AGUARDANDO) ==\n");
	printf ("ID\tVALOR TOTAL\tTIPO DO PEDIDO\n");
	while (p != cozinha) {
		printf ("%d\tR$ %.2f\t%s\n", p->id, p->valorTotal, tipos[p->tipo]);
		p = p->prox;
	}
}

void alterarPedidoCozinha () {
	int id;
	printf ("Digite o id do pedido que deseja alterar: ");
	scanf ("%d", &id);
	pedido *p;
	p = cozinha->prox;
	while (p != cozinha) {
		if (p->id == id) {
			int numTipo;
			do {
				printf ("Digite o novo valor total: R$ ");
				scanf ("%f", &p->valorTotal);
			} while (p->valorTotal <= 0);
			do {
				printf ("Digite o novo tipo do pedido (0 = local, 1 = delivery normal, 2 = delivery economico): ");
				scanf ("%d", &numTipo);
			} while (numTipo < 0 || numTipo > 2);
			p->tipo = numTipo;
			printf ("Pedio alterado com sucesso.\n");
			return;
		}
		p = p->prox;
	}
	printf ("Pedido nao encontrado.\n");
}

void cancelarPedido () {
	int id;
	printf ("Digite o id do pedido que deseja cancelar: ");
	scanf ("%d", &id);
	pedido *p, *tmp;
	p = cozinha->prox;
	tmp = cozinha;
	while (p != cozinha) {
		if (p->id == id) {
			tmp->prox = p->prox;
			p->tipo = 3;
			p->prox = registroSaida->prox;
			registroSaida->prox = p;
			printf ("Pedido cancelado com sucesso.\n");
			return;
		}
		tmp = p;
		p = p->prox;
	}
	printf ("Pedido nao encontrado.\n");
}

void exibirRegistroSaida () {
	pedido *p;
	p = registroSaida->prox;
	printf ("== LISTA D REGISTRO DE SAIDA ==\n");
	printf ("ID\tVALOR TOTAL\tTIPO DO PEDIDO\n");
	while (p != NULL) {
		printf ("%d\tR$ %.2f\t%s\n", p->id, p->valorTotal, tipos[p->tipo]);
		p = p->prox;
	}
}

void prepararPedidoCozinha () {
	pedido *p;
	p = cozinha->prox; // primeiro pedido da fila
	if (p == cozinha) {
		// fila vazia
		printf ("Nao ha pedidos na cozinha.\n");
		return;
	}
	// desagregar o pedido da cozinha (desenfileirar)
	cozinha->prox = p->prox;
	// agregar o pedido na estrutura correspondente ao tipo do pedido
	switch (p->tipo) {
		case 0:
			p->prox = local->prox;
			local->prox = p;
			local->id = p->id;
			local->valorTotal = p->valorTotal;
			local->tipo = p->tipo;
			local = p;
			break;
		case 1:
			p->prox = deliveryNormal->prox;
			deliveryNormal->prox = p;
			deliveryNormal->id = p->id;
			deliveryNormal->valorTotal = p->valorTotal;
			deliveryNormal->tipo = p->tipo;
			deliveryNormal = p;
			break;
		default:
			p->prox = deliveryEconomico->prox;
			deliveryEconomico->prox = p;
			tamPilhaDeliveryEconomico++;
	}
}

void entregarPedidoLocal () {
	pedido *p;
	p = local->prox;
	if (p == local) {
		printf ("Nao ha pedidos na fila de pedidos prontos locais.\n");
		return;
	}
	local->prox = p->prox;
	p->prox = registroSaida->prox;
	registroSaida->prox = p;
}

void entregarPedidoDeliveryNormal () {
	pedido *p;
	p = deliveryNormal->prox;
	if (p == deliveryNormal) {
		printf ("Nao ha pedidos na fila de pedidos prontos para delivery normal.\n");
		return;
	}
	deliveryNormal->prox = p->prox;
	p->prox = registroSaida->prox;
	registroSaida->prox = p;
}

void entregarPedidoDeliveryEconomico () {
	if (tamPilhaDeliveryEconomico < 3) {
		printf ("A pilha de pedidos prontos para delivery economico tem menos de 3 pedidos.\n");
		return;
	}
	pedido *p;
	p = deliveryEconomico->prox;
	while (p != NULL) {
		deliveryEconomico->prox = p->prox;
		p->prox = registroSaida->prox;
		registroSaida->prox = p;
		p = deliveryEconomico->prox;
	}
	tamPilhaDeliveryEconomico = 0;
}

void exibirPedidosLocal () {
	pedido *p;
	p = local->prox;
	printf ("== LISTA DE PEDIDOS PRONTOS LOCAIS ==\n");
	printf ("ID\tVALOR TOTAL\tTIPO DO PEDIDO\n");
	while (p != local) {
		printf ("%d\tR$ %.2f\t%s\n", p->id, p->valorTotal, tipos[p->tipo]);
		p = p->prox;
	}
}

void exibirPedidosDeliveryNormal () {
	pedido *p;
	p = deliveryNormal->prox;
	printf ("== LISTA DE PEDIDOS PRONTOS PARA DELIVERY NORMAL ==\n");
	printf ("ID\tVALOR TOTAL\tTIPO DO PEDIDO\n");
	while (p != deliveryNormal) {
		printf ("%d\tR$ %.2f\t%s\n", p->id, p->valorTotal, tipos[p->tipo]);
		p = p->prox;
	}
}

void exibirPedidosDeliveryEconomico () {
	pedido *p;
	p = deliveryEconomico->prox;
	printf ("== LISTA DE PEDIDOS PRONTOS PARA DELIVERY ECONOMICO ==\n");
	printf ("ID\tVALOR TOTAL\tTIPO DO PEDIDO\n");
	while (p != NULL) {
		printf ("%d\tR$ %.2f\t%s\n", p->id, p->valorTotal, tipos[p->tipo]);
		p = p->prox;
	}
}

void liberarMemoriaFila (pedido *fila) {
	pedido *p;
	p = fila->prox;
	while (p != fila) {
		pedido *aux = p->prox;
		free (p);
		p = aux;
	}
	free (fila);
}

void liberarMemoriaPilha (pedido *pilha) {
	pedido *p;
	p = pilha->prox;
	while (p != NULL) {
		pedido *aux = p->prox;
		free (p);
		p = aux;
	}
	free (pilha);
}

void liberarMemoriaListaLigada (pedido *listaLigada) {
	pedido *p;
	p = listaLigada->prox;
	while (p != NULL) {
		pedido *aux = p->prox;
		free (p);
		p = aux;
	}
	free (listaLigada);
}

int main () {
	// inicializando as estruturas
	cozinha = malloc (sizeof (pedido));
	cozinha->prox = cozinha;
	local = malloc (sizeof (pedido));
	local->prox = local;
	deliveryNormal = malloc (sizeof (pedido));
	deliveryNormal->prox = deliveryNormal;
	deliveryEconomico = malloc (sizeof (pedido));
	deliveryEconomico->prox = NULL;
	registroSaida = malloc (sizeof (pedido));
	registroSaida->prox = NULL;
	while (1) {
        int opcao;
        printf("Escolha uma opcao:\n");
        printf("1  - Cadastrar Pedido\n");
        printf("2  - Exibir Pedidos na Cozinha\n");
        printf("3  - Alterar Pedido na Cozinha\n");
        printf("4  - Cancelar Pedido na Cozinha\n");
        printf("5  - Preparar Pedido na Cozinha\n");
        printf("6  - Exibir Pedidos Prontos Locais\n");
        printf("7  - Exibir Pedidos Prontos Para Delivery Normal\n");
        printf("8  - Exibir Pedidos Prontos Para Delivery Economico\n");
        printf("9  - Entregar Pedido Pronto Local\n");
        printf("10 - Entregar Pedido Pronto Para Delivery Normal\n");
        printf("11 - Entregar Pedido Pronto Para Delivery Economico\n");
        printf("12 - Exibir Pedidos no Registro de Saida\n");
        printf("0  - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        // getchar();

        // Processa a escolha do usuário
        switch (opcao) {
            case 1:
				cadastrarPedido ();
                break;
            case 2:
				exibirPedidosCozinha ();
                break;
            case 3:
				alterarPedidoCozinha ();
				break;
			case 4:
				cancelarPedido ();
				break;
			case 5:
				prepararPedidoCozinha ();
				break;
			case 6:
				exibirPedidosLocal ();
				break;
			case 7:
				exibirPedidosDeliveryNormal ();
				break;
			case 8:
				exibirPedidosDeliveryEconomico ();
				break;
			case 9:
				entregarPedidoLocal ();
				break;
			case 10:
				entregarPedidoDeliveryNormal ();
				break;
			case 11:
				entregarPedidoDeliveryEconomico ();
				break;
			case 12:
				exibirRegistroSaida ();
				break;
            case 0:
                // Sai do programa liberando a memória
                liberarMemoriaFila (cozinha);
                liberarMemoriaFila (local);
                liberarMemoriaFila (deliveryNormal);
                liberarMemoriaPilha (deliveryEconomico);
                liberarMemoriaListaLigada (registroSaida);
                return 0;
            default:
                // Opção inválida
                printf("Opcao invalida\n");
        }
    }
	return 0;
}
