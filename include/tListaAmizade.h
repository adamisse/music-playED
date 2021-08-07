#ifndef T_LISTA_AMIZADE
#define T_LISTA_AMIZADE

typedef struct ListaAmigos tListaAmigos;

#include <stdio.h>
#include <stdlib.h>
#include "tUsuario.h"

tListaAmigos *iniciaSentinelaAmigos();

void insereAmigo(tListaAmigos *sent,tUsuario *usuario);

void liberaListaAmigos(tListaAmigos *sent);


//so de teste
void printaListaAmigos(tListaAmigos *sent);


#endif