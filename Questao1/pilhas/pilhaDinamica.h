#ifndef PILHADINAMICA_H
#define PILHADINAMICA_H

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *topo;
} PilhaDinamica;

void inicializarDinamica(PilhaDinamica *p);

int isEmptyDinamica(PilhaDinamica *p);

void pushDinamica(PilhaDinamica *p, int valor);

void popDinamica(PilhaDinamica *p);

int topDinamica(PilhaDinamica *p);

void imprimirDinamica(PilhaDinamica *p);

void liberarDinamica(PilhaDinamica *p);

#endif