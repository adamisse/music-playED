#include "../include/tListaPlayList.h"
#include "../include/tUsuario.h"

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

void criaFilaPlayList(tListaUsu *sent){
    FILE *arq = fopen("data/Entrada/playlists.txt","r");
    if(arq == NULL){
        printf("Erro na abertura do arquivo playLista.txt!\n");
        exit(1);
    }
    char nome[50];
    int qtdPlayL;

    while(fscanf(arq,"%[^;];%d",nome,&qtdPlayL) == 2){
        tUsuario *usuario = procuraUsuario(sent,nome);
        for(int i=0; i<qtdPlayL ;i++){
            char nomePlay[50];
            fscanf(arq,";%[^;^\n] ",nomePlay);
            
            tPlaylist *playList = inicializaPlayList();
            preencheNomePlayList(playList,nomePlay);
            preenchePlayList(usuario,playList);
        }
    }

    fclose(arq);
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
        liberaPlayList(p->playList);
        free(p);
        p = t;
    }

    free(sent);
}


void printaListaplayList(tListaPlaylist *sent){
    Celula *p;
    for(p=sent->pri; p!=NULL ; p = p->prox){
        printaPlayList(p->playList);
    }
}