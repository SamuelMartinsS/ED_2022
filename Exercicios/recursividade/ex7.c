/*Limpar uma lista ligada (Ficha de Trabalho n.º 5, alínea p) do exercício 2.), ou seja, eliminar todos os elementos de uma lista
ligada. Uma das versões pode ser a usada na resolução da Ficha de Trabalho n.º 5.*/
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

// void limparlista(plista *lst){
//   plista no = (plista)malloc(sizeof(listano));
//   plista paux;
//   while(paux->prox != NULL){
//      paux = * lst;
//     *lst = (*lst)->prox;
//     free(paux);
//   }
//   paux->prox = NULL;
//   printf("Lista limpa !\n");
// }
void limparlista(plista *lst){
    plista no = (plista)malloc(sizeof(listano));
    plista paux;

        paux = *lst;
        *lst = (*lst)->prox;
        if(paux-> prox == NULL)
            printf("lista limpa !\n");
        else
            limparlista(lst);
}

int main(){
  int cont;
  float x;
  int n;
  plista pl = crialista();
  for(int i = 0; i < 10;i++){
      junta_no_fim_lista(i,&pl);
  }
  escrevelista(pl);
  limparlista(&pl);
  escrevelista(pl);
  return 0;
}