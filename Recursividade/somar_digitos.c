#include <stdio.h>
#include <stdlib.h>

int soma_digitos_recursivo(int numero);
int main(){

    int numero;
    printf("Digite um Numero : ");scanf("%d",&numero);
    printf("%d",soma_digitos_recursivo(numero));
    

    return 0;
}
int soma_digitos_recursivo(int numero){
    if(numero == 0){
        return 0;
    }
    else{
        return(numero%10 + soma_digitos_recursivo(numero/10));
    }
}