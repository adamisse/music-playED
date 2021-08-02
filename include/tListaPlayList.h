#ifndef T_LISTA_PLAYLIST
#define T_LISTA_PLAYLIST

#include <stdio.h>
#include <stdlib.h>
#include "tListaUsuario.h"
#include "tPlaylist.h"

typedef struct ListaPlaylist tListaPlaylist;

tListaPlaylist *iniciaSentinelaPlaylist();

void criaFilaPlayList(tListaUsu *sent);

void inserePlaylist(tListaPlaylist *sent, tPlaylist *scan);

void liberaListaPlaylist(tListaPlaylist *sent);


//teste
void printaListaplayList(tListaPlaylist *sent);

#endif