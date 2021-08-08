#include "../include/tListaUsuario.h"
#include "../include/tListaPlayList.h"

int main(){
    tListaUsu *sentUsu = iniciaSentinelaUsuario();
    criaFilaUsuarios(sentUsu);
    criaFilaPlayList(sentUsu);

    //apenas testando aqui
    printaFilaUsuarios(sentUsu);
    refatorandoListaUsuarios(sentUsu);
    //testnado
    printaFilaUsuarios(sentUsu);

    geraSaida(sentUsu);
    liberaListaUsuario(sentUsu);
    return 0;
}