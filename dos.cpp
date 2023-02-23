#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Estudiante {
    string nombre;
    int identificador;
    int calificacion;
    //int &calif = calificacion;
};
int Menu();
int Menu() {
    int respuesta;
    cout<<"-------------------------------"<<endl;
    cout<<"Que es lo que quieres hacer?"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"1. Agregar nuevo estudiante"<<endl;
    cout<<"2. Actualizar calificaciones de un estudiante ya existente"<<endl;
    cout<<"3. Buscar estudiantes por numero de identificador"<<endl;
    cout<<"4. Salir del programa"<<endl;
    cin>>respuesta;
    return respuesta;
}

vector<Estudiante> estudiantes;
void agregarEstudiante() {
    Estudiante estudiante;

    // Solicitar el nombre, identificador y calificación del estudiante
    cout << "Ingrese el nombre del estudiante: ";
    cin >> estudiante.nombre;
    cout << "Ingrese el identificador del estudiante: (numero) ";
    cin >> estudiante.identificador;
    cout << "Ingrese la calificación del estudiante: ";
    cin >> estudiante.calificacion;

    // Agregar el estudiante al vector
    estudiantes.push_back(estudiante);

    cout << "El estudiante " << estudiante.nombre << " ha sido agregado." << endl;
}

void actualizarCalificacion() {
    int identificador;

    // Mostrar la lista de estudiantes
    cout << "Lista de estudiantes:" << endl;
    for (const Estudiante& estudiante : estudiantes) {
        cout << "Identificador: " << estudiante.identificador
             << ", Nombre: " << estudiante.nombre
             << ", Calificación: " << estudiante.calificacion << endl;
    }

    // Pedir el identificador del estudiante a actualizar
    cout << "Ingrese el identificador del estudiante: ";
    cin >> identificador;

    // Buscar el estudiante por identificador
    bool encontrado = false;
    for (auto& estudiante : estudiantes) {
        if (estudiante.identificador == identificador) {
            // Actualizar la calificación del estudiante
            cout << "Ingrese la nueva calificación del estudiante: ";
            int &calif=estudiante.calificacion;
            cin >> calif;
            cout << "La calificación del estudiante " << estudiante.nombre << " ha sido actualizada." << endl;
            encontrado = true;
            //break;
        }
    }

    if (!encontrado) {
        cout << "No se encontró ningún estudiante con ese identificador." << endl;
    }
}

void buscarEstudiante(){
    int identificador_buscado;
                bool encontrado = false;
                cout << "Ingresa el identificador del estudiante a buscar: ";
                cin >> identificador_buscado;

                for (auto& estudiante : estudiantes) {
                    if (estudiante.identificador == identificador_buscado) {
                        encontrado = true;
                        Estudiante* ptr_estudiante = &estudiante;
                        cout << "Estudiante encontrado: " << endl;
                        cout << "Nombre: " << ptr_estudiante->nombre << endl;
                        cout << "Identificador: " << ptr_estudiante->identificador << endl;
                        cout << "Calificación: " << ptr_estudiante->calificacion << endl;
                    break;
                    }
                }

                if (!encontrado) {
                    cout << "Estudiante no encontrado." << endl;
                }
}

int main(){
int opcion;
    do {
        opcion = Menu();
        switch (opcion) {
            case 1:
                agregarEstudiante();
                break;
            case 2:
                actualizarCalificacion();
                break;
            case 3:
                buscarEstudiante();
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 4);
    return 0;
}