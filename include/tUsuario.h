#ifndef T_USUARIO
#define T_USUARIO

typedef struct Usuario tUsuario;
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPlaylist.h"
#include "tListaAmizade.h"

tUsuario *inicializaUsuario();

void preencheNomeUsuario(tUsuario *usuario, char *nome);

void liberaUsuario(tUsuario *usuario);

char *retornaNomeUsu(tUsuario *usuario);

tListaPlaylist *retornaListaPlayList(tUsuario *usuario);

tListaAmigos *retornaListaAmigos(tUsuario *usuario);

void preencheListaAmigos(tUsuario *usuario1, tUsuario *usuario2);

void preencheListaPlayList(tUsuario *usuario, tPlaylist *playList);

void refatorandoUsuario(tUsuario *usuario);

#endif