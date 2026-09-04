1. Exercício – Simulador "Desfazer"
Objetivo
Implementar uma pilha para armazenar as ações realizadas em um editor de texto. A função "desfazer" deve sempre remover a última ação realizada.

Código
 
# Exercício 1 - Simulador "Desfazer"
# Estrutura utilizada: PILHA
# Princípio: LIFO (Last In, First Out)
 
# Criamos uma lista para representar a pilha de ações.
pilha = []
 
while True:
    print("\n===== SIMULADOR DESFAZER =====")
    print("1 - Digitar")
    print("2 - Apagar")
    print("3 - Substituir")
    print("4 - Desfazer")
    print("5 - Sair")
 
    opcao = input("Escolha uma opção: ")
 
    # Adiciona uma ação de digitação na pilha.
    if opcao == "1":
        texto = input("Digite o texto: ")
 
        # append() adiciona a ação no topo da pilha.
        pilha.append(("Digitar", texto))
 
        print("Ação registrada com sucesso.")
 
    # Adiciona uma ação de apagar na pilha.
    elif opcao == "2":
        texto = input("Informe o texto apagado: ")
 
        pilha.append(("Apagar", texto))
 
        print("Ação registrada com sucesso.")
 
    # Adiciona uma ação de substituição na pilha.
    elif opcao == "3":
        antigo = input("Texto antigo: ")
        novo = input("Texto novo: ")
 
        pilha.append(("Substituir", antigo, novo))
 
        print("Ação registrada com sucesso.")
 
    # Desfaz a última ação realizada.
    elif opcao == "4":
 
        if pilha:
            # pop() remove o último elemento inserido.
            acao = pilha.pop()
 
            print("Ação desfeita:", acao)
 
        else:
            print("Não existem ações para desfazer.")
 
    elif opcao == "5":
        print("Programa encerrado.")
        break
 
    else:
        print("Opção inválida.")
 
 
Justificativa da arquitetura
Foi escolhida uma Pilha (Stack) porque o funcionamento da operação "desfazer" segue o princípio LIFO (Last In, First Out).

Ou seja, a última ação realizada deve ser a primeira ação desfeita.

Em Python, a estrutura list é adequada para essa situação, utilizando:

append() → adiciona uma ação;
pop() → remove a última ação.
Essa arquitetura é simples, eficiente e representa diretamente o comportamento esperado pelo desafio.



2. Exercício – Sistema de Impressão
Objetivo
Implementar uma fila para controlar documentos enviados para impressão.

O documento que entrar primeiro na fila deve ser o primeiro a ser impresso.

Código
 
# Exercício 2 - Sistema de Impressão
# Estrutura utilizada: FILA
# Princípio: FIFO (First In, First Out)
 
from collections import deque
 
# Criamos uma fila utilizando deque.
fila = deque()
 
while True:
    print("\n===== SISTEMA DE IMPRESSÃO =====")
    print("1 - Adicionar documento")
    print("2 - Imprimir documento")
    print("3 - Mostrar fila")
    print("4 - Sair")
 
    opcao = input("Escolha uma opção: ")
 
    # Adiciona um novo documento ao final da fila.
    if opcao == "1":
        documento = input("Nome do documento: ")
 
        # append() adiciona o documento no final da fila.
        fila.append(documento)
 
        print("Documento adicionado à fila.")
 
    # Remove e imprime o primeiro documento da fila.
    elif opcao == "2":
 
        if fila:
            # popleft() remove o primeiro elemento da fila.
            documento = fila.popleft()
 
            print("Imprimindo:", documento)
 
        else:
            print("Não existem documentos na fila.")
 
    # Exibe todos os documentos aguardando impressão.
    elif opcao == "3":
 
        if fila:
            print("\nDocumentos aguardando impressão:")
 
            for documento in fila:
                print("-", documento)
 
        else:
            print("A fila está vazia.")
 
    elif opcao == "4":
        print("Sistema encerrado.")
        break
 
    else:
        print("Opção inválida.")
 
Justificativa da arquitetura
Foi escolhida a estrutura Fila (Queue) porque o sistema de impressão precisa seguir o princípio FIFO (First In, First Out).

Isso significa:

O primeiro documento que entrar na fila será o primeiro documento a ser impresso.

Foi utilizada a estrutura deque da biblioteca collections, pois ela permite realizar inserções e remoções nas extremidades de forma eficiente.

Os principais métodos utilizados foram:

append() → coloca o documento no final da fila;
popleft() → retira o documento mais antigo da fila.
A escolha do deque é mais adequada do que utilizar uma lista com pop(0), pois evita deslocamentos desnecessários dos demais elementos.



3. Desafio Master 🚀 – Triagem Hospitalar
Objetivo
Criar um sistema de gerenciamento de pacientes utilizando uma fila.

Existem dois tipos de atendimento:

Paciente normal: entra no final da fila;
Paciente prioritário: entra no início da fila.
Código
 
# Desafio Master - Triagem Hospitalar
# Estrutura utilizada: deque
# Arquitetura: fila com prioridade de inserção
 
from collections import deque
 
# Criamos a fila de atendimento.
fila = deque()
 
while True:
    print("\n===== TRIAGEM HOSPITALAR =====")
    print("1 - Adicionar paciente normal")
    print("2 - Adicionar paciente prioritário")
    print("3 - Atender paciente")
    print("4 - Mostrar fila")
    print("5 - Sair")
 
    opcao = input("Escolha uma opção: ")
 
    # Paciente normal entra no final da fila.
    if opcao == "1":
 
        nome = input("Nome do paciente: ")
 
        # append() adiciona o paciente no final.
        fila.append(nome)
 
        print("Paciente normal adicionado ao final da fila.")
 
    # Paciente prioritário entra no início da fila.
    elif opcao == "2":
 
        nome = input("Nome do paciente prioritário: ")
 
        # appendleft() adiciona diretamente no início.
        fila.appendleft(nome)
 
        print("Paciente prioritário adicionado ao início da fila.")
 
    # Realiza o atendimento do primeiro paciente.
    elif opcao == "3":
 
        if fila:
 
            # popleft() remove o primeiro paciente da fila.
            paciente = fila.popleft()
 
            print("Atendendo paciente:", paciente)
 
        else:
            print("Não existem pacientes aguardando.")
 
    # Mostra a fila atual.
    elif opcao == "4":
 
        if fila:
 
            print("\n===== FILA DE ATENDIMENTO =====")
 
            posicao = 1
 
            for paciente in fila:
                print(posicao, "-", paciente)
                posicao += 1
 
        else:
            print("A fila está vazia.")
 
    elif opcao == "5":
        print("Sistema encerrado.")
        break
 
    else:
        print("Opção inválida.")
 
Justificativa da arquitetura
Para esse desafio foi escolhida a estrutura deque, pois ela permite trabalhar com as duas extremidades da fila.

A arquitetura atende diretamente às regras de negócio:

append() → adiciona pacientes normais no final;
appendleft() → adiciona pacientes prioritários no início;
popleft() → remove o paciente que está na frente para atendimento.
A escolha do deque é importante porque não é necessário retirar todos os elementos da fila para inserir um paciente prioritário. O método appendleft() permite fazer essa operação diretamente.

Exemplo
Se a fila receber:

João → Normal
Maria → Normal
Carlos → Prioridade
Pedro → Normal
Ana → Prioridade
 
A fila ficará:

Ana
Carlos
João
Maria
Pedro
 
Assim, os pacientes prioritários são atendidos primeiro, conforme a regra estabelecida.



Trilha Python



01  A Pilha Matemática

Python



class PilhaMatematica:
    def __init__(self):
        # A lista nativa do Python é usada como estrutura base da pilha
        self.itens = []

    def push(self, valor: int):
        """Insere um número inteiro no topo da pilha."""
        self.itens.append(valor)

    def esvaziar_e_somar(self) -> int:
        """Esvazia a pilha iterativamente e retorna a soma dos elementos removidos."""
        soma = 0
        while self.itens:
            # pop() remove e retorna o elemento do topo (último inserido)
            soma += self.itens.pop()
        return soma

# Exemplo de execução:
pilha = PilhaMatematica()
pilha.push(10)
pilha.push(20)
pilha.push(30)

resultado = pilha.esvaziar_e_somar()
print(f"Soma total dos elementos: {resultado}")  # Saída: 60

Justificativa da Arquitetura: A list nativa foi escolhida porque os métodos append() e pop() no topo operam em tempo constante $O(1)$, garantindo máxima eficiência e uso de memória sem dependências externas.


02  O Call Center

Python



from collections import deque

class CallCenter:
    def __init__(self):
        # deque é otimizado para operações nas duas extremidades
        self.fila = deque()

    def adicionar_cliente(self, nome: str):
        """Adiciona um cliente ao fim da fila de espera."""
        self.fila.append(nome)
        print(f"Cliente '{nome}' entrou na fila.")

    def chamar_proximo(self) -> str:
        """Atende e remove o primeiro cliente da fila."""
        if self.fila:
            cliente = self.fila.popleft()
            print(f"Chamando para atendimento: {cliente}")
            return cliente
        print("A fila está vazia.")
        return None

# Exemplo de execução:
call_center = CallCenter()
call_center.adicionar_cliente("Alice")
call_center.adicionar_cliente("Bruno")

call_center.chamar_proximo()  # Atende Alice
call_center.chamar_proximo()  # Atende Bruno
call_center.chamar_proximo()  # Fila vazia
Justificativa da Arquitetura: O collections.deque foi escolhido porque sua remoção no início (popleft()) é $O(1)$. Em listas comuns, remover o primeiro elemento (pop(0)) custa $O(n)$ por deslocar toda a lista na memória.


Trilha C (Baixo Nível)

01 | Pilha via Array Estático

C



#include <stdio.h>
#define TAMANHO_MAX 100

typedef struct {
    int dados[TAMANHO_MAX];
    int top; // Índice manual do topo da pilha
} PilhaEstatica;

void inicializar(PilhaEstatica *p) {
    p->top = -1; // -1 indica que a pilha está vazia
}

void push(PilhaEstatica *p, int valor) {
    if (p->top >= TAMANHO_MAX - 1) {
        printf("Erro: Estouro de pilha (Stack Overflow)\n");
        return;
    }
    p->top++;
    p->dados[p->top] = valor;
}

int pop(PilhaEstatica *p) {
    if (p->top < 0) {
        printf("Erro: Pilha vazia (Stack Underflow)\n");
        return -1;
    }
    int valor = p->dados[p->top];
    p->top--;
    return valor;
}

int main() {
    PilhaEstatica pilha;
    inicializar(&pilha);

    push(&pilha, 5);
    push(&pilha, 15);

    printf("Removido: %d\n", pop(&pilha)); // Saída: 15
    printf("Removido: %d\n", pop(&pilha)); // Saída: 5

    return 0;
}
Justificativa da Arquitetura: A alocação em array estático com ponteiro top reserva memória diretamente na pilha de execução (stack) em tempo de compilação, garantindo operações de push e pop em $O(1)$ sem o custo computacional de alocação dinâmica (malloc/free).
02 | Fila Circular

C



#include <stdio.h>
#define CAPACIDADE 5

typedef struct {
    int dados[CAPACIDADE];
    int front;          // Aponta para o elemento a ser removido
    int rear;           // Aponta para a posição da última inserção
    int tamanho_atual;  // Rastreia o total de elementos armazenados
} FilaCircular;

void inicializar(FilaCircular *f) {
    f->front = 0;
    f->rear = -1;
    f->tamanho_atual = 0;
}

void enqueue(FilaCircular *f, int valor) {
    if (f->tamanho_atual == CAPACIDADE) {
        printf("Erro: Fila cheia\n");
        return;
    }
    // Aritmética modular permite que o índice retorne ao início
    f->rear = (f->rear + 1) % CAPACIDADE;
    f->dados[f->rear] = valor;
    f->tamanho_atual++;
}

int dequeue(FilaCircular *f) {
    if (f->tamanho_atual == 0) {
        printf("Erro: Fila vazia\n");
        return -1;
    }
    int valor = f->dados[f->front];
    f->front = (f->front + 1) % CAPACIDADE;
    f->tamanho_atual--;
    return valor;
}

int main() {
    FilaCircular fila;
    inicializar(&fila);

    enqueue(&fila, 10);
    enqueue(&fila, 20);

    printf("Desenfileirado: %d\n", dequeue(&fila)); // Saída: 10
    printf("Desenfileirado: %d\n", dequeue(&fila)); // Saída: 20

    return 0;
}
Justificativa da Arquitetura: O uso de aritmética modular (% CAPACIDADE) permite reutilizar posições do array liberadas por remoções anteriores em $O(1)$, eliminando o reordenamento de elementos na memória e reaproveitando 100% da estrutura.






