#include <iostream>
#include <cstring>
#include <limits>
#include "Persona.h"

using namespace std;


///---- CONSTRUCTOR ----\\\

Persona::Persona()
{
    strncpy(_nombre, "-", 16);
    strncpy(_apellido, "-", 16);
}

///---- SETTERS ----\\\


bool Persona::esValido(const char* str) {
    for (int i = 0; i < strlen(str); ++i) {
        if (!isalpha(str[i])) {
            return false;
        }
    }
    return true;
}

void Persona::setNombre(char* nombre) {
    while (!esValido(nombre)) {
        cout << "\n\t---- ERROR : NOMBRE INV�LIDO ----" << endl;
        cout << "\n\t - Nombre ('NULL' para salir): ";
        cin >> nombre;
    }
}

void Persona::setApellido(char* apellido) {
    while (!esValido(apellido)) {
        cout << "\n\t---- ERROR : APELLIDO INV�LIDO ----" << endl;
        cout << "\n\t - Apellido: ";
        cin >> apellido;
    }
    strncpy(_apellido, apellido, 15);
    _apellido[15] = '\0';
}


 ///---- GETTERS ----\\\

char* Persona::getNombre() {
    return _nombre;
}

char* Persona::getApellido() {
    return _apellido;
}

///---- M�TODOS ----\\\

bool Persona::cargar() {
    char nombre[16];
    char apellido[16];

    cout << endl << "\t - Nombre ('NULL' para salir): ";
    cin >> nombre;

    setNombre(nombre);
    if(strcmp(nombre, "NULL") == 0) {
        return true;
    }
    strncpy(_nombre, nombre, 15);
    _nombre[15] = '\0';

    cout << endl << "\t - Apellido: ";
    cin >> apellido;
    setApellido(apellido);

    return false;
}
void Persona::mostrar() {

    cout << endl << "\t - Nombre: " << _nombre << endl;
    cout << "\t - Apellido: " << _apellido;

}

void Persona::grabarEnDisco() {

}
void Persona::leerEnDisco() {

}
