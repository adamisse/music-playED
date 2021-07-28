#ifndef T_LISTA_USUARIO
#define T_LISTA_USUARIO

#include <stdio.h>
#include <stdlib.h>
#include "tUsuario.h"

typedef struct ListaUsu tListaUsu;

tListaUsu *iniciaSentinelaUsuario();

void insereUsuario(tListaUsu *sent,tUsuario *usuario);

void liberaListaUsuario(tListaUsu *sent);

#endif