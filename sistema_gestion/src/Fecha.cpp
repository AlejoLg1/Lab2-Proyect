#include <iostream>
using namespace std;
#include <cstdlib>
#include <string>
#include <ctime>
#include <limits>
#include <cstring>
#include "Fecha.h"
#include "rlutil.h"

using namespace rlutil;

void Fecha::establecerFechaPorDefecto(){
    _dia = 1;
    _mes = 1;
    _anio = 1900;
}

bool Fecha::esBisiesto(){
    if ((_anio % 4 == 0 && _anio % 100 != 0) || _anio % 400 == 0){
          return true;
    }
    return false;
}

bool Fecha::esDiaDeSemana(){
    struct tm time_in = {0,0,0, _dia, _mes - 1, _anio - 1900};

    time_t time_temp = mktime(&time_in);

    const struct tm* time_out = localtime(&time_temp);
    if(time_out->tm_wday >=1 && time_out->tm_wday <=6) return true;

    return false;
}

void Fecha::agregarDias(){
    int vDias[12]={ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if(esBisiesto()){
        vDias[1]++;
    }
    _dia++;
    if(_dia > vDias[_mes-1]){
        _dia = 1;
        _mes++;
        if(_mes > 12){
            _mes = 1;
            _anio++;
        }
    }
}

void Fecha::restarDias(){
    int dias[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if(esBisiesto()){
        dias[1]++;
    }

    _dia--;
    if( _dia < 1 ){
        _mes--;
        _dia = dias[_mes-1];
        if( _mes < 1 ){
            _mes = 12;
            _dia = dias[_mes-1];
            _anio--;
            if( _anio < 1900 ){
                establecerFechaPorDefecto();
            }
        }
    }
}

void Fecha::AgregarDias(int cantidadDias){

    if (cantidadDias > 0){
        for( int i = 0; i < cantidadDias; i++ ){
            agregarDias();
        }
    }

    if(cantidadDias < 0){
        int n = cantidadDias * -1;
        for( int i = 0; i < n ; i++ ){
            restarDias();
        }
   }

   if(cantidadDias == 0){
    return;
   }
}

Fecha::Fecha(){
    establecerFechaPorDefecto();
}

std::string Fecha::FechaActual(){

    time_t tSac = time(NULL);
    struct tm* pt1 = localtime(&tSac);
    char fecha[11];


    snprintf(fecha, sizeof(fecha), "%02d/%02d/%04d", pt1->tm_mday, pt1->tm_mon + 1, pt1->tm_year + 1900);
    return std::string(fecha);

}

Fecha::Fecha(int dia, int mes, int anio){
    _dia = dia;
    _mes = mes;
    _anio = anio;

    if (_dia <= 0 || _mes <= 0 || _anio <= 0 || _mes > 12){
        establecerFechaPorDefecto();
    }
    else{
        int dias[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (esBisiesto()){
            dias[1]++;
        }

        if (_dia > dias[_mes-1]){
            establecerFechaPorDefecto();
        }
    }
}

bool Fecha::fechaValida(){

    if (_anio < 1900 || _mes < 1 || _mes > 12 || _dia < 1) return false;

    int diasMes[] = { 31, esBisiesto() ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (_dia > diasMes[_mes - 1]) return false;

    if(!esDiaDeSemana()) return false;

    return true;
}

void Fecha::CargarFecha(){
   do{
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\t\t - D�a: ";
        cin >> _dia;
        cout << "\t\t - Mes: ";
        cin >> _mes;
        cout << "\t\t - A�o: ";
        cin >> _anio;

        if (!fechaValida()) {
            cout << "\t\t ---- FECHA INVALIDA POR FAVOR INGRESE NUEVAMENTE LA FECHA ----" << endl;
            Sleep(1000);
            system("cls");
        }
    }while (!fechaValida());
}

void Fecha::CargarFechaEvaluacion(int idEvaluacion, int legajoProfesor, int idMateria){

    do{
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\t\t - D�a: ";
        cin >> _dia;
        cout << "\t\t - Mes: ";
        cin >> _mes;
        cout << "\t\t - A�o: ";
        cin >> _anio;

        if (!fechaValida()) {
            cout << "\t\t ---- FECHA INVALIDA POR FAVOR INGRESE NUEVAMENTE LA FECHA ----" << endl;
            cout << "LA FECHA INGRESADA NO CORRESPONDE A UN D�A H�BIL (LUNES A VIERNES). VUELVA A INGRESAR LA FECHA: >";
            Sleep(4000);
            system("cls");
            precargarCargaEvaluacion(idEvaluacion, legajoProfesor, idMateria);
        }
    }while (!fechaValida());
}

string Fecha::toString(string formatoFecha){
   string fechaFormateada = "";

   string DD = to_string(_dia);
   string MM = to_string(_mes);
   string YYYY = to_string(_anio);
   // DD/MM/YYYY
   if (_dia < 10){
      DD = "0" + to_string(_dia);
   }
   if (_mes < 10){
      MM = "0" + to_string(_mes);
   }

   if (formatoFecha == "DD/MM/YYYY"){
      fechaFormateada = DD + "/" + MM + "/" + YYYY;
   }
   else if (formatoFecha == "YYYY/MM/DD"){
      fechaFormateada = YYYY + "/" + MM + "/" + DD;
   }
   else{
      fechaFormateada = DD + "/" + MM + "/" + YYYY;
   }

   return fechaFormateada;
}

int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

void Fecha::setDia(int dia){_dia = dia;}
void Fecha::setMes(int mes){_mes = mes;}
void Fecha::setAnio(int anio){_anio = anio;}

void Fecha::precargarCargaEvaluacion(int idEvaluacion, int legajoProfesor, int idMateria) {
    cout << "CREANDO EX�MEN FINAL" << endl << endl;

    cout << "\t - ID Final: ";
    cout << idEvaluacion << endl << endl;

    cout << "\t - Legajo Profesor: ";
    cout << legajoProfesor << endl << endl;

    cout << "\t - ID Materia: ";
    cout << idMateria << endl << endl;

    cout << "\t - Fecha: " << endl;
}
