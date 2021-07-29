#include "../include/tListaUsuario.h"

int main(){
    tListaUsu *sentUsu = iniciaSentinelaUsuario();
    criaFilaUsuarios(sentUsu);

    liberaListaUsuario(sentUsu);
    return 0;
}