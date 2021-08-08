#ifndef T_LISTA_AMIZADE
#define T_LISTA_AMIZADE

typedef struct ListaAmigos tListaAmigos;

#include <stdio.h>
#include <stdlib.h>
#include "tUsuario.h"

tListaAmigos *iniciaSentinelaAmigos();

void insereAmigo(tListaAmigos *sent, tUsuario *usuario);

void liberaListaAmigos(tListaAmigos *sent);

void comparaAmigos(tUsuario *usuario, tListaAmigos *sentAmg);

int procuraNomes(char *nomeUsu, char *nomeAmg);

#endif