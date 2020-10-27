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

int valor(MATRIZ* m, int i, int j){
    NO* pos = m->inicio;

    while(pos!=NULL && pos->lin <= i){
        if(pos->lin == i && pos->col == j) return pos->info;
        pos=pos->prox;
    }

    return 0;
}

void exibirLinha(MATRIZ* m, int i){
    NO* pos = m->inicio;

    while(pos != NULL && pos->lin != i){
        pos = pos ->prox;
    }
    
    int j = 0;
    while(j<m->maxcol){
        if(pos != NULL && pos->col == j){
            printf("%d ", pos->info);
            pos = pos->prox;
        }else{
            printf("0 ");
        }
        j++;
    }

}

void zerarDiagonal(MATRIZ* m){
    NO* pos = m->inicio;
    NO* ant = NULL;

    while(pos != NULL){
        if(pos->col == pos->lin){
            if(ant == NULL){
                m->inicio = pos->prox;
            }else{
                ant->prox = pos->prox;
            }

            NO* aux = pos;
            pos=pos->prox;
            free(aux);
        }else{
            ant=pos;
            pos = pos->prox;
        }        
    }
}

int main(){
    int mat[4][100] = {{0,0,0,0},{1,1,1,1},{3,3,3,3},{4,4,4,4}};

    MATRIZ* res = fazerMatriz(mat, 4, 4);

    zerarDiagonal(res);

    for(int i=0; i<res->maxlin; i++){
        exibirLinha(res, i);
        printf("\n");
    }

}