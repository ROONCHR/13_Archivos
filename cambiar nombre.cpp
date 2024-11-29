#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 80;
struct tRegistro{
	int codigo;
	char item[MAX];
	double valor;
};

int ZIZE= sizeof(tRegistro);

void mostrar(Registro R){
	cout<<"-->"<<codigo<<" "<<item<<" "<<valor<<endl;
}

int main(){
	tRegistro registro;
	fstream archivo;
	archivo.open("bd.dat",ios::Init|ios::binary);
	archivo.read( (char *)&registro,ZIZE);
	int cuantos = archivo.gcount();
	while(cuantos==ZIZE){
		mostrar(registro);
		archivo.read((char *)&registro,ZIZE);
		cuantos = archivo.gcount();
	}
	archivo.close();
	return 0;
}