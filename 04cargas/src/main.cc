#include <CampoElectrico.h>
#include <iostream>
#include <math.h>

using namespace std;
using namespace CampoElectrico;

const int NCARGAS = 3;

int main(){
	//std::unique_ptr<Carga> q1(new Carga(0,4,1e-9));
	Carga* q[NCARGAS];

	q[0] = new Carga( -0.02, 0, 5e-9);
	q[1] = new Carga(  0.02, 0, 5e-9);
	q[2] = new Carga(0,2,3);

	Vector2d v = getE(0, sqrt(0.04*0.04-0.02*0.02), *q, NCARGAS-1);

	cout<<v.x<<"i "<<v.y<<"j "<<endl;

	return 0;
}
