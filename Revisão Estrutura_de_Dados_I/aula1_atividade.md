Resumo — Estrutura de Dados I
1. Conceito de Estrutura de Dados
Estrutura de Dados é o estudo de técnicas utilizadas para organizar, armazenar e manipular dados de maneira eficiente em um programa.

A escolha adequada de uma estrutura de dados pode melhorar significativamente o desempenho de um algoritmo.

Exemplo:
Imagine um sistema que precisa armazenar as notas de 1.000 alunos. Em vez de criar 1.000 variáveis diferentes, podemos utilizar um vetor:

notas = [7.5, 8.0, 6.5, 9.0, 7.0, ...]

Assim, os dados ficam organizados e podem ser acessados e processados facilmente.

2. Tipos de dados e estruturas
As estruturas de dados podem ser classificadas, de maneira geral, em:

Lineares: os elementos são organizados sequencialmente.

Vetores
Listas
Pilhas
Filas
Não lineares: os elementos possuem relações hierárquicas ou mais complexas.

Árvores
Grafos
Em Estrutura de Dados I, normalmente há bastante foco nas estruturas lineares, além de conceitos básicos de árvores, algoritmos e complexidade.

3. Vetores
Um vetor (array) é uma estrutura que armazena vários elementos, normalmente do mesmo tipo, em posições organizadas por índices.

Exemplo:

Índice:   0    1    2    3    4
Valor:   10   20   30   40   50

Para acessar o valor 30:

vetor[2]

Vantagens
Acesso rápido aos elementos.
Estrutura simples.
Fácil de percorrer utilizando laços de repetição.
Desvantagens
Em muitos casos, possui tamanho fixo.
Inserções e remoções no meio podem exigir deslocamento de elementos.
Exemplo prático: armazenar as notas dos alunos de uma turma.

4. Listas encadeadas
Uma lista encadeada é formada por elementos chamados nós. Cada nó armazena um dado e uma referência para outro nó.

Exemplo:

[10 | próximo] → [20 | próximo] → [30 | próximo] → NULL

Nesse exemplo, o primeiro nó contém 10, o segundo contém 20 e o terceiro contém 30.

Vantagens
Pode crescer e diminuir dinamicamente.
Inserções e remoções podem ser eficientes quando já temos a posição adequada.
Desvantagens
O acesso a um elemento específico pode ser mais lento.
Cada nó precisa armazenar referências adicionais.
Exemplo prático: uma lista de tarefas em que novas tarefas podem ser adicionadas ou removidas durante a execução.

5. Pilha — Stack
A pilha segue o princípio:

LIFO — Last In, First Out
Último a entrar, primeiro a sair.

Imagine uma pilha de pratos:

       [Prato 3] ← topo
       [Prato 2]
       [Prato 1]

Se colocarmos o prato 4:

       [Prato 4] ← topo
       [Prato 3]
       [Prato 2]
       [Prato 1]

O prato 4 será o primeiro a ser retirado.

Operações principais
Push: adiciona um elemento.
Pop: remove o elemento do topo.
Peek/Top: consulta o elemento do topo sem removê-lo.
Exemplo de aplicação
A função "Desfazer" (Ctrl + Z) de um editor pode utilizar uma pilha. Cada ação realizada é colocada na pilha e, ao solicitar o desfazer, a última ação é retirada primeiro.

6. Fila — Queue
A fila segue o princípio:

FIFO — First In, First Out
Primeiro a entrar, primeiro a sair.

Exemplo:

Entrada → [João] [Maria] [Pedro] → Saída

João chegou primeiro, portanto será atendido primeiro.

Operações principais
Enqueue: adiciona um elemento ao final.
Dequeue: remove o elemento do início.
Front: consulta o primeiro elemento.
Exemplo de aplicação
Um sistema de impressão pode utilizar uma fila:

Documento A → Documento B → Documento C

O documento A será impresso antes dos documentos B e C.
