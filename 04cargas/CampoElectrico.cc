#include <CampoElectrico.h>
#include <iostream>
#include <math.h>

using namespace CampoElectrico;
using namespace std;

Carga::Carga(){
	set(0, 0, 0);
}

Carga::Carga(float x, float y, double q){
	set(x, y, q);
}

void Carga::set(float x, float y, double q){
	this->x = x;
	this->y = y;
	this->q = q;
}

// Recibe un array de cargas y su tamaño
// x0, y0 coordenadas donde calcular el campo eléctrico
double CampoElectrico::getE(float x0, float y0, Carga carga[], int size){
	double E=0;
	double ex = 0, ey=0;	// Valores totales

	for (int i=0; i<size; i++){
		double modulo = 8.99e9*carga[i].q/pow(distancia(x0, y0, carga->x, carga->y),2);
		// @TODO Sacar el ángulo entre dos puntos
		//	para hacer las proyecciones del módulo
		cout<<modulo<<endl;
	}

	return E;
}

float CampoElectrico::distancia(float x1, float y1, float x2, float y2){
	return sqrt(pow((x2-x1),2)+pow((y2-y1),2));
}
