#include "../include/tListaPlayList.h"

typedef struct celula Celula;

struct ListaPlaylist{
    Celula *pri;
    Celula *ult;
};

struct celula{
    tPlaylist *playList;
    Celula *prox;
};

tListaPlaylist *iniciaSentinelaPlaylist(){
    tListaPlaylist *set = (tListaPlaylist *) malloc(sizeof(tListaPlaylist));
    set->pri = NULL;
    set->ult = NULL;

    return set;
}

void inserePlaylist(tListaPlaylist *sent, tPlaylist *playlist){
    Celula *novaCel = (Celula *) malloc(sizeof(Celula));
    novaCel->prox = NULL;
    novaCel->playList = playlist;

    if(sent->pri == NULL){
        sent->pri = novaCel;
        sent->ult = novaCel;
    }else{
        sent->ult->prox = novaCel;
        sent->ult = novaCel;
    }
}

void liberaListaPlaylist(tListaPlaylist *sent){ 
    Celula *p = sent->pri;
    Celula *t;

    while(p != NULL){
        t = p->prox;
        //liberar oq estiver dentro da celula de usuario
        //provavelmente chamar aqui uma funcao assim:
        //liberaPlaylist(p->playList)
        free(p);
        p = t;
    }

    free(sent);
}