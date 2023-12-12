#include <stdio.h>

struct Aluno
{
    char nome[50];
    char dataNascimento[11]; // Formato: DD/MM/AAAA
    float nota1;
    float nota2;
    float media;
};

float calcularMedia(struct Aluno aluno)
{
    return (aluno.nota1 + aluno.nota2) / 2;
}

void verificarAprovacao(struct Aluno aluno)
{
    if (aluno.media >= 7.0)
    {
        printf("%s está APROVADO!\n", aluno.nome);
    }
    else
    {
        printf("%s está REPROVADO.\n", aluno.nome);
    }
}

int main()
{
    const int numAlunos = 5;
    struct Aluno alunos[numAlunos];
    int i;

    // Preencher informações dos alunos
    for (i = 0; i < numAlunos; ++i)
    {
        printf("Cadastro do Aluno %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", alunos[i].nome);
        printf("Data de Nascimento (DD/MM/AAAA): ");
        scanf("%s", alunos[i].dataNascimento);
        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);
        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);

        // Calcular e atribuir a média ao aluno
        alunos[i].media = calcularMedia(alunos[i]);

        printf("\n");
    }

    // Imprimir média de cada aluno
    printf("\nMédia de cada aluno:\n");
    for (i = 0; i < numAlunos; i++)
    {
        printf("%s: %.2f\n", alunos[i].nome, alunos[i].media);
    }

    // Verificar aprovação de cada aluno
    printf("\nSituação de cada aluno:\n");
    for (i = 0; i < numAlunos; i++)
    {
        verificarAprovacao(alunos[i]);
    }

    return 0;
}