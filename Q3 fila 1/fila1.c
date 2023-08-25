#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "fila1.h"
#include "lista.h"
#define N 100


typedef struct fila{
    int n;
    int ini;
    int v[N];
}Fila;



/*cria*/

Fila* fila_cria(void){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    if(f==NULL){
        printf("Memoria insuficiente!!!\n");
        exit(1);
    }
    f->n = 0;
    f->ini = 0;
    return f;
}



/*insere*/
void fila_insere(Fila *f, int info){
    int fim;
    if(f->n==N){
        printf("Capacidade da Fila Estourou!!!\n");
        exit(1);
    }
    fim = (f->ini + f->n) % N;
    f->v[fim]= info;
    f->n++;
}


/*Função que remove um elemento de uma fila.*/
int fila_remove(Fila *f){
    int a;
    if(fila_vazia(f)){
        printf("Fila Vazia!!!\n");
        exit(1);
    }
    a = f->v[f->ini];
    f->ini = (f->ini+1)%N;
    f->n--;
    return a;
}

/*Testa se uma fila é vazia.*/
int fila_vazia(Fila *f){
    return f->n==0;
}



/*imprime*/
void fila_imprime(Fila *f){
    int i; int k;
    for(i = 0; i<f->n;i++){
        k = (f->ini+i) % N;
        printf("%d\n",f->v[k]);
    }
}


/*libera*/
void fila_libera(Fila *f){
    free(f);
}











