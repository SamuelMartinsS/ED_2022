#include <stdio.h>
#include <string.h>
#define VAL 2
int binarySearch(int arr[], int l, int r, int x){
    while (l <= r) {
        int m = l + (r - l) / 2; //Declarar e calcular o meio
        if (arr[m] == x)        //Verificar se o meio é igual ao valor de x
            return m;          //Se foir igual ao valor de X então sai da função o valor da posição do vetor
        if (arr[m] < x)       //Verificar se o valor de meio é menor que x
            l = m + 1;       //Se for menor, então vamos somar 1 ao valor de meio para voltar a verificar
        else                //Se não ocorrer nenhuma das anteriores, então é porque o valor é menor que o meio
            r = m - 1;     //Por isso temos de subtrair 1 ao valor de meio
    }

    return -1;           //Se o valor de x não for encontrado então vai sair do ciclo e devolver -1
}

int main(void){
    int arr[] = { 2, 3, 4, 10,15,40,50,60,70,80,90,100,110,120,130,140,150,160 };
    int n = sizeof(arr) / sizeof(arr[0]); //Calcular o comprimento de um vetor
    printf("vetor tem %i elemtentos",n);
    int result = binarySearch(arr, 0, n, VAL);
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d",  result);
    return 0;
}