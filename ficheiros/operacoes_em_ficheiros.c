#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}
int main(){
  FILE * fp;
  char nome[10];
  int valor,media,temp[3][3]={};
  fp = fopen("contas.txt","r+");

  printf("\n\t\t+----------------+----------------+----------------+");
  printf("\n\t\t|   1a Cadeira   |   2a Cadeira   |   3a Cadeira   |");
  printf("\n\t\t+----------------+----------------+----------------+\n");
  for(int i = 0; i < 3;i++){
    fscanf(fp,"%s",nome);
    printf("\t\t|");
    for(int j = 0; j < 3;j++){
      fscanf(fp,"%d",&valor);
      temp[i][j] = valor;
      printf(" %9s - %i |",nome,temp[i][j]);
    }
    printf("\n\t\t+----------------+----------------+----------------+");
    printf("\n");
  }
  system("color 03");

  printf("\n\t\t+----------------------------+");
  for(int i = 0; i < 3;i++){
    printf("\n\t\t| Media da %ia cadeira ->",i+1);
    media = (temp[0][i] + temp[1][i] + temp[2][i])/3;
    printf(" %i  |",media);
    printf("\n\t\t+----------------------------+");
  }
  printf("\n");
  for(int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++) {
      if(temp[i][j] > temp[i+1][j])
        swap(&temp[i][j],&temp[i+1][j]);
    }
}
  for(int i = 0; i < 3;i++){
    printf("\n\t\t%ia Cadeira\n\t\t+----------------------------------------------+\n\t\t| Nota mais baixa -> %i | Nota mais alta -> %i |",i+1,temp[0][i],temp[2][i]);
    printf("\n\t\t+----------------------------------------------+\n");
  }
  printf("\n\n\n");

  return 0;
}
