#ifndef FILA_ESTATICA_H
#define FILA_ESTATICA_H

#define MAX 10

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int total;
} Fila;

void inicializarFila(Fila *f);
int vazia(Fila *f);
int cheia(Fila *f);
void enfileirar(Fila *f, int x);
int desenfileirar(Fila *f);

#endif