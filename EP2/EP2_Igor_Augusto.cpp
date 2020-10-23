#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>


// ######### ESCREVA O NROUSP AQUI
const char* nroUSP() {
    return("11796851");
}


// ######### ESCREVA SEU NOME AQUI
const char* nome() {
    return("Igor Augusto dos Santos");
}

// elemento da pilha
typedef struct estrutura {
	struct estrutura *prox;
       	int tipo; // 1=char e 2=float
       	union {
              	char simbolo;
              	float valor;
       	};
} NO;

typedef struct
{
    int tamanho=0;
    NO* topo=NULL;
}PILHA;


// funcao principal (retorna float e int)
float calcular(char* expressao, int* codigo);
void push(PILHA* p, int tipo, float valor, char carac);
NO pop(PILHA* p);


void push(PILHA* p, int tipo, float valor, char carac){
    NO* novo = (NO*)malloc(sizeof(NO));
    novo->tipo = tipo;
    if(tipo == 2){
        novo->valor = valor;
    }else{
        novo->simbolo = carac;
    }

    novo->prox = p->topo;
    p->topo = novo;
    p->tamanho++;
}

NO pop(PILHA* p){
    NO resp;
    if(p->topo == NULL) return resp;
    NO* aux;
    resp = *(p->topo);
    aux = p->topo;
    p->topo = aux->prox;
    p->tamanho--;
    free(aux);
    return resp;
}

//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------
float calcular(char* expressao, int* codigo){

	float resp = 0.0;
	*codigo = -1; 

    PILHA pi;
    int i = 0;
    char aux;

    while(expressao[i] != '\0'){
        aux = expressao[i]-48;
        if(aux<=9 && aux >= 0){
            push(&pi, 2, aux, '.');
        }else{
            push(&pi,1,0,expressao[i]);
        }

        if(expressao[i] == ')'){
            float a,b;
            char op;
            NO saida = pop(&pi);
            saida = pop(&pi);

            if(saida.tipo != 2){
                *codigo = -1;
                return 0.0;
            }
            b = saida.valor;
            saida = pop(&pi);

            if(saida.tipo != 1){
                *codigo = -1;
                return 0.0;
            }
            op = saida.simbolo;
            saida = pop(&pi);

            if(saida.tipo != 2){
                *codigo = -1;
                return 0.0;
            }
            a = saida.valor;
            saida = pop(&pi);

            if(saida.simbolo != '('){
                *codigo = -1;
                return 0.0;
            }

            switch (op)
            {
            case '+':
                push(&pi, 2, a+b, '.');
                break;
            case '-':
                push(&pi, 2, a-b, '.');
                break;
            case '*':
                push(&pi, 2, a*b, '.');
                break;
            case '/':
                if(b==0){
                    *codigo=0;
                    return 0.0;
                }
                push(&pi, 2, a/b, '.');
                break;         
            default:
                *codigo = -1;
                return 0.0;
                break;
            }
            
        }
        i++;
    }

    NO res = pop(&pi);
    if(res.tipo != 2 || pi.tamanho != 0){
        *codigo = -1;
        return 0.0;
    }
    *codigo = 1;
	return res.valor;
}



//----------------------------------------------------------------
// use main() apenas para fazer chamadas de teste ao seu programa
//----------------------------------------------------------------
int main() {

}

// por favor nao inclua nenhum código abaixo da função main()