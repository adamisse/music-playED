#ifndef T_LISTA_USUARIO
#define T_LISTA_USUARIO

//Definição da estrutura responsável pela lógica da lista de usuários;
typedef struct ListaUsu tListaUsu;

#include <stdio.h>
#include <stdlib.h>
#include "tUsuario.h"

/*
 * Inicializa a estrutura da lista de usuários com as células *pri e *ult;
 * output: Um ponteiro para o tipo tListaUsu que foi inicializado;
 * pos-condicao:  ponteiro de retorno será diferente de NULL e nele estarão contidos os ponteiros para primeira e ultima celula da lista de musicas;
*/
tListaUsu *iniciaSentinelaUsuario();

/*
 * Cria a estrutura da lista de usuários baseando-se no arquivo "amizade.txt";
 * input: um ponteiro para o tipo tListaUsu que foi inicializado;
 * pre-condicao: o arquivo "amizade.txt" não estar vazio;
 * pos-condicao: cria uma lista de usuários e registra suas respectivas amizades, com base no arquivo "amizade.txt"
*/
void criaListaUsuarios(tListaUsu *sent);

/* 
 * Insere um usuário do tipo tUsuario dentro de uma célula de tListaUsu;
 * inputs: Ponteiro para uma sentinela e para um usuário;
 * pre-condicao: Ambos, sentinela e usuário, previamente inicializados;
 * pos-condicao: Cria-se um ponteiro dentro de uma das células de lista de usuários para a tListaUsu que acabou de ser inserida;
*/
void insereUsuario(tListaUsu *sent, tUsuario *usuario);

/*
 *  Função responsável por liberar as celulas contidas na lista de usuários;
 *  Inputs: Ponteiro correspondente a sentinela da lista de usuários;
 *  pre-condição: Um ponteiro do tipo tListaUsu estar alocado;
 *  pos-condição: O ponteiro de tListaUsu é liberado juntamente de suas células;
*/
void liberaListaUsuario(tListaUsu *sent);

/*
 *  Função para verificar se a lista de usuários contém a string de usuário informada;
 *  Inputs: Ponteiro(sentinela) da lista de usuários e uma chave (ponteiro do tipo char) a ser buscada;
 *  Outputs: Ponteiro com valor do tipo tUsuario encontrado; 
 *  pre-condição: Lista de usuarios já inicializada e com nome válido;
 *  pos-condição: Avança pela lista até retornar o tUsuario correspondente à string informada, e caso não haja usuário correspondente retornará NULL;
*/
tUsuario *procuraUsuario(tListaUsu *sent, char *nome);

/*
 *  Responsável por criar um for loop chamando a função refatorandoUsuario;
 *  Inputs: Ponteiro(sentinela) da lista de usuários;
 *  pre-condição: Lista de usuarios já inicializada e com nome válido;
 *  pos-condição: Percorre a lista de usuários até o final, sendo que em cada iteração executa-se a função de refatoração do usuário;
*/
void refatorandoListaUsuarios(tListaUsu *sent);

/*
 *  Cria os arquivos "played-refatorada.txt" e "similaridades.txt", preenchendo-os através da chamada de funções presentes em outros TAD's;
 *  Inputs: Ponteiro(sentinela) da lista de usuários;
 *  pre-condição: Lista de usuarios já inicializada e com nome válido;
 *  pos-condição: Criação de dois arquivos de saída. O primeiro: "played-refatorada.txt" contendo o nome do usuário, a quantidade de artistas que este ouve, seguido da lista de playlists dos respectivos artistas/bandas. E o segundo: "similaridades.txt", que conterá as similaridades dos gostos entre os amigos.
*/
void geraSaida(tListaUsu *sent);

#endif