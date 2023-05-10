#include <stdio.h>

//Função que troca duas posições apontadas pelos ponteiros x e y , é mais eficaz !
void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n){
for(int i = 0; i < n; i++)
	for(int j = 0; j < n-i-1; j++)
		if(arr[j] > arr[j+1])
		    swap(&arr[j], &arr[j+1]);
  for(int i = 0; i < n;i++){
    printf("arr[%i] - %i\n",i,arr[i]);
  }
}

int main(){
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr, n);
	return 0;
}
