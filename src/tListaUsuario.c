#include "../include/tListaUsuario.h"

typedef struct celula Celula;

struct ListaUsu{
    Celula *pri;
    Celula *ult;
};

struct celula{
    tUsuario *usuario;
    Celula *prox;
};

tListaUsu *iniciaSentinela(){
    tListaUsu *set = (tListaUsu *) malloc(sizeof(tListaUsu));
    set->pri = NULL;
    set->ult = NULL;

    return set;
}

void insereUsuario(tListaUsu *sent,tUsuario *usuario){
    Celula *novaCel = (Celula *) malloc(sizeof(Celula));
    novaCel->usuario = usuario;
    novaCel->prox = NULL;
    
    if(sent->pri == NULL){
        sent->pri = novaCel;
        sent->ult = novaCel;
    }else{
        sent->ult->prox = novaCel;
        sent->ult = novaCel;
    }
}

void liberaListaUsuario(tListaUsu *set){
    Celula *p = set->pri;
    Celula *t;

    while(p != NULL){
        t = p->prox;
        //liberar oq estiver dentro da celula de usuario
        //provavelmente chamar aqui uma funcao assim:
        //liberaUsuario(p->usuario)
        free(p);
        p = t;
    }

    free(set);
}