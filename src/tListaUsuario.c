#include "../include/tListaUsuario.h"
#include "../include/tUsuario.h"

typedef struct celula Celula;

struct ListaUsu{
    Celula *pri;
    Celula *ult;
};

struct celula{
    tUsuario *usuario;
    Celula *prox;
};

tListaUsu *iniciaSentinelaUsuario(){
    tListaUsu *set = (tListaUsu *) malloc(sizeof(tListaUsu));
    set->pri = NULL;
    set->ult = NULL;

    return set;
}

//funcao printa somente o nome de cada usuario por enquanto(fiz so para testar)
void printaFila(tListaUsu *sent){
    Celula *p;
    for(p=sent->pri; p!=NULL ; p = p->prox){
        printaNome(p->usuario);
    }
}

void criaFilaUsuarios(tListaUsu *sent){
    FILE *arq = fopen("data/Entrada/amizade.txt","r");
    if(arq == NULL){
        printf("Erro na abertura do arquivo amizade.txt\n");
        exit(1);
    }

    char nomeAux[150], quebra;
    //criar um looping que fica na primeira linha e separa o nome de cada usuario
    //dentro desse looping vc chama a função para dar malloc no usuario
    //chama a funcao para preencher o nome do usuario com base no nome lido
    //por fim chama a funcao para inserir esse usuario na lista de usuarios
    //ou seja primeiro a gente cria a fila de usuario e preenche somente os seus nomes
    while(fscanf(arq,"%[^;^\n]%c",nomeAux,&quebra) == 2){
        tUsuario *usuario = inicializaUsuario();
        preencheNomeUsuario(usuario,nomeAux);
        insereUsuario(sent,usuario);

        if(quebra == '\n') break;
    }
    //apenas testando aqui
    printaFila(sent);


    //depois de preencher os nomes de cada usuario nesse primeiro looping sera possivel preencher a lista de amigos;
    //tinha que preencher o nome separadamente por que a fila de amigos depende do nome de cada usuario;

    fclose(arq);
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

void liberaListaUsuario(tListaUsu *sent){
    Celula *p = sent->pri;
    Celula *t;

    while(p != NULL){
        t = p->prox;
        
        liberaUsuario(p->usuario);
        free(p);
        p = t;
    }

    free(sent);
}