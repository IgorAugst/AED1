#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

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

NO *erro(NO *p, int min, int max)
{
    if (!p)
        return NULL;

    if (p->chave < min || p->chave > max)
        return p;

    NO *aux = erro(p->esq, min, p->chave - 1);

    return aux ? aux : erro(p->dir, p->chave + 1, max);
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
    NO *arv = NULL;

    // serao realizadas chamadas como esta:
    // organizar(&arv);
}

// por favor nao inclua nenhum codigo abaixo da funcao main()