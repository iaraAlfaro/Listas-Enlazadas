#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int num;
    char caracter;
    struct Nodo *sig;
} nodo;

void crearLista(nodo**);
void insertarNodos(nodo**, char, int);
void eliminarDatos(nodo**);
void eliminarDatoEspecifico(nodo**, int);
void separarLista(nodo*, nodo**, nodo**);
void emitirLista(nodo*);
void emiteNodo(nodo*);
void eliminarNodo(nodo**);
void emitirLista1(nodo*);
int main()
{
    nodo *lista1, *listaPar, *listaImpar;
    int opcion, n, eliminar;
    char c;

    do
    {
        printf("\nIngrese la opcion deseada:\n");
        printf("1) Crear lista.\n");
        printf("2) Insertar datos.\n");
        printf("3) Eliminar las listas.\n");
        printf("4) Separar la lista principal en dos listas pares e impares.\n");
        printf("5) Emitir todas las listas.\n");
        printf("6) Emitir lista principal.\n");
        printf("7) Eliminar dato dentro de la lista.\n");
        printf("Oprima 0 para salir.\n\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                crearLista(&lista1);
                crearLista(&listaPar);
                crearLista(&listaImpar);
            break;
            case 2:
                printf("\nIngrese un caracter: \n");
                fflush(stdin);
                scanf("%c", &c);
                printf("\nIngrese un numero: \n");
                fflush(stdin);
                scanf("%d", &n);
                insertarNodos(&lista1, c, n);
            break;
            case 3:
                eliminarNodo(&lista1);
                eliminarNodo(&listaPar);
                eliminarNodo(&listaImpar);
            break;
            case 4:
                separarLista(lista1, &listaPar, &listaImpar);
            break;
            case 5:
                printf("\nLista principal:\n");
                emitirLista1(lista1);
                printf("\nLista de numeros pares:\n");
                emitirLista1(listaPar);
                printf("\nLista de numeros impares:\n");
                emitirLista1(listaImpar);
            break;
            case 6:
                printf("\nLista principal:\n");
                emitirLista1(lista1);
            break;
            case 7:
                printf("Ingrese el numero que desea eliminar\n");
                fflush(stdin);
                scanf("%d", &eliminar);
                eliminarDatoEspecifico(&lista1, eliminar);
            break;
        }

    }
    while(opcion != 0);

    return 0;
}
void crearLista(nodo **p)
{
    *p = NULL;
}
void insertarNodos(nodo **p, char c, int n)
{
    nodo *aux;
    aux = (nodo*)malloc(sizeof(nodo));
    aux->caracter = c;
    aux->num = n;
    aux->sig = *p;
    *p = aux;
}

void eliminarNodo(nodo **p)
{
    if(*p == NULL)
    {
        printf("\nLa lista esta vacia\n");
    }
    else
    {
        eliminarDatos(p);
    }
}

void eliminarDatos(nodo **p)
{
    if(*p != NULL)
    {
        eliminarDatos(&(*p)->sig);
        free(*p);
        *p = NULL;
    }

}
void separarLista(nodo *lis1, nodo **par, nodo **impar)
{
    while(lis1 != NULL)
    {
        if(lis1->num % 2 == 0)
        {
            insertarNodos(par, lis1->caracter, lis1->num);
        }
        else
        {
            insertarNodos(impar, lis1->caracter, lis1->num);
        }
        lis1 = lis1->sig;
    }
}
void emitirLista1(nodo *p)
{
    if(p == NULL)
    {
        printf("\nLa lista esta vacia\n");
    }
    else
    {
        emitirLista(p);
    }
}

void emitirLista(nodo *p)
{
    if(p != NULL)
    {
        emiteNodo(p);
        emitirLista(p->sig);
    }
}

void emiteNodo(nodo *p)
{
    printf("\n\nCaracter: %c\nNumero: %d\n", p->caracter, p->num);
}

void eliminarDatoEspecifico(nodo **p, int borrar)
{
    nodo *aux;
    aux = *p;

    while(aux != NULL)
    {
        if(aux->num == borrar)
        {
           aux->num = 0;
        }

        aux = aux->sig;
    }
}
