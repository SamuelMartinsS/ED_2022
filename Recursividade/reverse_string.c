#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverse_string_recursivo(char *string, int tamanho);
int main(){
    char string[100];
    printf("Digite uma string : ");
    scanf("%s",string);
    printf("%s",reverse_string_recursivo(string,strlen(string)));
    return 0;
}
char *reverse_string_recursivo(char *string, int tamanho){
    static int count = 0;
    static char string_reverse[100];
    if(tamanho != 0){
        string_reverse[count] = string[tamanho-1];
        count++;
        reverse_string_recursivo(string,tamanho-1);
    }
    return string_reverse;
}