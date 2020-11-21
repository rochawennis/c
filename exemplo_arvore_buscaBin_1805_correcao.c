#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no_arv
{
 char nome[70];
 char cargo[40];
 float salario;
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
     
void insereNo(char nome[70],char cargo[40],float salario, tipo_arv *r){
	  
     tipo_arv *aux = r;
     
     
	 if (strcmp(nome,aux->nome)<0){ //insere à esquerda de aux
        if (aux->esq == NULL){
		   tipo_arv *novoNo;
		   novoNo = (tipo_arv *)malloc(sizeof(tipo_arv));
           strcpy (novoNo->nome,nome);
           strcpy (novoNo->cargo,cargo);
           novoNo->salario = salario;
           novoNo->esq = NULL;
           novoNo->dir = NULL;
           r->esq = novoNo;
        }
        else insereNo (nome, cargo, salario,r->esq);
     }
     else  if (aux->dir == NULL){ //insere à direita de aux
		   tipo_arv *novoNo;
           novoNo = (tipo_arv *)malloc(sizeof(tipo_arv));
           strcpy (novoNo->nome,nome);
           strcpy (novoNo->cargo,cargo);
           novoNo->salario = salario;
           novoNo->esq = NULL;
           novoNo->dir = NULL;
           r->dir = novoNo;
        }
        else insereNo (nome, cargo, salario,r->dir);
     }



//*****************************************************************************
void insere(char nome[70],char cargo[40],float salario){
    if (arvoreVazia()){//cria raiz da árvore
		tipo_arv *novoNo;
    	novoNo = (tipo_arv *)malloc(sizeof(tipo_arv));
        strcpy (novoNo->nome,nome);
        strcpy (novoNo->cargo,cargo);
        novoNo->salario = salario;
        novoNo->esq = NULL;
        novoNo->dir = NULL;
    	raiz = novoNo;
    }
    else insereNo (nome, cargo, salario, raiz);//insere o nó quando tiver pelo menos a raiz
}  




void emOrdem(tipo_arv *No){
   if (No!=NULL){
      emOrdem(No->esq);
      puts(No->nome);
      puts(No->cargo);
      printf("%.2f \n", No->salario);
      emOrdem(No->dir);
   }                  
}

void listagem(tipo_arv *No, char cargo[40]){
   if (No!=NULL){
      listagem(No->esq,cargo);
      if (strcmp(cargo,No->cargo)==0){
        puts(No->nome);
        puts(No->cargo);
        printf("%.2f \n", No->salario);
	  }
      listagem(No->dir,cargo);
   }                  
}


tipo_arv * busca(tipo_arv *No, char nome[70]){
	
    if ( No == NULL ) // se a árvore estiver vazia
      return NULL ; 
   else
      if ( strcmp(nome,No->nome)==0 ) // se encontrou o valor procurado
         return No; // retorna o endereço do nó
         /*funcao de comparacao de strings
	        if (strcmp(nome,aux->nome)<0)  
	 */ 
      else // se o valor procurado não estiver no nó raiz da árvore ou na raiz da subárvore
         if ( strcmp(nome,No->nome)<0 ) // verifica se o valor de x é menor que o valor da raiz
            return busca ( No->esq, nome ); // chamada recursiva para a subárvore esquerda
         else // se o valor de x é maior ou igual ao valor da raiz
            return busca ( No->dir, nome ); // chamada recursiva para a subárvore direita

}

tipo_arv * excluiNo(tipo_arv *r, char nome[70])  {
  tipo_arv *aux = r;
  if (aux != NULL) {
    if (strcmp(nome,aux->nome)<0)//caminha na árvore pelo lado esquerdo
      aux->esq = excluiNo (aux->esq,nome);
    else if (strcmp(nome,aux->nome)>0)
           aux->dir = excluiNo (aux->dir, nome);//caminha na árvore pelo lado direito
         else { /* achou o elemento */
              if (aux->esq == NULL && aux->dir == NULL) {
              /* CASO 1: elemento sem filhos: nó folha */
                return(NULL); 
                //esse null elimina a ligação com o nó pai
               }
              else if (aux->esq == NULL) { 
                    /* CASO 2: só tem filho à direita */
                     aux = aux->dir; //pelo material, o 90 entraria no lugar do 60
                     return(aux);
                    }
                   else if (aux->dir == NULL) { 
                          /* CASO 2: só tem filho à esquerda */
                          aux = aux->esq; 
                          return(aux);
                         }
                        else { /* CASO 3: tem os dois filhos */
                               tipo_arv *pai = aux;
                               tipo_arv *f = r->esq; 
                               /* substitui pelo antecessor */
                               //busca o nó que tem o maior elemento
                               while (f->dir != NULL) {
                                 pai = f;
                                 f = f->dir; 
                               }
                               /* troca as informações */
                               strcpy(aux->nome,f->nome);
                               
                               
                                if (pai == aux) 
                                  aux->esq = f->esq;
                                else pai->dir = f->esq;
                              }
              }
  } 
  return(aux);      
}

void exclui (char nome[70]){
      if (!arvoreVazia())
  	     raiz = excluiNo (raiz,nome); 
  }

//*****************************************************************************
// principal
//*****************************************************************************
main()
{
	char nome[70],cargo[40];
	float salario;
	int i;
	tipo_arv *retorno_busca, *retorno_exclui;
	
    for (i=1;i<=4;i++){
		fflush(stdin);
		printf("Digite o nome:");
		gets(nome);
		printf("Digite o cargo:");
		gets(cargo);
		printf("Digite o salario:");
		scanf("%f", &salario);
		insere(nome,cargo,salario);
    }
    
    
 
    printf("\n**** Em-Ordem ****\n");
    emOrdem(raiz);

    fflush(stdin);
    printf("\n Digite o nome a ser procurado:");
    gets(nome);
    
    retorno_busca = busca (raiz,nome);
    
    if (retorno_busca==NULL){
		printf("Nome nao encontrado! \n");
    }
    else{
		//exibir o cargo e o salario
		printf("Cargo:");
		puts(retorno_busca->cargo);
		printf("Salario:%.2f \n",retorno_busca->salario);
    }
    
    printf("\n Digite o nome a ser excluido:");
    gets(nome);
    
    exclui(nome);
	
	printf("\n**** Em-Ordem ****\n");
    emOrdem(raiz); 
    
    printf("\n Digite o cargo a ser listado:");
    gets(cargo);
    listagem(raiz, cargo);
	  
    system("pause");
    
}
