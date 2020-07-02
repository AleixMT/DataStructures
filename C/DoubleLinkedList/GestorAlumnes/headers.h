#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED
#include <stdio.h>
#include "registros.h"



void menu();



void AgregarAlumno(Nodo **lista, Nodo **ult);

void InsertarPrincipio(Lista* lista, Alumne* alumne);

void InsertarFinal(Lista* lista, Alumne* alumne);

void InsertarDespues(int n, Lista* lista, Alumne* alumne);

Alumne* Obtener(int n, Lista* lista);

int Contar(Lista* lista);

int EstaVacia(Lista* lista);

void EliminarPrincipio(Lista* lista);

void EliminarUltimo(Lista* lista);

void EliminarElemento(int n, Lista* lista);

void zeros(char nombre[50]);

int contar (char X[50]);

void AgregarAlumno(Nodo **lista, Nodo **ult);

void GuardarFichero(Nodo **Lista);

void BuscarNom(Nodo **Lista, char nom[50]);

void BuscarDni(Nodo **Lista, Alumne **alumnedni);



#endif // HEADERS_H_INCLUDED
