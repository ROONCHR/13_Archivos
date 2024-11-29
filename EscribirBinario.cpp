#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 80;
struct tRegistro {
    int codigo;
    char item[MAX];
    double valor;
};

int ZIZE = sizeof(tRegistro);

void mostrar(tRegistro R) {
    cout << "-->" << R.codigo << " " << R.item << " " << R.valor << endl;
}

void leer(tRegistro registro) {
    fstream archivo;
    archivo.open("bd.dat", ios::in | ios::binary);
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo para lectura.\n";
        return;
    }

    archivo.read((char *)&registro, ZIZE);
    int cuantos = archivo.gcount();
    while (cuantos == ZIZE) {
        mostrar(registro);
        archivo.read((char *)&registro, ZIZE);
        cuantos = archivo.gcount();
    }

    archivo.close();
}

void escribir(tRegistro registro) {
    fstream archivo;
    archivo.open("bd.dat", ios::out | ios::app | ios::binary); // Cambiado a modo escritura y agregar
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo para escritura.\n";
        return;
    }

    bool seguir = true;
    while (seguir) {
        cout << "Codigo: ";
        cin >> registro.codigo;
        cin.ignore(); // Limpia el buffer antes de getline
        cout << "Nombre: ";
        cin.getline(registro.item, MAX);
        cout << "Precio: ";
        cin >> registro.valor;

        archivo.write((char *)&registro, ZIZE);

        cout << "¿Otro [S/N]? : ";
        char c;
        cin >> c;
        if (c == 'n' || c == 'N') {
            seguir = false;
        }
    }

    archivo.close();
}

int main() {
    tRegistro registro;
    int resp;

    do {
        cout << "Programa para leer y escribir archivos binarios\n";
        cout << "Opciones:\n";
        cout << "1) Leer de Archivo y mostrar en pantalla.\n";
        cout << "2) Escribir en Archivo.\n";
        cout << "0) Salir.\n";
        cout << "Resp: ";
        cin >> resp;

        switch (resp) {
            case 1:
                leer(registro);
                break;
            case 2:
                escribir(registro);
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (resp != 0);

    return 0;
}
