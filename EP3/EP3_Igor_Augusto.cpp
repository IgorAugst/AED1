#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <climits>

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

typedef struct elementoL
{
    NO *NoArvore;
    NO *NoPai;
    struct elementoL *prox;
} NoLista;

typedef struct
{
    NoLista *inicio;
} lista;

void organizar(NO **raiz);
NO *erro(NO *p, int min, int max, NO **pai);
void anexar(lista *l, NO *chave, NO *pai);
void PreencherLista(lista *l, NO *p, NO *pai);

int nivel(NO* p, int ch, int level)
{
    if (p == NULL)
        return 0;

    if (p->chave == ch)
        return level;

    int abaixo = nivel(p->esq, ch, level + 1);
    if (abaixo != 0)
        return abaixo;

    abaixo = nivel(p->dir, ch, level + 1);
    return abaixo;
}

void anexar(lista *l, NO *chave, NO *pai)
{
    NoLista *novo;
    NoLista *ant = l->inicio;

    if (ant != NULL)
    {
        while (ant->prox != NULL)
            ant = ant->prox;
    }

    novo = (NoLista *)malloc(sizeof(NoLista));

    novo->NoArvore = chave;
    novo->NoPai = pai;
    novo->prox = NULL;
    if (!ant)
        l->inicio = novo;
    else
        ant->prox = novo;
}

void PreencherLista(lista *l, NO *p, NO *pai)
{
    if (p)
    {
        PreencherLista(l, p->esq, p);
        anexar(l, p, pai);
        PreencherLista(l, p->dir, p);
    }
}

bool verificaLista(lista *l, int ignorar)
{
    NoLista *atual = l->inicio;

    int count = 0;
    int maior = INT_MIN;
    while (atual)
    {
        if (count == ignorar)
        {
            count++;
            continue;
        }
        if (atual->NoArvore->chave < maior)
        {
            return false;
        }
        else
        {
            maior = atual->NoArvore->chave;
            atual = atual->prox;
            count++;
        }
    }

    return true;
}

NO *erro(NO *p, int min, int max, NO **pai)
{
    if (!p)
        return NULL;

    if (p->chave < min || p->chave > max)
        return p;

    (*pai) = p;
    NO *aux = erro(p->esq, min, p->chave - 1, pai);
    if (aux)
        return aux;

    (*pai) = p;
    return erro(p->dir, p->chave + 1, max, pai);
}

//------------------------------------------
// O EP consiste em implementar esta funcao
//------------------------------------------
void organizar(NO **raiz)
{
    lista *l = (lista *)malloc(sizeof(lista));
    l->inicio = NULL;
    lista *erros = (lista *)malloc(sizeof(lista));
    erros->inicio = NULL;

    PreencherLista(l, *raiz, NULL);

    NoLista *atual = l->inicio;
    int maior = INT_MIN;
    NO *errado = NULL;
    NO *pai = NULL;
    NoLista *ant = NULL;
    int ignora = 0;

    while (atual)
    {
        if (atual->NoArvore->chave < maior)
        {
            errado = atual->NoArvore;
            pai = atual->NoPai;
            break;
        }
        else
        {
            ant = atual;
            maior = atual->NoArvore->chave;
            atual = atual->prox;
            ignora++;
        }
    }

    if(errado == NULL){
        return;
    }

    if (!verificaLista(l, ignora))
    {
        anexar(erros, errado, pai);
    }

    if (!verificaLista(l, ignora - 1))
    {
        anexar(erros, ant->NoArvore, ant->NoPai);
    }

    errado = erros->inicio->NoArvore;
    pai = erros->inicio->NoPai;

    if(erros->inicio->prox != NULL){
        if(nivel(*raiz, erros->inicio->NoArvore->chave, 1) > nivel(*raiz, erros->inicio->prox->NoArvore->chave, 1)){
            errado = erros->inicio->prox->NoArvore;
            pai = erros->inicio->prox->NoPai;
        }
    }

    if (errado == NULL)
        return;

    if (errado->dir == NULL && errado->esq == NULL)
    { // caso seja folha
        if (pai)
        { //se nao for a raiz
            (pai->dir && pai->dir->chave == errado->chave) ? pai->dir = NULL : pai->esq = NULL;
            free(errado);
            return;
        }
    }

    if (errado->dir != NULL && errado->esq == NULL)
    { // se tiver um filho na direita
        if (pai)
        {
            (pai->dir && pai->dir->chave == errado->chave) ? pai->dir = errado->dir : pai->esq = errado->dir;
            free(errado);
            return;
        }else{
            (*raiz) = errado->dir;
        }
    }

    if (errado->dir == NULL && errado->esq != NULL)
    { // se tiver um filho na esquerda
        if (pai)
        {
            (pai->dir && pai->dir->chave) == errado->chave ? pai->dir = errado->esq : pai->esq = errado->esq;
            free(errado);
            return;
        }else{
            (*raiz) = errado->esq;
        }
    }

    if (errado->dir != NULL && errado->esq != NULL)
    { // se tiver 2 filhos
        NO *p = errado->esq;
        NO *ant = errado;

        while (p->dir != NULL)
        {
            ant = p;
            p = p->dir;
        }

        if (ant->chave == errado->chave)
        {
            errado->chave = p->chave;
            errado->esq = NULL;
            free(p);
            return;
        }
        else
        {
            errado->chave = p->chave;
            ant->dir = NULL;
            free(p);
            return;
        }
    }
}

//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------

// por favor nao inclua nenhum codigo abaixo da funcao main()