#include <stdio.h>
#include "pilhaEstatica.h"

void inicializar(PilhaEstatica *p) {
    p->topo = -1;
}

int isEmpty(PilhaEstatica *p) {
    return p->topo == -1;
}

int isFull(PilhaEstatica *p) {
    return p->topo == TAMMAX - 1;
}

void push(PilhaEstatica *p, int valor) {

    if (isFull(p)) {
        printf("Pilha cheia!\n");
        return;
    }

    p->topo++;
    p->dados[p->topo] = valor;
}

void pop(PilhaEstatica *p) {

    if (isEmpty(p)) {
        printf("Pilha vazia!\n");
        return;
    }

    printf("Removido: %d\n", p->dados[p->topo]);

    p->topo--;
}

int top(PilhaEstatica *p) {

    if (isEmpty(p)) {
        return -1;
    }

    return p->dados[p->topo];
}

void imprimir(PilhaEstatica *p) {

    if (isEmpty(p)) {
        printf("Pilha vazia!\n");
        return;
    }

    printf("\nPilha Estatica:\n");

    for (int i = p->topo; i >= 0; i--) {
        printf("%d\n", p->dados[i]);
    }
}