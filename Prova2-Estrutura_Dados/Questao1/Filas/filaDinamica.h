#ifndef FILADINAMICA_H
#define FILADINAMICA_H

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

void inicializar(Fila *f);
void enfileirar(Fila *f, int x);
int desenfileirar(Fila *f);

#endif