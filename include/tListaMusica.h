#ifndef T_LISTA_MUSICA
#define T_LISTA_MUSICA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tMusica.h"

typedef struct ListaMusica tListaMusica;

tListaMusica *iniciaSentinelaMusica();

//void criaFilaMusica(tListaMusica *sent);

void insereMusica(tListaMusica *sent,tMusica *musica);

void liberaListaMusica(tListaMusica *sent);

void printaListaMusica(tListaMusica *sent);

#endif