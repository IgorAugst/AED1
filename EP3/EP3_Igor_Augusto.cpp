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

void organizar(NO **raiz);
NO *erro(NO *p, int min, int max, NO **pai);

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
    NO *pai = NULL;
    NO *errado = erro(*raiz, INT_MIN, INT_MAX, &pai);

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
        }
    }

    if (errado->dir == NULL && errado->esq != NULL)
    { // se tiver um filho na esquerda
        if (pai)
        {
            (pai->dir && pai->dir->chave) == errado->chave ? pai->dir = errado->esq : pai->esq = errado->esq;
            free(errado);
            return;
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
int main()
{
    NO *arv = NULL;

    // serao realizadas chamadas como esta:
    // organizar(&arv);
}

// por favor nao inclua nenhum codigo abaixo da funcao main()