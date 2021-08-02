#include "../include/tListaMusica.h"

typedef struct celula Celula;

struct ListaMusica{
    Celula *pri;
    Celula *ult;
};

struct celula{
    Celula *prox;
    tMusica *usu;
};