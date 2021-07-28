#ifndef T_USUARIO
#define T_USUARIO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Usuario tUsuario;

tUsuario *iniciaUsuario();

void preencheUsuario(tUsuario *usuario);

void insereNome(tUsuario *usuario, char *nome);


#endif