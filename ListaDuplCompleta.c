	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	typedef struct nodo {
	     struct nodo *ant ;     // campo ponteiro que ir� apontar para o n� anterior
	     char valor ;           // campo que ir� armazenar um valor do tipo char por exemplo
	     struct nodo *prox ;  // campo ponteiro que ir� apontar para o pr�ximo n�
	 
	} lista ; // cria um tipo de dado chamado lista
	 
	lista *inicio_vogal = NULL;
	lista *inicio_cons = NULL;
	
	void inserir_vogal ( lista *aponta, char x ){
	     lista *aux ; // vari�vel auxiliar para criar um novo n� 
	     aux = ( lista * ) malloc ( sizeof ( lista ) ) ; // aloca dinamicamente um novo n�
	     aux -> valor = x ; // guarda no novo n�, no campo valor  o conte�do da vari�vel x
	     if (aponta == NULL ) { // verifica se a lista est� vazia
	          inicio_vogal = aux ; // vari�vel inicio aponta para o novo n�
	          inicio_vogal ->ant = NULL ; // campo ant n�o aponta para ningu�m (� o primeiro n�)
	          inicio_vogal ->prox = NULL; // campo prox  n�o aponta para ningu�m (� o �ltimo n�)
	     }
	     else { // se a lista n�o estiver vazia
	          while ( aponta ->prox != NULL  )  // enquanto n�o for o ultimo n�
	               aponta = aponta->prox  ; // vari�vel aponta aponta para o pr�ximo n�
	          aux ->ant   = aponta ; // campo ant do novo n� aponta para o ultimo n�
	          aux ->prox  = NULL  ; // campo ant do novo n� passa a ser o ultimo n�
	          aponta ->prox = aux; // antigo ultimo n� aponta para o novo n�
	     }
	}
	
	void inserir_cons ( lista *aponta, char x ){
	     lista *aux ; // vari�vel auxiliar para criar um novo n� 
	     aux = ( lista * ) malloc ( sizeof ( lista ) ) ; // aloca dinamicamente um novo n�
	     aux -> valor = x ; // guarda no novo n�, no campo valor  o conte�do da vari�vel x
	     if (aponta == NULL ) { // verifica se a lista est� vazia
	          inicio_cons = aux ; // vari�vel inicio aponta para o novo n�
	          inicio_cons ->ant = NULL ; // campo ant n�o aponta para ningu�m (� o primeiro n�)
	          inicio_cons ->prox = NULL; // campo prox  n�o aponta para ningu�m (� o �ltimo n�)
	     }
	     else { // se a lista n�o estiver vazia
	          while ( aponta ->prox != NULL  )  // enquanto n�o for o ultimo n�
	               aponta = aponta->prox  ; // vari�vel aponta aponta para o pr�ximo n�
	          aux ->ant   = aponta ; // campo ant do novo n� aponta para o ultimo n�
	          aux ->prox  = NULL  ; // campo ant do novo n� passa a ser o ultimo n�
	          aponta ->prox = aux; // antigo ultimo n� aponta para o novo n�
	     }
	}
	
	
	void imprimir ( lista *aponta ) {
	   if (aponta!=NULL){
	   
	     lista *anterior;
	     printf ( "Da esquerda para a direita:  " ) ;
	     while ( aponta!= NULL  ) { // enquanto n�o atingir o final da lista
	          printf ( " %c ", aponta ->valor  ) ;
	          anterior = aponta;   // vari�vel anterior guarda o endere�o da vari�vel aponta
	          aponta = aponta ->prox ; // aponta para o pr�ximo n�
	     }
	     printf( "\nDa direita para a esquerda:  " ) ;
	     while (anterior != NULL) { // enquanto n�o atingir o inicio da lista
	          printf( " %c ", anterior -> valor ) ;
	          anterior = anterior ->ant; // aponta para o n� anterior
	     }
		 printf("\n");
	   }	  
	}
	
	lista* procurar ( lista *aponta, char x ) {   // fun��o que ir� devolver um endere�o de mem�ria
	     while ( aponta != NULL ) {  // enquanto n�o atingir o final da lista
	          if ( x == aponta->valor ) // se encontrar
	               return aponta ; // devolve o endere�o do n�
	          else
	               aponta = aponta ->prox ; // aponta para o pr�ximo n�
	     }
	     return NULL ; // se n�o achou retorna NULL;
	}
	
	int retirar_vogal ( lista *aponta, char x ){ // fun��o que ir� retornar verdadeiro ou falso
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
		  if ( x == aponta->valor && x == aponta->prox->valor ){ // se o valor a ser retirado foi encontrado no primeiro n�
	             aux = aponta ; // n� que ser� retirado
	             inicio_vogal = aponta->prox ; // faz a liga��o para o n� seguinte
	             inicio_vogal -> ant = NULL; // campo ant do novo primeiro n� n�o aponta para ninguem
	             free( aux ) ; // libera o no apontado por aux
	             return 1 ; // retorna verdadeiro
	        }
	        else{ // se o valor n�o estiver no primeiro n�
	             while ( aponta->prox != NULL ) {  // verfica se n�o atingiu o fim da lista
	                   if ( x == aponta->prox->valor ) { // se o valor foi encontrado no pr�ximo n�
	                          aux = aponta->prox ;  // marca o pr�ximo n� para ser retirado
	                          aponta->prox = aux->prox ; // faz a liga��o do campo prox dos n�s que est�o entre o n� que ser� retirado
	                          if (aux->prox != NULL) // se o n� a ser retirado n�o for o ultimo
	                                 aux->prox->ant = aux->ant; // faz a liga��o do campo ant dos n�s que est�o entre o n� que ser� retirado
	                          free( aux ) ; // libera o no apontado por aux
	                          return 1 ; // retorna verdadeiro
	                    }
	                    else // se n�o encontrou o n� com o valor a ser retirado
	                       aponta = aponta->prox ; // aponta para o pr�ximo n�
	                }
				}
	        }
	    return 0 ; // atingiu o fim da lista e n�o encontrou o n�, retorna falso
	}
	
	int retirar_cons ( lista *aponta, char x ){ // fun��o que ir� retornar verdadeiro ou falso
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
	       if ( x == aponta->valor ){ // se o valor a ser retirado foi encontrado no primeiro n�
	             aux = aponta ; // n� que ser� retirado
	             inicio_cons = aponta->prox ; // faz a liga��o para o n� seguinte
	             inicio_cons -> ant = NULL; // campo ant do novo primeiro n� n�o aponta para ninguem
	             free( aux ) ; // libera o no apontado por aux
	             return 1 ; // retorna verdadeiro
	        }
	        else{ // se o valor n�o estiver no primeiro n�
	             while ( aponta->prox != NULL ) {  // verfica se n�o atingiu o fim da lista
	                   if ( x == aponta->prox->valor ) { // se o valor foi encontrado no pr�ximo n�
	                          aux = aponta->prox ;  // marca o pr�ximo n� para ser retirado
	                          aponta->prox = aux->prox ; // faz a liga��o do campo prox dos n�s que est�o entre o n� que ser� retirado
	                          if (aux->prox != NULL) // se o n� a ser retirado n�o for o ultimo
	                                 aux->prox->ant = aux->ant; // faz a liga��o do campo ant dos n�s que est�o entre o n� que ser� retirado
	                          free( aux ) ; // libera o no apontado por aux
	                          return 1 ; // retorna verdadeiro
	                    }
	                    else // se n�o encontrou o n� com o valor a ser retirado
	                       aponta = aponta->prox ; // aponta para o pr�ximo n�
	                }
				}
	        }
	    return 0 ; // atingiu o fim da lista e n�o encontrou o n�, retorna falso
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
			printf("Elemento n�o encontrado! \n");
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
