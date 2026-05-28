#ifndef FUNCIONARIO_H_INCLUDED
#define FUNCIONARIO_H_INCLUDED

typedef enum
{
    DIRETOR = 1,
    COORDENADOR = 2,
    FUNCIONARIO = 3
} Cargo;

typedef struct
{
    char nome[100];
    char cpf[20];
    float salario;
    Cargo cargo;

} TipoFuncionario;

#endif