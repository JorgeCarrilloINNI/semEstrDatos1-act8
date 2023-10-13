#include <iostream>
#include "Lista.h"

using namespace std;

int main(){
	
	Lista MiLista;
    Solicitud x;
    
    int opcion = 0, resultado;
    
    while(opcion != 3){
    	cout<<"1- Dar de alta la solicitud"<<endl;
    	cout<<"2- Buscar una solicitud"<<endl;
    	cout<<"3- Salir"<<endl;
    	cout<<"Opcion: ";
    	cin>>opcion;
    	
    	switch(opcion){
    		case 1:
    			cin>>x;
    			MiLista.DarAlta(x);
    			break;
    		case 2:
    			cout<<"Ingrese los datos de la Solicitud a buscar:"<<endl;
    			cin>>x;
    			resultado = MiLista.busquedaBinaria(x);
    			if(resultado == -1){
    				cout<<"No se encontro la Solicitud"<<endl;
				}else
					cout<<"Posicion en el arreglo: "<<resultado<<endl;
				break;
    		case 3:
    			cout<<"Saliendo..."<<endl;
    			break;
    		default:
    			cout<<"Seleccione una opcion correcta.."<<endl;
    			break;
		}
	}
	
	return 0;
}
