#include <stdio.h>

void inserts (int vec[],int n){
  int temp,j,k = 0;
  for(int i = 1; i < n;i++){
    temp = vec[i];
    j = i-1;
    while(j >= 0 && vec[j] > temp){
      vec[j+1] = vec[j];
      j = j - 1;
    }
    vec[j+1] = temp;
  }
  for(k = 0;k < n;k++){
    printf("vec[%i] - %d\n",k,vec[k]);
  }

}
int main(void){
  int vec[] = {3,7,1,9,4};
  int n = sizeof(vec)/sizeof(vec[0]);
  inserts(vec,n);
}
