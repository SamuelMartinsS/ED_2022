/* Calcular o n–ésimo número de Fibonacci sabendo que os Números de Fibonacci são termos de uma sucessão (com o mesmo
nome) definida por recorrência do seguinte modo: cada termo da sucessão é obtido pela soma dos dois temos anteriores.
Os primeiros números de Fibonacci são: 1, 1, 2, 3, 5, 8, 13, 21,...*/
#include <stdio.h>

float fibonacci(int termo,float t1,float t2){
    float num;
    int cc;
    float tt = t1 + t2;
    if(termo <= 1)
        return tt;
    else{
        t1 = t2;
        t2 = tt;
        tt = t1 + t2;
        termo--;
        tt = fibonacci(termo,t1,t2);
        return tt;
    }
}
int main(){
    int termo;
    float num;
    printf("Termo numero : ");scanf("%d",&termo);
    num = fibonacci(termo,0,1);
    printf(" ->%f",num);

    return 0;
}