#ifndef T_MUSICA
#define T_MUSICA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Musica tMusica;

tMusica *inicializaMusica(char *banda,char *musica);

void liberaMusica(tMusica *musica);

void printaMusica(tMusica *musica);

char *retornaNomeMus(tMusica *musica);

char *retornaNomeBan(tMusica *musica);


#endif