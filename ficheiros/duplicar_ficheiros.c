#include <stdio.h>
#include <stdlib.h>

int main (){

  FILE * fin, * fout;
  char caratere;
  char origem[30], destino[30];

  printf("Nome do ficheiro de origem : ");scanf("%s",origem);
  printf("\n");
  fin = fopen(origem,"rb");
  if(fin == NULL){
    printf("O ficheiro nao existe !");
    exit(0);
  }
  else{
    printf("Nome do ficheiro destino : ");scanf("%s",destino);
  }
  fout = fopen(destino,"w+");
    while(fscanf(fin,"%c",&caratere) != EOF){
      fprintf(fout, "%c",caratere);
    }
    printf("O ficheiro foi copiado com sucesso");

  fclose(fout);
  fclose(fin);


  return 0;
}
