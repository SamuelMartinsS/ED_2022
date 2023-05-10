#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int calc(int vec[10],int i){
    if(i == 10)
        return 0;
    else
        return vec[i] + calc(vec,i+1);
    
}
int main(){
    int vec[10] ={5,12,32,43,12,1,5,10,81,1};
    printf("%d",calc(vec,0));
    return 0;
}