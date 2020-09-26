//Igor Augusto Dos Santos

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>


// ######### ESCREVA O NROUSP AQUI
char* nroUSP() {
    return("11796851");
}


// ######### ESCREVA SEU NOME AQUI
char* nome() {
    return("Igor Augusto dos Santos");
}

// elemento da lista
typedef struct estr {
        int valor;
        struct estr* prox;
} NO;


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

	NO* p1 = NULL;
	NO* p2 = NULL;
	NO* teste = NULL;

	// aqui vc pode incluir codigo para inserir elementos
	// de teste nas listas p1 e p2

adicionar(&p1,0);
adicionar(&p1,3);
adicionar(&p1,3);
adicionar(&p1,7);
adicionar(&p1,8);
adicionar(&p2,1);
adicionar(&p2,2);
adicionar(&p2,2);
adicionar(&p2,5);
adicionar(&p2,7);


	teste = uniao(p1,p2);

	NO* pos = teste;

	while(pos!=NULL){
		printf("%d ",pos->valor);
		pos=pos->prox;
	}

}

// por favor nao inclua nenhum código abaixo da função main()