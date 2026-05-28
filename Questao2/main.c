#include <stdio.h>
#include "listaEncadeada.h"
#include "listaEstatica.h"

int main()
{
    TipoLista *listaDin;

    TipoListaEst listaEst;

    TipoFuncionario func;

    int op;

    char cpf[15];

    listaDin = criarLista();

    listaEst = criarListaEst();

    do
    {
        printf("\n1-CADASTRAR");
        printf("\n2-LISTA DINAMICA");
        printf("\n3-LISTA ESTATICA");
        printf("\n4-BUSCAR");
        printf("\n5-REMOVER");
        printf("\n6-SALVAR");
        printf("\n7-CARREGAR");
        printf("\n0-SAIR\n");

        scanf("%d",&op);

        switch(op)
        {
            case 1:

                printf("Nome: ");
                scanf(" %99[^\n]",func.nome);

                printf("CPF: ");
                scanf("%14s",func.cpf);

                printf("Salario: ");
                scanf("%f",&func.salario);

                listaDin = inserirLista(listaDin,func);

                inserirListaEst(&listaEst,func);

            break;

            case 2:

                imprimirLista(listaDin);

            break;

            case 3:

                imprimirListaEst(&listaEst);

            break;

            case 4:

                printf("CPF: ");
                scanf("%14s",cpf);

                if(buscarLista(listaDin,cpf)!=NULL) printf("ENCONTRADO DINAMICA\n");

                if(buscaListaEst(&listaEst,cpf)!=-1) printf("ENCONTRADO ESTATICA\n");

            break;

            case 5:

                printf("CPF: ");
                scanf("%14s",cpf);

                listaDin = removerLista(listaDin,cpf);

                removerListaEst(&listaEst,cpf);

            break;

            case 6:

                salvarLista(listaDin,"funcionariosDin.txt");

                salvarListaEst(&listaEst,"funcionariosEst.txt");

            break;

            case 7:

                listaDin =
                carregarLista(listaDin,"funcionariosDin.txt");

                carregarListaEst(&listaEst,"funcionariosEst.txt");

            break;
        }

    }while(op!=0);

    listaDin = liberarLista(listaDin);

    return 0;
}