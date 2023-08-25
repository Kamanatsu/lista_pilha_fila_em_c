#include "lista.h"

typedef struct pilha Pilha;

//Cria uma pilha.//
Pilha* pilha_cria(void);
//Testa se uma pilha é vazia.//
int pilha_vazia(Pilha *p);
//Adiciona um elemento no topo de uma pilha//
void pilha_push(Pilha *p, int info);
//Remove um elemento do topo de uma pilha.//
int pilha_pop(Pilha *p);
//Função que imprime os elementos de uma pilha.//
void pilha_imprime(Pilha *p);
//Libera o espaço alocado para uma pilha.//
void pilha_libera(Pilha *p);
//Gera uma nova pilha com elementos de outra pilha na ordem inversa.//
Pilha* inverte_pilha(Pilha* p);
//Gera uma nova pilha com elementos da intersecção de duas listas na ordem crescente.//
Pilha* empilha_elem_comuns(Lista* l1, Lista* l2);

