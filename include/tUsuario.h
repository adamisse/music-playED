#ifndef T_USUARIO
#define T_USUARIO

//Definição da estrutura que carrega os dados de cada cliente;
typedef struct Usuario tUsuario;
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPlaylist.h"
#include "tListaAmizade.h"

/*
 *  Função responsável pela inicialização do tipo tUsuario junto com seus dados internos;
 *  Output: Um ponteiro tipo tUsuario;
 *  pos-condição: tUsuario agora existe e tem espaço alocado para seus dados internos;
*/
tUsuario *inicializaUsuario();

/*
 *  Função para alocar/preencher um ponteiro interno de tUsuario com função de carregar o nome do cliente;
 *  Inputs: Um ponteiro tipo char que carrega a string nome e um ponteiro tipo tUsuario que receberá o nome;
 *  pre-condição: Char *nome deve existir e carregar uma string e o ponteiro de tUsuario deve estar previamente alocado;
 *  pos-condição: A estrutura interna do ponteiro tUsuario em questão agora carrega uma string contendo o nome do cliente;
*/
void preencheNomeUsuario(tUsuario *usuario, char *nome);

/*
 *  Função para liberar da memória um tipo tUsuario;
 *  Inputs: Um ponteiro tipo tUsuario com a estrutura a ser liberada;
 *  pre-condição: O ponteiro de tUsuario deve existir;
 *  pos-condição: Agora o ponteiro tUsuario tem seus dados internos liberados da memória por completo;
*/
void liberaUsuario(tUsuario *usuario);

/*
 *  Função de acesso ao nome de um cliente;
 *  Inputs: Um ponteiro tipo tUsuario;
 *  Output: Um ponteiro tipo char carregando uma string com o nome do cliente;
 *  pre-condição: O ponteiro de tUsuario deve existir e estar com o campo "nome" previamente preenchido;
 *  pos-condição: O campo "nome" contido no ponteiro tUsuario agora é visível;
*/
char *retornaNomeUsu(tUsuario *usuario);

/*
 *  Função de acesso a lista de playList's de um cliente;
 *  Inputs: Um ponteiro tipo tUsuario;
 *  Output: Um ponteiro tipo tListaPlaylist que carrega a sentinela de uma lista de playLists;
 *  pre-condição: O ponteiro de tUsuario deve existir;
 *  pos-condição: O campo "tListaPlaylist" contido no ponteiro tUsuario agora é visível;
*/
tListaPlaylist *retornaListaPlayList(tUsuario *usuario);

/*
 *  Função de acesso a lista de amigos de um cliente;
 *  Inputs: Um ponteiro tipo tUsuario;
 *  Output: Um ponteiro tipo tListaAmigos que carrega a sentinela de uma lista de amigos;
 *  pre-condição: O ponteiro de tUsuario deve existir;
 *  pos-condição: O campo "tListaAmigos" contido no ponteiro tUsuario agora é visível;
*/
tListaAmigos *retornaListaAmigos(tUsuario *usuario);

/*
 *  Função para acessar e inserir no campo de tListaAmigos um amigo;
 *  Inputs: Dois ponteiro tipo tUsuario que representam uma amizade;
 *  pre-condição: Os ponteiros de tUsuario devem existir;
 *  pos-condição: Agora a tListaAmigos contem a relação de amizade entre os usuarios;
*/
void preencheListaAmigos(tUsuario *usuario1, tUsuario *usuario2);

/*
 *  Função para acessar e inserir no campo de tListaPlaylist de um cliente uma nova playList;
 *  Inputs: Um ponteiro do tipo tUsuario com o cliente em questão e um ponteiro tPlaylist contendo a playList a ser adicionada;
 *  pre-condição: Os ponteiros de tUsuario/tPlaylist devem existir e estarem preenchidos;
 *  pos-condição: Agora a lista tListaPlaylist contem uma nova celula com a playList em questão;
*/
void preencheListaPlayList(tUsuario *usuario, tPlaylist *playList);

/*
 *  Função para inicializar e preencher uma nova lista de playLists que substituirá a antiga;
 *  Inputs: Um ponteiro do tipo tUsuario a ser refatorando;
 *  pre-condição: Os ponteiros de tUsuario deve existir e estar preenchido;
 *  pos-condição: Agora há uma nova lista de playLists do clienta, subtituindo a antiga não refatorada;
*/
void refatorandoUsuario(tUsuario *usuario);

#endif