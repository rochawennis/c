#include <stdio.h>
#include <stdlib.h>


typedef struct no_arv
{
 int info;
 struct no_arv *esq;
 struct no_arv *dir;
}tipo_arv;

tipo_arv *raiz=NULL;

//*****************************************************************************
// inserção no início: retorna a lista atualizada
int arvoreVazia(){
   if (raiz==NULL)
       return(1);
       
   return(0);
}        

//*****************************************************************************
// inserção no início: retorna a lista atualizada

tipo_arv * criaRaiz(int x){
   tipo_arv *novoNo;	
   novoNo = (tipo_arv *)malloc(sizeof(tipo_arv));
   novoNo->info = x;
   novoNo->esq=NULL;
   novoNo->dir=NULL;
   raiz = novoNo;
   return (novoNo);         
}         
    
//*****************************************************************************
// inserção no início: retorna a lista atualizada
tipo_arv * insereDir(tipo_arv *pai, int x)
{
 tipo_arv *no_pai = pai;    
 if (!arvoreVazia()){
    if (no_pai->dir!=NULL){
        printf("\n No direito ja ocupado" );
        return NULL;
    }
    else{
         
         tipo_arv *novoNo;	
         novoNo = (tipo_arv *)malloc(sizeof(tipo_arv));
         novoNo->info = x;
         novoNo->esq=NULL;
         novoNo->dir=NULL;
         no_pai->dir = novoNo;
         return(novoNo);    
     }
}                                           
 return NULL;
}       

// inserção no início: retorna a lista atualizada
tipo_arv * insereEsq(tipo_arv *pai, int x)
{
 tipo_arv *no_pai = pai;    
 if (!arvoreVazia()){
    if (no_pai->esq!=NULL){
        printf("\n No esquerdo ja ocupado" );
        return NULL;
    }
    else{
         
         tipo_arv *novoNo;	
         novoNo = (tipo_arv *)malloc(sizeof(tipo_arv));
         novoNo->info = x;
         novoNo->esq=NULL;
         novoNo->dir=NULL;
         no_pai->esq = novoNo;
         return(novoNo);    
     }
}                                           
 return NULL;
}

void preOrdem(tipo_arv *No){
   if (No!=NULL){
      printf("%d \t",No->info);
      preOrdem(No->esq);
      preOrdem(No->dir);
   }                  
}




//*****************************************************************************
// principal
//*****************************************************************************
main()
{
    tipo_arv *No;
    raiz = criaRaiz(10);
    
    No = raiz;
    insereDir(No,12);
    
    No = insereEsq(No,5);
    insereEsq(No,2);
    No = insereDir(No,8);
    insereEsq (No, 7);
    //continuar a inserção de acordo com o exercício
    No = insereDir(No,15);
    insereEsq (No, 14);
    insereDir (No, 20);
    
    
    preOrdem(raiz);
      
    system("pause");
    
}
