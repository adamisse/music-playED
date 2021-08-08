#include "../include/tListaPlayList.h"
#include "../include/tUsuario.h"

typedef struct celula Celula;

struct ListaPlaylist{
    Celula *pri;
    Celula *ult;
};

struct celula{
    tPlaylist *playList;
    Celula *prox;
};

tListaPlaylist *iniciaSentinelaPlaylist(){
    tListaPlaylist *set = (tListaPlaylist *) malloc(sizeof(tListaPlaylist));
    set->pri = NULL;
    set->ult = NULL;

    return set;
}

void criaFilaPlayList(tListaUsu *sent){
    FILE *arq = fopen("data/Entrada/playlists.txt","r");
    if(arq == NULL){
        printf("Erro na abertura do arquivo playLista.txt!\n");
        exit(1);
    }
    char nome[50];
    int qtdPlayL;

    while(fscanf(arq,"%[^;];%d",nome,&qtdPlayL) == 2){
        tUsuario *usuario = procuraUsuario(sent,nome);
        for(int i=0; i<qtdPlayL ;i++){
            char nomePlay[50];
            fscanf(arq,";%[^;^\n] ",nomePlay);
            
            tPlaylist *playList = inicializaPlayList();
            preenchePlayList(playList,nomePlay);
            //chamar função para preencher lista de musica da play list
            //essa função vai passar a playList
            preencheListaPlayList(usuario,playList);
        }
    }

    fclose(arq);
}

void refatoraListaPlaylist(tListaPlaylist *sent, tListaPlaylist *novaSent){
    Celula *p;
    
    for(p=sent->pri; p!=NULL ;p=p->prox){
        tListaMusica *sentMusic = retornaListaMusica(p->playList);
        refatorandoListaMusica(sentMusic,novaSent);
    }

    liberaListaPlaylist(sent);
}

void inserePlaylist(tListaPlaylist *sent, tPlaylist *playlist){
    Celula *novaCel = (Celula *) malloc(sizeof(Celula));
    novaCel->prox = NULL;
    novaCel->playList = playlist;

    if(sent->pri == NULL){
        sent->pri = novaCel;
        sent->ult = novaCel;
    }else{
        sent->ult->prox = novaCel;
        sent->ult = novaCel;
    }
}

tPlaylist *procuraPlaylist(tListaPlaylist *sent, char *nome){
    Celula *p = sent->pri;

    while(1){
        if(p == NULL) return NULL;
        else if(strcmp(nome,retornaNomePlay(p->playList)) == 0) return p->playList;
        else p = p->prox;
    }
}

int qtdPlayList(tListaPlaylist *sent){
    Celula *p;
    int qtd = 0;
    for(p=sent->pri; p!=NULL ;p=p->prox){
        qtd++;
    }

    return qtd;
}

void liberaListaPlaylist(tListaPlaylist *sent){ 
    Celula *p = sent->pri;
    Celula *t;

    while(p != NULL){
        t = p->prox;
        liberaPlayList(p->playList);
        free(p);
        p = t;
    }

    free(sent);
}

void printaNomeListaPlay(tListaPlaylist *sent, FILE *arq, char *nomeUsu){
    Celula *p;
    char adress[100] = "data/Saida/";
    char adressAux[100];
    char barra[2] = "/";
    char txt[5] = ".txt";
    strncat(adress,nomeUsu,100);
    strncat(adress,barra,100);

    for(p=sent->pri; p!=NULL ;p=p->prox){
        char *nomePlay = retornaNomePlay(p->playList);
        fprintf(arq,";%s",nomePlay);

        strcpy(adressAux,adress);
        strncat(adressAux,nomePlay,100);
        strncat(adressAux,txt,100);
        FILE *arqPlay = fopen(adressAux,"w");
        if(arqPlay == NULL){
            printf("Erro na abertura do arquivo de playList's\n");
            exit(1);
        }
        tListaMusica *sentMus = retornaListaMusica(p->playList);
        printaListaMusica2(sentMus,arqPlay);
        fclose(arqPlay);
    }
    fprintf(arq,"\n");
}

int comparaListaPlay(tListaPlaylist *sent1,tListaPlaylist *sent2){
    Celula *p, *t;
    int similaridade = 0;

    for(p=sent1->pri; p!=NULL ;p=p->prox){
        char *nomePlay1 = retornaNomePlay(p->playList);
        for(t=sent2->pri; t!=NULL ;t=t->prox){
            char *nomePlay2 = retornaNomePlay(t->playList);
            if(strcmp(nomePlay1,nomePlay2) == 0){
                tListaMusica *sentMus1 = retornaListaMusica(p->playList);
                tListaMusica *sentMus2 = retornaListaMusica(t->playList);

                similaridade += similaridadeListaMusica(sentMus1,sentMus2);
            }
        }
    }

    return similaridade;
}

void printaListaplayList(tListaPlaylist *sent){
    Celula *p;
    for(p=sent->pri; p!=NULL ; p = p->prox){
        printaPlayList(p->playList);
    }
}