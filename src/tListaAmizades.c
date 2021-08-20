#include "../include/tListaAmizade.h"

typedef struct celula Celula;

struct ListaAmigos
{
    Celula *pri;
    Celula *ult;
};

struct celula
{
    Celula *prox;
    tUsuario *usu;
};

tListaAmigos *iniciaSentinelaAmigos()
{
    tListaAmigos *set = (tListaAmigos *)malloc(sizeof(tListaAmigos));
    set->pri = NULL;
    set->ult = NULL;

    return set;
}

void insereAmigo(tListaAmigos *sent, tUsuario *usuario)
{
    Celula *novaCel = (Celula *)malloc(sizeof(Celula));
    novaCel->prox = NULL;
    novaCel->usu = usuario;

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

void liberaListaAmigos(tListaAmigos *sent)
{
    Celula *p = sent->pri;
    Celula *t;

    while (p != NULL)
    {
        t = p->prox;
        free(p);
        p = t;
    }

    free(sent);
}

void comparaAmigos(tUsuario *usuario, tListaAmigos *sentAmg)
{
    Celula *p;
    char *nomeUsu = retornaNomeUsu(usuario);
    for (p = sentAmg->pri; p != NULL; p = p->prox)
    {
        char *nomeAmg = retornaNomeUsu(p->usu);
        if (procuraNomes(nomeUsu, nomeAmg) == 0)
        {
            FILE *arq = fopen("data/Saida/similaridades.txt", "a+");
            tListaPlaylist *sentPlay1 = retornaListaPlayList(usuario);
            tListaPlaylist *sentPlay2 = retornaListaPlayList(p->usu);

            int similaridade = similaridadeListaPlay(sentPlay1, sentPlay2);
            fprintf(arq, "%s;%s;%d\n", nomeUsu, nomeAmg, similaridade);

            fclose(arq);
        }
    }
}

int procuraNomes(char *nomeUsu, char *nomeAmg)
{
    FILE *arq = fopen("data/Saida/similaridades.txt", "r");
    if (arq == NULL)
    {
        printf("Erro na aberturda do arquivo similaridades.txt\n");
        exit(1);
    }
    char nomeAux1[50], nomeAux2[50];
    int aux;
    while (fscanf(arq, "%[^;];%[^;];%d ", nomeAux1, nomeAux2, &aux) == 3)
    {
        if (strcmp(nomeAux1, nomeUsu) == 0 && strcmp(nomeAux2, nomeAmg) == 0)
        {
            fclose(arq);
            return 1;
        }
        else if (strcmp(nomeAux1, nomeAmg) == 0 && strcmp(nomeAux2, nomeUsu) == 0)
        {
            fclose(arq);
            return 1;
        }
    }
    fclose(arq);
    return 0;
}