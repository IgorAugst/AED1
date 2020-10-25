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

MATRIZ *fazerMatriz(TIPOINFO mat[][3], int x, int y)
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
            NO *aux = (NO *)malloc(sizeof(NO));
            aux->lin = i;
            aux->col = j;
            aux->info = mat[i][j];

            if(resp->inicio == NULL){
                resp->inicio = aux;
            }else{
                ant->prox = aux;
            }

            ant=aux;
        }
    }

    return resp;
}

int main(){
    int mat[3][3] = {{0,0,1},{1,0,1},{0,0,0}};

    MATRIZ* res = fazerMatriz(mat, 3, 3);
    res = NULL;
}