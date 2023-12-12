#include <stdio.h>
#include <string.h>
#include <locale.h>
#define TAM 3

struct lancandoContato
{
    char nome[250];
    char numero[150];
    char email[150];
};

void buscaContatoCad(struct lancandoContato contato[], char *contatoDesejado)
{

    int i;
    for (i = 0; i < TAM; i++)
    {
        if (strcmp(contato[i].nome, contatoDesejado) == 0)
        {
            printf("\nTelefone de %s:%s", contato[i].nome, contato[i].numero);
            break;
        }
        printf("\nContato não encontrado:");
    }
}
int main()
{
    setlocale(LC_ALL, "");

    int i;
    char contatoDesejado[250];
    struct lancandoContato contatos[3];

    for (i = 0; i < TAM; i++)
    {

        printf("Digite os Dados %dº Contato:\n", i + 1);
        printf("Nome:");
        gets(contatos[i].nome);
        printf("\nTelefone:\n");
        gets(contatos[i].numero);
        printf("E-mail:");
        gets(contatos[i].email);
    }
    printf("\nInforme o Contato Desejado para Buscar:");
    gets(contatoDesejado);

    buscaContatoCad(contatos, contatoDesejado);

    return 0;
}