#include "Lista.h"

Solicitud::Solicitud(){
    nombre  = "";
    carrera = "";
    prepa = "";
    promedio = 0;
}

Solicitud::Solicitud(std::string n, std::string c, std::string t, float p): nombre(n), carrera(c), prepa(t), promedio(p) {}
void Solicitud::operator=(Solicitud& x)
{
    nombre  = x.nombre;
    carrera = x.carrera;
    prepa = x.prepa;
    promedio = x.promedio;
}

std::ostream& operator<<( std::ostream& o, Solicitud& x)
{
	o<<"***************************************Solicitud***************************************"<<std::endl;
    o<<"nombre: "<<x.nombre<<"\t carrera: "<<x.carrera<<"\t prepa: "<<x.prepa<<"\t promedio: "<<x.promedio<<std::endl;
    return o;
}
std::istream& operator>>( std::istream& o, Solicitud& x)
{
    std::cout<<"inserta nombre: ";
    o>>x.nombre;
    std::cout<<"inserta carrera: ";
    o>>x.carrera;
    std::cout<<"inserta prepa de procedencia: ";
    o>>x.prepa;
    std::cout<<"inserta promedio: ";
    o>>x.promedio;
    return o;
}

bool Lista::vacia()const
{
    if(ult==-1)
        return true;
    return false;
}
bool Lista::llena()const
{
    if(ult==TAM-1)
        return true;
    return false;
}

int Lista::ultimo()const
{
    return ult;
}

std::ostream& operator<<(std::ostream & o, Lista& L)
{
    int i=0;
    std::cout<<"\n";
    while(i<=L.ultimo())
    {
        o<<L.datos[i];
        i++;
    }
    return o;
}

bool Lista::elimina(int pos)
{
    if(vacia() || pos<0 || pos>ult)
    {
        std::cout<<"\n error de eliminacion";
        return true;
    }
    int i=pos;
    while(i<ult)
    {
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return false;
}
int Lista::inserta(Solicitud& elem, int pos)
{
    if(llena()|| pos<0 || pos>ult+1)
    {
        std::cout<<"\n Error de insercion";
        return 0;
    }
    int i=ult+1;
    while(i>pos)
    {
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return 1;
}
void Lista::DarAlta(Solicitud& elem){
	inserta(elem, ult+1);
};


Solicitud operator +(Solicitud& e1, Solicitud& e2){
	return Solicitud(e1.nombre+e2.nombre, e1.carrera+e2.carrera, e1.prepa+e2.prepa, e1.promedio+e2.promedio);
}
    	
bool operator ==(Solicitud& e1, Solicitud& e2){
    return (e1.nombre == e2.nombre &&
        e1.carrera == e2.carrera &&
        e1.prepa == e2.prepa &&
        e1.promedio == e2.promedio);
}

bool operator !=(Solicitud& e1, Solicitud& e2){
    return !(e1 == e2);
}
    
bool operator <(Solicitud& e1, Solicitud& e2) {
    return e1.promedio < e2.promedio;
}
    
bool operator >(Solicitud& e1, Solicitud& e2) {
    return e1.promedio > e2.promedio;
}
bool operator <=(Solicitud& e1, Solicitud& e2) {
    return (e1.promedio < e2.promedio || e1.promedio == e2.promedio);
}
bool operator >=(Solicitud& e1, Solicitud& e2) {
    return (e1.promedio > e2.promedio || e1.promedio == e2.promedio);
}

int Lista::busquedaBinaria(Solicitud& c) {
	quicksort(0, ult);
	int i=0, j=ult, medio;
	
	while(i<=j){
		medio=(i+j)/2;
		if(datos[medio] == c)
			return medio;
		if(c < datos[medio]){
			j=medio-1;
		}else
			i=medio+1;
	}

    return -1;
}
void Lista::burbuja(){
	Solicitud aux;
	for (int i = 0; i < ult; i++) {
        for (int j = 0; j < ult - i; j++) {
            if (datos[j] > datos[j + 1]) {
                aux = datos[j];
                datos[j] = datos[j + 1];
                datos[j + 1] = aux;
            }
        }
    }
};
void Lista::insercion(){
	int i=1;
	Solicitud aux;
	while(i <= ult){
		aux=datos[i];
		int j=i;
		while(j > 0 && aux < datos[j-1]){
			datos[j] = datos[j-1];
			j=j-1;
		}
		if(i != j)
			datos[j]=aux;
		i = i+1;
	}
};
void Lista::quicksort(int menor, int mayor){
	Solicitud aux;
	if(menor >= mayor)
		return;
	aux = datos[mayor];
	datos[mayor] = datos[(menor+mayor)/2];
	datos[(menor+mayor)/2] = aux;
	
	int i = menor, j = mayor;
	while(i < j){
		while(i < j && datos[i] <= datos[mayor]){
			i = i+1;
		}
		while(i < j && datos[j] >= datos[mayor]){
			j = j-1;
		}
		if(i != j){
			aux = datos[i];
			datos[i] = datos[j];
			datos[j] = aux;
		}
	}
	if(i != mayor){
			aux = datos[i];
			datos[i] = datos[mayor];
			datos[mayor] = aux;
	}
	quicksort(menor, i-1);
	quicksort(i+1, mayor);
};





