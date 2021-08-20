#ifndef T_LISTA_MUSICA
#define T_LISTA_MUSICA

//Definição da estrutura responsável por manipular a sequência de músicas contidas nos arquivos e playlists;
typedef struct ListaMusica tListaMusica;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tMusica.h"
#include "tListaPlayList.h"

/*  
 *  Inicializa o struct de tListaMusica com *ult *pri;
 *  output: Um ponteiro para o tipo tListaMusica que foi inicializado;
 *  pos-condição: ponteiro de retorno ser diferente de NULL e contendo ponteiros para primeira e ultima celula da lista de musicas;
*/
tListaMusica *iniciaSentinelaMusica();

/* 
 * Insere Uma música do tipo tMmusica dentro de uma célula de tListaMusica;
 * inputs: Ponteiro para uma sentinela e para uma música;
 * pre-condicao: Ambos, sentinela e música, previamente inicializados;
 * pos-condicao: Cria-se um ponteiro dentro de uma das células de lista de músicas para a tMusica que acabou de ser inserida;
*/
void insereMusica(tListaMusica *sent, tMusica *musica);

/*
 *  Libera as celulas contidas na lista de músicas;
 *  Inputs: Ponteiro correspondente a sentinela da lista de músicas;
 *  pre-condição: Um ponteiro do tipo tListaMusica estar alocado;
 *  pos-condição: O ponteiro de tListaMusica é liberado juntamente de suas células;
*/
void liberaListaMusica(tListaMusica *sent);

/*
 * Baseando-se nas músicas contidas na lista de música, gera uma lista de playlists separada pelas músicas de cada um dos artistas;
 * inputs: Sentinelas  tanto para a lista de músicas quanto para a lista de playlists;
 * pre-condicao: Ambas as sentinelas previamente inicializadas;
 * pos-condicao: Cria-se uma playlist com o nome do artista/banda, e nela é inserida uma lista das músicas deste artista/banda que são ouvidas pelo usuário;
*/
void refatorandoListaMusica(tListaMusica *sentMus, tListaPlaylist *sentPlay);

/*
 * Efetua o cálculo do quão similares são duas listas de músicas;
 * inputs: Dois ponteiros para sentinelas de listas de músicas;
 * output: A quantidade de músicas similares;
 * pre-condicao: Ambas as sentinelas previamente inicializadas;
 * pos-condicao: A incrementação da similaridade entre as listas de músicas que foram comparadas;
*/
int similaridadeListaMusica(tListaMusica *sent1, tListaMusica *sent2);

/*
 * inputs: Ponteiros para uma sentinela e para um arquivo txt;
 * pre-condicao: Ambos, sentinela e arquivo para a lista de músicas já terem sido inicializados;
 * pos-condicao: Escrever, no arquivo de interesse, nome do artista/banda seguido do nome da música;
*/
void printaListaMusica(tListaMusica *sent, FILE *arq);

#endif