#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void leer(int unidades,double precio,string RUC, string producto) {
	const int IGV=21;
	double neto,total,igv;
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
	
}
void escribir(int unidades,double precio,string RUC, string producto){
	ofstream Archivo;
	Archivo.open("compras.txt");//apretura o creacion 
	cout<<"Escriba el Ruc de cliente(X para terminar)";
	cin>>RUC;
	while(RUC!="X"){
		cout<<"Unidades:";
		cin>>unidades;
		cout<<"Precio:";
		cin>>precio;
		cin.ignore();
		cout<<"Producto:";
		getline(cin,producto);
		
		Archivo<<RUC<<" "<<unidades<<" "<<precio<<" "<<producto<<endl;
		cout<<"Escriba el Ruc de cliente(X para terminar)";
		cin>>RUC;
	}
	Archivo<<"X";
	Archivo.close();
}
int main(){
	string RUC,producto;
	int unidades;
	double precio;
	char aux;
	
	//ofstream Archivo;
	int resp;
	do{
		cout<<"PROGRAMA DE ESCRIBIR Y LEER EN UN ARCHIVO:\n\n";
		cout<<"opciones:"<<endl;
		cout<<"1) Escribir\n";
		cout<<"2) Leer y mostrar calculos\n";
		cout<<"0)Salir\n";
		cout<<"resp: ";cin>>resp;
		if(resp==1){
			escribir(unidades,precio,RUC, producto);
		}else if(resp==2){
			leer(unidades,precio, RUC, producto );
		}
	
		
		
	}while(resp!=0);
	
	
	
	return 0;
}
