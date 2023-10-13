#ifndef LISTA_H
#define LISTA_H
#include <iostream>

const int TAM=100;

//***************************Definicion de la clase persona*************************
//**********************************************************************************
class Solicitud
{
private:
    std::string nombre;
    std::string carrera;
    std::string prepa;
    float promedio;
public:
    Solicitud();
    Solicitud(std::string n, std::string c, std::string t, float p);
    void operator=(Solicitud& x);
    friend std::ostream& operator<<( std::ostream&, Solicitud&);
    friend std::istream& operator>>( std::istream&, Solicitud&);
    friend Solicitud operator +(Solicitud& e1, Solicitud& e2);
    friend bool operator ==(Solicitud& e1, Solicitud& e2);
    friend bool operator !=(Solicitud& e1, Solicitud& e2);
	friend bool operator <(Solicitud& e1, Solicitud& e2);
    friend bool operator >(Solicitud& e1, Solicitud& e2);
	friend bool operator <=(Solicitud& e1, Solicitud& e2);
    friend bool operator >=(Solicitud& e1, Solicitud& e2);

};
//***************************************************************************************
//****************************Definicion de la clase Pila****************************
//***********************************************************************************
class Lista
{
private:
    Solicitud datos[TAM];
    int ult;
    bool elimina(int pos);
    int inserta(Solicitud& elem, int pos);
public:
    Lista():ult(-1) {}
    bool vacia()const;
    bool llena()const;
    int ultimo()const;
    friend std::ostream& operator<<(std::ostream & o, Lista& L);
    void DarAlta(Solicitud& elem);
    int busquedaBinaria(Solicitud& c);
    void burbuja();
    void insercion();
    void quicksort(int menor, int mayor);

};
//*************************************************************************************

#endif 
