#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

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

void remove_prim(plista * lst){
  if (listavazia(*lst))
    printf("a lista já é vazia!!!\n");
  else{
    plista paux = * lst;
    *lst = (*lst)->prox;
  free(paux);
  }
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

int main(){
  float n;
  int k = 0;
  char cont[4];
  plista pl = crialista();
  
continuar:
  system("cls");
  escrevelista(pl);

  printf("Adicionar numeros a pilha ? ");
  scanf("%s",cont);
  if(strcmp(cont,"sim") == 0){
      printf("Numero : ");
      scanf("%f",&n);
      junta_no_ini_lista(n,&pl);
      goto continuar;
      k++;
  }
  else if(strcmp(cont,"sai") == 0){
      getch();
      exit(0);
  }
  else{
    system("cls");
    printf("Eliminar o ultimo adicionado ? ");
    scanf("%s",cont);
    if(strcmp(cont,"sim") == 0){
      remove_prim(&pl);
    }
    escrevelista(pl);
  }
  printf("Continuar ? ");
  scanf("%s",cont);
  if(strcmp(cont,"sim") == 0)
      goto continuar;
  

  return 0;
}