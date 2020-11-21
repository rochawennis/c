#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct no_arv
{
 char info;
 struct no_arv *esq;
 struct no_arv *dir;
}tipo_arv;

tipo_arv *raiz=NULL;

//*****************************************************************************
// inser��o no in�cio: retorna a lista atualizada
char arvoreVazia(){
   if (raiz==NULL)
       return(1);
       
   return(0);
}   
     
void insereNo( char v, tipo_arv *r){
	
     tipo_arv *aux = r;
     if (v < aux->info){ //insere � esquerda de aux
        if (aux->esq == NULL){
		   tipo_arv *novoNo;
		   novoNo = (tipo_arv *)malloc(sizeof(tipo_arv));
           novoNo->info = v;
           novoNo->esq = NULL;
           novoNo->dir = NULL;
           r->esq = novoNo;
        }
        else insereNo (v,r->esq);
     }
     else  if (aux->dir == NULL){ //insere � direita de aux
		   tipo_arv *novoNo;
           novoNo = (tipo_arv *)malloc(sizeof(tipo_arv));
           novoNo->info = v;
           novoNo->esq = NULL;
           novoNo->dir = NULL;
           r->dir = novoNo;
        }
        else insereNo (v,r->dir);
     }



//*****************************************************************************
void insere(char valor){
    if (arvoreVazia()){//cria raiz da �rvore
		tipo_arv *novoNo;
    	novoNo = (tipo_arv *)malloc(sizeof(tipo_arv));
        novoNo->info = valor;
        novoNo->esq = NULL;
        novoNo->dir = NULL;
    	raiz = novoNo;
    }
    else insereNo (valor, raiz);//insere o n� quando tiver pelo menos a raiz
}  


void preOrdem(tipo_arv *No){
   if (No!=NULL){
      printf("%c",No->info);
      preOrdem(No->esq);
      preOrdem(No->dir);
   }                  
}

void emOrdem(tipo_arv *No){
   if (No!=NULL){
      emOrdem(No->esq);
      printf("%c",No->info);
      emOrdem(No->dir);
   }                  
}

void posOrdem(tipo_arv *No){
   if (No!=NULL){
      posOrdem(No->esq);
      posOrdem(No->dir);
      printf("%c",No->info);
   }                  
}




//*****************************************************************************
// principal
//*****************************************************************************
	
main () {
    // declara��o da string
    char palavra [70];
    int i, tam;
    // leitura da string
    printf ("*** Digite a string ***\n");
    scanf("%c", &palavra);
    insere (palavra);
    system ("PAUSE");
    
    
    printf("**** Pre-Ordem ****\n");
    preOrdem(raiz);
    printf("\n**** Em-Ordem ****\n");
    emOrdem(raiz);
    printf("\n**** Pos-Ordem ****\n");
    posOrdem(raiz);
    printf("\n\n");
	  
    system("pause");
    
}
