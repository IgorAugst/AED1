#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <climits>
#include <iostream>
#include "EP3_Igor_Augusto.cpp" //deixar o ep no msm diretorio

using namespace std;

#pragma region implementacao
typedef struct estruturaFila
{
    NO *vertice;
    estruturaFila *prox;
} NOFILA;

typedef struct
{
    NOFILA *inicio;
    NOFILA *fim;
} FILA;

void inicializarFila(FILA *f)
{
    f->inicio = NULL;
    f->fim = NULL;
}

void entrarFila(NO *vertice, FILA *f)
{
    NOFILA *novo;
    novo = (NOFILA *)malloc(sizeof(NOFILA));
    novo->vertice = vertice;
    novo->prox = NULL;
    if (f->fim)
        f->fim->prox = novo;
    else
        f->inicio = novo;
    f->fim = novo;
}

NO *sairFila(FILA *f)
{
    NO *aux;
    NOFILA *apaga;
    if (!f->inicio)
        return NULL;
    aux = f->inicio->vertice;
    apaga = f->inicio;
    f->inicio = f->inicio->prox;
    free(apaga);
    if (!f->inicio)
        f->fim = NULL;
    return aux;
}

void inicializar(NO **raiz)
{
    (*raiz) = NULL;
}

NO *inserirNo(NO **raiz, NO *pai, int ch, int pos)
{
    NO *novo;
    if (pai)
    {
        if ((pos == 1 && pai->esq != NULL) || (pos == 2 && pai->dir != NULL))
            return NULL;
    }

    novo = (NO *)malloc(sizeof(NO));
    novo->chave = ch;
    novo->esq = NULL;
    novo->dir = NULL;

    if (!pai)
        *raiz = novo;
    else
    {
        if (pos == 1)
            pai->esq = novo;
        else
            pai->dir = novo;
    }

    return novo;
}

void print2DUtil(NO *raiz, int space)
{
    int COUNT = 7;
    // Base case
    if (raiz == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(raiz->dir, space);

    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << raiz->chave << "\n";

    // Process left child
    print2DUtil(raiz->esq, space);
}

void preOrdem(NO *r)
{
    if (r)
    {
        printf("%d ", r->chave);
        preOrdem(r->esq);
        preOrdem(r->dir);
    }
}

void emOrdem(NO *r)
{
    if (r)
    {
        emOrdem(r->esq);
        printf("%d ", r->chave);
        emOrdem(r->dir);
    }
}

void posOrdem(NO *r)
{
    if (r)
    {
        posOrdem(r->esq);
        posOrdem(r->dir);
        printf("%d ", r->chave);
    }
}

void exibirEmNivel(NO *raiz)
{
    FILA f;
    NO *p = raiz;
    inicializarFila(&f);
    while ((p) || (f.inicio))
    {
        if (p->esq)
            entrarFila(p->esq, &f);
        if (p->dir)
            entrarFila(p->dir, &f);
        printf("%d ", p->chave);
        p = NULL;
        if (f.inicio)
            p = sairFila(&f);
    }
}

void preencherArvore(NO **raiz, int n, int valores[])
{
    FILA f;
    inicializarFila(&f);
    NO *aux = inserirNo(raiz, (*raiz), valores[0], 1);
    NO *prox;
    entrarFila(aux, &f);
    for (int i = 1; i < n; i++)
    {
        prox = sairFila(&f);
        aux = inserirNo(raiz, prox, valores[i], 1);
        entrarFila(aux, &f);
        i++;
        if (i == n)
            return;
        aux = inserirNo(raiz, prox, valores[i], 2);
        entrarFila(aux, &f);
    }
}

NO *busca(NO *raiz, int ch, NO **pai)
{
    NO *atual = raiz;
    *pai = NULL;

    while (atual)
    {
        if (atual->chave == ch)
        {
            return atual;
        }

        *pai = atual;
        if (ch < atual->chave)
            atual = atual->esq;
        else
            atual = atual->dir;
    }

    return NULL;
}

bool inserirABB(NO **raiz, int ch)
{
    NO *pai;
    NO *atual = busca(*raiz, ch, &pai);

    if (atual)
        return false;

    NO *novo = (NO *)malloc(sizeof(NO));
    novo->chave = ch;
    novo->esq = NULL;
    novo->dir = NULL;

    if (!pai)
    {
        *raiz = novo;
        return true;
    }

    if (pai->chave > ch)
        pai->esq = novo;
    else
        pai->dir = novo;

    return true;
}

bool verifica(NO *p, int min, int max)
{
    if (p == NULL)
        return true;

    if (p->chave < min || p->chave > max)
        return false;

    return verifica(p->esq, min, p->chave - 1) && verifica(p->dir, p->chave + 1, max);
}
#pragma endregion

int main()
{
    NO *raiz;
    inicializar(&raiz);

    int m[8][15] = {
        {10, 5, 15, 3, 7, 13, 18, 7, 4, 6, 8, 12, 14, 17, 19}, //2,7
        {10, 11, 15, 3, 7, 13, 18, 2, 4, 6, 8, 12, 14, 17, 19}, //5,1
        {10, 5, 15, 3, 7, 13, 18, 2, 4, 6, 8, 12, 16, 17, 19}, //14,16
        {20, 5, 15, 3, 7, 13, 18, 2, 4, 6, 8, 12, 14, 17, 19}, //10,20
        {-2, 5, 15, 3, 7, 13, 18, 2, 4, 6, 8, 12, 14, 17, 19}, //10,-1
        {10, 5, 15, 3, 7, 13, 20, 2, 4, 6, 8, 12, 14, 17, 19}, //18,20
        {10, 5, 15, 3, 7, 9, 18, 2, 4, 6, 8, 12, 14, 17, 19}, //13,9
        {10, 5, 15, 3, 7, 13, 18, 2, 4, 6, 8, 12, 14, 17, 19}};

    for (int i = 0; i < 8; i++)
    {
        inicializar(&raiz);
        preencherArvore(&raiz, 15, m[i]);
        organizar(&raiz);
        printf("### TESTE %d ###", i);
        print2DUtil(raiz, 0);
        printf(verifica(raiz, INT_MIN, INT_MAX) ? "\ncorreto\n" : "\nincorreto\n");
    }
}