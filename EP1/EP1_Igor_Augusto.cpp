//Igor Augusto Dos Santos

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>


#pragma region teste

typedef struct estr {
        int valor;
        struct estr* prox;
} NO;


typedef struct{
    NO* inicio;
}lista;

void inicializar(lista *l){
    l->inicio = NULL;
}

void exibirLista(lista *l){
    NO* pos = l->inicio;

    while(pos != NULL){
        printf("%d ", pos->valor);
        pos = pos->prox;
    }
}

NO* UltElemento(lista *l){
    NO* pos = l->inicio;
    if(pos != NULL)
        while(pos->prox) pos = pos->prox;
    return pos;
}


void anexar(lista *l, int chave){
    NO* novo;
    NO* ant = UltElemento(l);

    novo = (NO*)malloc(sizeof(NO));
    novo->valor = chave;
    novo->prox = NULL;
    if(!ant) l->inicio = novo;
    else ant->prox = novo;
}

#pragma endregion

// ######### ESCREVA O NROUSP AQUI
char* nroUSP() {
    return("11796851");
}


// ######### ESCREVA SEU NOME AQUI
char* nome() {
    return("Igor Augusto dos Santos");
}

// elemento da lista


// funcao principal
NO* uniao(NO* p1, NO* p2);
void adicionar(NO* *n, int valor);


void adicionar(NO* *n, int valor){
	if(*n == NULL){
		*n = (NO*)malloc(sizeof(NO));
		(*n)->prox = NULL;
		(*n)->valor=valor;
	}else{
		NO* pos = (*n);
		while(pos->prox != NULL){
			pos=pos->prox;
		}
		NO* aux = (NO*)malloc(sizeof(NO));
		aux->prox=NULL;
		aux->valor=valor;
		pos->prox=aux;
	}
}

//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------
NO* uniao(NO* p1, NO* p2) {

	NO* resp;
	resp = NULL;

	if(p1==NULL && p2==NULL) return resp;

	NO* pos1 = p1;
	NO* pos2 = p2;
	int ant = -1;

	while(pos1 != NULL && pos2 != NULL){
		if(pos1->valor < pos2->valor){
			if(pos1->valor != ant){
			adicionar(&resp,pos1->valor);
			ant=pos1->valor;
			}
			pos1=pos1->prox;
			continue;
		}

		if(pos1->valor > pos2->valor){
			if(pos2->valor != ant){
			adicionar(&resp,pos2->valor);
			ant=pos2->valor;
			}			
			pos2=pos2->prox;
			continue;
		}

		if(pos1->valor == pos2->valor){
			if(pos1->valor != ant){
			adicionar(&resp,pos1->valor);
			ant=pos1->valor;
			}
			pos2=pos2->prox;
			pos1=pos1->prox;
			continue;
		}
	}


	while(pos1 != NULL){
		if(pos1->valor != ant){
			adicionar(&resp,pos1->valor);
			ant=pos1->valor;
		}
		pos1=pos1->prox;
	}

	while(pos2 != NULL){
		if(pos2->valor != ant){
			adicionar(&resp,pos2->valor);
			ant=pos2->valor;
		}
		pos2 = pos2->prox;
	}

	return resp;
}



//----------------------------------------------------------------
// use main() apenas para fazer chamadas de teste ao seu programa
//----------------------------------------------------------------
int main() {
	lista l1;
	inicializar(&l1);
	lista l2;
	inicializar(&l2);

/*anexar(&l1,5);
anexar(&l1,10);
anexar(&l1,15);
anexar(&l1,20);
anexar(&l1,25);
anexar(&l1,30);

anexar(&l2,1);
anexar(&l2,11);
anexar(&l2,22);
anexar(&l2,33);
anexar(&l2,44);
anexar(&l2,55);*/

exibirLista(&l1);
printf("--\n");
exibirLista(&l2);
printf("---------------\n");

lista aux;
inicializar(&aux);

aux.inicio = uniao(l1.inicio, l2.inicio);

exibirLista(&aux);

	
}

// por favor nao inclua nenhum código abaixo da função main()