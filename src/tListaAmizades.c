#include "../include/tListaAmizade.h"

typedef struct celula Celula;

struct ListaAmigos{
    Celula *pri;
    Celula *ult;
};

struct celula{
    Celula *prox;
    tUsuario *usu;
};

tListaAmigos *iniciaSentinelaAmigos(){
    tListaAmigos *set = (tListaAmigos *) malloc(sizeof(tListaAmigos));
    set->pri = NULL;
    set->ult = NULL;

    return set;
}

void insereAmigo(tListaAmigos *sent,tUsuario *usuario){
    Celula *novaCel = (Celula *) malloc(sizeof(Celula));
    novaCel->prox = NULL;
    novaCel->usu = usuario;

    if(sent->pri == NULL){
        sent->pri = novaCel;
        sent->ult = novaCel;
    }else{
        sent->ult->prox = novaCel;
        sent->ult = novaCel;
    }
}

void liberaListaAmigos(tListaAmigos *sent){
    Celula *p = sent->pri;
    Celula *t;

    while(p != NULL){
        t = p->prox;
        free(p);
        p = t;
    }

    free(sent);
}


//so de teste aqui
void printaListaAmigos(tListaAmigos *sent){
    Celula *p;
    char *nome;
    for(p=sent->pri; p!=NULL ; p = p->prox){
        nome = retornaNomeUsu(p->usu);
        printf("%s ",nome);
    }
}