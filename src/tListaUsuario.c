#include "../include/tListaUsuario.h"
#include "../include/tListaAmizade.h"
#include "../include/tUsuario.h"

typedef struct celula Celula;

struct ListaUsu
{
    Celula *pri;
    Celula *ult;
};

struct celula
{
    tUsuario *usuario;
    Celula *prox;
};

tListaUsu *iniciaSentinelaUsuario()
{
    tListaUsu *set = (tListaUsu *)malloc(sizeof(tListaUsu));
    set->pri = NULL;
    set->ult = NULL;

    return set;
}

void criaListaUsuarios(tListaUsu *sent)
{
    FILE *arq = fopen("data/Entrada/amizade.txt", "r");
    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo amizade.txt\n");
        exit(1);
    }

    char nomeAux[150], nomeAux2[150], quebra;
    while (fscanf(arq, "%[^;^\n]%c", nomeAux, &quebra) == 2)
    {
        tUsuario *usuario = inicializaUsuario();
        preencheNomeUsuario(usuario, nomeAux);
        insereUsuario(sent, usuario);

        if (quebra == '\n')
            break;
    }

    while (fscanf(arq, "%[^;];%[^\n]\n", nomeAux, nomeAux2) == 2)
    {
        tUsuario *amigo1 = procuraUsuario(sent, nomeAux);
        tUsuario *amigo2 = procuraUsuario(sent, nomeAux2);

        preencheListaAmigos(amigo1, amigo2);
    }
    fclose(arq);
}

void refatorandoListaUsuarios(tListaUsu *sent)
{
    Celula *p = sent->pri;
    while (p != NULL)
    {
        refatorandoUsuario(p->usuario);
        p = p->prox;
    }
}

void insereUsuario(tListaUsu *sent, tUsuario *usuario)
{
    Celula *novaCel = (Celula *)malloc(sizeof(Celula));
    novaCel->usuario = usuario;
    novaCel->prox = NULL;

    if (sent->pri == NULL)
    {
        sent->pri = novaCel;
        sent->ult = novaCel;
    }
    else
    {
        sent->ult->prox = novaCel;
        sent->ult = novaCel;
    }
}

void geraSaida(tListaUsu *sent)
{
    Celula *p;
    char adress[150];
    system("mkdir data/Saida");

    char adressAux[150] = "mkdir data/Saida/";
    FILE *arq = fopen("data/Saida/played-refatorada.txt", "w");
    FILE *arqSimi = fopen("data/Saida/similaridades.txt", "w");
    if (arq == NULL || arqSimi == NULL)
    {
        printf("Erro na criação do arquivo played-refatorada.txt ou similaridades.txt\n");
        exit(1);
    }
    fclose(arqSimi);

    for (p = sent->pri; p != NULL; p = p->prox)
    {
        tListaPlaylist *sentPlay = retornaListaPlayList(p->usuario);
        int qtdPlay = qtdPlayList(sentPlay);
        char *nomeUsu = retornaNomeUsu(p->usuario);

        strcpy(adress, adressAux);
        strncat(adress, nomeUsu, 150);
        system(adress);

        fprintf(arq, "%s;%d", nomeUsu, qtdPlay);
        printaListaplayList(sentPlay, arq, nomeUsu);

        tListaAmigos *sentAmg = retornaListaAmigos(p->usuario);
        comparaAmigos(p->usuario, sentAmg);
    }
    fclose(arq);
}

void liberaListaUsuario(tListaUsu *sent)
{
    Celula *p = sent->pri;
    Celula *t;

    while (p != NULL)
    {
        t = p->prox;

        liberaUsuario(p->usuario);
        free(p);
        p = t;
    }

    free(sent);
}

tUsuario *procuraUsuario(tListaUsu *sent, char *nome)
{
    Celula *p = sent->pri;

    while (1)
    {
        if (p == NULL)
            return NULL;
        else if (strcmp(nome, retornaNomeUsu(p->usuario)) == 0)
            return p->usuario;
        else
            p = p->prox;
    }
}