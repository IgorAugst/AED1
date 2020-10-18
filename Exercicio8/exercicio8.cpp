#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

#pragma region implementacao
typedef struct ESTRUTURA
{
    int chave;
    struct ESTRUTURA *prox;
    struct ESTRUTURA *ant;
} NO;

typedef struct
{
    NO *inicio;
    NO *fim;
} LISTA;

void inicializar(LISTA *l)
{
    l->inicio = NULL;
    l->fim = NULL;
}

void anexar(LISTA *l, int chave)
{
    NO *novo = (NO *)malloc(sizeof(NO));
    if (l->inicio == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    novo->chave = chave;
    novo->prox = NULL;
    novo->ant = l->fim;
    l->fim->prox = novo;
    l->fim = novo;
}

void exibirLista(LISTA *l)
{
    NO *pos = l->inicio;

    while (pos != NULL)
    {
        printf("%d ", pos->chave);
        pos = pos->prox;
    }
}

void exibirInvertida(LISTA *l)
{
    NO *pos = l->fim;
    while (pos != l->inicio)
    {
        printf("%d ", pos->chave);
        pos = pos->ant;
    }

    printf("%d ", pos->chave);
}

NO *retorna(LISTA *l, int n)
{
    NO *pos = l->inicio;

    for (int i = 0; i < n; i++)
    {
        pos = pos->prox;
    }

    return pos;
}
#pragma endregion

NO *listaNumerada(int n)
{
    NO *resp = (NO *)malloc(sizeof(NO));
    resp->ant = NULL;
    resp->prox = NULL;
    resp->chave = 1;

    NO *ant = resp;

    for (int i = 2; i <= n; i++)
    {
        NO *aux = (NO *)malloc(sizeof(NO));
        aux->chave = i;
        aux->ant = ant;
        aux->ant->prox = aux;
        aux->prox = NULL;
        ant = aux;
    }
    return resp;
}

void moverParaFim(LISTA *l, NO *p)
{
    if (l->fim == p)
        return;
    if(l->inicio == p){
        l->inicio = p->prox;
    }
    p->ant->prox = p->prox;
    p->prox->ant = p->ant;
    p->prox = NULL;
    p->ant = l->fim;
    l->fim->prox = p;
    l->fim = p;
}

int main()
{
    LISTA l;
    inicializar(&l);
    NO *ult;

    for (int i = 0; i < 10; i++)
    {
        anexar(&l, i);
    }

    NO *p = retorna(&l, 0);
    moverParaFim(&l, p);

    exibirLista(&l);
    printf("\n--------------\n");
    exibirInvertida(&l);
}