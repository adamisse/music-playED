#ifndef T_MUSICA
#define T_MUSICA

//Definição da estrutura responsável pela lógica das músicas;
typedef struct Musica tMusica;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  
 *  Inicializa o struct de tMusica com as strings de *banda e *musica, respectivamente;
 *  inputs: Dois ponteiros de char, para as strings de banda e música;
 *  output: Um ponteiro para o tipo tMusica que foi inicializado;
 *  pos-condição: Retorno de um ponteiro para o tipo tMusica;
*/
tMusica *inicializaMusica(char *banda, char *musica);

/*
 *  Função responsável por liberar o ponteiro do tipo tMusica bem como as strings de nomes da banda e música;
 *  Inputs: Um ponteiro para o tipo tMusica;
 *  pre-condição: Um ponteiro do tipo tMusica estar alocado;
 *  pos-condição: O ponteiro de tMusica é liberado juntamente de suas informações;
*/
void liberaMusica(tMusica *musica);

/*
 *  Retorna a string do nome da música, contida na estrutura tMusica;
 *  inputs: Um ponteiro para o tipo tMusica;
 *  output: O nome da música contido no ponteiro da struct;
 *  pre-condição: Um ponteiro do tipo tMusica estar alocado;
 *  pos-condição: Retorno de uma string 'nomeMus' do tipo tMusica;
*/
char *retornaNomeMus(tMusica *musica);

/*
 *  Retorna a string do nome da banda, contida na estrutura tMusica;
 *  inputs: Um ponteiro para o tipo tMusica;
 *  output: O nome da banda contido no ponteiro da struct;
 *  pre-condição: Um ponteiro do tipo tMusica estar alocado;
 *  pos-condição: Retorno de uma string 'nomeBand' do tipo tMusica;
*/
char *retornaNomeBan(tMusica *musica);

#endif