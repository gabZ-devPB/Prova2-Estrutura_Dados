#include "listaEstatica.h"
#include <stdio.h>
#include <string.h>

TipoListaEst criarListaEst()
{
    TipoListaEst lista;

    lista.qtde = 0;

    return lista;
}

int listaVaziaEst(TipoListaEst *lista)
{
    return(lista->qtde == 0);
}

int listaCheiaEst(TipoListaEst *lista)
{
    return(lista->qtde == TamMax);
}

int buscaListaEst(TipoListaEst *lista,char cpf[15])
{
    int i;

    for(i=0;i<lista->qtde;i++)
    {
        if(strcmp(lista->elemt[i].cpf,cpf)==0)
            return i;
    }

    return -1;
}

int inserirListaEst(TipoListaEst *lista,TipoFuncionario func)
{
    int i,pos;

    if(listaCheiaEst(lista))
        return 0;

    if(buscaListaEst(lista,func.cpf)!=-1)
        return 0;

    pos = lista->qtde;

    for(i=0;i<lista->qtde;i++)
    {
        if(strcmp(lista->elemt[i].nome,func.nome)>0)
        {
            pos = i;
            break;
        }
    }

    for(i=lista->qtde;i>pos;i--)
        lista->elemt[i]=lista->elemt[i-1];

    lista->elemt[pos]=func;

    lista->qtde++;

    return 1;
}

void imprimirListaEst(TipoListaEst *lista)
{
    int i;

    if(listaVaziaEst(lista))
    {
        printf("LISTA VAZIA\n");
        return;
    }

    for(i=0;i<lista->qtde;i++)
    {
        printf("\nNome: %s",lista->elemt[i].nome);

        printf("\nCPF: %s",lista->elemt[i].cpf);

        printf("\nSalario: %.2f\n",lista->elemt[i].salario);
    }
}

int removerListaEst(TipoListaEst *lista,char cpf[15])
{
    int i,pos;

    pos = buscaListaEst(lista,cpf);

    if(pos==-1)
        return 0;

    for(i=pos;i<lista->qtde-1;i++)
        lista->elemt[i]=lista->elemt[i+1];

    lista->qtde--;

    return 1;
}

void salvarListaEst(TipoListaEst *lista,char nomeArquivo[])
{
    FILE *fp;

    fp = fopen(nomeArquivo,"w");

    if(fp==NULL)
        return;

    for(int i=0;i<lista->qtde;i++)
    {
        fprintf(fp,"%s,%s,%.2f\n",
                lista->elemt[i].nome,
                lista->elemt[i].cpf,
                lista->elemt[i].salario);
    }

    fclose(fp);
}

void carregarListaEst(TipoListaEst *lista,char nomeArquivo[])
{
    FILE *fp;
    TipoFuncionario func;

    fp = fopen(nomeArquivo,"r");

    if(fp==NULL)
        return;

    while(fscanf(fp,"%99[^,],%14[^,],%f\n",
                 func.nome,
                 func.cpf,
                 &func.salario)==3)
    {
        inserirListaEst(lista,func);
    }

    fclose(fp);
}