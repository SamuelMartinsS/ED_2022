#include <stdio.h>
#include <conio.h>

double fatorial(int num){
    double nfatorial;
    if( num <= 1)
        return 1;
    else{
        nfatorial = num * fatorial(num - 1);
        return nfatorial;
    }
}

int main(){

    int num;
    double nfatorial;

    printf("Fatorial de : ");scanf("%d",&num);
    nfatorial = fatorial(num);
    printf(" ->%lf",nfatorial);

    return 0;
}