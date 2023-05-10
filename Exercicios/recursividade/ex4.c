/*Contar o número de algarismos que compõem um número inteiro não negativo n.
(Por exemplo: 2 tem 1 algarismo, 231 tem 3 algarismos, 998877 tem 6 algarismos,...)*/
#include <stdio.h>

int digitos(int num){
     int cont = 1;
    if(num >= 10){
        num = num / 10;
        cont = cont + digitos(num);
        return cont;
    }
    else
        return cont;
    
}
int main(){
    int num;
    int ndigitos;
    printf("Numero : ");scanf("%d",&num);
    ndigitos = digitos(num);
    printf(" ->%d",ndigitos);
    return 0;
}