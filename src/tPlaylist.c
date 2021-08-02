#include "../include/tPlaylist.h"
#include "../include/tListaMusica.h"

struct Playlist{
    char *nome;
    tListaMusica *sentMus;
};

tPlaylist *inicializaPlayList(){
    tPlaylist *playList = (tPlaylist *) malloc(sizeof(tPlaylist));
    //chamar uma funcao inicializaSentinelaMusic() aqui;

    return playList;
}

void preencheNomePlayList(tPlaylist *playList,char *nome){
    playList->nome = strdup(nome);
}

void liberaPlayList(tPlaylist *playList){
    free(playList->nome);
    //chama uma função aqui para liberar a lista de musicas

    free(playList);
}


//test
void printaPlayList(tPlaylist *playList){
    printf("%s ",playList->nome);
}