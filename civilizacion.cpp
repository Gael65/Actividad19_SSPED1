#include "civilizacion.h"

Civilizacion::Civilizacion() {}

Civilizacion::Civilizacion(const string &nombre, int ubicacionX, int ubicacionY, int puntuacion) {
    this -> nombre = nombre;
    this -> ubicacionX = ubicacionX;
    this -> ubicacionY = ubicacionY;
    this -> puntuacion = puntuacion;
}

void Civilizacion::setNombre(const string &v) {
    nombre = v;
}

void Civilizacion::setUbicacionX(int v) {
    ubicacionX = v;
}

void Civilizacion::setUbicacionY(int v) {
    ubicacionY = v;
}

void Civilizacion::setPuntuacion(int v) {
    puntuacion = v;
}

string Civilizacion::getNombre() const{
    return nombre;
}

int Civilizacion::getUbicacionX() {
    return ubicacionX;
}

int Civilizacion::getUbicacionY() {
    return ubicacionY;
}

int Civilizacion::getPuntuacion() {
    return puntuacion;
}

void Civilizacion::agregarFinal(const Aldeano &a) {
    aldeanos.push_back(a);
    setPuntuacion(getPuntuacion() + 100);
}

void Civilizacion::agregarInicio(const Aldeano &a) {
    aldeanos.push_front(a);
    setPuntuacion(getPuntuacion() + 100);
}

void Civilizacion::mostrar() {
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++) {
        cout << *it;
    }
}

void Civilizacion::eliminarNombre(const string &nombre) {
    bool erased = false;
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++) {
        Aldeano &a = *it;

        if(nombre == a.getNombre()) {
            aldeanos.erase(it);
            erased = true;
            break;
        }
    }
    if(erased == false) {
        cout << "No se encontro..." << endl;
    }
}

void Civilizacion::eliminarSalud(size_t salud) {
    aldeanos.remove_if([salud](const Aldeano &a){return a.getSalud() < salud;});
}

bool comparador(const Aldeano &a) {
    return a.getEdad() >= 60;
}

void Civilizacion::eliminarEdad() {
    aldeanos.remove_if(comparador);
}

Aldeano* Civilizacion::buscar(const string &nombre) {
    bool found = false;
    Aldeano *ptr;
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++) {
        Aldeano &a = *it;

        if(nombre == a.getNombre()) {
            found = true;
            ptr = &(*it);
            break;
        }
    }
    if(found == false) {
        ptr = nullptr;
    }
    return ptr;
}

void Civilizacion::ordenarNombre() {
    aldeanos.sort();
}

bool comparadorEdad(const Aldeano &a1, const Aldeano &a2) {
    return a1.getEdad() > a2.getEdad();
}

void Civilizacion::ordenarEdad() {
    aldeanos.sort(comparadorEdad);
}

void Civilizacion::ordenarSalud() {
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getSalud() > a2.getSalud();});
}

void Civilizacion::respaldar_aldeanos()
{
    ofstream archivo(getNombre() + ".txt");
    
    for (auto it = aldeanos.begin(); it != aldeanos.end(); ++it) {
        Aldeano &aldeano = *it; 
        archivo << aldeano.getNombre() << endl;
        archivo << aldeano.getEdad()   << endl;
        archivo << aldeano.getGenero() << endl;
        archivo << aldeano.getSalud()  << endl;
    }

    archivo.close();
}


void Civilizacion::recuperar_aldeanos(string v){
    ifstream archivo (v);

    if(archivo.is_open()){
        string temp;
        int edad;
        int salud;
        string aux;
        Aldeano a;
        while(true){
            getline(archivo,temp);
            if(archivo.eof()){
                break;
            }
            aux = temp;
            a.setNombre(aux);

            getline(archivo,temp);
            edad = stoi(temp);
            a.setEdad(edad);

            getline(archivo,temp);
            aux = temp;
            a.setGenero(aux);

            getline(archivo,temp);
            salud = stoi(temp);
            a.setSalud(salud);

            agregarFinal(a);

        }
    }
    archivo.close();
}