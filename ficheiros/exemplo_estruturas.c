#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define val 3

typedef struct empresa{
  char nome[20];
  int idade;
  float salario;
}emp;

emp dados() {
  emp trab ;
  system("cls");
  fflush(stdin);
  printf("Nome : ");
  scanf("%s",trab.nome);
  fflush(stdin);
  printf("Idade : ");
  scanf("%i",&trab.idade);
  fflush(stdin);
  printf("Salario : ");
  scanf("%f",&trab.salario);
  fflush(stdin);

  return trab;
};

void printemp(emp trab){
  printf("\n\t\t\t+----------------------------------------+\n");
  printf("\n\t\t\t\t\tNome : %s",trab.nome);
  printf("\n\t\t\t\t\tIdade : %i",trab.idade);
  printf("\n\t\t\t\t\tSalario : %0.2f\n",trab.salario);
}
int main(){
  system("color 03");
  emp empresa[val];
  for(int i = 0;i < val;i++){
    empresa[i] = dados();
  }
  system("cls");
  printf("\n\t\t\t Dados dos empregados da empresa *******\n\n");
  for(int i = 0;i < val;i++){
    printemp(empresa[i]);
  }
  printf("\n\t\t\t+----------------------------------------+");
  printf("\n\n\n\n\n\n\n");
  getch();
  return 0;
}
