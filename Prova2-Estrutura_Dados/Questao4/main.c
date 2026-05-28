#include <stdio.h>

#include "calculo.h"

int main(void){

    char op;

    float v;

    Calc* calc;

    calc = cria_calc("%.2f\n");

    printf("Digite a expressao em NPI:\n");

    printf("Exemplo: 1 2 3 * + 4 -\n\n");

    do{

        scanf(" %c", &op);

        if(op == '+' || op == '-' || op == '*' || op == '/'){

            operador(calc, op);
        }
        else{

            ungetc(op, stdin);

            if(scanf("%f", &v) == 1){

                operando(calc, v);
            }
        }

    }while(op != 'q');

    libera_calc(calc);

    return 0;
}