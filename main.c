#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rb.h"

int main() {
    No *raiz = NULL;

    // Inserindo elementos na árvore
    inserir(&raiz, 10);
    inserir(&raiz, 20);
    inserir(&raiz, 5);
    inserir(&raiz, 15);
    inserir(&raiz, 25);
    inserir(&raiz, 3);
    inserir(&raiz, 7);

    printf("Árvore vermelho-preta (pré-ordem):\n");
    preorder_rb(raiz);
    printf("\n");

    // Removendo elementos da árvore
    removerNo(&raiz, 5);
    removerNo(&raiz, 20);

    printf("Árvore vermelho-preta após remoções (pré-ordem):\n");
    preorder_rb(raiz);
    printf("\n");


    return 0;
}
