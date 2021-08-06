#ifndef T_PLAYLIST
#define T_PLAYLIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tListaMusica.h"

typedef struct Playlist tPlaylist;

tPlaylist *inicializaPlayList();

void preenchePlayList(tPlaylist *playList,char *nome);

void liberaPlayList(tPlaylist *playList);

char *retornaNomePlay(tPlaylist *Playlist);

tListaMusica *retornaListaMusica(tPlaylist *playList);

//test
void printaPlayList(tPlaylist *playList);

#endif