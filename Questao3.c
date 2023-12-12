#include <stdio.h>
#include <stdlib.h>

struct Produto
{
    char nome[50];
    float preco;
    int quantidadeEstoque;
};

void realizarCompra(struct Produto *produto)
{
    int quantidadeCompra;
    printf("Digite a quantidade que deseja comprar: ");
    scanf("%d", &quantidadeCompra);

    if (quantidadeCompra > 0 && quantidadeCompra <= produto->quantidadeEstoque)
    {
        float valorCompra = quantidadeCompra * produto->preco;
        printf("Compra realizada com sucesso! Valor total: R$%.2f\n", valorCompra);

        // Atualizar quantidade em estoque
        produto->quantidadeEstoque -= quantidadeCompra;
    }
    else
    {
        printf("Quantidade inválida ou insuficiente em estoque.\n");
    }
}

void consultarEstoque(struct Produto *produto)
{
    printf("Nome do Produto: %s\n", produto->nome);
    printf("Quantidade em Estoque: %d\n", produto->quantidadeEstoque);
    printf("Preço por unidade: R$%.2f\n", produto->preco);
    printf("Valor total em Estoque: R$%.2f\n", produto->quantidadeEstoque * produto->preco);
}

int main()
{
    struct Produto meuProduto;

    // Inicializar os dados do produto
    printf("Informe o nome do produto: ");
    scanf("%s", meuProduto.nome);

    printf("Informe o preço do produto: ");
    scanf("%f", &meuProduto.preco);

    printf("Informe a quantidade em estoque: ");
    scanf("%d", &meuProduto.quantidadeEstoque);

    int escolha;
    do
    {
        // Menu de opções
        printf("\nMenu:\n");
        printf("1 - Realizar uma compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            realizarCompra(&meuProduto);
            break;
        case 2:
            consultarEstoque(&meuProduto);
            break;
        case 3:
            printf("Saindo do programa. Até logo!\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 3);

    return 0;
}