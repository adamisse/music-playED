#ifndef T_LISTA_PLAYLIST
#define T_LISTA_PLAYLIST

typedef struct ListaPlaylist tListaPlaylist;

#include <stdio.h>
#include <stdlib.h>
#include "tListaUsuario.h"

tListaPlaylist *iniciaSentinelaPlaylist();

void criaListaPlayList(tListaUsu *sent);

void inserePlaylist(tListaPlaylist *sent, tPlaylist *scan);

tPlaylist *procuraPlaylist(tListaPlaylist *sent, char *nome);

void liberaListaPlaylist(tListaPlaylist *sent);

void refatoraListaPlaylist(tListaPlaylist *sent, tListaPlaylist *novaSent);

int qtdPlayList(tListaPlaylist *sent);

int comparaListaPlay(tListaPlaylist *sent1, tListaPlaylist *sent2);

void printaListaplayList(tListaPlaylist *sent, FILE *arq, char *nomeUsu);

#endif