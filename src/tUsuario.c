#include "../include/tUsuario.h"
#include "../include/tListaUsuario.h"
#include "../include/tListaAmizade.h"
#include "../include/tListaPlayList.h"

struct Usuario{
    char *nome;
    tListaAmigos *sentAmg;
    tListaPlaylist *sentPla;
};

tUsuario *inicializaUsuario(){
    tUsuario *usuario = (tUsuario *) malloc(sizeof(tUsuario));
    return usuario;
}

void preencheNomeUsuario(tUsuario *usuario, char *nome){
    usuario->nome = strdup(nome);
}

void liberaUsuario(tUsuario *usuario){
    free(usuario->nome);
    //chamar 2 funções de free aqui
    //liberaListaAmigos(usuario->sentAmg);
    //liberaListaPlaylist(usuario->sentPla);

    free(usuario);
}



void printaNome(tUsuario *usuario){
    printf("%s\n",usuario->nome);
}