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


CampoElectrico::Vector2d CampoElectrico::getE(float x0, float y0, float qx, float qy, double carga){
	CampoElectrico::Vector2d vCampoE={0, 0};
	float d = CampoElectrico::distancia(x0, y0, qx, qy); // d = distancia física del punto a cada una de las cargas
	double moduloE = abs(K*carga/pow(d,2));
	double proporcion = abs(moduloE/d);	// Proporción entre distancia física y módulo del campo eléctrico
	double Ex = (x0 - qx) * proporcion;	// Distancia del cateto * proporción
	double Ey = (y0 - qy) * proporcion;	// Distancia del cateto * proporción
	vCampoE.x += Ex;
	vCampoE.y += Ey;
	return vCampoE;
}

float CampoElectrico::distancia(float x1, float y1, float x2, float y2){
	return sqrt(pow((x2-x1),2)+pow((y2-y1),2));
}
