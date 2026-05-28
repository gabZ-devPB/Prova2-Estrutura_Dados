#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calculo.h"
#include "pilhaEstatica.h"

struct calc{

    char formato[20];

    Pilha* p;
};

Calc* cria_calc(char* formato){

    Calc* c = (Calc*) malloc(sizeof(Calc));

    strcpy(c->formato, formato);

    c->p = cria_pilha();

    return c;
}

void operando(Calc* c, float v){

    push(c->p, v);

    printf(c->formato, v);
}

void operador(Calc* c, char op){

    float v1;
    float v2;
    float resultado;

    if(pilha_vazia(c->p))
        v2 = 0;
    else
        v2 = pop(c->p);

    if(pilha_vazia(c->p))
        v1 = 0;
    else
        v1 = pop(c->p);

    switch(op){

        case '+':
            resultado = v1 + v2;
            break;

        case '-':
            resultado = v1 - v2;
            break;

        case '*':
            resultado = v1 * v2;
            break;

        case '/':
            resultado = v1 / v2;
            break;
    }

    push(c->p, resultado);

    printf(c->formato, resultado);
}

void libera_calc(Calc* c){

    libera_pilha(c->p);

    free(c);
}