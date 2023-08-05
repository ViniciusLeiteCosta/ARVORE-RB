#ifndef RB_H
#define RB_H

//CORES
typedef enum Cor {
    VERMELHO,
    PRETO
} Cor;

//ESTRUTURA NO
typedef struct No {
    int dado;
    Cor cor;
    struct No* pai;
    struct No* esq;
    struct No* dir;
} No;

No* criarNo(int dado);
void inserir(No** raiz, int dado);
void preorder_rb(No* no);
void removerNo(No** raiz, int dado);
void corrigirDuploPreto(No** raiz, No* x);

#endif
