#include<algorithm>

#include "videogame.h"

VideoGame::VideoGame() {}

void VideoGame::setNombreUsuario(const string &v) {
    nombreUsuario = v;
}

string VideoGame::getNombreUsuario() {
    return nombreUsuario;
}

void VideoGame::agregarFinal(const Civilizacion &c) {
    civilizaciones.push_back(c);
}

void VideoGame::insertar(const Civilizacion &c, size_t p) {
    civilizaciones.insert(civilizaciones.begin() + p, c);
}

void VideoGame::inicializar(size_t n, const Civilizacion &c) {
    civilizaciones = vector<Civilizacion>(n, c);
}

void VideoGame::mostrar() {
    cout << left;
    cout << setw(15) << "Nombre";
    cout << setw(5) << "X";
    cout << setw(5) << "Y";
    cout << setw(10) << "Puntuacion";
    cout << endl;
    for(size_t i = 0; i < civilizaciones.size(); i++){
        Civilizacion &c = civilizaciones[i];
        cout << c;
    }
}

void VideoGame::frente() {
    if(civilizaciones.empty()) {
        cout << "Vector vacío..." << endl;
    }
    else {
        cout << civilizaciones.front() << endl;
    }
}

void VideoGame::ultimo() {
    if(civilizaciones.empty()) {
        cout << "Vector vacío..." << endl;
    }
    else {
        cout << civilizaciones.back() << endl;
    }
}

void VideoGame::ordenarNombre() {
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) {
        return c1.getNombre() > c2.getNombre();
    });
}

void VideoGame::ordenarUbicacionX() {
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) {
        return c1.getUbicacionX() > c2.getUbicacionX();
    });
}

void VideoGame::ordenarUbicacionY() {
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) {
        return c1.getUbicacionY() > c2.getUbicacionY();
    });
}

void VideoGame::ordenarPuntuacion() {
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) {
        return c1.getPuntuacion() > c2.getPuntuacion();
    });
}

void VideoGame::eliminar(const Civilizacion &c) {
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);
    if (it != civilizaciones.end()) {
        civilizaciones.erase(it);
    } 
    else {
        cout << "El elemento no se encuentra en el arreglo" << endl;
    }
}

Civilizacion* VideoGame::buscar(const Civilizacion &c) {
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);

    if(it == civilizaciones.end()) {
        return nullptr;
    }
    else {
        return &(*it);
    }
}

size_t VideoGame::total() {
    return civilizaciones.size();
}

void VideoGame::respaldar()
{
    ofstream archivo("civilizaciones.txt");

    for (int i = 0; i < civilizaciones.size(); ++i) {
        Civilizacion &c = civilizaciones[i];
        archivo << c.getNombre() << endl;
        archivo << c.getUbicacionX() << endl;
        archivo << c.getUbicacionY() << endl;
        archivo << c.getPuntuacion() << endl;
        c.respaldar_aldeanos();
    }
    archivo.close();
}

void VideoGame::recuperar(){
    ifstream archivo("civilizaciones.txt");
    if(archivo.is_open()){
        string temp;
        string aux;
        int ubicacion;
        int puntuacion;
        
        while(true){
            
            Civilizacion c;

            getline(archivo,temp);
            if(archivo.eof()){ break;}
            c.setNombre(temp);

            aux = temp + ".txt";
            c.recuperar_aldeanos(aux);

            getline(archivo,temp);
            ubicacion = stoi(temp);
            c.setUbicacionX(ubicacion);

            getline(archivo,temp);
            ubicacion = stoi(temp);
            c.setUbicacionY(ubicacion);

            getline(archivo,temp);
            puntuacion = stoi(temp);
            c.setPuntuacion(puntuacion);

            agregarFinal(c);
        }
    }
    archivo.close();
}