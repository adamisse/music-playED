#ifndef T_LISTA_USUARIO
#define T_LISTA_USUARIO

typedef struct ListaUsu tListaUsu;

#include <stdio.h>
#include <stdlib.h>
#include "tUsuario.h"

tListaUsu *iniciaSentinelaUsuario();

void criaListaUsuarios(tListaUsu *sent);

void insereUsuario(tListaUsu *sent, tUsuario *usuario);

void liberaListaUsuario(tListaUsu *sent);

tUsuario *procuraUsuario(tListaUsu *sent, char *nome);

void refatorandoListaUsuarios(tListaUsu *sent);

void geraSaida(tListaUsu *sent);

#endif