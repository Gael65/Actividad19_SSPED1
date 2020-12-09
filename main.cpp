#include <iostream>

#include "videogame.h"
#include "menu.h"

using namespace std;

int main() {
    VideoGame myVideoGame;
    string opc;

    while(true) {
        cout << "1. Nombre de usuario" << endl;
        cout << "2. Agregar civilizacion al final" << endl;
        cout << "3. Insertar civilizacion" << endl;
        cout << "4. Crear civilizaciones (inicializar)" << endl;
        cout << "5. Primer civilizacion" << endl;
        cout << "6. Ultima civilizacion" << endl;
        cout << "7. Ordenar" << endl;
        cout << "8. Eliminar" << endl;
        cout << "9. Buscar" << endl;
        cout << "10. Modificar" << endl;
        cout << "11. Resumen (mostrar)" << endl;
        cout << "12. Respaldar" << endl;
        cout << "13. Recuperar" << endl;
        cout << "14. Salir" << endl << endl;

        cout << "Selecciona una opcion: ";
        getline(cin, opc);

        if(opc == "1") {
            cout << endl;
            string nombre;
            cout << "Ingresa el nombre de usuario: ";
            getline(cin, nombre);

            myVideoGame.setNombreUsuario(nombre);
            cout << endl;
        }

        else if(opc == "2") {
            cout << endl;
            Civilizacion c;
            cin >> c;

            myVideoGame.agregarFinal(c);
            cout << endl;
        }

        else if(opc == "3") {
            cout << endl;
            Civilizacion c;
            cin >> c;

            size_t p;
            cout << "Dame la posicion para insertar: "; cin >> p; cin.ignore();

            if(p >= myVideoGame.total()) {
                cout << endl;
                cout << "Posicion no valida..." << endl;
            }
            else {
                myVideoGame.insertar(c, p);
            }
            cout << endl;
        }

        else if(opc == "4") {
            cout << endl;
            Civilizacion c;
            cin >> c;

            size_t n;
            cout << "n: "; cin >> n; cin.ignore();

            myVideoGame.inicializar(n, c);
            cout << endl;
        }

        else if(opc == "5") {
            cout << endl;
            cout << "El primer elemento del vector:" << endl;
            cout << left;
            cout << setw(15) << "Nombre";
            cout << setw(5) << "X";
            cout << setw(5) << "Y";
            cout << setw(10) << "Puntuacion" << endl;
            myVideoGame.frente();
            cout << endl;
        }

        else if (opc == "6") {
            cout << endl;
            cout << "El ultimo elemento del vector:" << endl;
            cout << left;
            cout << setw(15) << "Nombre";
            cout << setw(5) << "X";
            cout << setw(5) << "Y";
            cout << setw(10) << "Puntuacion" << endl;
            myVideoGame.ultimo();
            cout << endl;
        }

        else if(opc == "7") {
            cout << endl;
            string opc2;

            cout << "1. Por nombre" << endl;
            cout << "2. Por ubicacion en X" << endl;
            cout << "3. Por ubicacion en Y" << endl;
            cout << "4. Por puntuacion" << endl;

            getline(cin, opc2);

            if(opc2 == "1") {
                myVideoGame.ordenarNombre();
            }
            else if(opc2 == "2") {
                myVideoGame.ordenarUbicacionX();
            }
            else if(opc2 == "3") {
                myVideoGame.ordenarUbicacionY();
            }
            else if(opc2 == "4") {
                myVideoGame.ordenarPuntuacion();
            }
            else {
                cout << "Opcion no valida" << endl;
            }
            cout << endl;
        }

        else if(opc == "8") {
            cout << endl;
            Civilizacion c;
            string nombre;

            cout << "Nombre de la civilizacion a eliminar: ";
            getline(cin, nombre);

            c.setNombre(nombre);

            myVideoGame.eliminar(c);
            cout << endl;
        }

        else if(opc == "9") {
            cout << endl;
            string nombre;

            cout << "Nombre de civilizacion a buscar: ";
            getline(cin, nombre);
            cout << endl;

            Civilizacion c;
            c.setNombre(nombre);

            Civilizacion *ptr = myVideoGame.buscar(c);

            if(ptr == nullptr) {
                cout << "No encontrado..." << endl;
            }
            else {
                cout << "Registro encontrado:" << endl;
                cout << left;
                cout << setw(15) << "Nombre";
                cout << setw(5) << "X";
                cout << setw(5) << "Y";
                cout << setw(10) << "Puntuacion" << endl;
                cout << *ptr;
                menu(*ptr);
            }
            cout << endl;
        }

        else if(opc == "10") {
            cout << endl;
            string nombre, opc2;
            cout << "Nombre de civilizacion a modificar: ";
            getline(cin, nombre);

            Civilizacion c;
            c.setNombre(nombre);

            Civilizacion *ptr = myVideoGame.buscar(c);

            if(ptr == nullptr) {
                cout << "No encontrado..." << endl;
            }
            else {
                cout << endl;
                cout << "Registro encontrado:" << endl;
                cout << left;
                cout << setw(15) << "Nombre";
                cout << setw(5) << "X";
                cout << setw(5) << "Y";
                cout << setw(10) << "Puntuacion" << endl;
                cout << *ptr << endl;

                cout << "1. Modificar nombre" << endl;
                cout << "2. Modificar ubicacion en X" << endl;
                cout << "3. Modificar ubicacion en Y" << endl;
                cout << "4. Modificar puntuacion" << endl;

                cout << "Selecciona una opcion: "; getline(cin, opc2);

                if(opc2 == "1") {
                    cout << endl;
                    string nombre;
                    cout << "Dame el nuevo nombre: "; getline(cin, nombre);

                    ptr->setNombre(nombre);
                }
                else if(opc2 == "2") {
                    cout << endl;
                    int ubicacionX;

                    cout << "Dame la nueva ubicacion en X: ";
                    cin >> ubicacionX; cin.ignore();

                    ptr->setUbicacionX(ubicacionX);
                }
                else if(opc2 == "3") {
                    cout << endl;
                    int ubicacionY;

                    cout << "Dame la nueva ubicacion en Y: ";
                    cin >> ubicacionY; cin.ignore();

                    ptr->setUbicacionY(ubicacionY);
                }
                else if(opc2 == "4") {
                    cout << endl;
                    int puntuacion;

                    cout << "Dame la nueva puntuacion: ";
                    cin >> puntuacion; cin.ignore();

                    ptr->setPuntuacion(puntuacion);
                }
                else {
                    cout << "Opcion no valida" << endl << endl;
                }
            }
        }

        else if(opc == "11") {
            cout << endl;
            myVideoGame.mostrar();
            cout << endl;
        }

        else if(opc == "12") {
            myVideoGame.respaldar();
        }

        else if(opc == "13") {
            myVideoGame.recuperar();
        }

        else if(opc == "14") {
            break;
        }

        else {
            cout << endl;
            cout << "Opcion no valida..." << endl << endl;
        }
    }

    return 0;
}