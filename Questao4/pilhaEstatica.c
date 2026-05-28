#include "pilhaEstatica.h"

struct pilha{
    int topo;
    float vet[TamMax];
};

Pilha* cria_pilha(void){

    Pilha* p = (Pilha*) malloc(sizeof(Pilha));

    p->topo = 0;

    return p;
}

void push(Pilha* p, float v){

    if(p->topo == TamMax){
        printf("Pilha Cheia!\n");
        exit(1);
    }

    p->vet[p->topo] = v;

    p->topo++;
}

float pop(Pilha* p){

    float v;

    if(pilha_vazia(p)){
        printf("Pilha Vazia!\n");
        exit(1);
    }

    v = p->vet[p->topo - 1];

    p->topo--;

    return v;
}

int pilha_vazia(Pilha* p){

    return (p->topo == 0);
}

void libera_pilha(Pilha* p){

    free(p);
}

void imprime_pilha(Pilha* p){

    int i;

    for(i = p->topo - 1; i >= 0; i--){
        printf("%.2f\n", p->vet[i]);
    }
}