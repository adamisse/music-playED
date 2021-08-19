#ifndef T_LISTA_PLAYLIST
#define T_LISTA_PLAYLIST

//Estrutura para servir de sentinela para uma lista de playLists;
typedef struct ListaPlaylist tListaPlaylist;

#include <stdio.h>
#include <stdlib.h>
#include "tListaUsuario.h"

/*
 *  Inicializa um struct tListaPlaylist;
 *  Outputs: Um ponteiro do tipo tListaPlaylist inicializada;
 *  pos-condição: Ponteiro do tipo tListaPlaylist agora e assume uma lista de playLists;
*/
tListaPlaylist *iniciaSentinelaPlaylist();

/*
 *  Função para preencher ler arquivo playlists.txt e criar listas de playLists para cada usuario;
 *  Inputs: Um ponteiro do tipo tListaUsu contendo uma pre definida lista de usuarios;
 *  pre-condição: Uma lista de usuarios já definida e a existencia de um arquivo txt contendo os usuario/playLists em data/Entrada/playlists.txt
 *  pos-condição: Os usuarios possuem suas listas de playLists preenchidas;
*/
void criaListaPlayList(tListaUsu *sent);

/*
 *  Função para inserir um ponteiro tipo tPlaylist dentro de sua respectiva lista;
 *  Inputs: Um ponteiro tListaPlaylist(sentinela da lista de playLists) e outro ponteiro do tipo tPlayList(a ser inserido na lista);
 *  pre-condição: O ponteiro do tipo tListaPlayList esta definido e o ponteiro tPlayList estar definido/preenchido;
 *  pos-condição: É adicionada mais uma celula(contendo a playLists passada) a lista de playLists;
*/
void inserePlaylist(tListaPlaylist *sent, tPlaylist *scan);

/*
 *  Função para procurar a existencia de uma tPlayLists na lista com base em uma chave(seu respectivo nome);
 *  Inputs: Ponteiro(sentinela) da lista de playLists e uma chave (ponteiro do tipo char) a ser buscada;
 *  Outputs: Ponteiro com valor do tipo tPlaylist encontrado; 
 *  pre-condição: Lista de playList já inicializada e nome válido;
 *  pos-condição: Playlist de retorno existe caso o nome seja encontrado;
*/
tPlaylist *procuraPlaylist(tListaPlaylist *sent, char *nome);

/*
 *  Função para liberar a lista de playLists(suas respetivas celulas e playLists contidas);
 *  Inputs: Ponteiro (sentinela) de tListaPlaylist;
 *  pre-condição: Ponteiro (sentinela) tListaPlaylist esteja inicializado;
 *  pos-condição: A lista de playLists agora foi liberada(celulas/sentinela/conteudo das playLists);
*/
void liberaListaPlaylist(tListaPlaylist *sent);

/*
 *  Função para preencher nova listaPlaylist com base nos valores contidos no em uma lista anteiormente preenchida;
 *  Inputs: Dois ponteiros do tipo tListaPlaylis(duas sentinelas);
 *  pre-condição: *sent deve estar definida/preenchida e *novaSent definida;
 *  pos-condição: A *novaSent será preenchida com base nos dados de *sent, em sequencia *sent é liberada;
*/
void refatoraListaPlaylist(tListaPlaylist *sent, tListaPlaylist *novaSent);

/*
 *  Função para contar quantidade de playLists em tListaPlaylist;
 *  Inputs: Um ponteiro (sentinela) do tipo tListaPlayList a ser analisada;
 *  Outputs: Inteiro com a quantidade de playLists contidas na lista em questão;
 *  pre-condição: *sent deve estar definida;
 *  pos-condição: Retorno de um inteiro com o número de elemtos na lista;
*/
int qtdPlayList(tListaPlaylist *sent);

/*
 *  Função para percorrer duas listas de playLists e calculas a similaridade de seus dados internos;
 *  Inputs: Dois ponteiros(duas sentinelas) com as listas a serem comparadas;
 *  Outputs: Um inteiro com o total de similaridades;
 *  pre-condição: Os ponterios(sentinelas) estarem definidos e preenchidos;
 *  pos-condição: Inteiro com a quantidade de musicas iguais na comparação das playLists;
*/
int similaridadeListaPlay(tListaPlaylist *sent1, tListaPlaylist *sent2);

/*
 *  Função para gerar arquivos de saida com base nos dados contidos na lista de playLists;
 *  Inputs: Ponteiro(sentinela) da lista de playLists, um ponteiro de arquivo(played-refatorada.txt) e um ponteiro char identificando o diretorio;
 *  pre-condição: Criação dos diretorios onde serão armazenados os arquivos criados. Definição prévia dos ponteiros de parametro.
 *  pos-condição: Existência dos arquivos de texto com os dados da lista de playLists dentro do diretorios do respectivo usuario e preenchimento do arquivo played-refatorada.txt.
*/
void printaListaplayList(tListaPlaylist *sent, FILE *arq, char *nomeUsu);

#endif