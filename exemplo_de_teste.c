#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


struct carros{
    char matricula[7];
    int  kms;
    char proprietario[10];
    struct carros * next;
};

int vazia(struct carros * head){
    if (head == NULL){
        return 1;
    }
    else {
        return 0;
    }
}
void addini(struct carros ** head,char matricula[],int kms,char proprietario[]){
    struct carros * lista_aux = (struct carros *)malloc(sizeof(struct carros));
    if(lista_aux == NULL){
        printf("ERRO");
    }
    else{
        strcpy(lista_aux->matricula,matricula);
        lista_aux->kms = kms;
        strcpy(lista_aux->proprietario,proprietario);
        lista_aux->next = *head;
        *head = lista_aux;
    }
}

void delen(struct carros ** head, char matricula[]){
    struct carros * lista_aux = *head;
    struct carros * temp = NULL;
    if(vazia(*head)){
        printf("Lista de carros vazia !");
    }
    else{
        if(lista_aux->next == NULL){
            free(lista_aux);
            *head = NULL;
        }
        else{
            while(strcmp(lista_aux->matricula, matricula) != 0 && lista_aux->next != NULL){
                temp = lista_aux;
                lista_aux = lista_aux->next;
            }
            if(strcmp(lista_aux->matricula,matricula) == 0 && lista_aux->next != NULL){
                temp->next = lista_aux->next;
                free(lista_aux);
             }
            else if (strcmp(lista_aux->matricula, matricula) == 0 && lista_aux->next == NULL){
                temp->next = NULL;
                free(lista_aux);
            }
        }
    }
}

void print(struct carros * head){
    if(vazia(head)){
        printf("\nLista de carros vazia !");
    }
    else{
        printf("\n\nLista de carros :");
        printf("\n================================");
        
        do{
            printf("\nMatricula : %s",head->matricula);
            printf("\nQuilometros : %d",head->kms);
            printf("\nProprietario : %s",head->proprietario);
            printf("\n================================");
            head = head->next;
        }while(head != NULL);
    }
}

int numero_de_carros_recursivo(struct carros * head,int count){
    if(head != NULL){
        count++;
        head = head->next;
        return (numero_de_carros_recursivo(head,count));
    }
    return count;

}

struct  carros * swap(struct carros * xp , struct carros * yp){
    struct carros * temp = yp->next;
    yp->next = yp;
    xp->next = temp;

    return yp;
}

int bubblesort(struct carros **head, int count){
    struct carros ** lista_aux;
    int i, j, done;
    for (i = 0; i <= count; i++){
        lista_aux = head;
        done = 0;
        for (j = 0; j < count - i - 1; j++){
            struct carros *p1 = *lista_aux;
            struct carros *p2 = p1->next;
            if (p1->kms > p2->kms){
                *lista_aux = swap(p1, p2);
                done = 1;
            }

            lista_aux = &(*lista_aux)->next;
        }
        if (done == 0)
            break;
    }
}

int main(){
    struct carros * head = NULL;
    char matricula[7];
    int kms;
    char proprietario[10];
    int ch = 0;
    int count;
home :
    system("cls");
    printf("1. Adicionar carros");
    printf("\n2. Eliminar carros");
    printf("\n3. Verificar carros registados");
    printf("\n4. Ordenar carros registados(e necessario fazer primeiro a verificacao)");
    printf("\n5. Sair");
    printf("\nOpcao : ");scanf("%d",&ch);
    switch(ch){
        case 1:
            printf("\n\nAdicionar");
            printf("\nMatricula do carro : ");scanf("%s",matricula);
            printf("Quilometros do carro : ");scanf("%d",&kms);
            printf("Proprietario do carro : ");scanf("%s",proprietario);
            addini(&head,matricula,kms,proprietario);
            goto home;
        case 2:
            printf("\n\nRemover");
            printf("\nMatricula do carro : ");scanf("%s",matricula);
            delen(&head, matricula);
            goto home;
        case 3:
            print(head);
            count = numero_de_carros_recursivo(head, 0);
            printf("\nNumero de carros registados : %d", count);
            getch();
            goto home;
        
        case 4:
            printf("\n\nOrdenar por Quilometros");
            bubblesort(&head,count);
            goto home;
        case 5:
            exit(0);
        default :
            goto home;
    }
    return 0;
}