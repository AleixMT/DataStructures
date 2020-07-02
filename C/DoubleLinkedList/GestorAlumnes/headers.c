#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#include <malloc.h>
#include <string.h>
#include "registros.h"
#include <stdbool.h>

void menu(){

    printf("\n1.Afegir alumne\n");
    printf("2.Buscar per DNI\n");
    printf("3.Buscar per Nom\n");
    printf("4.Veure ultim alumne buscat\n");
    printf("5.Eliminar ultim alumne buscat\n");
    printf("0.Sortir\n");

}

Nodo* CrearNodo(Alumne* alumne){
    Nodo* nodo = (Nodo *) malloc(sizeof(Nodo));
    strncpy(nodo->alumne.nom, alumne->nom, 50);
    strncpy(nodo->alumne.dni, alumne->dni, 50);
    strncpy(nodo->alumne.correu, alumne->correu, 50);
    strncpy(nodo->alumne.nota, alumne->nota, 50);
    strncpy(nodo->alumne.data, alumne->data,50);
    strncpy(nodo->alumne.sexe, alumne->sexe,50);
    nodo->siguiente = NULL;
    return nodo;
}

void DestruirNodo(Nodo* nodo){
    free(nodo);
}

void zeros(char nombre[50]){
    int i = 0;

    while(i != 50){
        nombre[i] = '\0';
        i++;
    }
}

int contar (char X[50])
{
    int i;
    int cont;
    cont=0;
    while (X[i]!='\0')
    {
        i++;
        cont++;
    }
    return cont;
}

void InsertarPrincipio(Lista* lista, Alumne* alumne){
    Nodo* nodo = CrearNodo(alumne);
    nodo->siguiente = lista->cabeza;
    lista->cabeza = nodo;
    lista->longitud++;
}

void InsertarFinal(Lista* lista, Alumne* alumne){
    Nodo* nodo = CrearNodo(alumne);
    if(lista->cabeza == NULL){
        lista->cabeza = nodo;
    }else{
        Nodo* puntero = lista->cabeza;
        while(puntero->siguiente){
            puntero = puntero->siguiente;
        }
        puntero->siguiente = nodo;
    }
    lista->longitud++;
}

void InsertarDespues(int n, Lista* lista, Alumne* alumne){
    Nodo* nodo = CrearNodo(alumne);
    if(lista->cabeza == NULL){
        lista->cabeza = nodo;
    }else{
        Nodo* puntero = lista->cabeza;
        int posicion = 0;
        while(puntero->siguiente && posicion<n){
            puntero = puntero->siguiente;
            posicion++;
        }
        nodo->siguiente = puntero->siguiente;
        puntero->siguiente = nodo;
    }
    lista->longitud++;
}

Alumne* Obtener(int n, Lista* lista){
    if(lista->cabeza == NULL){
        return NULL;
    }else{
        Nodo* puntero = lista->cabeza;
        int posicion = 0;
        while(puntero->siguiente && posicion<n){
            puntero = puntero->siguiente;
            posicion++;
        }
        if(posicion != n){
            return NULL;
        }else{
            return &puntero->alumne;
        }
    }
}

int Contar(Lista* lista){
    return lista->longitud;
}

int EstaVacia(Lista* lista){
    return lista->cabeza == NULL;
}

void EliminarPrincipio(Lista* lista){
    if(lista->cabeza){
        Nodo* eliminado = lista->cabeza;
        lista->cabeza = lista->cabeza->siguiente;
        DestruirNodo(eliminado);
        lista->longitud--;
    }
}

void EliminarUltimo(Lista* lista){
    if(lista->cabeza){
        if(lista->cabeza->siguiente){
            Nodo* puntero = lista->cabeza;
            while(puntero->siguiente->siguiente){
                puntero = puntero->siguiente;
            }
            Nodo* eliminado = puntero->siguiente;
            puntero->siguiente = NULL;
            DestruirNodo(eliminado);
            lista->longitud--;
        }else{
            Nodo* eliminado = lista->cabeza;
            lista->cabeza = NULL;
            DestruirNodo(eliminado);
            lista->longitud--;
        }
    }
}

void EliminarElemento(int n, Lista* lista){
    if(lista->cabeza){
        if(n == 0){
            Nodo* eliminado = lista->cabeza;
            lista->cabeza = lista->cabeza->siguiente;
            DestruirNodo(eliminado);
            lista->longitud--;
        }else if(n < lista->longitud){
            Nodo* puntero = lista->cabeza;
            int posicion = 0;
            while(posicion < (n-1)){
                puntero = puntero->siguiente;
                posicion++;
            }
            Nodo* eliminado = puntero->siguiente;
            puntero->siguiente = eliminado->siguiente;
            DestruirNodo(eliminado);
            lista->longitud--;
        }
    }
}
void AgregarAlumno(Nodo **lista, Nodo **ult){


    Alumne alumne;
    zeros(alumne.nom);
    zeros(alumne.dni);
    zeros(alumne.correu);
    zeros(alumne.nota);
    zeros(alumne.data);
    zeros(alumne.sexe);
    printf("Escriu el nom\n");
    scanf("%[^\n]",alumne.nom);
    printf("Escriu el DNI\n");
    scanf("%[^\n]",alumne.dni);
    printf("Escriu el teu correu\n");
    scanf("%[^\n]",alumne.correu);
    printf("Escriu la teva data de naixement\n");
    scanf("%[^\n]",alumne.data);
    printf("Escriu la teva nota\n");
    scanf("%[^\n]",alumne.nota);
    printf("Escriu el teu sexe H o D");
    scanf("%[^\n]",alumne.sexe);
}

void GuardarFichero(Nodo **Lista){
    Nodo *p;
    p = *Lista;
    FILE* f;
    f = fopen("dades.txt","w");
    while(p != NULL){
        fprintf(f,"%s\n", p->alumne.nom);
        fprintf(f,"%s\n", p->alumne.dni);
        fprintf(f,"%s\n", p->alumne.correu);
        fprintf(f,"%s\n", p->alumne.nota);
        fprintf(f,"%s\n", p->alumne.data);
        fprintf(f,"%s\n", p->alumne.sexe);

        p = p->siguiente;
    }
    fclose(f);
}

void BuscarNom(Nodo **Lista, char nom[50]){
    Nodo *alumneTrobat;
    Nodo *p;
    int i=0, pFinal=0, igual=0;
    char llistaAlum[50];

    pFinal = contar(nom);
    zeros(llistaAlum);

    while(p != NULL){
        strncpy(llistaAlum, p->alumne.nom,50);
        while((nom[i] == llistaAlum[i]) && (i != pFinal)){
            i++;
            if(pFinal == i){
                igual++;
                if(alumneTrobat == NULL){
                    alumneTrobat = p;
                }
            }
        }
        zeros(llistaAlum);
        p = p->siguiente;
        i=0;
    }
    if(igual == 0){
        printf("No hi ha cap alumne amb aquell nom");
    }else{
        if(igual == 1){
            printf("Alumne trobat");
            printf("%s", alumneTrobat->alumne.nom);
        }else{
            printf("Hi ha %d alumnes amb aquest nom", igual);
        }
    }
}





void BuscarDni(Nodo **Lista, Alumne **alumnedni){
    bool dni = false;
    Nodo *p;
    p = *Lista;
    while((p != NULL) && (!dni)){

        if(alumnedni == p->alumne.dni){
            dni=true;
            printf("Alumne trobat amb aquest DNI\n");
            printf("Nom%s\n",p->alumne.nom);
        }
        p = p->siguiente;
    }
    return dni;
}







