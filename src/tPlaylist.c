#include "../include/tPlaylist.h"
#include "../include/tListaMusica.h"

struct Playlist{
    char *nome;
    tListaMusica *sentMus;
};

tPlaylist *inicializaPlayList(){
    tPlaylist *playList = (tPlaylist *) malloc(sizeof(tPlaylist));
    playList->sentMus = iniciaSentinelaMusica();

    return playList;
}

void preenchePlayList(tPlaylist *playList,char *nome){
    playList->nome = strdup(nome);
    
    char address[150] = "data/Entrada/";
    strncat(address,playList->nome,150);

    FILE *arq = fopen(address,"r");
    if(arq == NULL){
        printf("Erro na abertura do arquivo de musicas\n");
        exit(1);
    }

    char nomeBanda[150], nomeMusica[150];
    while(fscanf(arq,"%[^-]- %[^\n] ",nomeBanda,nomeMusica) == 2){
        tMusica *musica = inicializaMusica(nomeBanda,nomeMusica);
        insereMusica(playList->sentMus,musica);
    }

    fclose(arq);
}

void liberaPlayList(tPlaylist *playList){
    free(playList->nome);
    liberaListaMusica(playList->sentMus);

    free(playList);
}

//test
void printaPlayList(tPlaylist *playList){
    printf("%s:\n",playList->nome);
    printaListaMusica(playList->sentMus);
    printf("\n");
}