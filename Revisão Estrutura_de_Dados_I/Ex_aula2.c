Exercício 1 — Soma de um vetor
#include <stdio.h>

int main() {
    int vetor[10];
    int i, soma = 0;
    float media;

    for (i = 0; i < 10; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &vetor[i]);
        soma = soma + vetor[i];
    }

    printf("\nNumeros digitados:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }

    media = soma / 10.0;

    printf("\n\nSoma: %d", soma);
    printf("\nMedia: %.2f\n", media);

    return 0;
}



Exercício 2 — Maior e menor
#include <stdio.h>

int main() {
    int vetor[10];
    int i;
    int maior, menor;
    int posMaior, posMenor;

    for (i = 0; i < 10; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    maior = vetor[0];
    menor = vetor[0];
    posMaior = 0;
    posMenor = 0;

    for (i = 1; i < 10; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
            posMaior = i;
        }

        if (vetor[i] < menor) {
            menor = vetor[i];
            posMenor = i;
        }
    }

    printf("\nMaior valor: %d", maior);
    printf("\nPosicao: %d", posMaior);

    printf("\nMenor valor: %d", menor);
    printf("\nPosicao: %d\n", posMenor);

    return 0;
}



Exercício 3 — Números pares
#include <stdio.h>

int main() {
    int vetor[20];
    int i, quantidade = 0, soma = 0;

    for (i = 0; i < 20; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nNumeros pares:\n");

    for (i = 0; i < 20; i++) {
        if (vetor[i] % 2 == 0) {
            printf("%d ", vetor[i]);
            quantidade++;
            soma = soma + vetor[i];
        }
    }

    printf("\n\nQuantidade de pares: %d", quantidade);
    printf("\nSoma dos pares: %d\n", soma);

    return 0;
}



Exercício 4 — Inversão de vetor
#include <stdio.h>

int main() {
    int vetor[10];
    int i, temp;

    for (i = 0; i < 10; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nVetor original:\n");

    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }

    for (i = 0; i < 5; i++) {
        temp = vetor[i];
        vetor[i] = vetor[9 - i];
        vetor[9 - i] = temp;
    }

    printf("\n\nVetor invertido:\n");

    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}


Exercício 5 — Matriz 3 × 3
#include <stdio.h>

int main() {
    int matriz[3][3];
    int i, j;
    int soma = 0;
    int maior;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Digite o valor [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    maior = matriz[0][0];

    printf("\nMatriz:\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", matriz[i][j]);

            soma = soma + matriz[i][j];

            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
        }
        printf("\n");
    }

    printf("\nSoma: %d", soma);
    printf("\nMaior valor: %d\n", maior);

    return 0;
}


Exercício 6 — Diagonal principal
#include <stdio.h>

int main() {
    int matriz[4][4];
    int i, j;
    int soma = 0;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("Digite o valor [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nDiagonal principal:\n");

    for (i = 0; i < 4; i++) {
        printf("%d ", matriz[i][i]);
        soma = soma + matriz[i][i];
    }

    printf("\n\nSoma da diagonal: %d\n", soma);

    return 0;
}


Exercício 7 — Matriz de notas
#include <stdio.h>

int main() {
    float notas[4][3];
    float media;
    int i, j;

    for (i = 0; i < 4; i++) {
        printf("\nAluno %d\n", i + 1);

        for (j = 0; j < 3; j++) {
            printf("Digite a nota %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }

    printf("\n--- MEDIA DOS ALUNOS ---\n");

    for (i = 0; i < 4; i++) {
        media = 0;

        for (j = 0; j < 3; j++) {
            media = media + notas[i][j];
        }

        media = media / 3;

        printf("Aluno %d: %.2f\n", i + 1, media);
    }

    return 0;
}




Exercício 8 — Struct Produto
#include <stdio.h>

struct Produto {
    char nome[50];
    int codigo;
    float preco;
    int quantidade;
};

int main() {
    struct Produto produtos[5];
    int i;
    float valor, maiorValor = 0;
    int posMaior = 0;

    for (i = 0; i < 5; i++) {
        printf("\nProduto %d\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]", produtos[i].nome);

        printf("Codigo: ");
        scanf("%d", &produtos[i].codigo);

        printf("Preco: ");
        scanf("%f", &produtos[i].preco);

        printf("Quantidade: ");
        scanf("%d", &produtos[i].quantidade);
    }

    printf("\n--- PRODUTOS ---\n");

    for (i = 0; i < 5; i++) {
        valor = produtos[i].preco * produtos[i].quantidade;

        printf("\nNome: %s\n", produtos[i].nome);
        printf("Codigo: %d\n", produtos[i].codigo);
        printf("Preco: %.2f\n", produtos[i].preco);
        printf("Quantidade: %d\n", produtos[i].quantidade);
        printf("Valor em estoque: %.2f\n", valor);

        if (valor > maiorValor) {
            maiorValor = valor;
            posMaior = i;
        }
    }

    printf("\n--- MAIOR VALOR EM ESTOQUE ---\n");
    printf("Produto: %s\n", produtos[posMaior].nome);
    printf("Valor: %.2f\n", maiorValor);

    return 0;
}




Exercício 9 — Struct Aluno
#include <stdio.h>

struct Aluno {
    char nome[50];
    int idade;
    float nota1;
    float nota2;
    float nota3;
};

int main() {
    struct Aluno alunos[5];
    int i;
    float media;
    float maiorMedia = 0;
    int posMaior = 0;
    int aprovados = 0;
    int reprovados = 0;

    for (i = 0; i < 5; i++) {
        printf("\nAluno %d\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);

        printf("Idade: ");
        scanf("%d", &alunos[i].idade);

        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);

        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);

        printf("Nota 3: ");
        scanf("%f", &alunos[i].nota3);

        media = (alunos[i].nota1 + alunos[i].nota2 +
                 alunos[i].nota3) / 3;

        printf("Media: %.2f\n", media);

        if (media >= 7) {
            printf("Situacao: Aprovado\n");
            aprovados++;
        } else {
            printf("Situacao: Reprovado\n");
            reprovados++;
        }

        if (i == 0 || media > maiorMedia) {
            maiorMedia = media;
            posMaior = i;
        }
    }

    printf("\n--- RESULTADO FINAL ---\n");
    printf("Quantidade de aprovados: %d\n", aprovados);
    printf("Quantidade de reprovados: %d\n", reprovados);

    printf("\nAluno com maior media: %s\n",
           alunos[posMaior].nome);
    printf("Maior media: %.2f\n", maiorMedia);

    return 0;
}

Exercício 10 — Sistema Integrado
#include <stdio.h>

struct Funcionario {
    char nome[50];
    int idade;
    char cargo[50];
    float salario;
};

int main() {
    struct Funcionario funcionarios[10];
    int i, maior = 0;
    float soma = 0, media;

    // Cadastro
    for (i = 0; i < 10; i++) {
        printf("\n--- Funcionario %d ---\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]", funcionarios[i].nome);

        printf("Idade: ");
        scanf("%d", &funcionarios[i].idade);

        printf("Cargo: ");
        scanf(" %[^\n]", funcionarios[i].cargo);

        printf("Salario: ");
        scanf("%f", &funcionarios[i].salario);

        soma = soma + funcionarios[i].salario;

        if (i > 0 &&
            funcionarios[i].salario > funcionarios[maior].salario) {
            maior = i;
        }
    }

    // Média salarial
    media = soma / 10;

    // Listar funcionários
    printf("\n--- TODOS OS FUNCIONARIOS ---\n");

    for (i = 0; i < 10; i++) {
        printf("\nNome: %s\n", funcionarios[i].nome);
        printf("Idade: %d\n", funcionarios[i].idade);
        printf("Cargo: %s\n", funcionarios[i].cargo);
        printf("Salario: R$ %.2f\n", funcionarios[i].salario);
    }

    // Maior salário
    printf("\n--- MAIOR SALARIO ---\n");
    printf("Nome: %s\n", funcionarios[maior].nome);
    printf("Salario: R$ %.2f\n", funcionarios[maior].salario);

    // Média
    printf("\nMedia salarial: R$ %.2f\n", media);

    // Acima da média
    printf("\n--- FUNCIONARIOS ACIMA DA MEDIA ---\n");

    for (i = 0; i < 10; i++) {
        if (funcionarios[i].salario > media) {
            printf("%s - R$ %.2f\n",
                   funcionarios[i].nome,
                   funcionarios[i].salario);
        }
    }

    return 0;
}
