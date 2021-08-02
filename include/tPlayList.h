#ifndef T_PLAYLIST
#define T_PLAYLIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Playlist tPlaylist;

tPlaylist *inicializaPlayList();

void preencheNomePlayList(tPlaylist *playList,char *nome);

void liberaPlayList(tPlaylist *playList);


//test
void printaPlayList(tPlaylist *playList);

#endif