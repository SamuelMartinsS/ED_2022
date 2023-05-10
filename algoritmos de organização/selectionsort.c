#include <stdio.h>

//Função que troca duas posições apontadas pelos ponteiros x e y , é mais eficaz !
void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n){
	int temp;
	for (int i = 0; i < n; i++){
		temp = i;                         //guardar o valor de i (valor minimo)
		for (int j = i+1; j < n; j++)    // igualar o j ao i e adicionar 1 assim vamos comparar o valor guardado anteriormente pelo proximo
		  if (arr[j] < arr[temp])       // O for vai fazer com que corremos o vetor para comparar todos os valores com o primeiro
        temp = j;                  //Se a condição do if for verificada, entao encontramos um valor menor do que o inicial e vamos dar esse valor a variavel temp

		swap(&arr[temp], &arr[i]);    // vamos entrar noutra função, esta que vai levar os endereços de memoria das posições que vão ser trocadas
	}
  for(int i = 0; i < n; i++){
    printf("arr[%i] - %i\n",i,arr[i]);
  }
}

int main()
{
	int arr[] = {24, 11, 27, 21, 1};
	int n = sizeof(arr)/sizeof(arr[0]);//Calcular o comprimento do vetor
	selectionSort(arr, n);
	return 0;
}
