#include <iostream>

#include <iostream>
#include <fstream>
#include "struct.h"

using namespace std;
void mostrar(tRegistro R);
void actualizar(tRegistro registro){
	fstream archivo;
	archivo.open("bd.dat",ios::in | ios::out | ios::binary);
	archivo.seekg(0,ios::end);//POSICIONA EL CURSOR EN LA POSICION ESE CERO ESTA SI O SI SI ES QUE ESTA EL ORIGEN EL END
	int pos = archivo.tellg();
	int numReg = pos /ZIZE;
	cout<< "Numero de registros: "<<numReg<<endl;
	int num;
	cout << "Regristro numero?: ";
	cin >> num;
	if((num >0) && (num<=numReg)){
		archivo.seekg((num-1)*ZIZE,ios::beg);
		archivo.read((char *) &registro,ZIZE);
		mostrar(registro);
		cout<<endl<<"Cambiar nombre [S/N]?";
		char c;
		cin.sync();
		cin>>c;
		if((c=='s')||(c=='S')){
			cout <<"Nombre: ";
			cin.sync();
			cin.getline(registro.item,80);
			cout<<endl<<"cambiar precio [S/N]?";
			cin.sync();
			cin >> c;
		if((c=='s')||(c=='S')){
			cout <<"Precio: ";
			cin>> registro.valor;
		}
		archivo.seekg((num-1)*ZIZE,ios::beg);
		archivo.write((char *) &registro, ZIZE);
		cout<<endl<<"Registro actualizado: "<<endl;
		archivo.seekg((num-1)*ZIZE,ios::beg);
		archivo.read((char*) &registro, ZIZE);
		mostrar(registro); 			
		}
		archivo.close();
	}
}

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
        cout << "3) Actualizar Archivo.\n";
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
            case 3:
            	actualizar(registro);
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (resp != 0);

    return 0;
}
