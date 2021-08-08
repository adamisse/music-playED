#include "../include/tListaUsuario.h"
#include "../include/tListaPlayList.h"

int main(){
    tListaUsu *sentUsu = iniciaSentinelaUsuario();
    criaFilaUsuarios(sentUsu);
    criaFilaPlayList(sentUsu);

    refatorandoListaUsuarios(sentUsu);
    geraSaida(sentUsu);
    
    liberaListaUsuario(sentUsu);
    return 0;
}