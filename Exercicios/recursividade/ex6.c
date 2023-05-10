/*Escrever uma sequência de algarismos, dado um n ∈ IN0 como os exemplos:
1 (n=1)
212 (n=2)
32123 (n=3)
4321234 (n=4)
...
Pretende-se escrever apenas uma das sequências anteriores*/
#include <stdio.h>
#include <stdlib.h>

int print(int num,int k){
    if(num <= 0){
        for(int i = 2 ; i <= k ; i++ )
            printf("%i",i);
    }
    else{
        printf("%i",num);
        num = print(num-1,k);
        return num;
    }
}
int main(){
    int num;
    printf("Altura da piramide : ");scanf("%i",&num);
    print(num,num);
    return 0;
}