#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
	
	const int IGV=21;
	int unidades;
	string RUC, producto;
	double precio,neto,total,igv;
	char aux;//para el espacio cualdo se lee string
	
	ifstream Archivo;//para crear el archivo
	int contador=0;
	
	Archivo.open("compras.txt");//Abrir el archivo
	if(Archivo.is_open()){//se verifica si esta abierto
		Archivo >> RUC;
		while(RUC!="X"){
			Archivo >> unidades >>precio;
			Archivo.get(aux);
			getline(Archivo,producto);
			contador++;
			neto=unidades*precio;
			igv=neto*IGV/100;
			total=neto+igv;
			
			cout<<"Compra "<<contador<<".-"<<endl;
			cout<<"    "<<producto<<" : "<< unidades <<" x "<<fixed<<setprecision(2)<<precio<<" = "<<neto<<" -IGV :"<<igv<<" - Total :"<< total<<endl;
			Archivo>>RUC;
		}
		Archivo.close();
		
		
	}else{
		cout<<"°°ERROR: El Archivo no se pudo abrir.°°"<<endl;
	}
	
	
	return 0;
}
