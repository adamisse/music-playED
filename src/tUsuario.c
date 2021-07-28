#include "../include/tUsuario.h"
#include "../include/tListaAmizade.h"

struct Usuario{
    char *nome;

    tListaAmigos *sent;
    //ponteiro para lista de amizades
    //ponteiro para lista de playlist
};