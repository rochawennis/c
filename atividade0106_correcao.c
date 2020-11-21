
typedef struct nodo {
     struct nodo *ant ;     // campo ponteiro que ir� apontar para o n� anterior
     char nomedep[70];
	 int graupare;           // campo que ir� armazenar um valor do tipo char por exemplo
     struct nodo *prox ;
	 float vitem;  // campo ponteiro que ir� apontar para o pr�ximo n�
 
} lista ; 

lista *inicio = NULL;

struct Data {
      int dia[2];
      int mes[2];
      int ano[4]; 
   };  // um registro y do tipo dma


typedef struct no_arv
{
 char nome[70];
 struct Data dataped;
 float vtotal;
 lista *dependentes;
 struct no_arv *esq;
 struct no_arv *dir;
}tipo_arv;

tipo_arv *raiz=NULL;


void inserir ( lista *aponta, char nomedep[70], int graupare, float vitem ){
     lista *aux ; // vari�vel auxiliar para criar um novo n� 
     aux = ( lista * ) malloc ( sizeof ( lista ) ) ; // aloca dinamicamente um novo n�
     strcpy(aux -> nomedep,nomedep);
     aux -> graupare = graupare;
     aux -> vitem = vitem;
      
     if (aponta == NULL ) { // verifica se a lista est� vazia
          inicio = aux ; // vari�vel inicio aponta para o novo n�
          inicio ->ant = NULL ; // campo ant n�o aponta para ningu�m (� o primeiro n�)
          inicio ->prox = NULL; // campo prox  n�o aponta para ningu�m (� o �ltimo n�)
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
     lista *anterior;
   if (aponta!=NULL){//verifica se a lista tem pelo menos 1 n�
   
     while ( aponta!= NULL  ) { // enquanto n�o atingir o final da lista
          printf("Descricao:");
          puts(aponta->nomedep); 
          printf("Quantidade: %d \n", aponta->graupare);
          printf("Valor: %.2f \n", aponta->vitem);
          anterior = aponta;   // vari�vel anterior guarda o endere�o da vari�vel aponta
          aponta = aponta ->prox ; // aponta para o pr�ximo n�
     }
 
     printf("\n");
  }
}
void imprimirvtotal ( lista *aponta) {
     lista *anterior;
   if (aponta!=NULL){//verifica se a lista tem pelo menos 1 n�
   
     while ( aponta!= NULL ) { // enquanto n�o atingir o final da lista
          printf("Descricao:");
          puts(aponta->nomedep); 
          printf("Quantidade: %d \n", aponta->graupare);
          printf("Valor: %.2f \n", aponta->vitem);
          anterior = aponta;   // vari�vel anterior guarda o endere�o da vari�vel aponta
          aponta = aponta ->prox ; // aponta para o pr�ximo n�
     }

     printf("\n");
  }
}


//*****************************************************************************
// inser��o no in�cio: retorna a lista atualizada
int arvoreVazia(){
   if (raiz==NULL)
       return(1);
       
   return(0);
}   
     
void insereNo(char nome[70], struct Data dataped, float vtotal, tipo_arv *r){
	  
     tipo_arv *aux = r;
     int dep,resp;
     char nomedep[70];
	 int graupare;
	 float vitem;

     
	 if (strcmp(nome,aux->nome)<0){ //insere � esquerda de aux
        if (aux->esq == NULL){
		   tipo_arv *novoNo;
		   novoNo = (tipo_arv *)malloc(sizeof(tipo_arv));
        strcpy (novoNo->nome,nome);
        novoNo->vtotal = vtotal;
		novoNo->dataped.dia[2] = dataped.dia;
		novoNo->dataped.mes[2] = dataped.mes;
		novoNo->dataped.ano[4] = dataped.ano;
           inicio = NULL;
				while (resp!=2){
					fflush(stdin);
					printf("Descricao:");
					gets(nomedep);
					printf("Quantidade:");
					scanf("%d", &graupare);
					printf("Valor:");
					scanf("%f", &vitem);
					inserir(inicio,nomedep,graupare,vitem);
				    printf("Deseja Continuar? (1-SIM/2-NAO):");
                    scanf("%d", &resp);			
				}
				novoNo->vtotal = (graupare*vitem);
           novoNo->dependentes = inicio;
           novoNo->esq = NULL;
           novoNo->dir = NULL;
           r->esq = novoNo;
        }
        else insereNo (nome, dataped, vtotal,r->esq);
     }
     else  if (aux->dir == NULL){ //insere � direita de aux
		   tipo_arv *novoNo;
           novoNo = (tipo_arv *)malloc(sizeof(tipo_arv));
        strcpy (novoNo->nome,nome);
        novoNo->vtotal = vtotal;
		novoNo->dataped.dia[2] = dataped.dia;
		novoNo->dataped.mes[2] = dataped.mes;
		novoNo->dataped.ano[4] = dataped.ano;
           inicio = NULL;
				while (resp!=2){
					fflush(stdin);
					printf("Descricao:");
					gets(nomedep);
					printf("Quantidade:");
					scanf("%d", &graupare);
					printf("Valor:");
					scanf("%f", &vitem);
					inserir(inicio,nomedep,graupare,vitem);
				    printf("Deseja Continuar? (1-SIM/2-NAO):");
                    scanf("%d", &resp);			
				}
			novoNo->vtotal = (graupare*vitem);
           novoNo->dependentes = inicio;
           novoNo->esq = NULL;
           novoNo->dir = NULL;
           r->dir = novoNo;

        }
        else insereNo (nome, dataped, vtotal ,r->dir);
     }



//*****************************************************************************
void insere(char nome[70],struct Data dataped, float vtotal){
	int dep,resp;
    char nomedep[70];
	int graupare;
	float vitem;
    
    if (arvoreVazia()){//cria raiz da �rvore
		tipo_arv *novoNo;
    	novoNo = (tipo_arv *)malloc(sizeof(tipo_arv));
        strcpy (novoNo->nome,nome);
        novoNo->vtotal = vtotal;
		novoNo->dataped.dia[2] = dataped.dia;
		novoNo->dataped.mes[2] = dataped.mes;
		novoNo->dataped.ano[4] = dataped.ano;
		inicio = NULL;
				while (resp!=2){
					fflush(stdin);
					printf("Descricao:");
					gets(nomedep);
					printf("Quantidade:");
					scanf("%d", &graupare);
					printf("Valor:");
					scanf("%f", &vitem);
					inserir(inicio,nomedep,graupare,vitem);
				    printf("Deseja Continuar? (1-SIM/2-NAO):");
                    scanf("%d", &resp);			
				}
		novoNo->vtotal = (graupare*vitem);
        novoNo->dependentes = inicio;
        novoNo->esq = NULL;
        novoNo->dir = NULL;
    	raiz = novoNo;
    }
    else insereNo (nome, dataped, vtotal ,raiz);//insere o n� quando tiver pelo menos a raiz
}  


void emOrdem(tipo_arv *No){
   if (No!=NULL){
      emOrdem(No->esq);
      printf("Nome:");
      puts(No->nome);
      printf("Data: %d / %d / %d \n", No->dataped.dia[2], No->dataped.mes[2], No->dataped.ano[4]);
	  printf("Valor Total: %.2f \n", No->vtotal);
      imprimir ( No->dependentes );
      emOrdem(No->dir);
   }                  
}

void emOrdemvtotal(tipo_arv *No, float vtotal){
   if (No!=NULL){
      emOrdemvtotal(No->esq,vtotal);
      if (vtotal,No->vtotal>=500){
	  printf("Nome:");
      puts(No->nome);
      printf("Data: %d / %d / %d \n", No->dataped.dia[2], No->dataped.mes[2], No->dataped.ano[4]);
	  printf("Valor Total: %.2f \n", No->vtotal);
      imprimir ( No->dependentes );
	  }
      emOrdemvtotal(No->dir,vtotal);
   }              
}


tipo_arv * busca(tipo_arv *No, char nome[70]){
	
    if ( No == NULL ) // se a �rvore estiver vazia
      return NULL ; 
   else
      if ( strcmp(nome,No->nome)==0 ) // se encontrou o valor procurado
         return No; // retorna o endere�o do n�
         /*funcao de comparacao de strings
	        if (strcmp(nome,aux->nome)<0)  
	 */ 
      else // se o valor procurado n�o estiver no n� raiz da �rvore ou na raiz da sub�rvore
         if ( strcmp(nome,No->nome)<0 ) // verifica se o valor de x � menor que o valor da raiz
            return busca ( No->esq, nome ); // chamada recursiva para a sub�rvore esquerda
         else // se o valor de x � maior ou igual ao valor da raiz
            return busca ( No->dir, nome ); // chamada recursiva para a sub�rvore direita

}


tipo_arv * buscavtotal(tipo_arv *No, float vtotal){
	
    if ( No == NULL ) // se a �rvore estiver vazia
      return NULL ; 
   else
      if (vtotal = No->vtotal>499) // se encontrou o valor procurado
         return No; // retorna o endere�o do n�
         /*funcao de comparacao de strings
	        if (strcmp(nome,aux->nome)<0)  
	 */ 
      else // se o valor procurado n�o estiver no n� raiz da �rvore ou na raiz da sub�rvore
         if ( No->vtotal>499 ) // verifica se o valor de x � menor que o valor da raiz
            return buscavtotal ( No->esq, vtotal); // chamada recursiva para a sub�rvore esquerda
         else // se o valor de x � maior ou igual ao valor da raiz
            return buscavtotal ( No->dir, vtotal); // chamada recursiva para a sub�rvore direita

}



tipo_arv * excluiNo(tipo_arv *r, char nome[70])  {
  tipo_arv *aux = r;
  if (aux != NULL) {
    if (strcmp(nome,aux->nome)<0)//caminha na �rvore pelo lado esquerdo
      aux->esq = excluiNo (aux->esq,nome);
    else if (strcmp(nome,aux->nome)>0)
           aux->dir = excluiNo (aux->dir, nome);//caminha na �rvore pelo lado direito
         else { /* achou o elemento */
              if (aux->esq == NULL && aux->dir == NULL) {
              /* CASO 1: elemento sem filhos: n� folha */
                return(NULL); 
                //esse null elimina a liga��o com o n� pai
               }
              else if (aux->esq == NULL) { 
                    /* CASO 2: s� tem filho � direita */
                     aux = aux->dir; //pelo material, o 90 entraria no lugar do 60
                     return(aux);
                    }
                   else if (aux->dir == NULL) { 
                          /* CASO 2: s� tem filho � esquerda */
                          aux = aux->esq; 
                          return(aux);
                         }
                        else { /* CASO 3: tem os dois filhos */
                               tipo_arv *pai = aux;
                               tipo_arv *f = r->esq; 
                               /* substitui pelo antecessor */
                               //busca o n� que tem o maior elemento
                               while (f->dir != NULL) {
                                 pai = f;
                                 f = f->dir; 
                               }
                               /* troca as informa��es */
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
	char nome[70];
	int i;
	float vtotal;
	tipo_arv *retorno_busca, *retorno_exclui;
	struct Data dataped;
	
    for (i=1;i<=2;i++){
		fflush(stdin);
		printf("Digite o nome:");
		gets(nome);
		printf("Dia:");
		scanf("%d", &dataped.dia);
		printf("Mes:");
		scanf("%d", &dataped.mes);
		printf("Ano:");
		scanf("%d", &dataped.ano);
		insere(nome, dataped, vtotal);
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
		
		imprimir (retorno_busca->dependentes);
    }
    
    printf("\n Digite o nome a ser excluido:");
    gets(nome);
    
    exclui(nome);
   
   	printf("\n**** Em-Ordem ****\n");
    emOrdem(raiz);
	
	printf("\n-------------------------------------\n"); 
    
    
    fflush(stdin);
    printf("\nPedidos acima de 500.00: \n");
    
    retorno_busca = buscavtotal (raiz,vtotal);
    
    if (retorno_busca==NULL){
		printf("Nenhum pedido \n");
    }
    else{	
		emOrdemvtotal(raiz, vtotal);	
    }
    	  
    system("pause");
    
}
