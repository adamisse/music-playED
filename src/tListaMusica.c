#include "../include/tListaMusica.h"

typedef struct celula Celula;

struct ListaMusica
{
    Celula *pri;
    Celula *ult;
};

struct celula
{
    tMusica *mus;
    Celula *prox;
};

tListaMusica *iniciaSentinelaMusica()
{
    tListaMusica *sent = (tListaMusica *)malloc(sizeof(tListaMusica));
    sent->pri = NULL;
    sent->ult = NULL;

    return sent;
}

void insereMusica(tListaMusica *sent, tMusica *musica)
{
    Celula *novaCel = (Celula *)malloc(sizeof(Celula));
    novaCel->mus = musica;
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

void liberaListaMusica(tListaMusica *sent)
{
    Celula *p = sent->pri;
    Celula *t;

    while (p != NULL)
    {
        t = p->prox;
        liberaMusica(p->mus);
        free(p);
        p = t;
    }

    free(sent);
}

void refatorandoListaMusica(tListaMusica *sentMus, tListaPlaylist *sentPlay)
{
    Celula *p;
    for (p = sentMus->pri; p != NULL; p = p->prox)
    {
        char *nomeBand = retornaNomeBan(p->mus);
        char *nomeMusi = retornaNomeMus(p->mus);
        tMusica *musica = inicializaMusica(nomeBand, nomeMusi);

        tPlaylist *playList = procuraPlaylist(sentPlay, nomeBand);
        if (playList == NULL)
        {
            tPlaylist *playList = inicializaPlayList();
            preencheNovaPlayList(playList, musica, nomeBand);
            inserePlaylist(sentPlay, playList);
        }
        else
        {
            tListaMusica *sentMus = retornaListaMusica(playList);
            insereMusica(sentMus, musica);
        }
    }
}

int similaridadeListaMusica(tListaMusica *sent1, tListaMusica *sent2)
{
    Celula *p, *t;
    int similaridade = 0;

    for (p = sent1->pri; p != NULL; p = p->prox)
    {
        char *nomeMus1 = retornaNomeMus(p->mus);
        for (t = sent2->pri; t != NULL; t = t->prox)
        {
            char *nomeMus2 = retornaNomeMus(t->mus);

            if (strcmp(nomeMus1, nomeMus2) == 0)
                similaridade++;
        }
    }
    return similaridade;
}

void printaListaMusica(tListaMusica *sent, FILE *arq)
{
    Celula *p;
    for (p = sent->pri; p != NULL; p = p->prox)
    {
        char *nomeBand = retornaNomeBan(p->mus);
        char *nomeMusi = retornaNomeMus(p->mus);

        fprintf(arq, "%s - %s\n", nomeBand, nomeMusi);
    }
}