#ifndef T_USUARIO
#define T_USUARIO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPlaylist.h"

typedef struct Usuario tUsuario;

tUsuario *inicializaUsuario();

void preencheNomeUsuario(tUsuario *usuario, char *nome);

void preencheQtdPlayList(tUsuario *usuario, int qtdPlayList);

void liberaUsuario(tUsuario *usuario);

char *retornaNomeUsu(tUsuario *usuario);

void preencheListaAmigos(tUsuario *usuario1, tUsuario *usuario2);

void preencheListaPlayList(tUsuario *usuario,tPlaylist *playList);

//so testando
void printaUsuario(tUsuario *usuario);

#endif