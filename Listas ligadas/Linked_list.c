#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct listas
{
    int data;
    struct listas *next;
};

int vazia(struct listas *head)
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

void addini(struct listas **head,int num){
    struct listas * nova_lista = (struct listas*)malloc(sizeof(struct listas));
    if(nova_lista == NULL){
        printf("Erro !");
    }else{
        nova_lista->data = num;
        nova_lista->next = *head;
        *head = nova_lista;
    }
}

void addfim(struct listas **head, int num){
    struct listas *nova_lista = (struct listas *)malloc(sizeof(struct listas));
    struct listas *temp;

    if (*head == NULL)
    {
        nova_lista->data = num;
        nova_lista->next = NULL;
        (*head) = nova_lista;
    }
    temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    nova_lista->data = num;
    temp->next = nova_lista;
    nova_lista->next = NULL;
}

void delini(struct listas **head)
{
    struct listas * temp = NULL;
    if (*head == NULL)
        printf("\nLista vazia");
    else
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void delfim(struct listas **head)
{
    if (vazia(*head))
    {
        printf("\nLista vazia");
    }
    else
    {
        struct listas *nova_lista;
        struct listas *lista_aux;
        nova_lista = *head;
        lista_aux = NULL;
        while (nova_lista->next != NULL)
        {
            lista_aux = nova_lista;
            nova_lista = nova_lista->next;
        }
        free(nova_lista);
        if (lista_aux != NULL)
            lista_aux->next = NULL;
        else
        {
            *head = NULL;
        }
    }
}

void adden(struct listas ** head, int n,int num)
{
    struct listas *nova_lista = (struct listas*)malloc(sizeof(struct listas));
    if (n == 1)
        addini(head,num);
    else
    {
        nova_lista->data = num;
        nova_lista->next = NULL;
        struct listas * lista_aux;
        int i = 1;
        lista_aux = *head;
        while (i < n+1 && lista_aux->next != NULL)
        {
            lista_aux = lista_aux->next;
            i++;
        }
        if (lista_aux->next == NULL)
            addfim(head,num);
        else
        {
            lista_aux->data = nova_lista->data;
        }
    }
}

void delen(struct listas **head, int n){
    struct listas *lista_aux = *head;
    struct listas *lista_aux1 = NULL;
    if(vazia(*head)){
        printf("\nLista vazia");
    }
    else{
        if(n == 1)
            delini(head);
        int i = 1;
        while(i < n && lista_aux->next != NULL){
            lista_aux1 = lista_aux;
            lista_aux = lista_aux->next;
            i++;
        }
        if(lista_aux->next == NULL){
            delfim(head);
        }
        else{
            lista_aux1->next = lista_aux->next;
            free(lista_aux);

        }
    }
}

void print(struct listas *head)
{
    int i = 1;
    if (vazia(head))
    {
        printf("Lista vazia");
    }
    else {
        while (head != NULL){
            printf("\n[%i] : %i\t", i, head->data);
            head = head->next;
            i++;
        }
    }
}

int main(){
    int ch;
    int pos;
    struct listas *lista = NULL;
menu:
    system("cls");
    printf("\n1. Adicionar ao inicio\n2. Adicionar ao fim\n3. Eliminar inicio\n4. Eliminar Fim\n5. Adicionar em n\n6. Eliminar em n\n7. Mostrar\n8. Sair\nOpcao : ");scanf("%d",&ch);
    switch(ch){
        case 1:
            addini(&lista,1);
            goto menu;
        case 2:
            addfim(&lista,0);
            goto menu;
        case 3:
            delini(&lista);
            goto menu;
        case 4:
            delfim(&lista);
            goto menu;
        case 5:
            printf("\nAdicionar na posicao ");scanf("%d",&pos);
            adden(&lista,pos,2);
            goto menu;
        case 6:
            printf("\nEliminar na posicao ");scanf("%d",&pos);
            delen(&lista,pos);
            goto menu;
        case 7:
            printf("\nConteudo das listas :");
            print(lista);
            getch();
            goto menu;

        case 8:
            exit(1);
        default:
            goto menu;
    }
    return 0;
}
