#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct lno * plista;
typedef struct lno {
  float valor; 
  plista prox; 

} listano;

plista crialista()  {
  plista p = NULL;
  return p;
}

int listavazia(plista lst) {
  if(lst == NULL)
    return 1;
  else
    return 0;
}
void limparlista(plista *lst){
  plista no = (plista)malloc(sizeof(listano));
  plista paux;
  while(paux->prox != NULL){
     paux = * lst;
    *lst = (*lst)->prox;
    free(paux);
  }
  paux->prox = NULL;
  printf("Lista limpa !\n");
}

void junta_no_ini_lista(float x, plista * lst){

  plista no = (plista)malloc(sizeof(listano));
  if (no == NULL){
    perror("ERRO!!! Nao ha memoria disponivel...");
    exit(-1);
  }
  else{
    no->valor = x;
    no->prox = * lst;
    *lst = no;
  }
}

void junta_no_fim_lista(float x, plista * lst)  {
  plista pl = (plista)malloc(sizeof(listano));
  if (pl == NULL)
    printf("Erro !");
  else{
    pl->valor = x;
    pl->prox = NULL;
    if((* lst) == NULL)
      * lst = pl;
    else{
      plista paux = * lst;
      while (paux->prox != NULL)
        paux = paux->prox;
        paux->prox = pl;
    }
  }
}

void junta_no_nesimo(float x,plista * lst, int n){
  plista pl = (plista)malloc(sizeof(listano));
  if ( n == 1)
    junta_no_ini_lista(x,lst);
  else{
    pl->valor = x;
    pl->prox = NULL;
    plista paux;
    int i = 1;
    paux = *lst;
    while(i < n && paux->prox != NULL){   //n-1 na posicao anterior n+1 na proxima posicao
      paux = paux->prox;
      i++;
    }
    if(paux->prox == NULL)
      junta_no_fim_lista(x,lst);
    else{
      paux->valor = pl->valor;
    }
  }
}

void remove_prim(plista * lst){
  if (listavazia(*lst))
    printf("a lista já é vazia!!!\n");
  else{
    plista paux = * lst;
    *lst = (*lst)->prox;
  free(paux);
  }
}

void remove_ult(plista * lst) {
  if (listavazia(*lst))
    printf("a lista já é vazia!!!\n");
  else{
    plista paux1, paux2;
    paux1 = * lst;
    paux2 = NULL;
    while(paux1->prox != NULL){
      paux2 = paux1;
      paux1 = paux1->prox;
    }
    free(paux1);
    if(paux2 != NULL)
      paux2->prox = NULL;
    else * lst = NULL;
  }
}
void remove_nesimo (plista * lst, int n){
  if (n == 1)
    remove_prim(lst);
  else {
    plista paux1,paux2;
    int i = 1;
    paux1 = *lst;
    while(i < n-1 && paux1->prox != NULL){
      paux1 = paux1->prox;
      i++;
    }
    if(paux1->prox == NULL)
      printf("lista nao tem elemento %i\n",n);
    else{
      paux2 = paux1->prox;
      paux1->prox = paux2->prox;
      free(paux2);
    }
  }
}

int conta (plista lst){
  int count = 0;
  if(listavazia(lst))
    printf("a lista e vazia !!!\n");
  else{
    
    do
    {
      count++;
      lst = lst->prox;
    } while (lst != NULL);
  }
  return count;
}

void escrevelista(plista lst) {
  if(listavazia(lst))
    printf("a lista e vazia!!!\n");
  else{
    printf("[");
    do{
      printf(" %.1f,",lst->valor);
      lst = lst->prox;
  }while(lst != NULL);
  printf("\b ]\n");
  }
}
void swap(float *xp, float *yp){
	float temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(float arr[], int n){
for(int i = 0; i < n; i++)
	for(int j = 0; j < n-i-1; j++)
		if(arr[j] > arr[j+1])
		    swap(&arr[j], &arr[j+1]);
  for(int i = 0; i < n;i++){
    printf("arr[%i] - %0.2f\n",i,arr[i]);
  }
}

void selectionSort(float arr[], int n){
	int temp;
	for (int i = 0; i < n; i++){
		temp = i;                        
		for (int j = i+1; j < n; j++)    
		  if (arr[j] > arr[temp])      
        temp = j;                 

		swap(&arr[temp], &arr[i]);   
	}
  for(int i = 0; i < n;i++){
    printf("arr[%i] - %0.2f\n",i,arr[i]);
  }
}
int main(){
  int cont;
  float x;
  int n;
  plista pl = crialista();
  for(int i = 0; i < 10;i++){
      junta_no_fim_lista(i,&pl);
  }
  // junta_no_ini_lista(9,&pl);
  // printf("indica um valor : ");
  // scanf("%f",&x);
  // printf("posicao : ");
  // scanf("%d",&n);
  // junta_no_nesimo(x,&pl,n);
  // printf("limpar lista");
  // limparlista(&pl);
  cont = conta(pl);
  printf("%i elementos\n",cont);
  float vec[cont];
  for(int i = 0 ; i < cont; i++){
    vec[i] = pl->valor;
    pl = pl->prox;
  }
  bubbleSort(vec,cont);
  printf("\n\n");
  selectionSort(vec,cont);
  // escrevelista(pl);
  return 0;
}