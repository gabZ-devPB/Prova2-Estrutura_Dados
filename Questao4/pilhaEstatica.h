#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define TamMax 50

typedef struct pilha Pilha;

Pilha* cria_pilha(void);
void push(Pilha* p, float v);
float pop(Pilha* p);
int pilha_vazia(Pilha* p);
void libera_pilha(Pilha* p);
void imprime_pilha(Pilha* p);

#endif