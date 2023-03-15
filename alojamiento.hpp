/***********************************************************************************
 * Fichero alojamiento.hpp para la definición de atributos y métodos de la clase
 * Alojamiento para la gestión de la información correspondiente con un alojamiento
 * turístico.
 *
 * Alumno/a: Manuel Luque Esteban
 * Fecha: 13/02/2023
 * *********************************************************************************/

/// ¡¡¡COMPLETAR TODO LO QUE FALTA!!!

#ifndef ALOJAMIENTO_HPP_
#define ALOJAMIEENTO_HPP_

// Incluir todas las bibliotecas necesarias
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


/// Definir la clase Alojamiento dentro del namespace bblProgII

namespace bblProgII{


        class Alojamiento{
// ----- MÉTODOS PÚBLICOS DE LA CLASE Alojamiento

        // Constructor por defecto.
        // Inicializa todos los atributos que son cadenas de caracteres con
        // la cadena vacía y los atributos que son números con cero
        Alojamiento();

        // Constructor de copia
        Alojamiento(const Alojamiento &otro_alojamiento);

        // Constructor específico.
        // Inicializa los atributos según los parámetros correspondientes.
        // Parámetros:
        //  - id_alo (E): identificador del alojamiento
        //  - nom (E): nombre del alojamiento
        //  - id_anf (E): identificador del anfitrión
        //  - nom_anf (E): nombre del anfitrión
        //  - barr (E): barrio del alojamiento
        //  - lat (E): latitud de la ubicación del alojamiento
        //  - lon (E): longitud de la ubicación del alojamiento
        //  - tipo_alo (E): tipo del alojamiento
        //  - prec (E): precio del alojamiento
        //  - min_noch (E): mínimo de noches
        //  - dis_365 (E): número de días al año disponible
        // PRECONDICIÓN:
        //  - prec >= 0
        //  - dis_365 <= 365
        //  - las cadenas de caracteres no son vacías
        Alojamiento(unsigned id_alo,
                    const std::string &nom,
                    unsigned id_anf,
                    const std::string &nom_afn,
                    const std::string &barr,
                    double lat,
                    double lon,
                    const std::string &tipo_alo,
                    double prec,
                    unsigned min_noch,
                    unsigned dis_365);

        // Destructor
        ~Alojamiento();

        // ----------------- MÉTODOS DE ASIGNACIÓN

        // Asigna el identificador del alojamiento
        // Parámetros:
        //  - id_alo (E): identificador del alojamiento
        void asignar_id_alojamiento(unsigned id_alo);

        // Asigna el nombre del alojamiento
        // Parámetros:
        //  - nom (E): nombre del alojamiento
        // PRECONDICIÓN:
        //  - 'nom' no es cadena vacía
        void asignar_nombre(const std::string &nom);

        // Asigna el identificador del anfitrion
        // Parámetros:
        //  - id_anf (E): identificador del anfitrión
        void asignar_id_anfitrion(unsigned id_anf);

        // Asigna el nombre del anfitrión
        // Parámetros:
        //  - nom_anf (E): nombre del anfitrión
        // PRECONDICIÓN:
        //  - 'nom_anf' no es cadena vacía
        void asignar_nombre_anfitrion(const std::string &nom_anf);

        // Asigna el barrio (zona) donde se ubica el alojamiento
        // Parámetros:
        //  - barr (E): nombre del barrio
        // PRECONDICIÓN:
        //  - 'barr' no es cadena vacía
        void asignar_barrio(const std::string &barr);

        // Asigna la latitud de la ubicación del alojamiento
        // Parámetros:
        //  - lat (E): latitud de la ubicación
        void asignar_latitud(double lat);

        // Asigna la longitud de la ubicación del alojamiento
        // Parámetros:
        //  - lon (E): longitud de la ubicación
        void asignar_longitud(double lon);

        // Asigna el tipo de alojamiento
        // Parámetros:
        //  - tipo_alo (E): tipo de alojamiento
        // PRECONDICIÓN:
        //  - 'tipo_alo' no es cadena vacía
        void asignar_tipo_alojamiento(const std::string &tipo_alo);

        // Asigna el precio del alojamiento
        // Parámetros:
        //  - prec (E): precio del alojamiento
        // PRECONDICIÓN: precio >= 0
        void asignar_precio(double prec);

        // Asigna el mínimo número de noches que puede alquilarse el alojamiento
        // Parámetros:
        //  - min_noch (E): mínimo número de noches
        void asignar_minimo_noches(unsigned min_noch);

        // Asignar el número de días al año de disponibilidad del alojamiento
        // Parámetros:
        //  - dis_365 (E): número de días al año disponible
        // PRECONDICIÓN: dis_365 <= 365
        void asignar_disponibilidad_365(unsigned dis_365);

        // ----------------- MÉTODOS DE CONSULTA

        // Consulta el id del alojamiento
        unsigned consultar_id_alojamiento() const;

        // Consulta el nombre del alojamiento
        std::string consultar_nombre() const;

        // Consulta el id del anfitrión del alojamiento
        unsigned consultar_id_anfitrion() const;

        // Consulta el nombre del anfitrión del alojamiento
        std::string consulta_nombre_anfitrion() const;

        // Consulta el barrio (zona) donde se ubica el alojamiento
        std::string consultar_barrio() const;

        // Consulta la latitud de la localización del alojamiento
        double consultar_latitud() const;

        // Consulta la longitud de la localización del alojamiento
        double consultar_longitud() const;

        // Consulta el tipo de alojamiento
        std::string consultar_tipo_alojamiento() const;

        // Consulta el precio del alojamiento
        double consultar_precio() const;

        // Consulta el mínimo número de noches que puede alquilarse
        unsigned consultar_minimo_noches() const;

        // Consulta el número de días al año que está disponible
        unsigned consultar_disponibilidad_365() const;

        // Escribe por pantalla los datos del alojamiento,
        // en el siguiente formato (nótese que se
        // usan tabuladores para formatear la salida):
        //  ID alojamiento:      <id_alojamiento>
        //  Nombre alojamiento:  <nombre>
        //  ID anfitrión:        <id_anfitrion>
        //  Nombre anfitrión:    <nombre_anfitrion>
        //  Barrio (área):       <barrio>
        //  Localización:        <latitud>, <longitud>
        //  Tipo de alojamiento: <tipo_alojamiento>
        //  Precio por noche:    <precio>
        //  Mínimo de noches:    <minimo_noches>
        //  Disponibilidad/año:  <disponibilidad_365>
        void escribir() const;

        // --------- OPERADORES SOBRECARGADOS (IMPLEMENTADOS POR EL PROFESORADO)

        // Operador de asignación de Alojamiento
        // (IMPLEMENTADO POR EL PROFESOR)
        Alojamiento &operator=(const Alojamiento &otro_alojamiento);

        // Operador de comparación de igualdad
        // (NECESARIO PARA LAS PRUEBAS UNITARIAS)
        // (IMPLEMENTADO POR EL PROFESOR)
        bool operator==(const Alojamiento &otro_alojamiento) const;

    // ----- PARTE PRIVADA DE LA CLASE Alojamiento

        // ATRIBUTOS
        unsigned id_alojamiento;      // Identificador (único) del alojamiento
        string nombre;              // Nombre del alojamiento
        unsigned id_anfitrion;        // Identificador (único) del anfitrión/a
        string nombre_anfitrion;    // Nombre del anfitrión/a
        string barrio;              // Barrio (zona) donde se ubica el apartamento
        double latitud, longitud;   // Latitud y longitud de la ubicación del apartamento
        string tipo_alojamiento;    // Tipo de alojamiento
        double precio;              // Precio del alojamiento por cada día de estancia
        unsigned minimo_noches;       // Mínimo número de noches que se puede alquilar
        unsigned disponibilidad_365;  // Número de días al año que está disponible

        };

    }

#endif