#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <climits>
#include <iostream>

using namespace std;

// ######### ESCREVA O NROUSP AQUI
const char *nroUSP()
{
    return ("11796851");
}

// no da arvore
typedef struct estr
{
    int chave;
    struct estr *esq;
    struct estr *dir;
} NO;

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
#pragma endregion

void organizar(NO **raiz);

NO *erro(NO **p, int min, int max, NO** pai)
{
    if (!(*p))
        return NULL;

    if ((*p)->chave < min || (*p)->chave > max)
        return (*p);

    (*pai) = (*p);
    NO *aux = erro(&((*p)->esq), min, (*p)->chave - 1, pai);

    return aux ? aux : erro(&((*p)->dir), (*p)->chave + 1, max, pai);
}

//------------------------------------------
// O EP consiste em implementar esta funcao
//------------------------------------------
void organizar(NO **raiz)
{
    // seu codigo AQUI
    // sugestao: faca NO* p = *raiz para percorrer a arvore com p
    // nao use *raiz para mais nada, exceto quando precisar modificar este ponteiro (tipicamente quando exclur o no apontado por ele)
}

//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------
int main()
{
    NO *raiz;
    inicializar(&raiz);

    int m[15] = {10, 5, 15, 3, 7, 13, 18, 2, 4, 6, 8, 12, 14, 17, 19};

    for (int i = 0; i < 15; i++)
    {
        inserirABB(&raiz, m[i]);
    }

    NO *pai;
    NO *aux = busca(raiz, 13, &pai);
    aux->chave = 9;

    //print2DUtil(raiz, 0);
    printf("\n-----------\n");
    pai = NULL;
    NO *e = erro(&raiz, INT_MIN, INT_MAX, &pai);
    printf("pai: %d\nerro:%d", pai->chave, e->chave);
    print2DUtil(raiz, 0);
}

// por favor nao inclua nenhum codigo abaixo da funcao main()