#include <stdlib.h>
#include <stdio.h>

typedef int TIPOINFO;

typedef struct estrutura
{
    int lin;
    int col;
    TIPOINFO info;
    struct estrutura *prox;
} NO;

typedef struct
{
    NO *inicio;
    int maxlin;
    int maxcol;
} MATRIZ;

MATRIZ *fazerMatriz(TIPOINFO mat[][100], int x, int y)
{
    MATRIZ *resp = (MATRIZ *)malloc(sizeof(MATRIZ));
    resp->maxlin = x;
    resp->maxcol = y;
    resp->inicio = NULL;
    NO* ant = NULL;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {

            if(mat[i][j] == 0) continue;
            
            NO *aux = (NO *)malloc(sizeof(NO));
            aux->lin = i;
            aux->col = j;
            aux->info = mat[i][j];

            if(resp->inicio == NULL){
                resp->inicio = aux;
            }else{
                ant->prox = aux;
            }

            aux->prox = NULL;
            ant=aux;
        }
    }

    return resp;
}

void exibir(MATRIZ* m){
    NO* pos = m->inicio;

    while(pos != NULL){
        printf("lin: %d, col: %d, value: %d\n", pos->lin, pos->col, pos->info);
        pos = pos->prox;
    }
}