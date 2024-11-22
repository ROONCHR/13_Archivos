#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(){
	string RUC,producto;
	int unidades;
	double precio;
	char aux;
	
	ofstream Archivo;
	
	Archivo.open("compras.txt");//apretura o creacion 
	cout<<"Escriba el Ruc de cliente(X para terminar)";
	cin>>RUC;
	while(RUC!="X"){
		cout<<"Unidades:";
		cin>>unidades;
		cout<<"Precio:";
		cin>>precio;
		cout<<"Producto:";
		getline(cin,producto);
		Archivo<<RUC<<" "<<unidades<<" "<<precio<<" "<<producto<<endl;
		cout<<"Escriba el Ruc de cliente(X para terminar)";
		cin>>RUC;
	}
	Archivo<<"X";
	Archivo.close();
	
	return 0;
}
