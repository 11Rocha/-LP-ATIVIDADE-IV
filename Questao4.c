#include <stdio.h>

struct ContaBancaria
{
    int numeroConta;
    char nomeTitular[50];
    float saldo;
    char tipoConta[20];
};

void depositar(struct ContaBancaria *conta, float valor)
{
    conta->saldo += valor;
    printf("Depósito de R$%.2f realizado com sucesso. Novo saldo: R$%.2f\n", valor, conta->saldo);
}

void sacar(struct ContaBancaria *conta, float valor)
{
    if (valor <= conta->saldo)
    {
        conta->saldo -= valor;
        printf("Saque de R$%.2f realizado com sucesso. Novo saldo: R$%.2f\n", valor, conta->saldo);
    }
    else
    {
        printf("Saldo insuficiente para saque. Saldo atual: R$%.2f\n", conta->saldo);
    }
}

void imprimirSaldo(struct ContaBancaria *conta)
{
    printf("Saldo atual da conta: R$%.2f\n", conta->saldo);
}

int main()
{
    struct ContaBancaria minhaConta;

    // Inicializar dados da conta
    printf("Informe o número da conta: ");
    scanf("%d", &minhaConta.numeroConta);

    printf("Informe o nome do titular: ");
    scanf("%s", minhaConta.nomeTitular);

    printf("Informe o saldo inicial: ");
    scanf("%f", &minhaConta.saldo);

    printf("Informe o tipo de conta (poupança ou corrente): ");
    scanf("%s", minhaConta.tipoConta);

    int escolha;
    float valor;

    do
    {
        // Menu de operações
        printf("\nMenu:\n");
        printf("1 - Depositar\n");
        printf("2 - Sacar\n");
        printf("3 - Imprimir Saldo\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            printf("Informe o valor para depósito: ");
            scanf("%f", &valor);
            depositar(&minhaConta, valor);
            break;
        case 2:
            printf("Informe o valor para saque: ");
            scanf("%f", &valor);
            sacar(&minhaConta, valor);
            break;
        case 3:
            imprimirSaldo(&minhaConta);
            break;
        case 4:
            printf("Saindo do programa. Até logo!\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 4);

    return 0;
}
