Exercício 1 — 
Em C, o equivalente usando ponteiros seria:

#include <stdio.h>

int main() {
    int a[] = {10, 20, 30};
    int *b = a;

    a[3] = 40;

    printf("a: %d %d %d %d\n", a[0], a[1], a[2], a[3]);
    printf("b: %d %d %d %d\n", b[0], b[1], b[2], b[3]);

    printf("endereco de a: %p\n", (void *)a);
    printf("endereco de b: %p\n", (void *)b);

    return 0;
}

Atenção: esse exemplo acima tem um problema: o array a foi criado com espaço para apenas 3 elementos. Para adicionar o 40, devemos criar espaço para 4:

int a[4] = {10, 20, 30};

Então:

a: 10 20 30 40
b: 10 20 30 40
endereco de a: ...
endereco de b: ...

a e b apontam para a mesma região de memória.

Em C:

int *b = a;

faz b receber o endereço do primeiro elemento de a.

E se fosse uma cópia?
Em C não existe a.copy() como em Python. É necessário copiar os valores manualmente, por exemplo:

int a[4] = {10, 20, 30, 40};
int b[4];

for (int i = 0; i < 4; i++) {
    b[i] = a[i];
}

Agora a e b são arrays diferentes.

 Exercício 2 — Construindo uma cadeia
Em C, usamos uma struct e um ponteiro para o próximo nó:

#include <stdio.h>

typedef struct Node {
    char valor;
    struct Node *proximo;
} Node;

int main() {
    Node n1 = {'A', NULL};
    Node n2 = {'B', NULL};
    Node n3 = {'C', NULL};

    n1.proximo = &n2;
    n2.proximo = &n3;
    n3.proximo = NULL;

    Node *atual = &n1;

    while (atual != NULL) {
        printf("%c\n", atual->valor);
        atual = atual->proximo;
    }

    return 0;
}

A estrutura é:

n1             n2             n3
 ↓              ↓              ↓
 A      →       B      →       C      → NULL

Saída:

A
B
C

 Exercício 3 — Depuração
Em C:

Node n1 = {10, NULL};
Node n2 = {20, NULL};
Node n3 = {30, NULL};

n1.proximo = &n2;
n2.proximo = &n3;

Node *atual = &n1;

while (atual != NULL) {
    printf("%d\n", atual->valor);
}

Qual é o problema?
O ponteiro atual nunca muda.

Ele fica eternamente apontando para n1.

Qual linha deve ser acrescentada?
Dentro do while:

atual = atual->proximo;

Código corrigido:

while (atual != NULL) {
    printf("%d\n", atual->valor);
    atual = atual->proximo;
}

Saída:

10
20
30

Sistema de atendimento da clínica em C
Vamos criar três estruturas:

Paciente
   ↓
 Node
   ↓
FilaAtendimento

Paciente
typedef struct {
    char nome[50];
    int idade;
    char prioridade[20];
} Paciente;

Node
O Node guarda um paciente e um ponteiro para o próximo nó:

typedef struct Node {
    Paciente paciente;
    struct Node *proximo;
} Node;

Fila
A fila terá:

typedef struct {
    Node *inicio;
    Node *fim;
    int tamanho;
} FilaAtendimento;

Visualmente:

inicio                              fim
  ↓                                  ↓
 Ana → Bruno → Carlos → NULL


 Funcionalidades obrigatórias
Uma implementação completa em C:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    char prioridade[20];
} Paciente;

typedef struct Node {
    Paciente paciente;
    struct Node *proximo;
} Node;

typedef struct {
    Node *inicio;
    Node *fim;
    int tamanho;
} FilaAtendimento;


void inicializarFila(FilaAtendimento *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}


int estaVazia(FilaAtendimento *fila) {
    return fila->inicio == NULL;
}


void adicionar(FilaAtendimento *fila, Paciente paciente) {
    Node *novo = malloc(sizeof(Node));

    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }

    novo->paciente = paciente;
    novo->proximo = NULL;

    if (estaVazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }

    fila->tamanho++;
}


Paciente *atender(FilaAtendimento *fila) {
    if (estaVazia(fila)) {
        return NULL;
    }

    Node *removido = fila->inicio;
    fila->inicio = fila->inicio->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    Paciente *paciente = malloc(sizeof(Paciente));
    *paciente = removido->paciente;

    free(removido);

    fila->tamanho--;

    return paciente;
}


void listar(FilaAtendimento *fila) {
    Node *atual = fila->inicio;

    while (atual != NULL) {
        printf("%s - %d anos - %s\n",
               atual->paciente.nome,
               atual->paciente.idade,
               atual->paciente.prioridade);

        atual = atual->proximo;
    }
}


int tamanho(FilaAtendimento *fila) {
    return fila->tamanho;
}


int main() {
    FilaAtendimento fila;

    inicializarFila(&fila);

    Paciente p1 = {"Ana", 32, "Normal"};
    Paciente p2 = {"Bruno", 70, "Prioridade"};
    Paciente p3 = {"Carlos", 45, "Normal"};

    adicionar(&fila, p1);
    adicionar(&fila, p2);
    adicionar(&fila, p3);

    printf("Fila de pacientes:\n");
    listar(&fila);

    printf("\nQuantidade: %d\n", tamanho(&fila));

    Paciente *atendido = atender(&fila);

    if (atendido != NULL) {
        printf("\nAtendendo: %s\n", atendido->nome);
        free(atendido);
    }

    printf("\nFila depois do atendimento:\n");
    listar(&fila);

    return 0;
}

Saída
Fila de pacientes:
Ana - 32 anos - Normal
Bruno - 70 anos - Prioridade
Carlos - 45 anos - Normal

Quantidade: 3

Atendendo: Ana

Fila depois do atendimento:
Bruno - 70 anos - Prioridade
Carlos - 45 anos - Normal

23. Desafio — Atendimento prioritário
Agora precisamos fazer com que pacientes "Prioridade" sejam colocados antes dos pacientes "Normal".

Por exemplo:

Ana    - Normal
Bruno  - Normal
Carlos - Prioridade

Deve ficar:

inicio
  ↓
Carlos → Ana → Bruno → NULL
                    ↑
                   fim

A solução é verificar a prioridade no momento do adicionar().

Uma versão do método:

void adicionarPrioritario(FilaAtendimento *fila, Paciente paciente) {
    Node *novo = malloc(sizeof(Node));

    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }

    novo->paciente = paciente;
    novo->proximo = NULL;

    /* Fila vazia */
    if (estaVazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
        fila->tamanho++;
        return;
    }

    /* Paciente prioritário */
    if (strcmp(paciente.prioridade, "Prioridade") == 0) {

        novo->proximo = fila->inicio;
        fila->inicio = novo;

    } else {

        /* Paciente normal vai para o final */
        fila->fim->proximo = novo;
        fila->fim = novo;
    }

    fila->tamanho++;
}

Com:

Ana - Normal
Bruno - Normal
Carlos - Prioridade

a fila ficará:

Carlos → Ana → Bruno → NULL

E o atendimento será:

1. Carlos
2. Ana
3. Bruno

Observação: essa versão coloca um novo prioritário sempre no início. Se você quiser preservar a ordem de chegada entre vários prioritários, é necessário procurar o último prioritário e inserir depois dele.

24. Trabalho colaborativo
A estrutura em C pode ser representada assim:

Paciente
   ↓
Node
   ↓
Node
   ↓
Node

Ou:

Fila
 ↓
[Paciente A | *] → [Paciente B | *] → [Paciente C | NULL]

Os testes devem verificar:

fila vazia;
um paciente;
vários pacientes;
atendimento;
remoção do último paciente;
paciente prioritário.
Um erro proposital interessante para testar é esquecer:

atual = atual->proximo;

Isso provoca um loop infinito durante a listagem.

 Revisão
O programa final deve possuir:

✅ Paciente
✅ Node
✅ FilaAtendimento
✅ adicionar()
✅ atender()
✅ listar()
✅ estaVazia()
✅ tamanho()
✅ teste com pelo menos cinco pacientes
✅ tratamento de memória com malloc() e free()
✅ documentação de um erro encontrado
26. Checklist de aprendizagem em C
✅ Entendi endereço de memória.
✅ Sei o que é um ponteiro.
✅ Sei utilizar & para obter um endereço.
✅ Sei utilizar * para acessar o conteúdo apontado.
✅ Sei utilizar -> para acessar campos através de ponteiros.
✅ Entendi compartilhamento de endereços.
✅ Sei diferenciar ponteiro e cópia.
✅ Entendi objetos/estruturas na memória.
✅ Consigo criar um Node.
✅ Consigo conectar nós com ponteiros.
✅ Consigo percorrer uma lista encadeada.
✅ Consigo identificar um loop infinito.
✅ Consigo implementar uma fila encadeada.
✅ Sei utilizar malloc() e free().
✅ Consigo explicar minha solução.
27. Reflexão final
O que é uma referência em C?
Em C, normalmente trabalhamos com ponteiros para representar uma referência a uma região de memória. Um ponteiro armazena o endereço de outro objeto.

Qual a diferença entre b = a e b = a.copy()?
Em C, não temos copy() como em Python.

Quando fazemos:

int *b = a;

b aponta para o mesmo local de memória que a.

Para ter uma cópia independente, precisamos copiar os valores para outra variável ou array.

Por que uma estrutura encadeada precisa de referências?
Porque cada nó precisa guardar o endereço do próximo nó:

struct Node *proximo;

Assim podemos construir:

A → B → C → NULL

Qual erro você encontrou durante a depuração?
Um erro possível é esquecer de avançar o ponteiro:

atual = atual->proximo;

Sem essa instrução, atual continua apontando para o mesmo nó e o programa pode entrar em um loop infinito.
