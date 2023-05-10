#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

/*
    ================================================================================================================================
    Este programa inclui :
    ================================================================================================================================
    Listas de Listas ligadas simples
    ================================================================================================================================
    Recursividade
    ================================================================================================================================
    Algoritmo de organização bubblesort
    ================================================================================================================================
    Ler e escrever em ficheiros binários
    ================================================================================================================================
    Manuseamento de listas ligadas simples (adicionar , remover, alterar , remover x , remover todas, etc ...)
    ================================================================================================================================
*/
struct listas {
    char nome[20];
    int numero;
    int done;
    struct listas * next;
};

struct listas_temp{
    char nome[20];
    int numero;
    int done;
};

int vazia(struct listas * head){
    if(head == NULL) return 1;
    else return 0;
}

void add_ini(struct listas **head, char nome[], int num,int done)
{
    struct listas *nova_lista = (struct listas *)malloc(sizeof(struct listas));
    if (nova_lista == NULL)
    {
        printf("Erro !");
    }
    else
    {
        strcpy(nova_lista->nome, nome);
        nova_lista->numero = num;
        nova_lista->done = done;
        nova_lista->next = *head;
        *head = nova_lista;
    }
}

void add_fim(struct listas ** head, char nome[], int num, int done){
    struct listas *nova_lista = (struct listas *)malloc(sizeof(struct listas));
    struct listas *temp;

    if (*head == NULL)
    {
        strcpy(nova_lista->nome,nome);
        nova_lista->numero = num;
        nova_lista->done = done;
        nova_lista->next = NULL;
        (*head) = nova_lista;
    }
    temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    strcpy(nova_lista->nome,nome);
    nova_lista->numero = num;
    nova_lista->done = done;
    temp->next = nova_lista;
    nova_lista->next = NULL;
}

void add_mid(struct listas ** head,char nome[], int num, int done){
    struct listas *nova_lista = (struct listas *)malloc(sizeof(struct listas));
    struct listas * temp = *head;
    int cont = 0;
    if(vazia(*head)){
        add_fim(head,nome,num,done);
    }
    else if(temp->next == NULL){
        add_fim(head,nome,num,done);
    }
    else{
        while(temp != NULL){
            temp = temp->next;
            cont++;
        }
        temp = *head;
        cont = cont/2;
        printf("%d\n",cont);
        int i = 1;
        while(i < cont){
            i++;
            temp = temp->next;
        }
        strcpy(nova_lista->nome, nome);
        nova_lista->numero = num;
        nova_lista->done = done;
        nova_lista->next = temp->next;
        temp->next = nova_lista;
    }
}

void add_x(struct listas **head, int n,char nome[], int num,int done)
{
    struct listas *nova_lista = (struct listas *)malloc(sizeof(struct listas));
    if (n == 1)
        add_ini(head, nome, num, done);
    else
    {
        strcpy(nova_lista->nome, nome);
        nova_lista->numero = num;
        nova_lista->done = done;
        nova_lista->next = NULL;
        struct listas *lista_aux;
        int i = 1;
        lista_aux = *head;
        while (i < n && lista_aux->next != NULL)
        {
            lista_aux = lista_aux->next;
            i++;
        }
        if (lista_aux->next == NULL)
            add_fim(head, nome, num, done);
        else
        {
            nova_lista->next = lista_aux->next;
            lista_aux->next = nova_lista;
        }
    }
}

void remove_prim(struct listas **head)
{
    struct listas *temp = NULL;
    if (*head == NULL)
        printf("\nLista vazia");
    else
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void remove_ult(struct listas ** head){
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

void remove_done(struct listas ** head){
    struct listas *aux = NULL;
    struct listas *aux1 = NULL;
    struct listas *aux2 = NULL;
    int debug_cont = 0;
    aux = *head;
    aux1 = NULL;
    aux2 = NULL;
    int i = 0;
    int cont = 0;
    if (vazia(*head))
    {
        printf("\nLista vazia !");
    }
    else
    {
        do{
            i++;
            aux = aux->next;
        }while(aux->next != NULL);

        aux = *head;
        do
        {
            debug_cont++;
            if (aux->done == 1)
            {
                if (i == 1)
                {
                    remove_prim(head);
                }
                else if (aux->next == NULL)
                {
                    remove_ult(head);
                }
                else
                {
                    aux1->next = aux->next;
                    free(aux);
                }
            }
            aux1 = aux;
            aux = aux->next;
        } while (aux != NULL);
    }
}

void remove_en (struct listas **head, char nome[])
{
    int count = 0;
    struct listas *lista_aux = *head;
    struct listas *temp = NULL;
    if (vazia(*head))
    {
        printf("\nlistas vazia !");
    }
    else
    {
        if (lista_aux->next == NULL)
        {
            free(lista_aux);
            *head = NULL;
        }
        else{
            while (strcmp(lista_aux->nome, nome) != 0 && lista_aux->next != NULL)
            {
                temp = lista_aux;
                lista_aux = lista_aux->next;
                count++;
            }
            if (strcmp(lista_aux->nome, nome) == 0 && count == 0){
                (*head) = (*head)->next;
                free(lista_aux);
            }
            if (strcmp(lista_aux->nome, nome) == 0 && lista_aux->next != NULL)
            {
                temp->next = lista_aux->next;
                free(lista_aux);
            }
            else if (strcmp(lista_aux->nome, nome) == 0 && lista_aux->next == NULL)
            {
                temp->next = NULL;
                free(lista_aux);
            }
        }
    }
}

void remove_x(struct listas **head, int n)
{
    struct listas *lista_aux = *head;
    struct listas *lista_aux1 = NULL;
    if (vazia(*head))
    {
        printf("\nLista vazia");
    }
    else
    {
        if (n == 1)
            remove_prim(head);
        int i = 1;
        while (i < n && lista_aux->next != NULL)
        {
            lista_aux1 = lista_aux;
            lista_aux = lista_aux->next;
            i++;
        }
        if (lista_aux->next == NULL)
        {
            remove_ult(head);
        }
        else
        {
            lista_aux1->next = lista_aux->next;
            free(lista_aux);
        }
    }
}

void acabar_tarefa(struct listas ** head, char nome[]){
    struct listas * aux = *head;
    if(vazia(*head)){
        printf("\nLista vazia !");
    }
    else{
        do{
            if(strcmp(aux->nome,nome) == 0)
                aux->done = 1;
            aux = aux->next;
        }while(aux->next != NULL);
    }
}

struct listas *swap(struct listas *x, struct listas *y)
{
    struct listas *temp = y->next;
    y->next = x;
    x->next = temp;
    return y;
}

void bubblesort(struct listas ** head,int count)
{
    struct listas **aux = NULL;
    struct listas *l1 = NULL;
    struct listas *l2 = NULL;

    int troca;
    for (int i = 0; i <= count; i++){
        aux = head;
        troca= 0;
        for (int j = 0; j < count - i - 1; j++){
            l1 = *aux;
            l2 = l1->next;
            if (l1->done > l2->done){
                *aux = swap(l1, l2);
                troca = 1;
            }
            aux = &(*aux)->next;
        }
        if (troca == 0)
            break;
    }
}


void print(struct listas * head)
{
    if(vazia(head)){
        printf("\nLista vazia");
    }
    else{
        struct listas * aux = head;
        printf("\n =====================");
        do{
            printf("\n Feito : %d",aux->done);
            printf("\n Nome : %s",aux->nome);
            printf("\n Numero : %d",aux->numero);
            printf("\n =====================");
            aux = aux->next;
        }while(aux != NULL);
    }
}

void escrever_no_ficheiro(struct listas *head){
    FILE *fp;
    struct listas * aux = head;
    struct listas_temp temp;
    fp = fopen("info.dat","a+b");
    if(vazia(head)){
        printf("Lista vazia");
    }
    else{
        while(aux != NULL){
            strcpy(temp.nome,aux->nome);
            temp.numero = aux->numero;
            temp.done = aux->done;
            fwrite(&temp,sizeof(struct listas_temp),1,fp);
            aux = aux->next;
        }
    }
}

void ler_do_ficheiro(struct listas *head)
{
    FILE *fp;
    struct listas_temp temp;
    fp = fopen("info.dat", "r+b");
    while (fread(&temp, sizeof(temp), 1, fp) > 0){
        add_ini(&head, temp.nome,temp.numero,temp.done);
    }
    fclose(fp);
}

int numero_de_listas(struct listas *head, int count)
{
    if (head != NULL)
    {
        count++;
        head = head->next;
        return (numero_de_listas(head, count));
    }
    return count;
}

int main(){
    struct listas * head[5];
    for(int i = 0; i < 5;i++)
        head[i] = NULL;
    int n_lista;
    char nome[20];
    int numero;
    int ch = 0;
    int n;
    int count = 0;
home:
    system("cls");
    printf("1. Adicionar ");
    printf("\n2. Eliminar");
    printf("\n3. Escrever no ficheiro");
    printf("\n4. Organizar");
    printf("\n5. Ver lista");
    printf("\n6. Sair");
    printf("\nOpcao : ");scanf("%d", &ch);
    switch(ch){
        case 1:
            printf("\nLista numero : ");
            scanf("%d", &n_lista);
            printf("Nome : ");scanf("%s",nome);
            printf("Numero : ");scanf("%d",&numero);
            add_mid(&head[n_lista],nome,numero,0);
            getch();
            goto home;
        case 2:
            printf("\nLista numero : ");
            scanf("%d", &n_lista);
            printf("Adicionar na posicao :");scanf("%d",&n);
            printf("Nome : ");
            scanf("%s", nome);
            printf("Numero : ");
            scanf("%d", &numero);
            add_x(&head[n_lista],n, nome, numero, 0);
            getch();
            goto home;
        case 3:
            printf("\nLista numero : ");scanf("%d", &n_lista);
            printf("Nome : ");scanf("%s",nome);
            remove_en(&head[n_lista],nome);
            getch();
            goto home;
        case 4:
            printf("\nLista numero : ");
            scanf("%d", &n_lista);
            escrever_no_ficheiro(head[n_lista]);
            printf("Ficheiro escrito no ficheiro com sucesso !");
            getch();
            goto home;
        case 5:
            printf("\nLista numero : ");
            scanf("%d", &n_lista);
            count = numero_de_listas(head[n_lista],0);
            bubblesort(&head[n_lista],count);
            printf("A lista foi organizada");
            getch();
            goto home;
        case 6:
            printf("\nLista numero : ");
            scanf("%d", &n_lista);
            print(head[n_lista]);
            getch();
            goto home;
        case 7:
            exit(1);
        default:
            goto home;
    }
    return 0;
}