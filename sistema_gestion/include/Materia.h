#ifndef MATERIA_H
#define MATERIA_H
#include <locale.h>
#include "Profesor.h"

class Materia
{

    private:
        int _id;
        Profesor _profesor;
        int _nivel;
        char _nombreMateria[30];

        int generarId();
        Profesor BuscarProfesor(int);
    public:

         ///---- CONSTRUCTOR ----\\\

        Materia();

        ///---- SETTERS ----\\\

        void setId();

        void setProfesor(int);

        void setNivel(int);

        void setNombreMateria(char*);


        ///---- GETTERS ----\\\

        int getId();

        Profesor getProfesor();

        int getNivel();

        char* getNombreMateria();




        ///---- M�TODOS ----\\\

        void cargarMateria();

        void mostrarMateria();

        void grabarEnDiscoMateria();

        void leerEnDiscoMateria();

        bool leerEnDiscoMateriaPorPosicion(int);


};

#endif // MATERIA_H
