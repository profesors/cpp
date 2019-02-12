#include <CampoElectrico.h>
#include <iostream>
#include <iomanip>
#include <math.h>

CampoElectrico::Carga::Carga(){
	set(0, 0, 0);
}

CampoElectrico::Carga::Carga(float x, float y, double q){
	set(x, y, q);
}

void CampoElectrico::Carga::set(float x, float y, double q){
	this->x = x;
	this->y = y;
	this->q = q;
}

// Recibe un array de cargas y su tamaño
// x0, y0 coordenadas donde calcular el campo eléctrico
CampoElectrico::Vector2d CampoElectrico::getE(float x0, float y0, Carga carga[], int size){
	CampoElectrico::Vector2d vCampoE={0, 0};

	for (int i=0; i<size; i++){
		float d = CampoElectrico::distancia(x0, y0, carga[i].x, carga[i].y); // d = distancia física del punto a cada una de las cargas
		double moduloE = abs(K*carga[i].q/pow(d,2));
		double proporcion = abs(moduloE/d);	// Proporción entre distancia física y módulo del campo eléctrico
		double Ex = (x0 - carga[i].x) * proporcion;	// Distancia del cateto * proporción
		double Ey = (y0 - carga[i].y) * proporcion;	// Distancia del cateto * proporción
		//std::cout<<std::setprecision(12)<<std::setw(20)<<x0<<" "<<y0<<" "<<carga[i].x<<" "<<carga[i].y<<" "<<d<<std::endl;
		//std::cout<<std::setprecision(12)<<std::setw(20)<<Ey<<std::endl;
		vCampoE.x += Ex;
		vCampoE.y += Ey;
	}
	return vCampoE;
}

float CampoElectrico::distancia(float x1, float y1, float x2, float y2){
	return sqrt(pow((x2-x1),2)+pow((y2-y1),2));
}
