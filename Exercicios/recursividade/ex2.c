#include <stdio.h>

float pontos(int num){
    float npontos = 1;;
    if(num <= 1){
        return 1;
    }
    else{
        npontos = num + pontos(num - 1);
        return npontos;
    }
}
int main(){
    int num;
    float npontos;
    printf("Altura do triangulo : ");scanf("%d",&num);
    npontos = pontos(num);
    printf(" ->%f",npontos);

    return 0;
}