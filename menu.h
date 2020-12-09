#include "civilizacion.h"

void menu(Civilizacion &c) {
    string opc;

    while(true) {
        cout << endl;
        cout << "1) Agregar aldeano" << endl;
        cout << "2) Eliminar aldeano" << endl;
        cout << "3) Clasificar aldeanos" << endl;
        cout << "4) Buscar aldeano" << endl;
        cout << "5) Modificar aldeano" << endl;
        cout << "6) Mostrar aldeanos" << endl;
        cout << "0) Salir" << endl;

        cout << endl;
        cout << "Selecciona una opcion: "; getline(cin, opc);

        if(opc == "1") {
            cout << endl;
            string opc2;
            Aldeano a;

            cout << "1. Agregar aldeano al inicio" << endl;
            cout << "2. Agregar aldeano al final" << endl;

            cout << endl;
            cout << "Selecciona una opcion: "; getline(cin, opc2);

            if(opc2 == "1") {
                cin >> a;
                c.agregarInicio(a);
            }
            else if(opc2 == "2") {
                cin >> a;
                c.agregarFinal(a);
            }
            else {
                cout << endl;
                cout << "Opcion no valida..." << endl;
            }
        }
        else if(opc == "2") {
            cout << endl;
            string opc2;

            cout << "1. Eliminar por nombre" << endl;
            cout << "2. Eliminar por salud" << endl;
            cout << "3. Eliminar por edad (mayor o igual a 60)" << endl;

            cout << endl;
            cout << "Selecciona una opcion: "; getline(cin, opc2);

            if(opc2 == "1") {
                cout << endl;
                string nombre;

                cout << "Dame el nombre del aldeano a eliminar: ";
                getline(cin, nombre);

                c.eliminarNombre(nombre);
            }
            else if(opc2 == "2") {
                cout << endl;
                size_t salud;

                cout << "Dame la salud de referencia para eliminar: ";
                cin >> salud; cin.ignore();

                c.eliminarSalud(salud);
            }
            else if(opc2 == "3") {
                c.eliminarEdad();
            }
            else {
                cout << endl;
                cout << "Opcion no valida... " << endl;
            }
        }
        else if(opc == "3") {
            cout << endl;
            string opc2;

            cout << "1. Clasificar por nombre (ascendente)" << endl;
            cout << "2. Clasificar por edad (descendente)" << endl;
            cout << "3. Clasificar por salud (descendente)" << endl;

            cout << endl;
            cout << "Selecciona una opcion: "; getline(cin, opc2);

            if(opc2 == "1") {
                c.ordenarNombre();
            }
            else if(opc2 == "2") {
                c.ordenarEdad();
            }
            else if(opc2 == "3") {
                c.ordenarSalud();
            }
            else {
                cout << endl;
                cout << "Opcion no valida..." << endl;
            }
        }
        else if(opc == "4") {
            cout << endl;
            string nombre;
            cout << "Aldeano a buscar: "; getline(cin, nombre);
            
            Aldeano *ptr = c.buscar(nombre);

            if(ptr == nullptr) {
                cout << endl;
                cout << "No encontrado..." << endl;
            }
            else {
                cout << endl;
                cout << "Registro encontrado:" << endl;
                cout << left;
                cout << setw(10) << "Nombre";
                cout << setw(10) << "Edad";
                cout << setw(10) << "Genero";
                cout << setw(10) << "Salud" << endl;
                cout << *ptr;
            }
        }
        else if(opc == "5") {
            cout << endl;
            string nombre;
            cout << "Aldeano a buscar: "; getline(cin, nombre);
            
            Aldeano *ptr = c.buscar(nombre);

            if(ptr == nullptr) {
                cout << endl;
                cout << "No encontrado..." << endl;
            }
            else {
                cout << endl;
                cout << "Registro encontrado:" << endl;
                cout << setw(10) << "Nombre";
                cout << setw(10) << "Edad";
                cout << setw(10) << "Genero";
                cout << setw(10) << "Salud" << endl;
                cout << *ptr;

                cout << endl;
                cout << "1. Modificar nombre" << endl;
                cout << "2. Modificar edad" << endl;
                cout << "3. Modificar genero" << endl;
                cout << "4. Modificar salud" << endl;

                cout << endl;
                string opc2;
                cout << "Selecciona una opcion: "; getline(cin, opc2);

                if(opc2 == "1") {
                    cout << endl;
                    string nombre;
                    cout << "Dame el nuevo nombre: "; getline(cin, nombre);

                    ptr->setNombre(nombre);
                }
                else if(opc2 == "2") {
                    cout << endl;
                    int edad;
                    cout << "Dame la nueva edad: "; cin >> edad; cin.ignore();

                    ptr->setEdad(edad);
                }
                else if(opc2 == "3") {
                    cout << endl;
                    string genero;
                    cout << "Dame el nuevo genero: "; getline(cin, genero);

                    ptr->setGenero(genero);
                }
                else if(opc2 == "4") {
                    cout << endl;
                    int salud;
                    cout << "Dame la nueva salud: "; cin >> salud; cin.ignore();

                    ptr->setSalud(salud);
                }
                else {
                    cout << endl;
                    cout << "Opcion no valida..." << endl;
                }
            }
        }
        else if(opc == "6") {
            cout << endl;
            cout << left;
            cout << setw(10) << "Nombre";
            cout << setw(10) << "Edad";
            cout << setw(10) << "Genero";
            cout << setw(10) << "Salud" << endl;
            c.mostrar();
        }
        else if(opc == "0") {
            break;
        }
        else {
            cout << endl;
            cout << "Opcion no valida" << endl;
        }
    }
}