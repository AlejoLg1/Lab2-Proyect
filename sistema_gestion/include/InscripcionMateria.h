#ifndef INSCRIPCIONMATERIA_H
#define INSCRIPCIONMATERIA_H
#include <iostream>
#include <vector>
#include <locale.h>
#include "Alumno.h"
#include "Materia.h"



class InscripcionMateria
{
    private:
        int _alumno;
        int _materias[7];  // Arreglo de tama�o fijo para las materias
        bool _estadoMaterias[7];  // Arreglo de tama�o fijo para los estados de las materias
        int _numMaterias; // Variable para rastrear el n�mero actual de materias


    public:

        ///---- CONSTRUCTOR ----\\\

        InscripcionMateria();

        ///---- SETTERS ----\\\

        void setAlumno(int);

        void setMaterias(int, int);

        void setEstadoMaterias(bool, int);

        void setNumMaterias(bool);
        ///---- GETTERS ----\\\

        int getAlumno();

        int* getMaterias();

        int getMaterias2(int) const;

        bool getEstadoMaterias(int);

        int getNumMaterias();

        ///---- M�TODOS ----\\\

        int cargarInscripcionMateria(Alumno&, const Materia&, int);

        void inscribirseMateria(int);

        void mostrarInscripcionMateria();

        void mostrarInscripcionMateriaSinElNombreDeUsuario(int );

        void mostrarRegistroDeIncriccionesMateria(int);

        void DarseDeBajaMateria(int);

        int cargarBajaDeUnRegistroDeIncriccionesMateria(Alumno&, const Materia&, int, int);

        void grabarEnDiscoInscripcionMateria();

        void ModificarEnDiscoInscripcionMateria(int );

        void leerEnDiscoInscripcionMateria();

        bool leerEnDiscoInscripcionMateriaPorPosicion(int);

        bool leerEntrada(int&);

        bool preguntarContinuar(const std::string&);

        void MostrarTodosLosRegistrosIncripcionMateria();

        void reset();  // Inicializa los miembros con valores predeterminados




};

#endif // INSCRIPCIONMATERIA_H
