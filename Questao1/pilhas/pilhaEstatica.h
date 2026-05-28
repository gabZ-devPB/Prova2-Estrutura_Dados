#ifndef PILHAESTATICA_H
#define PILHAESTATICA_H

#define TAMMAX 5

typedef struct {
    int dados[TAMMAX];
    int topo;
} PilhaEstatica;

void inicializar(PilhaEstatica *p);

int isEmpty(PilhaEstatica *p);

int isFull(PilhaEstatica *p);

void push(PilhaEstatica *p, int valor);

void pop(PilhaEstatica *p);

int top(PilhaEstatica *p);

void imprimir(PilhaEstatica *p);

#endif