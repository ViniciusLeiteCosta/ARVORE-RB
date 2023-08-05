#include "rb.h"
#include <stdio.h>
#include <stdlib.h>

No* criarNo(int dado) {

    No* criarNo(int dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->cor = VERMELHO; // Novos nós sempre são vermelhos
    novoNo->pai = NULL;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;

}

// ROTAÇÃO À ESQUERDA
void rotacaoEsq(No** raiz, No* x) {
    No* y = x->dir;
    x->dir = y->esq;
    if (y->esq != NULL)
        y->esq->pai = x;
    y->pai = x->pai;
    if (x->pai == NULL)
        *raiz = y;
    else if (x == x->pai->esq)
        x->pai->esq = y;
    else
        x->pai->dir = y;
    y->esq = x;
    x->pai = y;
}

// ROTAÇÃO À DIREITA
void rotacaoDir(No** raiz, No* x) {
    No* y = x->esq;
    x->esq = y->dir;
    if (y->dir != NULL)
        y->dir->pai = x;
    y->pai = x->pai;
    if (x->pai == NULL)
        *raiz = y;
    else if (x == x->pai->esq)
        x->pai->esq = y;
    else
        x->pai->dir = y;
    y->dir = x;
    x->pai = y;
}

//INSERIR
void inserir(No** raiz, int dado) {
    No* novoNo = criarNo(dado);
    inserirNo(raiz, novoNo);
    corrigirInsercao(raiz, novoNo);
}

void inserirNo(No** raiz, No* novoNo) {
    No* pai = NULL;
    No* atual = *raiz;

    while (atual != NULL) {
        pai = atual;
        if (novoNo->dado < atual->dado)
            atual = atual->esq;
        else
            atual = atual->dir;
    }

    novoNo->pai = pai;

    if (pai == NULL)
        *raiz = novoNo;
    else if (novoNo->dado < pai->dado)
        pai->esq = novoNo;
    else
        pai->dir = novoNo;

    novoNo->cor = VERMELHO; // Novo nó é sempre inserido como vermelho
}

//CORREÇÃO
void corrigirInsercao(No** raiz, No* novoNo) {
    while (novoNo->pai != NULL && novoNo->pai->cor == VERMELHO) {
        if (novoNo->pai == novoNo->pai->pai->esq) {
            No* tio = novoNo->pai->pai->dir;

            // Caso 1: Tio é vermelho
            if (tio != NULL && tio->cor == VERMELHO) {
                novoNo->pai->cor = PRETO;
                tio->cor = PRETO;
                novoNo->pai->pai->cor = VERMELHO;
                novoNo = novoNo->pai->pai;
            } else {
                // Caso 2: Tio é preto e novo nó é filho direito
                if (novoNo == novoNo->pai->dir) {
                    novoNo = novoNo->pai;
                    rotacaoEsquerda(raiz, novoNo);
                }
                // Caso 3: Tio é preto e novo nó é filho esquerdo
                novoNo->pai->cor = PRETO;
                novoNo->pai->pai->cor = VERMELHO;
                rotacaoDireita(raiz, novoNo->pai->pai);
            }
        } else {
            No* tio = novoNo->pai->pai->esq;

            // Caso 1: Tio é vermelho
            if (tio != NULL && tio->cor == VERMELHO) {
                novoNo->pai->cor = PRETO;
                tio->cor = PRETO;
                novoNo->pai->pai->cor = VERMELHO;
                novoNo = novoNo->pai->pai;
            } else {
                // Caso 2: Tio é preto e novo nó é filho esquerdo
                if (novoNo == novoNo->pai->esq) {
                    novoNo = novoNo->pai;
                    rotacaoDireita(raiz, novoNo);
                }
                // Caso 3: Tio é preto e novo nó é filho direito
                novoNo->pai->cor = PRETO;
                novoNo->pai->pai->cor = VERMELHO;
                rotacaoEsquerda(raiz, novoNo->pai->pai);
            }
        }
    }
    (*raiz)->cor = PRETO; // Garantir que a raiz permaneça preta
}

//PREORDER
void preorder_rb(No* no) {

    if (no == NULL)
        return;

    char corNo[10];
    if (no->cor == VERMELHO)
        strcpy(corNo, "Vermelho");
    else
        strcpy(corNo, "Preto");

    printf("[%d %s] ", no->dado, corNo);
    preorder_rb(no->esq);
    preorder_rb(no->dir);
}

//REMOVER
void removerNo(No** raiz, int dado) {
    No* z = *raiz;
    while (z != NULL && z->dado != dado) {
        if (dado < z->dado)
            z = z->esq;
        else
            z = z->dir;
    }

    if (z == NULL)
        return;

    No* y = z;
    No* x = NULL;
    Cor corOriginalY = y->cor;

    if (z->esq == NULL) {
        x = z->dir;
        transplantar(raiz, z, z->dir);
    } else if (z->dir == NULL) {
        x = z->esq;
        transplantar(raiz, z, z->esq);
    } else {
        y = minimo(z->dir);
        corOriginalY = y->cor;
        x = y->dir;
        if (y->pai == z)
            x->pai = y;
        else {
            transplantar(raiz, y, y->dir);
            y->dir = z->dir;
            y->dir->pai = y;
        }
        transplantar(raiz, z, y);
        y->esq = z->esq;
        y->esq->pai = y;
        y->cor = z->cor;
    }

    if (corOriginalY == PRETO)
        corrigirDuploPreto(raiz, x);

    free(z);
}

//CORREÇÃO DUPLO PRETO
void corrigirDuploPreto(No** raiz, No* x) {

    if (x == *raiz)
        return;

    No* pai = x->pai;
    No* irmao = (x == pai->esq) ? pai->dir : pai->esq;

    if (irmao == NULL)
        corrigirDuploPreto(raiz, pai);
    else {
        if (irmao->cor == VERMELHO) {
            pai->cor = VERMELHO;
            irmao->cor = PRETO;
            if (irmao == pai->esq)
                rotacaoEsquerda(raiz, pai);
            else
                rotacaoDireita(raiz, pai);
            corrigirDuploPreto(raiz, x);
        } else {
            if ((irmao->esq == NULL || irmao->esq->cor == PRETO) &&
                (irmao->dir == NULL || irmao->dir->cor == PRETO)) {
                irmao->cor = VERMELHO;
                if (pai->cor == VERMELHO)
                    pai->cor = PRETO;
                else
                    corrigirDuploPreto(raiz, pai);
            } else {
                if (irmao == pai->esq && (irmao->esq == NULL || irmao->esq->cor == PRETO)) {
                    irmao->cor = VERMELHO;
                    irmao->dir->cor = PRETO;
                    rotacaoEsquerda(raiz, irmao);
                } else if (irmao == pai->dir && (irmao->dir == NULL || irmao->dir->cor == PRETO)) {
                    irmao->cor = VERMELHO;
                    irmao->esq->cor = PRETO;
                    rotacaoDireita(raiz, irmao);
                }
                irmao = (x == pai->esq) ? pai->dir : pai->esq;
                irmao->cor = pai->cor;
                pai->cor = PRETO;
                if (irmao == pai->dir)
                    irmao->dir->cor = PRETO;
                else
                    irmao->esq->cor = PRETO;
                if (irmao == pai->esq)
                    rotacaoEsquerda(raiz, pai);
                else
                    rotacaoDireita(raiz, pai);
            }
        }
    }
}
}
