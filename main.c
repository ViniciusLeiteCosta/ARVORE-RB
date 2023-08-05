#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rb.h"

int main() {
    No *raiz = NULL;
    int opcao, valor;

    do {
        printf("\nOPCOES:\n");
        printf("1 - INSERIR\n");
        printf("2 - PREORDER\n");
        printf("3 - REMOVER\n");
        printf("99 - SAIR\n");
        printf("OPCAO: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("DIGITE O VALOR A SER INSERIDO: ");
                scanf("%d", &valor);
                inserir(&raiz, valor);
                break;
            case 2:
                printf("PREORDER - RB:\n");
                preorder_rb(raiz);
                printf("\n");
                break;
            case 3:
                printf("DIGITE O VALOR A SER REMOVIDO: ");
                scanf("%d", &valor);
                removerNo(&raiz, valor);
                break;
            case 99:
                printf("----- FIM DO PROGRAMA -----\n");
                break;
            default:
                printf("OPCAO INVALIDA.\n");
        }
    } while (opcao != 99);

    return 0;
}
