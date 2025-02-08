#include <stdio.h>

typedef struct Pedido {
  int id;
  float valorTotal;
  char tipoEntrega[2] // 'L' para Local e 'D' para Delivery
  struct Pedido* proximo; // 
} Pedido;

typedef struct Fila {
  Pedido* frente; // Para a ordem de encaminhamento p cozinha
  Pedido* tras; // Para remover os ultimos pedidos
  int tamanho; // para contar o numero de pedidos na fila
}


int main () {
  return 0;
}
