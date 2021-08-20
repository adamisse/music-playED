#ifndef T_PLAYLIST
#define T_PLAYLIST

//Definição da estrutura responsável pela lógica das playlists;
typedef struct Playlist tPlaylist;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tListaMusica.h"
#include "tListaPlayList.h"

/*  
 *  Inicializa o struct de tPlaylist, fazendo a sua alocação e chamando uma função de inicialização para a sua sentinela;
 *  output: Um ponteiro para o tipo tPlaylist que foi inicializado;
 *  pos-condição: Retorno de um ponteiro para o tipo tPlaylist;
*/
tPlaylist *inicializaPlayList();

/*
 *  Função responsável pela abertura dos arquivos de playlists, bem como a captura de suas informações; 
 *  Inputs: Um ponteiro do tipo tPlaylist, e uma string para armazenar o nome da playlist;
 *  pre-condição: A existência do arquivo de interesse e a playlist em questão ter sido previamente inicializada;
 *  pos-condição: Há o armazenamento das músicas contidas na playlist de entrada dentro de uma célula do tipo tListaMusica;
*/
void preenchePlayList(tPlaylist *playList, char *nome);

/*
 *  Função responsável pelo preenchimento da nova playlist, bem como a modificação do nome (que recebe o nome da banda/artista);
 *  Inputs: Um ponteiro do tipo tPlaylist, um ponteiro do tipo tMusica e uma string para o novo nome da playlist;
 *  pre-condição: Os ponteiros tPlaylist e tMusica previamente alocados e a entrada ser feita de maneira correta;
 *  pos-condição: A playlist passa a ter o nome passado no parâmetro da função e é chamada uma função para inserir as músicas dentro da nova playlist;
*/
void preencheNovaPlayList(tPlaylist *playList, tMusica *musica, char *nome);

/*
 *  Função responsável por liberar o ponteiro do tipo tPlaylist bem como a string do nome da playlist e a sua sentinela;
 *  Inputs: Um ponteiro para o tipo tPlaylist;
 *  pre-condição: Um ponteiro do tipo tPlaylist estar alocado;
 *  pos-condição: O ponteiro de tPlaylist é liberado juntamente das informações presentes na estrutura;
*/
void liberaPlayList(tPlaylist *playList);

/*
 *  Retorna a string do nome da playlist, contida na estrutura tPlaylist;
 *  inputs: Um ponteiro para o tipo tPlaylist;
 *  output: O nome da playlist contido no ponteiro da struct;
 *  pre-condição: Um ponteiro do tipo tPlaylist estar alocado;
 *  pos-condição: Retorno de uma string 'nome' do tipo tPlaylist;
*/
char *retornaNomePlay(tPlaylist *Playlist);

/*
 *  Retorna a sentinela do nome da playlist, contida na estrutura tPlaylist;
 *  inputs: Um ponteiro para o tipo tPlaylist;
 *  output: Uma sentinela contida em tPlaylist;
 *  pre-condição: Um ponteiro do tipo tPlaylist estar alocado;
 *  pos-condição: É feito o retorno de uma sentinela 'sentMus' do tipo tPlaylist;
*/
tListaMusica *retornaListaMusica(tPlaylist *playList);

#endif