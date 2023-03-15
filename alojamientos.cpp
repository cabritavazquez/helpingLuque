/***********************************************************************************
 * Fichero alojamientos.cpp para la implementación de atributos y métodos de la clase
 * Alojamientos para la gestión de la información correspondiente a una lista de
 * alojamientos turísticos.
 *
 * Alumno/a: 
 * Fecha: 
 * *********************************************************************************/

#include "utilidades.hpp"
#include "alojamiento.hpp"
#include "alojamientos.hpp"
#include <cmath>
#include <array>
#include <string>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <iostream>

using namespace std;

// ---------- Funciones auxiliares para la implementación de algunos métodos
// ---------- de la clase Alojamientos
// (IMPLEMENTADAS POR EL PROFESORADO)
namespace
{
    const double PI = 4.0 * atan(1.0);
    double grados_a_radianes(double grados)
    {
        // return grados * M_PI / 180.0;
        return grados * PI / 180.0;
    }

    // Devuelve la distancia en kilómetros entre dos puntos
    // cuya latitud y longitud se indica.
    // PARÁMETROS:
    //  - latitud1 (E): latitud del punto uno
    //  - longitud1 (E): longitud del punto uno
    //  - latitud2 (E): latitud del punto dos
    //  - longitud2 (E): longitud del punto dos
    double distancia_haversine(double latitud1, double longitud1, double latitud2, double longitud2)
    {
        const double RADIO_TERRESTRE = 6378.0; // Radio terrestre en el ecuador

        latitud1 = grados_a_radianes(latitud1);
        longitud1 = grados_a_radianes(longitud1);
        latitud2 = grados_a_radianes(latitud2);
        longitud2 = grados_a_radianes(longitud2);

        double dif_lat = latitud2 - latitud1;
        double dif_lon = longitud2 - longitud1;

        double a = pow(sin(dif_lat / 2.0), 2.0) + cos(latitud1) * cos(latitud2) * pow(sin(dif_lon / 2.0), 2.0);

        double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));

        return RADIO_TERRESTRE * c;
    }
} // namespace

namespace bblProgII
{
    // ------------------------ OPERADORES SOBRECARGADOS (IMPLEMENTADOS POR EL PROFESORADO)

    // Operador de asignación de Alojamientos
    Alojamientos &Alojamientos::operator=(const Alojamientos &otro_objeto)
    {
        if (this != &otro_objeto)
        {
            alojamientos = otro_objeto.alojamientos;
            num_alojamientos = otro_objeto.num_alojamientos;
        }
        return *this;
    }

    // Operador de comparación de Alojamientos
    bool Alojamientos::operator==(const Alojamientos &otro_objeto) const
    {
        bool iguales = num_alojamientos == otro_objeto.num_alojamientos;

        unsigned i = 0;

        while (i < num_alojamientos && iguales)
        {
            iguales = alojamientos[i] == otro_objeto.alojamientos[i];
            i++;
        }

        return iguales;
    }

    // Operador [] de acceso mediante índice
    Alojamiento Alojamientos::operator[](unsigned indice) const
    {
        assert(indice < num_alojamientos);

        return alojamientos[indice];
    }

    // -----------------------------------------------------------------

    // -------------- IMPLEMENTACIÓN DE LOS MÉTODOS PRIVADOS Y PÚBLICOS


    Alojamientos::Alojamientos(){


    }

    Alojamientos::Alojamientos(const Alojamientos &otro_objeto){


    }

    Alojamientos::~Alojamientos(){


    }

    

} // namespace bblProgII