#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.h"

void inicializar(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
    printf("Fila dinamica inicializada\n");
}

void enfileirar(Fila *f, int x) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = x;
    novo->prox = NULL;

    if (f->fim == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }

    printf("Enfileirado: %d\n", x);
}

int desenfileirar(Fila *f) {
    if (f->inicio == NULL) {
        printf("ERRO: fila vazia\n");
        return -1;
    }

    No *aux = f->inicio;
    int x = aux->valor;

    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) f->fim = NULL;

    free(aux);

    printf("Desenfileirado: %d\n", x);
    return x;
}