#include <stdio.h>
#include <stdlib.h>
#include "pilhaDinamica.h"

void inicializarDinamica(PilhaDinamica *p) {
    p->topo = NULL;
}

int isEmptyDinamica(PilhaDinamica *p) {
    return p->topo == NULL;
}

void pushDinamica(PilhaDinamica *p, int valor) {

    No *novo = (No *) malloc(sizeof(No));

    novo->valor = valor;
    novo->prox = p->topo;

    p->topo = novo;
}

void popDinamica(PilhaDinamica *p) {

    if (isEmptyDinamica(p)) {
        printf("Pilha vazia!\n");
        return;
    }

    No *temp = p->topo;

    printf("Removido: %d\n", temp->valor);

    p->topo = temp->prox;

    free(temp);
}

int topDinamica(PilhaDinamica *p) {

    if (isEmptyDinamica(p)) {
        return -1;
    }

    return p->topo->valor;
}

void imprimirDinamica(PilhaDinamica *p) {

    if (isEmptyDinamica(p)) {
        printf("Pilha vazia!\n");
        return;
    }

    No *aux = p->topo;

    printf("\nPilha Dinamica:\n");

    while (aux != NULL) {
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
}

void liberarDinamica(PilhaDinamica *p) {

    No *temp;

    while (p->topo != NULL) {

        temp = p->topo;

        p->topo = p->topo->prox;

        free(temp);
    }
}