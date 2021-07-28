#ifndef T_USUARIO
#define T_USUARIO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Usuario tUsuario;

tUsuario *inicializaUsuario();

void preencheNomeUsuario(tUsuario *usuario, char *nome);

void liberaUsuario(tUsuario *usuario);


//so testando
void printaNome(tUsuario *usuario);

#endif