#include "../include/tListaMusica.h"

typedef struct celula Celula;

struct ListaMusica{
    Celula *pri;
    Celula *ult;
};

struct celula{
    tMusica *mus;
    Celula *prox;
};

tListaMusica *iniciaSentinelaMusica(){
    tListaMusica *sent = (tListaMusica *) malloc(sizeof(tListaMusica));
    sent->pri = NULL;
    sent->ult = NULL;

    return sent;
}

void insereMusica(tListaMusica *sent,tMusica *musica){
    Celula *novaCel = (Celula *) malloc(sizeof(Celula));
    novaCel->mus = musica;
    novaCel->prox = NULL;
    
    if(sent->pri == NULL){
        sent->pri = novaCel;
        sent->ult = novaCel;
    }else{
        sent->ult->prox = novaCel;
        sent->ult = novaCel;
    }
}

void liberaListaMusica(tListaMusica *sent){
    Celula *p = sent->pri;
    Celula *t;

    while(p != NULL){
        t = p->prox;
        liberaMusica(p->mus);
        free(p);
        p = t;
    }

    free(sent);
}

void printaListaMusica(tListaMusica *sent){
    Celula *p;
    for(p=sent->pri; p!=NULL ; p = p->prox){
        printaMusica(p->mus);
        printf("\n");
    }
}