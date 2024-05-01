#ifndef PERSONA_H
#define PERSONA_H


class Persona
{
    private:
        char _nombre [16];
        char _apellido [16];
        //Fecha _nacimiento;


    public:
        ///---- CONSTRUCTOR ----\\\

        Persona();

        ///---- SETTERS ----\\\

        void setNombre(char*);

        void setApellido(char*);

        //void setNacimiento(Fecha);


        ///---- GETTERS ----\\\

        char* getNombre();

        char* getApellido();

        //bool getFechao(Fecha);



        ///---- M�TODOS ----\\\

        void cargar();

        void mostrar();

        void grabarEnDisco();

        void leerEnDisco();



};

#endif // PERSONA_H
