#include <iostream>


using namespace std;

int tabla[][3] = {{0, 0, 0},{0, 1, 0},{1, 0, 0},{1, 1, 1}};
double pesos[] = {0, 0, 0};

int main()
{
	//cout<<tabla[1][1]<<endl;
	bool aprendiendo{true};
	int salida_entera{0}, iteracion{0};
	double tasa_aprende = 0.1;
	while(aprendiendo){
		++iteracion;
		aprendiendo = false;
		for (int i=0; i!=4; ++i){
			double salida_real = tabla[i][0] * pesos[0] + tabla[i][1] * pesos[1] + pesos[2];
			salida_entera = (salida_real>0)?1:0;
			int error = tabla[i][2] - salida_entera;
			if (error != 0){
				pesos[0] += tasa_aprende * error * tabla[i][0];
				pesos[1] += tasa_aprende * error * tabla[i][1];
				pesos[2] += tasa_aprende * error;
				aprendiendo = true;
			}
		}
	}

	cout<<"Iteraciones "<<iteracion<<endl;
	cout<<"Peso entrada_1: "<<pesos[0]<<endl;
	cout<<"Peso entrada_2: "<<pesos[1]<<endl;
	cout<<"Peso umbral: "<<pesos[2]<<endl;

	for(int i=0; i!=4; ++i){
		double salida_real = tabla[i][0] * pesos[0] + tabla[i][1] * pesos[1] + pesos[2];
		salida_entera = (salida_real>0)?1:0;
		cout<<tabla[i][0]<<" y "<<tabla[i][1]<<" = "<<tabla[i][2]<<" perceptrón: "<<salida_entera<<endl;
	}

	return 0;
}
