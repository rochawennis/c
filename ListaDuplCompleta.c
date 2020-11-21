	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	typedef struct nodo {
	     struct nodo *ant ;     // campo ponteiro que irá apontar para o nó anterior
	     char valor ;           // campo que irá armazenar um valor do tipo char por exemplo
	     struct nodo *prox ;  // campo ponteiro que irá apontar para o próximo nó
	 
	} lista ; // cria um tipo de dado chamado lista
	 
	lista *inicio_vogal = NULL;
	lista *inicio_cons = NULL;
	
	void inserir_vogal ( lista *aponta, char x ){
	     lista *aux ; // variável auxiliar para criar um novo nó 
	     aux = ( lista * ) malloc ( sizeof ( lista ) ) ; // aloca dinamicamente um novo nó
	     aux -> valor = x ; // guarda no novo nó, no campo valor  o conteúdo da variável x
	     if (aponta == NULL ) { // verifica se a lista está vazia
	          inicio_vogal = aux ; // variável inicio aponta para o novo nó
	          inicio_vogal ->ant = NULL ; // campo ant não aponta para ninguém (é o primeiro nó)
	          inicio_vogal ->prox = NULL; // campo prox  não aponta para ninguém (é o último nó)
	     }
	     else { // se a lista não estiver vazia
	          while ( aponta ->prox != NULL  )  // enquanto não for o ultimo nó
	               aponta = aponta->prox  ; // variável aponta aponta para o próximo nó
	          aux ->ant   = aponta ; // campo ant do novo nó aponta para o ultimo nó
	          aux ->prox  = NULL  ; // campo ant do novo nó passa a ser o ultimo nó
	          aponta ->prox = aux; // antigo ultimo nó aponta para o novo nó
	     }
	}
	
	void inserir_cons ( lista *aponta, char x ){
	     lista *aux ; // variável auxiliar para criar um novo nó 
	     aux = ( lista * ) malloc ( sizeof ( lista ) ) ; // aloca dinamicamente um novo nó
	     aux -> valor = x ; // guarda no novo nó, no campo valor  o conteúdo da variável x
	     if (aponta == NULL ) { // verifica se a lista está vazia
	          inicio_cons = aux ; // variável inicio aponta para o novo nó
	          inicio_cons ->ant = NULL ; // campo ant não aponta para ninguém (é o primeiro nó)
	          inicio_cons ->prox = NULL; // campo prox  não aponta para ninguém (é o último nó)
	     }
	     else { // se a lista não estiver vazia
	          while ( aponta ->prox != NULL  )  // enquanto não for o ultimo nó
	               aponta = aponta->prox  ; // variável aponta aponta para o próximo nó
	          aux ->ant   = aponta ; // campo ant do novo nó aponta para o ultimo nó
	          aux ->prox  = NULL  ; // campo ant do novo nó passa a ser o ultimo nó
	          aponta ->prox = aux; // antigo ultimo nó aponta para o novo nó
	     }
	}
	
	
	void imprimir ( lista *aponta ) {
	   if (aponta!=NULL){
	   
	     lista *anterior;
	     printf ( "Da esquerda para a direita:  " ) ;
	     while ( aponta!= NULL  ) { // enquanto não atingir o final da lista
	          printf ( " %c ", aponta ->valor  ) ;
	          anterior = aponta;   // variável anterior guarda o endereço da variável aponta
	          aponta = aponta ->prox ; // aponta para o próximo nó
	     }
	     printf( "\nDa direita para a esquerda:  " ) ;
	     while (anterior != NULL) { // enquanto não atingir o inicio da lista
	          printf( " %c ", anterior -> valor ) ;
	          anterior = anterior ->ant; // aponta para o nó anterior
	     }
		 printf("\n");
	   }	  
	}
	
	lista* procurar ( lista *aponta, char x ) {   // função que irá devolver um endereço de memória
	     while ( aponta != NULL ) {  // enquanto não atingir o final da lista
	          if ( x == aponta->valor ) // se encontrar
	               return aponta ; // devolve o endereço do nó
	          else
	               aponta = aponta ->prox ; // aponta para o próximo nó
	     }
	     return NULL ; // se não achou retorna NULL;
	}
	
	int retirar_vogal ( lista *aponta, char x ){ // função que irá retornar verdadeiro ou falso
	    lista *aux ;
	    if ( aponta == NULL )  // se a lista estiver vazia
	          return 0 ;  // retorna falso
	    else
	      if (x==aponta->valor && aponta->ant==NULL && aponta->prox==NULL){
				aux = aponta ;
				inicio_vogal = NULL;
				free(aux);
				return 1 ;
	       }
	      else{
		  if ( x == aponta->valor && x == aponta->prox->valor ){ // se o valor a ser retirado foi encontrado no primeiro nó
	             aux = aponta ; // nó que será retirado
	             inicio_vogal = aponta->prox ; // faz a ligação para o nó seguinte
	             inicio_vogal -> ant = NULL; // campo ant do novo primeiro nó não aponta para ninguem
	             free( aux ) ; // libera o no apontado por aux
	             return 1 ; // retorna verdadeiro
	        }
	        else{ // se o valor não estiver no primeiro nó
	             while ( aponta->prox != NULL ) {  // verfica se não atingiu o fim da lista
	                   if ( x == aponta->prox->valor ) { // se o valor foi encontrado no próximo nó
	                          aux = aponta->prox ;  // marca o próximo nó para ser retirado
	                          aponta->prox = aux->prox ; // faz a ligação do campo prox dos nós que estão entre o nó que será retirado
	                          if (aux->prox != NULL) // se o nó a ser retirado não for o ultimo
	                                 aux->prox->ant = aux->ant; // faz a ligação do campo ant dos nós que estão entre o nó que será retirado
	                          free( aux ) ; // libera o no apontado por aux
	                          return 1 ; // retorna verdadeiro
	                    }
	                    else // se não encontrou o nó com o valor a ser retirado
	                       aponta = aponta->prox ; // aponta para o próximo nó
	                }
				}
	        }
	    return 0 ; // atingiu o fim da lista e não encontrou o nó, retorna falso
	}
	
	int retirar_cons ( lista *aponta, char x ){ // função que irá retornar verdadeiro ou falso
	    lista *aux ;
	    if ( aponta == NULL )  // se a lista estiver vazia
	          return 0 ;  // retorna falso
	    else
	     if (x==aponta->valor && aponta->ant==NULL && aponta->prox==NULL){
				aux = aponta ;
				inicio_cons = NULL;
				free(aux);
				return 1 ;
	       }
	      else{
	       if ( x == aponta->valor ){ // se o valor a ser retirado foi encontrado no primeiro nó
	             aux = aponta ; // nó que será retirado
	             inicio_cons = aponta->prox ; // faz a ligação para o nó seguinte
	             inicio_cons -> ant = NULL; // campo ant do novo primeiro nó não aponta para ninguem
	             free( aux ) ; // libera o no apontado por aux
	             return 1 ; // retorna verdadeiro
	        }
	        else{ // se o valor não estiver no primeiro nó
	             while ( aponta->prox != NULL ) {  // verfica se não atingiu o fim da lista
	                   if ( x == aponta->prox->valor ) { // se o valor foi encontrado no próximo nó
	                          aux = aponta->prox ;  // marca o próximo nó para ser retirado
	                          aponta->prox = aux->prox ; // faz a ligação do campo prox dos nós que estão entre o nó que será retirado
	                          if (aux->prox != NULL) // se o nó a ser retirado não for o ultimo
	                                 aux->prox->ant = aux->ant; // faz a ligação do campo ant dos nós que estão entre o nó que será retirado
	                          free( aux ) ; // libera o no apontado por aux
	                          return 1 ; // retorna verdadeiro
	                    }
	                    else // se não encontrou o nó com o valor a ser retirado
	                       aponta = aponta->prox ; // aponta para o próximo nó
	                }
				}
	        }
	    return 0 ; // atingiu o fim da lista e não encontrou o nó, retorna falso
	}
	
	
	main(){
		char dado[30];
		int i, j, tam;
		char dado_remove,dado_busca[30];
		int resp=1;//1-SIM e 0-NAO
		int retorno_retira;
		lista *retorno_busca;
		
		
		printf("Digite a string:");
		gets(dado);
		
		tam = strlen(dado);
		for (i=0;i<tam;i++){
			
			if (dado[i]=='a' || dado[i]=='e' || dado[i]=='i' || dado[i]=='o' || dado[i]=='u'){
				inserir_vogal(inicio_vogal,dado[i]);
			}
			else if (dado[i]!=' ' && dado[i]!='@' && dado[i]!='#' && dado[i]!='%' && dado[i]!='&' && dado[i]!='*' && dado[i]!='(' && dado[i]!=')' && dado[i]!='!' && dado[i]!='?'){
				inserir_cons(inicio_cons,dado[i]);
			} 		
		}
			
	
	     
	    //imprimir a lista
	    printf("*Lista das vogais*\n");
	    imprimir(inicio_vogal);
	    printf("*Lista das consoantes*\n");
	    imprimir(inicio_cons);
	    
	    printf("Digite o caractere a ser procurado:");
	    scanf("%c", &dado_busca[i]);
	    
	    if (dado_busca[i]=='a' || dado_busca[i]=='e' || dado_busca[i]=='i' || dado_busca[i]=='o' || dado_busca[i]=='u'){
				
		
	        retorno_busca = procurar (inicio_vogal, dado_busca[i]);
	    }
		else if (dado_busca[i]!=' ' && dado_busca[i]!='@' && dado_busca[i]!='#' && dado_busca[i]!='%' && dado_busca[i]!='&' && dado_busca[i]!='*' && dado_busca[i]!='(' && dado_busca[i]!=')'){
		
		    retorno_busca = procurar (inicio_cons, dado_busca[i]);  
		}
	    
	    if (retorno_busca==NULL){
			printf("Elemento não encontrado! \n");
	    }
	    else printf("Elemento encontrado! \n");
	    
	    fflush(stdin);
	    printf("Digite o caractere a ser removido:");
	    scanf("%c", &dado_remove);
	    for (i = 0; i < tam; i++){
	    if (dado_remove = dado_remove) {
	    		retorno_retira = retirar_vogal(inicio_vogal,dado_remove);
		  }	   
	} 
	    if (dado_remove == dado_remove){
			retorno_retira = retirar_vogal(inicio_vogal,dado_remove);
			
	    }
		else if (dado_remove!=' ' && dado_remove!='@' && dado_remove!='#' && dado_remove!='%' && dado_remove!='&' && dado_remove!='*' && dado_remove!='(' && dado_remove!=')'){
			retorno_retira = retirar_cons(inicio_cons,dado_remove);
			
		}
	
		if (retorno_retira==0){
			printf("Elemento nao retirado!\n");
		}
		else printf("Elemento retirado!\n");
			
	    //imprimir a lista
	    printf("*Lista das vogais*\n");
	    imprimir(inicio_vogal);
	    printf("*Lista das consoantes*\n");
	    imprimir(inicio_cons);
	    
	    system("pause");
	}
