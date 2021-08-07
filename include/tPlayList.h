#ifndef T_PLAYLIST
#define T_PLAYLIST

typedef struct Playlist tPlaylist;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tListaMusica.h"
#include "tListaPlayList.h"

tPlaylist *inicializaPlayList();

void preenchePlayList(tPlaylist *playList,char *nome);

void preencheNovaPlayList(tPlaylist *playList, tMusica *musica, char *nome);

void liberaPlayList(tPlaylist *playList);

char *retornaNomePlay(tPlaylist *Playlist);

tListaMusica *retornaListaMusica(tPlaylist *playList);

//test
void printaPlayList(tPlaylist *playList);


#endif