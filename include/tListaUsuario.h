#ifndef T_LISTA_USUARIO
#define T_LISTA_USUARIO

#include <stdio.h>
#include <stdlib.h>
#include "tUsuario.h"

typedef struct ListaUsu tListaUsu;

tListaUsu *iniciaSentinelaUsuario();

void criaFilaUsuarios(tListaUsu *sent);

void insereUsuario(tListaUsu *sent,tUsuario *usuario);

void liberaListaUsuario(tListaUsu *sent);

tUsuario *procuraUsuario(tListaUsu *sent, char *nome);


//so de teste
void printaFilaUsuarios(tListaUsu *sent);

#endif