#include "../include/tPlaylist.h"

struct Playlist
{
    char *nome;
    tListaMusica *sentMus;
};

tPlaylist *inicializaPlayList()
{
    tPlaylist *playList = (tPlaylist *)malloc(sizeof(tPlaylist));
    playList->sentMus = iniciaSentinelaMusica();

    return playList;
}

void preenchePlayList(tPlaylist *playList, char *nome)
{
    playList->nome = strdup(nome);

    char address[150] = "data/Entrada/";
    strncat(address, playList->nome, 150);

    FILE *arq = fopen(address, "r");
    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo de musicas\n");
        exit(1);
    }

    char nomeBanda[150], nomeMusica[150];
    while (fscanf(arq, "%[^-]- %[^\n] ", nomeBanda, nomeMusica) == 2)
    {
        nomeBanda[strlen(nomeBanda) - 1] = '\0';
        tMusica *musica = inicializaMusica(nomeBanda, nomeMusica);
        insereMusica(playList->sentMus, musica);
    }

    fclose(arq);
}

void preencheNovaPlayList(tPlaylist *playList, tMusica *musica, char *nome)
{
    playList->nome = strdup(nome);
    insereMusica(playList->sentMus, musica);
}

void liberaPlayList(tPlaylist *playList)
{
    free(playList->nome);
    liberaListaMusica(playList->sentMus);

    free(playList);
}

char *retornaNomePlay(tPlaylist *Playlist)
{
    return Playlist->nome;
}

tListaMusica *retornaListaMusica(tPlaylist *playList)
{
    return playList->sentMus;
}
