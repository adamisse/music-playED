#ifndef T_LISTA_MUSICA
#define T_LISTA_MUSICA

typedef struct ListaMusica tListaMusica;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tMusica.h"
#include "tListaPlayList.h"

tListaMusica *iniciaSentinelaMusica();

void insereMusica(tListaMusica *sent, tMusica *musica);

void liberaListaMusica(tListaMusica *sent);

void refatorandoListaMusica(tListaMusica *sentMus, tListaPlaylist *sentPlay);

int similaridadeListaMusica(tListaMusica *sent1, tListaMusica *sent2);

void printaListaMusica(tListaMusica *sent, FILE *arq);

#endif