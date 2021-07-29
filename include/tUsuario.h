#ifndef T_USUARIO
#define T_USUARIO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Usuario tUsuario;

tUsuario *inicializaUsuario();

void preencheNomeUsuario(tUsuario *usuario, char *nome);

void liberaUsuario(tUsuario *usuario);

char *retornaNomeUsu(tUsuario *usuario);

void preencheListaAmigos(tUsuario *usuario1, tUsuario *usuario2);

//so testando
void printaUsuario(tUsuario *usuario);

#endif