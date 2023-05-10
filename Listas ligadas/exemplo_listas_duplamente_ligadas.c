#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

/*
    ================================================================================================================================
    Este programa inclui :
    ================================================================================================================================
    Listas de Listas duplamente ligadas simples
    ================================================================================================================================
    Recursividade
    ================================================================================================================================
    Algoritmo de organização bubblesort
    ================================================================================================================================
    Ler e escrever em ficheiros binários
    ================================================================================================================================
    Manuseamento de listas duplamente ligadas (adicionar , remover, alterar , remover x , remover todas, etc ...)
    ================================================================================================================================
*/

struct listas
{
    char nome[20];
    int numero;
    int done;
    struct listas *prev;
    struct listas *next;
};

struct listas_temp
{
    char nome[20];
    int numero;
    int done;
};

int vazia(struct listas *head)
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

void add_ini(struct listas **head,char nome[], int num,int done)
{
    struct listas *nova_lista = (struct listas *)malloc(sizeof(struct listas));
    strcpy(nova_lista->nome,nome);
    nova_lista->numero = num;
    nova_lista->done = done;
    nova_lista->next = (*head);
    nova_lista->prev = NULL;
    if ((*head) != NULL)
        (*head)->prev = nova_lista;
    (*head) = nova_lista;
}

void add_fim(struct listas **head, char nome[], int num, int done)
{
    struct listas *nova_lista = (struct listas *)malloc(sizeof(struct listas));
    struct listas *temp;
    if (*head == NULL)
    {
        strcpy(nova_lista->nome, nome);
        nova_lista->numero = num;
        nova_lista->done = done;
        nova_lista->next = NULL;
        nova_lista->prev = NULL;
        (*head) = nova_lista;
    }
    temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    strcpy(nova_lista->nome, nome);
    nova_lista->numero = num;
    nova_lista->done = done;
    temp->next = nova_lista;
    nova_lista->next = NULL;
    nova_lista->prev = temp;
}

void add_mid(struct listas **head, int n,char nome[],int num,int done)
{
    struct listas *nova_lista = (struct listas *)malloc(sizeof(struct listas));
    if (n = 1)
        add_ini(head,nome,num,done);
    else
    {
        
        strcpy(nova_lista->nome, nome);
        nova_lista->numero = num;
        nova_lista->done = done;
        nova_lista->next = NULL;
        nova_lista->prev = NULL;
        struct listas *lista_aux = *head;
        int cont = 1;
        while (cont < n && lista_aux->next != NULL)
        {
            lista_aux = lista_aux->next;
        }
        if (lista_aux->next == NULL)
            add_fim(head,nome,num,done);
        else
        {
            nova_lista->prev = lista_aux;
            nova_lista->next = lista_aux->next;
            lista_aux->next = nova_lista;
            lista_aux->next->prev = nova_lista;
        }
    }
}

void print(struct listas *head)
{
    if (vazia(head))
    {
        printf("\nLista vazia");
    }
    else
    {
        struct listas *aux = head;
        struct listas *last = NULL;
        printf("\n\nDo primeiro para o ultimo\n");
        printf("\n =====================");
        while(aux != NULL){
            printf("\n Feito : %d", aux->done);
            printf("\n Nome : %s", aux->nome);
            printf("\n Numero : %d", aux->numero);
            printf("\n =====================");
            aux = aux->next;
            last = aux;
        }
        printf("\n\n Do ultimo para o primeiro\n");
        printf("\n =====================");
        while(last != NULL) {
            printf("\n Feito : %d", aux->done);
            printf("\n Nome : %s", aux->nome);
            printf("\n Numero : %d", aux->numero);
            printf("\n =====================");
            last = last->prev;
        }
    }

}
void remove_prim(struct listas **head)
{
    if (vazia(*head))
    {
        printf("\nLista vazia !");
    }
    else
    {
        struct listas *nova_lista;
        nova_lista = (*head);
        (*head) = (*head)->next;
        (*head)->prev = NULL;
        free(nova_lista);
    }
}

void remove_ult(struct listas **head)
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

void remove_x(struct listas **head, char nome[])
{
    int c =0;
    if (vazia(*head))
    {
        printf("\nLista vazia !");
    }
    else
    {
        struct listas *nova_lista = *head;
        struct listas *lista_aux = NULL;
        if (lista_aux->next == NULL)
        {
            free(lista_aux);
            *head = NULL;
        }
        else
        {
            while (strcmp(nova_lista->nome, nome) == 0 || nova_lista->next != NULL)
            {
                lista_aux = nova_lista;
                nova_lista = nova_lista->next;
            }
            if (strcmp(nova_lista->nome, nome) == 0 && nova_lista->prev == NULL)
            {
                (*head) = (*head)->next;
                free(nova_lista);
            }
            else if (strcmp(nova_lista->nome, nome) == 0 && nova_lista->next != NULL)
            {
                lista_aux->next = nova_lista->next;
                nova_lista->next->prev = lista_aux;
                free(nova_lista);
            }
            else if (strcmp(nova_lista->nome, nome) == 0 && nova_lista->next == NULL)
            {
                lista_aux->next = NULL;
                free(nova_lista);
            }
        }
    }
}
int main(){
    struct listas * head = NULL;
    char nome[20];
    int num;
    int aux;
    int ch = 0;
home:
    printf("\n1. Adicionar ao inicio");
    printf("\n2. Adicionar ao fim");
    printf("\n3. eliminar x");
    printf("\n4. Adicionar x");
    printf("\n5. Ver");
    printf("\nOpcao : ");
    scanf("%d",&ch);

    switch(ch){
        case 1:
            printf("\n Nome : ");scanf("%s",nome);
            printf("\n Numero : ");scanf("%d",&num);
            add_ini(&head,nome,num,0);
            goto home;
        case 2:
            printf("\n Nome : ");scanf("%s",nome);
            printf("\n Numero : ");scanf("%d",&num);
            add_fim(&head, nome, num, 0);
            goto home;
        case 3:
            printf("\n Nome : ");scanf("%s",nome);
            remove_x(&head,nome);
            goto home;
        case 4:
            // printf("\n Nome : ");scanf("%s",nome);
            // printf("\n Numero : ");scanf("%d",&num);
            // printf("\n Adicionar na posicao : ");scanf("%d",&aux);
            // add_x(&head,nome,num,0,aux);
            goto home;
        case 5:
            print(head);
            getch();
            goto home;
        case 6:
            exit(1);
        default:
            goto home;
    }
    return 0;
}