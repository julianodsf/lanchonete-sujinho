# Problema 1: Lanchonete Sujinho

Em um sistema de lanchonete os pedidos são atendidos para serem servidos localmente ou delivery. Os pedidos precisam estar organizados com, no mínimo, um número identificador, valor total e uma indicação se é local ou delivery.

## Requisitos

- [ ]  Os pedidos precisam ser cadastrados e encaminhados para a cozinha na mesma ordem que são recebidos (cadastrados no sistema).
- [ ]  O sistema deve implementar as operações básicas CRUD para os pedidos. Os pedidos que já estão prontos não podem ser removidos ou alterados.
- [ ]  Quando os pedidos estiverem prontos, eles desem ser encaminhados aos clientes e precisam ser organizados em estruturas de saída. Cada opção de saída (local ou delivery) deve ser representada por uma estrutura do tipo fila.
- [ ]  - [ ]  O sistema deve implementar uma opção de entrega econômica no caso de delivery. Ao fazer o pedido o cliente pode optar por esse tipo de entrega. Nesse caso, o sistema precisa esperar por pelo menos 3 pedidos com essa mesma opção;
- [ ]  Os pedidos de entrega econômica devem ficar armazenados em uma estrutura a parte do tipo pilha. A opção de entrega do primeiro pedido da pilha, deve automaticamente realizar a entrega de todos os outros.
- [ ]  Todos os pedidos que são entregues (local ou delivery), entrega normal ou econômica, devem estar armazenados em um registro geral de saída. O registro de saída também deve manter os pedidos cancelados. Implemente uma maneira de diferenciar os cancelados nessa estrutura.

# Informações relevantes

- Todos os códigos devem ser implementados em C e devem estar compilando, no mínimo.
- Implemente as estruturas de dados e faça uso da memória da maneira que você julgar melhor, mas a escolha das estruturas adequadas e otimização da memória será critério de avaliação.
- Os códigos devem implementar opção de visualizar as estruturas e seus dados.
- Mesmo que seu código não esteja com todas as funções implementadas, é preciso que esteja compilando. Códigos que não compilam não serão corrigidos.
- Os códigos testados para geração de I.A. que atingirem índice acima de 60% serão desconsiderados e os alunos receberão nota ZERO.
- Trabalhos testados para semelhança (códigos copiados) que apresentarem coincidências notáveis em partes importantes, serão considerados como um só trabalho e a nota será dividida entre as duplas envolvidas.
- Os códigos devem ser enviados em um arquivo .c ou .txt.
- O envio dos códigos é por e-mail (*marcel.moura@ifpi.edu.br*) até às 20h de domingo, 09.01.2025;
- O trabalho deve ser entregue com identificação da dupla na forma de comentário no início do código.
- O professor poderá entrar em contato ou solicitar uma apresentação do código, caso necessário.

   # Critérios de avaliação:

- Atendimento dos requisitos: 6,0;
- Organização e clareza do código: 2,0;
- Qualidade dos algoritmos (requisitos de análise): 2,0;
