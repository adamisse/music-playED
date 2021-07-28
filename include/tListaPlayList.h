#ifndef T_LISTA_PLAYLIST
#define T_LISTA_PLAYLIST

#include <stdio.h>
#include <stdlib.h>
#include "tPlaylist.h"

typedef struct ListaPlaylist tListaPlaylist;

tListaPlaylist *iniciaSentinelaPlaylist();

void inserePlaylist(tListaPlaylist *sent, tPlaylist *scan);

void liberaListaPlaylist(tListaPlaylist *sent);

#endif