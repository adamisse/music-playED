#include "../include/tMusica.h"

struct Musica{
    char *nomeMus;
    char *nomeBand;
};

tMusica *inicializaMusica(char *banda,char *musica){
    tMusica *mus = (tMusica *) malloc(sizeof(tMusica));
    mus->nomeBand = strdup(banda);
    mus->nomeMus = strdup(musica);

    return mus;
}

void liberaMusica(tMusica *musica){
    free(musica->nomeMus);
    free(musica->nomeBand);
    free(musica);
}

char *retornaNomeMus(tMusica *musica){
    return musica->nomeBand;
}

char *retornaNomeBan(tMusica *musica){
    return musica->nomeBand;
}

void printaMusica(tMusica *musica){
    printf("%s- %s",musica->nomeBand,musica->nomeMus);
}