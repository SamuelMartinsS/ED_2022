#include <stdio.h>
#define val 10
int search(int arr[], int n, int x){
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

int main(void){
	int arr[] = { 2, 3, 4, 10, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	(search(arr, n, val) == -1) ? printf("O elemento %i nao pertence ao vetor",val) : printf("O elemento %i esta na posicao %d",val, search(arr, n, val));
	return 0;
}
