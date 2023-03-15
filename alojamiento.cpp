/***********************************************************************************
 * Fichero alojamiento.cpp para la implementación de atributos y métodos de la clase
 * Alojamiento para la gestión de la información correspondiente con un alojamiento
 * turístico.
 *
 * Alumno/a: Manuel Luque Esteban
 * Fecha: 13/02/2023
 * *********************************************************************************/

#include "alojamiento.hpp"
#include <string>
#include <cassert>
#include <iostream>
#include <iomanip>

using namespace std;

namespace bblProgII
{
    // ---------------- OPERADORES SOBRECARGADOS (IMPLEMENTADOS POR EL PROFESORADO)

    // Operador de asignación de Alojamientos
    Alojamiento &Alojamiento::operator=(const Alojamiento &otro_alojamiento)
    {
        if (this != &otro_alojamiento)
        {
            id_alojamiento = otro_alojamiento.id_alojamiento;         // Identificador (único) del alojamiento
            nombre = otro_alojamiento.nombre;                         // Nombre del alojamiento
            id_anfitrion = otro_alojamiento.id_anfitrion;             // Identificador (único) del anfitrión
            nombre_anfitrion = otro_alojamiento.nombre_anfitrion;     // Nombre del anfitrión
            barrio = otro_alojamiento.barrio;                         // Barrio (zona) donde se ubica el apartamento
            latitud = otro_alojamiento.latitud;                       // Latitud de la ubicación del apartamento
            longitud = otro_alojamiento.longitud;                     // Longitud de la ubicación del apartamento
            tipo_alojamiento = otro_alojamiento.tipo_alojamiento;     // Tipo de alojamiento
            precio = otro_alojamiento.precio;                         // Precio del alojamiento por cada día de estancia
            minimo_noches = otro_alojamiento.minimo_noches;           // Mínimo número de noches que se puede alquilar
            disponibilidad_365 = otro_alojamiento.disponibilidad_365; // Número de días al año que está disponible
        }

        return *this;
    }

    // Operador de comparación de igualdad
    bool Alojamiento::operator==(const Alojamiento &otro_alojamiento) const
    {
        bool iguales = false;
        if (id_alojamiento == otro_alojamiento.id_alojamiento &&
            nombre == otro_alojamiento.nombre &&
            id_anfitrion == otro_alojamiento.id_anfitrion &&
            nombre_anfitrion == otro_alojamiento.nombre_anfitrion &&
            barrio == otro_alojamiento.barrio &&
            latitud == otro_alojamiento.latitud &&
            longitud == otro_alojamiento.longitud &&
            tipo_alojamiento == otro_alojamiento.tipo_alojamiento &&
            precio == otro_alojamiento.precio &&
            minimo_noches == otro_alojamiento.minimo_noches &&
            disponibilidad_365 == otro_alojamiento.disponibilidad_365)
        {
            iguales = true;
        }

        return iguales;
    }

    // ---------------------------------------------------------------------

    // -------------- IMPLEMENTACIÓN DE LOS MÉTODOS PRIVADOS Y PÚBLICOS
    
    Alojamiento::Alojamiento(){

        id_alojamiento = 0;
        nombre = "";
        id_anfitrion = 0;
        nombre_anfitrion = "";
        barrio = "";
        latitud = 0.0;
        longitud = 0.0;
        tipo_alojamiento = "";
        precio = 0.0;
        minimo_noches = 0;
        disponibilidad_365 = 0;

    }

    Alojamiento::Alojamiento(const Alojamiento &otro_alojamiento){

        id_alojamiento = otro_alojamiento.id_alojamiento;
        nombre = otro_alojamiento.nombre;
        id_anfitrion = otro_alojamiento.id_anfitrion;
        nombre_anfitrion = otro_alojamiento.nombre_anfitrion;
        barrio = otro_alojamiento.barrio;
        latitud = otro_alojamiento.latitud;
        longitud = otro_alojamiento.longitud;
        tipo_alojamiento = otro_alojamiento.tipo_alojamiento;
        precio = otro_alojamiento.precio;
        minimo_noches = otro_alojamiento.minimo_noches;
        disponibilidad_365 = otro_alojamiento.disponibilidad_365;

    }

    Alojamiento::Alojamiento(unsigned id_alo,
                    const std::string &nom,
                    unsigned id_anf,
                    const std::string &nom_afn,
                    const std::string &barr,
                    double lat,
                    double lon,
                    const std::string &tipo_alo,
                    double prec,
                    unsigned min_noch,
                    unsigned dis_365){

                    while( prec >= 0 && dis_365 >= 365 && nom != " " && nom_afn != " " && barr != " " && tipo_alo != " "){

                    id_alojamiento = id_alo;
                    nombre = nom;
                    id_anfitrion = id_anf;
                    nombre_anfitrion = nom_afn;
                    barrio = barr;
                    latitud = lat;
                    longitud = lon;
                    tipo_alojamiento = tipo_alo;
                    precio = prec;
                    minimo_noches = min_noch;
                    disponibilidad_365 = dis_365;
                    }

                    }

    Alojamiento::~Alojamiento(){

    }

    void Alojamiento::asignar_id_alojamiento(unsigned id_alo){

        id_alojamiento = id_alo;

    }

    void Alojamiento::asignar_nombre(const std::string &nom){

        while (nom != " "){

        nombre = nom;

        }

    }

    void Alojamiento::asignar_id_anfitrion(unsigned id_anf){


        id_anfitrion = id_anf;
    }

    void Alojamiento::asignar_nombre_anfitrion(const std::string &nom_anf){

        while( nom_anf != " "){

            nombre_anfitrion = nom_anf;
        }

    }

    void Alojamiento::asignar_barrio(const std::string &barr){

        while( barr != " "){

            barrio = barr;
        }
    }

    void Alojamiento::asignar_latitud(double lat){

        latitud = lat;

    }

    void Alojamiento::asignar_longitud(double lon){

        longitud = lon;

    }

    void Alojamiento::asignar_tipo_alojamiento(const std::string &tipo_alo){

        while(tipo_alo != " "){

            tipo_alojamiento = tipo_alo;
        }
    }

    void Alojamiento::asignar_precio(double prec){

        while (prec >= 0){

            precio = prec;
        }

    }

    void Alojamiento::asignar_minimo_noches(unsigned min_noch){

        minimo_noches = min_noch;

    }

    void Alojamiento::asignar_disponibilidad_365(unsigned dis_365){

        while ( dis_365 >= 0){

            disponibilidad_365 = dis_365;
        }
    }

    unsigned Alojamiento::consultar_id_alojamiento() const{

        return id_alojamiento;

    }

    string Alojamiento::consultar_nombre() const{

        return nombre;

    }

    unsigned Alojamiento::consultar_id_anfitrion() const{

        return id_anfitrion;
    }

    string Alojamiento::consulta_nombre_anfitrion() const{

        return nombre_anfitrion;

    }

    string Alojamiento::consultar_barrio() const{

        return barrio;
    }

    double Alojamiento::consultar_latitud() const{

        return latitud;

    }

    double Alojamiento::consultar_longitud() const{

        return longitud;
    }

    string Alojamiento::consultar_tipo_alojamiento() const{

        return tipo_alojamiento;

    }

    double Alojamiento::consultar_precio() const{

        return precio;
    }

    unsigned Alojamiento::consultar_minimo_noches() const{

        return minimo_noches;
    }

    unsigned Alojamiento::consultar_disponibilidad_365() const{

        return disponibilidad_365;
    }

    void Alojamiento::escribir() const{

        cout<<"ID lojamiento:        "<<"<"<<id_alojamiento<<">"<<endl;
        cout<<"Nombre alojamiento:   "<<"<"<<nombre<<">"<<endl;
        cout<<"id_alojamiento:       "<<"<"<<id_alojamiento<<">"<<endl;
        cout<<"ID anfitrion:         "<<"<"<<id_anfitrion<<">"<<endl;
        cout<<"Nombre anfitrion:     "<<"<"<<nombre_anfitrion<<">"<<endl;
        cout<<"Barrio (área):        "<<"<"<<barrio<<">"<<endl;
        cout<<"Localizacion:         "<<"<"<<latitud<<">, <"<<longitud<<">"<<endl;
        cout<<"Tipo de alojamiento:  "<<"<"<<tipo_alojamiento<<">"<<endl;
        cout<<"Precio por noche:     "<<"<"<<precio<<">"<<endl;
        cout<<"Minimo de noches:     "<<"<"<<minimo_noches<<">"<<endl;
        cout<<"Disponibilidad/año:   "<<"<"<<disponibilidad_365<<">"<<endl;


    }






} // namespace bblProgII