#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <iostream>
#include <vector>

#include "civilizacion.h"

using namespace std;

class VideoGame {
private:
    string nombreUsuario;
    vector<Civilizacion> civilizaciones;

public:
    VideoGame();

    void setNombreUsuario(const string &v);

    string getNombreUsuario();

    void agregarFinal(const Civilizacion &c);
    void insertar(const Civilizacion &c, size_t p);
    
    void inicializar(size_t n, const Civilizacion &c); //Crear n civilizaciones

    void mostrar();
    
    void frente(); //Devuelve la primer civilizacion
    void ultimo(); // Devuelve la ultima civilizacion
    
    void ordenarNombre();
    void ordenarUbicacionX();
    void ordenarUbicacionY();
    void ordenarPuntuacion();

    void eliminar(const Civilizacion &c);
    
    Civilizacion* buscar(const Civilizacion &c);

    size_t total();

    void respaldar();
    void recuperar();
};

#endif