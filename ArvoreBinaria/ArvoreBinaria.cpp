#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <iostream>

using namespace std;

typedef struct estrutura
{
    int chave;
    estrutura *dir;
    estrutura *esq;
} NO;

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

void preencherArvore(NO **raiz, int n)
{
    FILA f;
    inicializarFila(&f);
    NO *aux = inserirNo(raiz, (*raiz), 0, 1);
    NO *prox;
    entrarFila(aux, &f);
    for (int i = 1; i < n; i++)
    {
        prox = sairFila(&f);
        aux = inserirNo(raiz, prox, i, 1);
        entrarFila(aux, &f);
        i++;
        if (i == n)
            return;
        aux = inserirNo(raiz, prox, i, 2);
        entrarFila(aux, &f);
    }
}

int main()
{
    NO *raiz;
    inicializar(&raiz);

    /*
    inserirNo(&raiz, raiz, 3, 1);
    inserirNo(&raiz, raiz, 1, 2);
    inserirNo(&raiz, raiz, 2, 1);
    */

    preencherArvore(&raiz, 15);

    print2DUtil(raiz, 0);
    printf("\n");
    emOrdem(raiz);
}