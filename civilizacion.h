#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <iostream>
#include <iomanip>
#include <list>
#include <fstream>

#include "aldeano.h"

using namespace std;

class Civilizacion {
private:
    string nombre;
    int ubicacionX;
    int ubicacionY;
    int puntuacion;

    list<Aldeano> aldeanos;

public:
    Civilizacion();
    Civilizacion(const string &nombre, int ubicacionX, int ubicacionY, int puntuacion);

    void setNombre(const string &v);
    void setUbicacionX(int v);
    void setUbicacionY(int v);
    void setPuntuacion(int v);

    string getNombre() const;
    int getUbicacionX();
    int getUbicacionY();
    int getPuntuacion();

    void agregarFinal(const Aldeano &a);
    void agregarInicio(const Aldeano &a);

    void mostrar();

    void eliminarNombre(const string &nombre);
    void eliminarSalud(size_t salud);
    void eliminarEdad();

    Aldeano* buscar(const string &nombre);

    void ordenarNombre();
    void ordenarEdad();
    void ordenarSalud();

    void respaldar_aldeanos();
    void recuperar_aldeanos(string v);

    friend ostream& operator<<(ostream &out, const Civilizacion &c){
        out << left;
        out << setw(15) << c.nombre;
        out << setw(5) << c.ubicacionX;
        out << setw(5) << c.ubicacionY;
        out << setw(10) << c.puntuacion;
        out << endl;
        
        return out;
    }

    friend istream& operator>>(istream &in, Civilizacion &c){
        cout << "Nombre: ";
        getline(cin, c.nombre);

        cout << "Ubicacion en X: ";
        cin >> c.ubicacionX;

        cout << "Ubicacion en Y: ";
        cin >> c.ubicacionY;

        cout << "Puntuacion: ";
        cin >> c.puntuacion; cin.ignore();
        
        return in;
    }

    bool operator == (const Civilizacion &c) {
        return nombre == c.nombre;
    }

    bool operator == (const Civilizacion &c) const {
        return nombre == c.nombre;
    }
};

#endif