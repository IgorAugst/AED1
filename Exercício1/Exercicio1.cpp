#include<stdio.h>
#include<stdlib.h>

int verificarOrdem(int vetor[], int N){
    int resp=0;

    for(int i=0; i<N-1; i++){

        if(vetor[i]>vetor[i+1]){

            if(resp==1){
                return 99;
            }else{
                resp=-1;
            }
        }

        if(vetor[i]<vetor[i+1]){

            if(resp==-1){
                return 99;
            }else{
                resp=1;
            }
        }
    }

    return resp;
}

int main(){
    int a[5]={1,2,3,3,5};
    printf("%d\n", verificarOrdem(a,5));

    int b[5]={5,5,3,3,1};
    printf("%d\n", verificarOrdem(b,5));

    int c[5]={2,2,2,2,2};
    printf("%d\n", verificarOrdem(c,5));

    int d[5]={1,2,1,2,5};
    printf("%d\n", verificarOrdem(d,5));
}