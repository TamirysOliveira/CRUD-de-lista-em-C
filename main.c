//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h> 

//declaração de constantes
#define FALSE 0
#define TRUE 1

//declaração de tipos
typedef struct No
{
    int valor; //no caso, representando uma lista de inteiros
    struct No *prox;
} TNo;

typedef TNo *TLista;

//protótipos das funções
int inserir(TLista *L, int numero);
int remover(TLista *L, int numero);
int alterar(TLista L, int velho, int novo);
int buscar(TLista L, int numero);
void exibir(TLista L);

int menu();

//main
void main()
{
    //declaração de variáveis
    TLista L1 = NULL; //lista inicialmente vazia
    int opcao, num1, num2, quant;

    do
    {
        //exibindo o menu ao usuário
        opcao = menu();

        switch (opcao)
        {
        //inserção
        case 1:
            printf("Entre com o número a ser inserido: ");
            scanf("%d", &num1);

            if (inserir(&L1, num1) == TRUE) //ou apenas inserir (&L1, num1)
            {
                printf("O numero %d foi inserido na lista!\n", num1);
            }
            else
            {
                printf("ERRO: o numero %d nao foi inserido na lista!\n", num1);
            }
            break;

        //remoção
        case 2:
            printf("Entre com o número a ser removido: ");
            scanf("%d", &num1);

            quant = remover(&L1, num1);
            if (quant != 0)
            {
                printf("%d ocorrencias do numero %d removidas da lista!\n", quant, num1);
            }
            else
            {
                printf("ERRO: o numero %d não encontra-se na lista!\n", num1);
            }
            break;

        //alterar
        case 3:
            printf("Entre com o número a ser alterado: ");
            scanf("%d", &num1);

            printf("Entre com o novo elemento: ");
            scanf("%d", &num2);

            quant = alterar(L1, num1, num2);
            if (quant != 0)
            {
                printf("%d ocorrencias de %d alteradas por %d!\n", quant, num1, num2);
            }
            else
            {
                printf("ERRO: o numero %d não encontra-se na lista!\n", num1);
            }
            break;

        //pesquisar
        case 4:
            printf("Entre com o número a ser buscado: ");
            scanf("%d", &num1);

            if (buscar(L1, num1) == TRUE) //ou    if (buscar (L1, num1))
            {
                printf("O numero %d foi encontrado na lista!\n", num1);
            }
            else
            {
                printf("O numero %d nao foi encontrado na lista!\n", num1);
            }
            break;

        //exibir
        case 5:
            exibir(L1);
            break;

        //saída
        case 6:
            printf("Fim do programa!\n");
            break;

        //opção inválida
        default:
            printf("Opção inválida! Tente novamente.\n");
        }

        system("pause");
    } while (opcao != 6);
}

//implementações das funções
int inserir(TLista *L, int numero)
{
    //declaração de variáveis
    TLista aux;

    //Passo1: alocar memória para o novo elemento
    aux = (TLista)malloc(sizeof(TNo));

    //testar se a memória foi alocada
    if (aux == NULL) //if (!aux)
    {
        return FALSE;
    }
    else
    {
        //Passo2: Armazenar na memória alocada o novo valor
        aux->valor = numero;

        //Passo3: Fazer o prox do novo nó apontar para o antigo primeiro elemento da lista
        aux->prox = *L;

        //Passo4: Mandar L apontar para o novo nó
        *L = aux;

        //retornando sucesso
        return TRUE;
    }
}
