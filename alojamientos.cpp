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

            num_alojamientos = 0;


    }

    Alojamientos::Alojamientos(const Alojamientos &otro_objeto){

        for(unsigned i = 0; i< num_alojamientos; i++){

            alojamientos[i] = otro_objeto.alojamientos[i];
            num_alojamientos = otro_objeto.num_alojamientos;
        }

    }

    Alojamientos::~Alojamientos(){


    }

    void Alojamientos::consultar_alojamiento(unsigned id_alojamiento, Alojamiento &alojamiento, Resultado &res) const{

        for(unsigned i = 0; i < num_alojamientos; i++){

            if(id_alojamiento != alojamientos[i].consultar_id_alojamiento()){
                i++;
                res = NO_EXISTE;
            }
            res = OK;
            alojamiento = alojamientos[i];
        }

    }

    unsigned Alojamientos::numero_alojamientos() const{

        return num_alojamientos;
    }

    void Alojamientos::lista_alojamientos(Ids &ids_alojamientos) const{

        for(int i = 0; i < num_alojamientos; i++){
            ids_alojamientos.ids[i]= alojamientos[i].consultar_id_alojamiento();
        }

    }
    

    void Alojamientos::alojamientos_anfitrion(unsigned id_anfitrion, Ids &ids_alojamientos) const{

        for(int i = 0; i < num_alojamientos;i++){
            if(id_anfitrion == alojamientos[i].consultar_id_anfitrion()){
                
                int j =0;
                ids_alojamientos.ids[j] = alojamientos[i].consultar_id_alojamiento();
                j++;

            }

        }


    }

    void Alojamientos::alojamientos_alrededor(double latitud, double longitud, double kms, Ids &ids_alojamientos) const{
                    
                                                                         ///////////////////////////////////////////////HACER
            for(int i = 0; i < num_alojamientos;i++){
                if( distancia_puntos(latitud,longitud,alojamientos[i].consultar_latitud(),alojamientos[i].consultar_longitud()) 
                        <= kms){

                        }
            }

    }

    void Alojamientos::alojamientos_barrio(const std::string &barrio, Ids &ids_alojamientos) const{

        int j =0;
         for(int i = 0; i < num_alojamientos;i++){
            if(barrio == alojamientos[i].consultar_barrio()){
                  
                ids_alojamientos.ids[j] = alojamientos[i].consultar_id_alojamiento();
                j++;

            }

        }
    }

    void Alojamientos::alojamientos_tipo(const std::string &tipo_alojamiento, Ids &ids_alojamientos) const{
        int j =0;
        for(int i = 0; i < num_alojamientos;i++){
            if(tipo_alojamiento == alojamientos[i].consultar_tipo_alojamiento()){
                
                ids_alojamientos.ids[j] = alojamientos[i].consultar_id_alojamiento();
                j++;

            }

        }

    }

    void Alojamientos::alojamientos_precio(double precio, Ids &ids_alojamientos) const{
        
        int j =0;
         for(int i = 0; i < num_alojamientos;i++){
            if(alojamientos[i].consultar_precio() <= precio){
                
                
                ids_alojamientos.ids[j] = alojamientos[i].consultar_id_alojamiento();
                j++;

            }

        }

    }

    void Alojamientos::alojamientos_noches(unsigned num_noches, Ids &ids_alojamientos) const{

        int j =0;
         for(int i = 0; i < num_alojamientos;i++){
            if(alojamientos[i].consultar_minimo_noches() <= num_noches){
            
                ids_alojamientos.ids[j] = alojamientos[i].consultar_id_alojamiento();
                j++;

            }

        }

    }

    void Alojamientos::alojamientos_filtros(const std::string &barrio, ///////////////////////////////////////////HACER
                                  const std::string &tipo_alojamiento,
                                  double precio,
                                  unsigned num_noches,
                                  Ids &ids_alojamientos) const{




                                  }

    void Alojamientos::escribir_en_fichero(const std::string &nombre_fichero, Resultado &res) const{
                                                                    ////////////////////////////////////////////////HACER

    }

    void Alojamientos::escribir() const{

        for(int i = 0; i < num_alojamientos; i++){

            alojamientos[i].escribir();
        }


    }

    void Alojamientos::insertar_alojamiento(const Alojamiento &alojamiento, Resultado &res){


        if(num_alojamientos == 3000){
            res = LISTA_LLENA;
        }
        else{

            if(buscar_alojamiento_ok(alojamiento.consultar_id_alojamiento()) == true){
                res = YA_EXISTE;
            }
            else{
                
                insertar_final(alojamiento);
                ordenar_alojamientos(alojamientos);
                num_alojamientos++;
                res = OK;

            }


        }



    }

    void Alojamientos::modificar_alojamiento(const Alojamiento &alojamiento, Resultado &res){

        if(buscar_alojamiento_ok(alojamiento.consultar_id_alojamiento()) == true){

            alojamientos[buscar_alojamiento_pos(alojamiento.consultar_id_alojamiento())] = alojamiento;
            res = OK;

        }
        else{

            res = NO_EXISTE;
        }


    }

    void Alojamientos::eliminar_alojamiento(unsigned id_alojamiento, Resultado &res){



    }

    void Alojamientos::leer_alojamientos(const std::string &nombre_fichero, Resultado &res){
                                                            //////////////////////////////////////////////////HACER

    }

    //METODOS PRIVADOS

    void Alojamientos::buscar_alojamiento(unsigned id_alojamiento, unsigned &posicion, bool &encontrado) const{

        for(int i = 0; i < num_alojamientos; i++){

            if( alojamientos[i].consultar_id_alojamiento() >= id_alojamiento){

                posicion = i;

                if(alojamientos[i].consultar_id_alojamiento() == id_alojamiento){

                    encontrado = true;
                }
                else{
                    encontrado = false;
                }
            }

        }


    }


    void Alojamientos::abrir_hueco(unsigned posicion){


    }

    void Alojamientos::cerrar_hueco(unsigned posicion){


    }

    void Alojamientos::insertar_final(Alojamiento alojamiento){

        for(int i = 0; i <= num_alojamientos; i++){

            if(i == num_alojamientos){
                alojamientos[i] = alojamiento;
            }
        }

    }

    bool Alojamientos::buscar_alojamiento_ok(unsigned id_alojamiento) const{

            bool encontrado;

        for(int i = 0; i < num_alojamientos; i++){

                if(alojamientos[i].consultar_id_alojamiento() == id_alojamiento){

                    encontrado = true;
                }
                else{
                    encontrado = false;
                }

        }
        return encontrado;

    }

    unsigned Alojamientos::buscar_alojamiento_pos(unsigned id_alojamiento){

        unsigned pos;

        for(int i = 0; i <= num_alojamientos; i++){

            if( alojamientos[i].consultar_id_alojamiento() == id_alojamiento){

                pos = i;
            }
        }

        return pos;
    }

    void Alojamientos::ordenar_alojamientos(Talojamientos &alojamientos){

        for( int i = 0; i < num_alojamientos; i++){
            for(int j = 0; j< j-i; j++){
                if( alojamientos[j].consultar_id_alojamiento() << alojamientos[j+1].consultar_id_alojamiento()){

                    Alojamiento aux = alojamientos[j];
                    alojamientos[j] = alojamientos[j+1];
                    alojamientos[j+1] = aux;

                }
            }
        }
    }

    double Alojamientos::distancia_puntos(double latitud1, double longitud1, double latitud2, double longitud2){

        double distancia = sqrt(pow(abs(latitud1-latitud2),2) + pow(abs(longitud1-longitud2),2));

        return distancia;
    }






    
    
} // namespace bblProgII
