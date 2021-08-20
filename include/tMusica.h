#ifndef T_MUSICA
#define T_MUSICA

typedef struct Musica tMusica;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tMusica *inicializaMusica(char *banda,char *musica);

void liberaMusica(tMusica *musica);

void printaMusica(tMusica *musica);

char *retornaNomeMus(tMusica *musica);

char *retornaNomeBan(tMusica *musica);




#endif