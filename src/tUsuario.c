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
    usuario->sentAmg = iniciaSentinelaAmigos();
    usuario->sentPla = iniciaSentinelaPlaylist();

    return usuario;
}

void preencheNomeUsuario(tUsuario *usuario, char *nome){
    usuario->nome = strdup(nome);
}

void preencheListaAmigos(tUsuario *usuario1, tUsuario *usuario2){
    insereAmigo(usuario1->sentAmg,usuario2);
    insereAmigo(usuario2->sentAmg,usuario1);
}

void liberaUsuario(tUsuario *usuario){
    free(usuario->nome);
    //chamar 2 funções de free aqui para liberar o usuario por completo;
    liberaListaAmigos(usuario->sentAmg);
    //liberaListaPlaylist(usuario->sentPla);

    free(usuario);
}

char *retornaNomeUsu(tUsuario *usuario){
    return usuario->nome;
}

void printaUsuario(tUsuario *usuario){
    printf("%s\n",usuario->nome);
    printf("Amigos:");
    printaListaAmigos(usuario->sentAmg);
    printf("\n");
}