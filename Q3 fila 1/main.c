#include <stdio.h>
#include <stdlib.h>
#include "fila1.h" //executar também com “fila2.h”

int main(void){
    int a, qtd;
    Fila* f1 = fila_cria();
    fila_insere(f1,31);
    fila_insere(f1,33);
    fila_insere(f1,35);
    fila_insere(f1,37);
    fila_insere(f1,39);
    a = fila_remove(f1);
    printf("Valor removido da fila f1: %d\n",a);
    fila_imprime(f1);
}