#include<stdio.h>

int contar_digitos_recursivo(int numero);
int main(){
    int numero;
    printf("Digite um numero : ");scanf("%d",&numero);
    printf("%d",contar_digitos_recursivo(numero));
    return 0;
}

int contar_digitos_recursivo(int numero){
    static int count = 0;
    if(numero != 0){
        count++;
        contar_digitos_recursivo(numero/10);
    }
    return count;
}