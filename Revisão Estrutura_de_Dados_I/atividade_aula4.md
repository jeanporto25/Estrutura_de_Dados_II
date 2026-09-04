1. Exercício – Simulador "Desfazer"ObjetivoImplementar uma pilha para armazenar as ações realizadas em um editor de texto. A função "desfazer" deve sempre remover a última ação realizada.CódigoPython# Exercício 1 - Simulador "Desfazer"
# Estrutura utilizada: PILHA
# Princípio: LIFO (Last In, First Out)

pilha = []

while True:
    print("\n===== SIMULADOR DESFAZER =====")
    print("1 - Digitar")
    print("2 - Apagar")
    print("3 - Substituir")
    print("4 - Desfazer")
    print("5 - Sair")

    opcao = input("Escolha uma opção: ")

    if opcao == "1":
        texto = input("Digite o texto: ")
        pilha.append(("Digitar", texto))
        print("Ação registrada com sucesso.")

    elif opcao == "2":
        texto = input("Informe o texto apagado: ")
        pilha.append(("Apagar", texto))
        print("Ação registrada com sucesso.")

    elif opcao == "3":
        antigo = input("Texto antigo: ")
        novo = input("Texto novo: ")
        pilha.append(("Substituir", antigo, novo))
        print("Ação registrada com sucesso.")

    elif opcao == "4":
        if pilha:
            acao = pilha.pop()
            print("Ação desfeita:", acao)
        else:
            print("Não existem ações para desfazer.")

    elif opcao == "5":
        print("Programa encerrado.")
        break

    else:
        print("Opção inválida.")
Justificativa da ArquiteturaFoi escolhida uma Pilha (Stack) porque a operação "desfazer" obedece ao princípio LIFO (Last In, First Out): a última ação registrada é a primeira a ser revertida. Em Python, a estrutura list atende à demanda com alta performance, utilizando append() para inserção no topo e pop() para remoção do topo, ambas em tempo constante $O(1)$.2. Exercício – Sistema de ImpressãoObjetivoImplementar uma fila para controlar documentos enviados para impressão. O documento que entrar primeiro na fila deve ser o primeiro a ser impresso.CódigoPython# Exercício 2 - Sistema de Impressão
# Estrutura utilizada: FILA
# Princípio: FIFO (First In, First Out)

from collections import deque

fila = deque()

while True:
    print("\n===== SISTEMA DE IMPRESSÃO =====")
    print("1 - Adicionar documento")
    print("2 - Imprimir documento")
    print("3 - Mostrar fila")
    print("4 - Sair")

    opcao = input("Escolha uma opção: ")

    if opcao == "1":
        documento = input("Nome do documento: ")
        fila.append(documento)
        print("Documento adicionado à fila.")

    elif opcao == "2":
        if fila:
            documento = fila.popleft()
            print("Imprimindo:", documento)
        else:
            print("Não existem documentos na fila.")

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
Justificativa da ArquiteturaA estrutura de Fila (Queue) foi selecionada para garantir a ordem FIFO (First In, First Out). Utilizou-se o collections.deque porque ele provê operações de remoção no início (popleft()) em tempo $O(1)$. O uso de uma lista nativa com pop(0) exigiria o deslocamento de todos os elementos restantes na memória, resultando em complexidade $O(n)$.3. Desafio Master 🚀 – Triagem HospitalarObjetivoCriar um sistema de gerenciamento de pacientes utilizando uma fila que suporte dois níveis de prioridade:Paciente normal: entra no final da fila.Paciente prioritário: entra no início da fila.CódigoPython# Desafio Master - Triagem Hospitalar
# Estrutura utilizada: deque
# Arquitetura: Fila com prioridade de inserção

from collections import deque

fila = deque()

while True:
    print("\n===== TRIAGEM HOSPITALAR =====")
    print("1 - Adicionar paciente normal")
    print("2 - Adicionar paciente prioritário")
    print("3 - Atender paciente")
    print("4 - Mostrar fila")
    print("5 - Sair")

    opcao = input("Escolha uma opção: ")

    if opcao == "1":
        nome = input("Nome do paciente: ")
        fila.append(nome)
        print("Paciente normal adicionado ao final da fila.")

    elif opcao == "2":
        nome = input("Nome do paciente prioritário: ")
        fila.appendleft(nome)
        print("Paciente prioritário adicionado ao início da fila.")

    elif opcao == "3":
        if fila:
            paciente = fila.popleft()
            print("Atendendo paciente:", paciente)
        else:
            print("Não existem pacientes aguardando.")

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
Justificativa da ArquiteturaO collections.deque (fila de duas extremidades) permite inserção e remoção eficientes em ambas as pontas em $O(1)$. Isso permite inserir pacientes prioritários na frente com appendleft() e normais ao fundo com append(), mantendo o consumo do topo para atendimento (popleft()) sem a necessidade de reordenar a estrutura.Trilha Python (Exercícios de Fixação)01 | A Pilha MatemáticaPythonclass PilhaMatematica:
    def __init__(self):
        self.itens = []

    def push(self, valor: int):
        """Insere um número inteiro no topo da pilha."""
        self.itens.append(valor)

    def esvaziar_e_somar(self) -> int:
        """Esvazia a pilha iterativamente e retorna a soma dos elementos removidos."""
        soma = 0
        while self.itens:
            soma += self.itens.pop()
        return soma

# Exemplo de execução:
pilha = PilhaMatematica()
pilha.push(10)
pilha.push(20)
pilha.push(30)

resultado = pilha.esvaziar_e_somar()
print(f"Soma total dos elementos: {resultado}")  # Saída: 60
Justificativa da Arquitetura: A list nativa foi escolhida porque os métodos append() e pop() no topo operam em tempo constante $O(1)$, garantindo máxima eficiência e uso de memória sem dependências externas.02 | O Call CenterPythonfrom collections import deque

class CallCenter:
    def __init__(self):
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
Justificativa da Arquitetura: O collections.deque foi escolhido porque sua remoção no início (popleft()) é $O(1)$. Em listas comuns, remover o primeiro elemento (pop(0)) custa $O(n)$ por deslocar toda a lista na memória.Trilha C / Baixo Nível (Exercícios de Fixação)01 | Pilha via Array EstáticoC#include <stdio.h>
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
Justificativa da Arquitetura: A alocação em array estático com ponteiro top reserva memória diretamente na pilha de execução (stack) em tempo de compilação, garantindo operações de push e pop em $O(1)$ sem o custo computacional de alocação dinâmica (malloc/free).02 | Fila CircularC#include <stdio.h>
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
