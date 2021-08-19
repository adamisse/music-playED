#ifndef T_LISTA_AMIZADE
#define T_LISTA_AMIZADE

//Estrutura ultilizada como sentinela da lista de amigos;
typedef struct ListaAmigos tListaAmigos;

#include <stdio.h>
#include <stdlib.h>
#include "tUsuario.h"

            ////TIRAR ISSO DAQUI DEPOIS////////////////////
//padrão de comentarios a ser estabelecido
/*Inicializa uma matriz de nlinhas e ncolunas
 * inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
 * output: ponteiro para a matriz inicializada
 * pre-condicao: nlinhas e ncolunas diferentes de 0
 * pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas
 */


/*
 *  Inicialização do struct tListaAmigos com *ult *pri;
 *  Outputs: Um ponteiro do tipo tListaAmigos que foi inicializado;
 *  pos-condição: ponteiro de retorno ser diferente de NULL e contendo ponteiros para primeira e ultima celula da lista de amigos;
*/
tListaAmigos *iniciaSentinelaAmigos();

/*
 *  Inserção de um tipo tUsuario dentro de uma nova celula correspondente a lista de Amigos;
 *  Inputs: Ponteiro referente a sentinela da lista de amigos e um ponteiro para o tUsuario que será inserido;
 *  pre-condição: Ponteiro da sentinela de tListaAmigos já inicializado e um ponteiro para um usuario já inicializado/preenchido;
 *  pos-condição: A lista de amigos conter em uma das suas celulas um ponteiro para o tUsuario que foi inserido;
*/
void insereAmigo(tListaAmigos *sent, tUsuario *usuario);

/*
 *  Libera as celulas contidas na lista de amigos;
 *  Inputs: Ponteiro correspondente a sentinela da lista de amigos;
 *  pre-condição: Um ponteiro do tipo tListaAmigos previamente alocado;
 *  pos-condição: O ponteiro de tListaAmigos agora foi liberado em conjunto das suas celulas internas;
*/
void liberaListaAmigos(tListaAmigos *sent);

/*
 *  Função para percorrer a lista de amigos de um usuario, e calcular e exibir as similaridades musicais contidas;
 *  Inputs: Ponteiro para um tUsuario em questão e outro ponteiro para a sentinela da lista de amigos desse mesmo usuario;
 *  pre-condição: Um ponteiro de tUsuario definido/preenchido, um ponteiro para uma lista de amigos definida e um arquivo txt em data/Saida/similaridades.txt;
 *  pos-condição: O resultado das similaridades entre o usuario e seus amigos exibido no respectivo arquivo de saida;
*/
void comparaAmigos(tUsuario *usuario, tListaAmigos *sentAmg);

/*
 *  Função para procurar nomes de usuarios no arquivo similaridades.txt, evitando a reincidencia do calculo/exibição de similaridade;
 *  Inputs: Dois ponteiros do tipo char contendo os nomes dos usuarios a serem procurados;
 *  Outputs: Um inteiro com valor 0 ou 1 para determinar o resultado da procura;
 *  pre-condição: Dois ponteiros char nomeUsu/nomeAmg existentes e a existencia de um arquivo em data/Saida/similaridades.txt;
 *  pos-condição: Um inteiro booleano determinando o resultado da procura;
*/
int procuraNomes(char *nomeUsu, char *nomeAmg);

#endif