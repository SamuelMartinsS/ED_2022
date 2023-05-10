#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define DEBUG 0

struct listas
{
    int data;
    struct listas *next;
    struct listas *prev;
};

int vazia(struct listas *head)
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

void addini(struct listas **head, int num)
{
    struct listas *nova_lista = (struct listas *)malloc(sizeof(struct listas));
    nova_lista->data = num;
    nova_lista->next = (*head);
    nova_lista->prev = NULL;
    if ((*head) != NULL)
        (*head)->prev = nova_lista;
    (*head) = nova_lista;
}

void addfim(struct listas **head, int num)
{
    struct listas *nova_lista = (struct listas *)malloc(sizeof(struct listas));
    struct listas *temp;
    if (*head == NULL)
    {
        nova_lista->data = num;
        nova_lista->next = NULL;
        nova_lista->prev = NULL;
        (*head) = nova_lista;
    }
    temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    nova_lista->data = num;
    temp->next = nova_lista;
    nova_lista->next = NULL;
    nova_lista->prev = temp;
}

void adden(struct listas **head, int n, int num)
{
    struct listas *nova_lista = (struct listas *)malloc(sizeof(struct listas));
    if (n = 1)
        addini(head, num);
    else
    {
        struct listas *lista_aux;
        nova_lista->data = num;
        nova_lista->next = NULL;
        nova_lista->prev = NULL;
        int cont = 1;
        if (cont == 1)
        {
        }
        while (cont < n && lista_aux->next != NULL)
        {
            lista_aux = lista_aux->next;
        }
        if (lista_aux->next == NULL)
            addfim(head, num);
        else
        {
            lista_aux->data = nova_lista->data;
        }
    }
}

void print(struct listas *head)
{
    int i = 1;
    if (vazia(head))
    {
        system("cls");
        printf("=================\n");
        printf("== LISTA VAZIA ==\n");
        printf("=================\n");
    }
    else
    {
        struct listas *last;
        while (head != NULL)
        {
            printf("[%i] : %i\t", i, head->data);
            last = head;
            head = head->next;
            i++;
        }
        printf("\n");
        printf("\n");
        i = 1;
        while (last != NULL)
        {
            printf("[%i] : %i\t", i, last->data);
            last = last->prev;
            i++;
        };
    }
}
void delini(struct listas **head)
{
    if (vazia(*head))
    {
        system("cls");
        printf("=================\n");
        printf("== LISTA VAZIA ==\n");
        printf("=================\n");
    }
    else
    {
        struct listas *nova_lista;
        nova_lista = (*head);
        (*head) = (*head)->next;
        free(nova_lista);
    }
}

void delfim(struct listas **head)
{
    if (vazia(*head))
    {
        system("cls");
        printf("=================\n");
        printf("== LISTA VAZIA ==\n");
        printf("=================\n");
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

void delen(struct listas **head, int n)
{
    if (vazia(*head))
    {
        system("cls");
        printf("=================\n");
        printf("== LISTA VAZIA ==\n");
        printf("=================\n");
    }
    else
    {
        struct listas *nova_lista;
        struct listas *lista_aux;
        nova_lista = *head;
        lista_aux = NULL;
        int cont = 1;
        while (cont < n && nova_lista->next != NULL)
        {
            cont++;
            nova_lista = nova_lista->next;
        }
        if (nova_lista->next == NULL)
        {
            system("cls");
            printf("=================\n");
            printf("== NAO EXISTE! ==\n");
            printf("=================\n");
        }
        else
        {
            lista_aux = nova_lista->next;
            nova_lista->next = lista_aux->next;
            free(lista_aux);
        }
    }
}

int main()
{
    struct listas *head = NULL;
    int num;
    int n;
    int ch = 0;
home:
    if (!DEBUG)
        system("cls");
    printf("======= MENU =======\n==   1. ADD INI   ==\n==   2. ADD FIM   ==\n==   3. ADD ENS   ==\n==   4. DEL INI   ==\n==   5. DEL FIM   ==\n==   6. DEL ENS   ==\n==   7. VER       ==\n====================\n Opcao : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("\n|| NUM : ");
        scanf("%d", &num);
        addini(&head, num);
        getch();
        goto home;
    case 2:
        printf("\n|| NUM : ");
        scanf("%d", &num);
        addfim(&head, num);
        getch();
        goto home;
    case 3:
        printf("\n|| NUM : ");
        scanf("%d", &num);
        printf("|| POS : ");
        scanf("%d", &n);
        adden(&head, n, num);
        getch();
        goto home;
    case 4:
        delini(&head);
        getch();
        goto home;
    case 5:
        delfim(&head);
        getch();
        goto home;
    case 6:
        printf("|| POS : ");
        scanf("%d", &n);
        delen(&head, num);
        getch();
        goto home;
    case 7:
        print(head);
        getch();
        goto home;
    default:
        exit(0);
    }
    return 0;
}