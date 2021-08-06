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
        preencheQtdPlayList(usuario,qtdPlayL);
        for(int i=0; i<qtdPlayL ;i++){
            char nomePlay[50];
            fscanf(arq,";%[^;^\n] ",nomePlay);
            
            tPlaylist *playList = inicializaPlayList();
            preenchePlayList(playList,nomePlay);
            //chamar função para preencher lista de musica da play list
            //essa função vai passar a playList
            preencheListaPlayList(usuario,playList);
        }
    }

    fclose(arq);
}

void refatoraListaPlaylist(tListaPlaylist *sent, int qtdPlay){
    Celula *p = sent->pri;
    for(int i=0; i<qtdPlay ;i++){
        tListaMusica *sentMus = retornaListaMusica(p->playList);
        //a ideia aqui eh criar uma serie de playLists com base nessa lista de musicas;
        //colocar essas playLists novas na lista com a inserePlaylist();
        //depois liberar essa playLista inicial contida na celula atual;

        //como criar as playList com base na lista de musicas *???????????????????????????????????*
        //ok isso daqui ta complicado msm

        p = p->prox;
    }
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

tPlaylist *procuraPlaylist(tListaPlaylist *sent, char *nome){
    Celula *p = sent->pri;

    while(1){
        if(p == NULL) return NULL;
        else if(strcmp(nome,retornaNomePlay(p->playList)) == 0) return p->playList;
        else p = p->prox;
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