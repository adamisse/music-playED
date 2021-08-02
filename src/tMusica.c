#include "../include/tMusica.h"

struct Musica{
    char *nomeMus;
    char *nomeBand;
};

char *retornaNomeMusica(tMusica *musica){
    return musica->nomeMus;
}

char *retornaNomeBanda(tMusica *musica){
    return musica->nomeBand;
}